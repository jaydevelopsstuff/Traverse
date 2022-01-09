#include "Traverse.h"

#include "logging/TraverseLogging.h"

#include <string>

#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

using namespace Traverse;
using namespace Poco;

const std::string brand = "Traverse";

Logger& logger = Logger::create(brand, Logging::getDefaultChannel());

void Traverse::initialize() {
    Logger::root().setChannel(Logging::getDefaultChannel());

    logger.information("Initializing " + brand);
}