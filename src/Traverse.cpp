#include "Traverse.h"

#include "config/Config.h"
#include "config/TraverseConfig.h"
#include "logging/TraverseLogging.h"

#include <string>

#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

using namespace Traverse;
using namespace Poco;

const std::string brand = "Traverse";

/** The Traverse Logger */
Logger& logger = Logger::create(brand, Logging::getDefaultChannel());

/** The Traverse Config */
TraverseConfig config;

void Traverse::initialize() {
    Logger::root().setChannel(Logging::getDefaultChannel());

    logger.information("Initializing " + brand);

    logger.information("Loading config");
    config.load();
}