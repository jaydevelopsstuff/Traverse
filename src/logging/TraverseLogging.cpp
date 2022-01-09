#include "TraverseLogging.h"

#include <Poco/AutoPtr.h>
#include <Poco/Channel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/PatternFormatter.h>

Channel::Ptr Traverse::Logging::getDefaultChannel() {
    AutoPtr<PatternFormatter> patternFormatter(new PatternFormatter("[%s] [%p]: %t"));
    AutoPtr<ConsoleChannel> consoleChannel(new ConsoleChannel());

    return AutoPtr(new FormattingChannel(patternFormatter, consoleChannel));
}