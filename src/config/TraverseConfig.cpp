#include "TraverseConfig.h"

#include <Poco/FileStream.h>
#include <Poco/JSON/Object.h>

using namespace Traverse;

void TraverseConfig::load() {
    if(!l_configFile.exists()) {
        l_configFile.createFile();

        FileOutputStream out(l_configFile.path());

        defaultConfig.stringify(out, 4);

        out.close();
    }

    Config::load();
}