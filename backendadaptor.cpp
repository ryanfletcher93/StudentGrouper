#include "backendadaptor.h"

BackendAdaptor::BackendAdaptor()
{

}

void BackendAdaptor::setConfigFileAndParse(std::string configFile) {
    csvParser.setFilePath(configFile);

    this->studentSet = csvParser.parseFile();
}
