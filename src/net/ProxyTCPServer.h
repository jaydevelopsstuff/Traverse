#pragma once

#include "../Types.h"
#include "../Traverse.h"
#include "Connection.h"

#include <Poco/Logger.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/TCPServerParams.h>
#include <Poco/Thread.h>

using namespace Poco::Net;

namespace Traverse::Net {
    class ProxyTCPServer : protected TCPServer {
        public:
            ProxyTCPServer(u16 t_port, u32 t_maxConnected, TCPServerParams* t_params) : TCPServer(new TCPServerConnectionFactoryImpl<Connection>(), t_port, t_params), maxConnectioned(t_maxConnected) {}

            void listen();

            void shutdown();
            
        private:
            Poco::Logger& logger = Poco::Logger::get(Traverse::getBrand());
            bool running = false;
            u32 maxConnectioned;
            u32 maxThreads;
    };
}