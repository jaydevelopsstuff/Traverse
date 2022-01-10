#pragma once

#include <Poco/Channel.h>

using namespace Poco;

namespace Traverse::Logging {
    Channel::Ptr getDefaultChannel();
}