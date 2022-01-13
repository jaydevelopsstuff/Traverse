#pragma once

#include <Poco/Channel.h>
#include <Poco/Logger.h>

namespace Traverse {
    /** Initializes Traverse, this should only ever be called once to start the proxy. */
    void initialize();

    /** Shuts down Traverse and all of its components. */
    void shutdown();

    const std::string getBrand();

    Poco::Channel::Ptr& getDefaultLoggerChannel();
}
