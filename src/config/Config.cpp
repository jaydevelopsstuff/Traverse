#include "Config.h"

#include <Poco/FileStream.h>
#include <Poco/JSON/Parser.h>

using namespace Traverse;

void Config::load() {
    if(!l_configFile.exists()) throw new Exception::ConfigLoadException("Config file not found!");

    Parser parser;
    FileInputStream in(l_configFile.path());
    
    l_jsonObject = *parser.parse(in).extract<Object::Ptr>();
}

Dynamic::Var Config::get(const std::string& key) const {
    return l_jsonObject.get(key);
}

Array::Ptr Config::getArray(const std::string& key) const {
    return l_jsonObject.getArray(key);
}