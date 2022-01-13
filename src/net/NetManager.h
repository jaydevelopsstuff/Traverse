#pragma once

#include "Connection.h"
#include "ProxyTCPServer.h"
#include "../config/TraverseConfig.h"
#include <Poco/Net/TCPServerParams.h>
#include <vector>

using namespace Traverse::Net;

namespace Traverse {
    class NetManager {
        public:
            NetManager(TraverseConfig& t_config) {
                TCPServerParams::Ptr params = new TCPServerParams();
                params->setMaxThreads(t_config.getMaxNetworkThreads());
                tcpServerPtr = new ProxyTCPServer(t_config.getPort(), t_config.getMaxConnected(), params);
                instancePtr = this;
            }

            void startListening();

            /**
             * Retrieves all the connected clients, some may not have completed the login process. Do NOT remove ANY
             * elements of this list manually.
             * @return std::vector<Connection*>& All connected clients
             */
            std::vector<Connection*>& getConnections() {
                return connections;
            }

            void shutdown();

            static NetManager& instance() {
                return *instancePtr;
            }

            /**
             * Adds a connection to the connections vector, this should only ever be invoked from the {@link Connection} class.
             * @param t_connection A pointer to the connection to add
             */
            static void addConnection(Connection* t_connection) {
                instance().connections.push_back(t_connection);
            }

        private:
            inline static NetManager* instancePtr;

            ProxyTCPServer* tcpServerPtr;
            std::vector<Connection*> connections;
            bool listening = false;
    };
}