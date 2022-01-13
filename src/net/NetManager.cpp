#include "NetManager.h"

#include "Connection.h"

using namespace Traverse;

void NetManager::startListening() {
    if(listening) throw new Exception::RuntimeException("Already started listening!");
    tcpServerPtr->listen();
    listening = true;
}

void NetManager::shutdown() {
    if(!listening) return;
    for(Connection* connectionPtr : connections) {
        connectionPtr->disconnect("Server shutting down!");
    }
    tcpServerPtr->shutdown();
}