#pragma once

#include <Poco/Channel.h>

namespace Traverse {
    void initialize();

    Poco::Channel::Ptr& getDefaultLoggerChannel();
}
