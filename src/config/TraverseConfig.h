#pragma once

#include "Config.h"

#include "../Types.h"

#include <Poco/Logger.h>
#include <string>

#include <Poco/JSON/Object.h>
#include <Poco/JSONString.h>

namespace Traverse {
    class TraverseConfig : public Config {
        public:
            static Object defaultConfig;

            TraverseConfig() : Config("settings.json") {
                if(defaultConfigSetup) return;
                // Create default configuration
                defaultConfig.set("log-level", "INFORMATION");
                defaultConfig.set("port", 25565);
                defaultConfig.set("max-connected", 200);
                defaultConfig.set("network", Object().set("max-threads", 6));
                defaultConfig.set("authentication", Object().set("online-mode", true).set("session-server", "https://sessionserver.mojang.com"));
                defaultConfigSetup = true;
            }

            void load() override;

            std::string getLogLevel() const {
                return getValue<std::string>("log-level");
            }

            u16 getPort() const {
                return getValue<u16>("port");
            }

            u32 getMaxConnected() const {
                return getValue<u32>("max-connected");
            }

            u32 getMaxNetworkThreads() const {
                return getObject("network")->getValue<u32>("max-threads");
            }

            bool isOnlineMode() const {
                return getObject("authentication")->getValue<bool>("online-mode");
            }

            std::string getSessionServer() const {
                return getObject("authentication")->getValue<std::string>("session-server");
            }

        private:
            static bool defaultConfigSetup;
    };
    inline Object TraverseConfig::defaultConfig = Object(JSON_PRESERVE_KEY_ORDER);
    inline bool TraverseConfig::defaultConfigSetup = false;
    //inline const std::string TraverseConfig::defaultConfig = "{ \n \"port\": 25565,\n \"max-connected\": 200,\n \"authentication\": { \n \"online-mode\": true, \n \"session-server\": \"https://sessionserver.mojang.com\" \n } \n }";
}