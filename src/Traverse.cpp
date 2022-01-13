#include "Traverse.h"

#include "config/Config.h"
#include "config/TraverseConfig.h"
#include "logging/TraverseLogging.h"
#include "net/NetManager.h"

#include <string>

#include <Poco/Thread.h>
#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

using namespace Traverse;
using namespace Poco;

const std::string brand = "Traverse";

/** The Traverse Logger */
Logger& logger = Logger::create(brand, Logging::getDefaultChannel());

/**
 * Whether a shutdown is scheduled, when this turns true, the main thread will stop blocking and 
 * Traverse::initialize will complete, causing the program to shut down.
 */
bool shutdownScheduled = false;

/** The Traverse Config */
TraverseConfig config;

NetManager* networkManagerPtr;

void Traverse::initialize() {
    Logger::root().setChannel(Logging::getDefaultChannel());

    logger.information("Initializing");

    logger.information("Loading config");
    try {
        config.load();
    } catch(std::exception e) {
        logger.fatal("Error while loading config: " + std::string(e.what()));
        shutdown();
        return;
    }
    logger.information("Log Level: " + config.getLogLevel());
    Logger::root().setLevel(config.getLogLevel());
    logger.setLevel(config.getLogLevel());

    logger.information("Initializing Network Manager");
    networkManagerPtr = new NetManager(config);

    // Try to start TCP server
    try {
        networkManagerPtr->startListening();
    } catch(std::exception e) {
        logger.fatal("Error while starting TCP server: " + std::string(e.what()));
    }

    while(!shutdownScheduled) {
        // Busy waiting, is this ok?
        Poco::Thread::sleep(50);
    }
    logger.information("Exiting");
}

void Traverse::shutdown() {
    logger.information("Shutting down!");
    networkManagerPtr->shutdown();
    shutdownScheduled = true;
}

const std::string Traverse::getBrand() {
    return brand;
}