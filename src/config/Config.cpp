#include "Config.h"

#include <Poco/FileStream.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>

using namespace Traverse;

void Config::load() {
    if(!configFile.exists()) throw new Exception::ConfigLoadException("Config file not found!");

    Parser parser;
    FileInputStream in(configFile.path());
    
    jsonObject = *parser.parse(in).extract<Object::Ptr>();
}

Dynamic::Var Config::get(const std::string& key) const {
    return jsonObject.get(key);
}

Array::Ptr Config::getArray(const std::string& key) const {
    return jsonObject.getArray(key);
}

Object::Ptr Config::getObject(const std::string& key) const {
    return jsonObject.getObject(key);
}