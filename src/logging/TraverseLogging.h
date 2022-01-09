#pragma once

#include <Poco/Logger.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

using namespace Poco;

namespace Traverse::Logging {
    Channel::Ptr getDefaultChannel();
}