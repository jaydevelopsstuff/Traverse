#include "Connection.h"

#include "../Traverse.h"
#include "NetManager.h"

#include <Poco/Logger.h>
#include <Poco/Thread.h>

using namespace Traverse::Net;

void Connection::run() {
    address = socket().address().toString();
    Poco::Logger::get("Traverse").debug("Connection from " + address);
    NetManager::addConnection(this);

    while(!disconnectScheduled) {
        // Busy waiting, is this ok?
        Poco::Thread::sleep(20);
        if(socket().available() <= 0) continue;
    }

    if(!gracefulDisconnect) {
        socket().close();
        return;
    }

    socket().close();
    // TODO: Send disconnect packet
}