#pragma once

#include <string>

#include <Poco/Net/TCPServerConnection.h>

using namespace Poco::Net;

namespace Traverse::Net {
    class Connection : public TCPServerConnection {
        public:
            Connection(const StreamSocket& t_socket) : TCPServerConnection(t_socket) {}

            void run() override;

            void disconnect() {
                disconnectScheduled = true;
                gracefulDisconnect = true;
                disconnectReason = "Disconnected";
            }

            void disconnect(std::string t_reason) {
                disconnectScheduled = true;
                gracefulDisconnect = true;
                disconnectReason = t_reason;
            }

            void hardDisconnect() {
                disconnectScheduled = true;
                gracefulDisconnect = false;
                disconnectReason = "Disconnected";
            }

            void hardDisconnect(std::string t_reason) {
                disconnectScheduled = true;
                gracefulDisconnect = false;
                disconnectReason = t_reason;
            }

            bool hasLoggedIn() const {
                return completedLogin;
            }

        private:
            std::string address;
            bool completedLogin = false;

            bool disconnectScheduled = false;
            bool gracefulDisconnect;
            std::string disconnectReason;
    };
}