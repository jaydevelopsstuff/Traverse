#pragma once

#include "../exception/Exception.h"

#include <string>

#include <Poco/File.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Parser.h>

using namespace Poco;
using namespace Poco::JSON;

namespace Traverse {
    class Config {
        public:
            Config(std::string t_filePath) : configFile(t_filePath) {}

            virtual void load();

            Dynamic::Var get(const std::string& key) const;

	        Array::Ptr getArray(const std::string& key) const;

	        Object::Ptr getObject(const std::string& key) const;

            template<typename T>
            T getValue(const std::string& key) const {
                return jsonObject.getValue<T>(key);
            }

            File getFile() const {
                return configFile;
            }

        protected:
            File configFile;
            Object jsonObject;
    };
}