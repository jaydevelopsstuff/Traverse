#include "ProxyTCPServer.h"
#include <Poco/Thread.h>

using namespace Traverse::Net;

void ProxyTCPServer::listen() {
    start();
    running = true;
}

void ProxyTCPServer::shutdown() {
    stop();
    running = false;
}