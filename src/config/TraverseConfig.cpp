#include "TraverseConfig.h"

#include <Poco/FileStream.h>
#include <Poco/JSON/Object.h>

using namespace Traverse;

void TraverseConfig::load() {
    if(!configFile.exists()) {
        configFile.createFile();

        FileOutputStream out(configFile.path());

        defaultConfig.stringify(out, 4);

        out.close();
    }

    Config::load();
}