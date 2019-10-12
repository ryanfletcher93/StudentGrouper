#ifndef BACKENDADAPTOR_H
#define BACKENDADAPTOR_H

#include "csvparser.h"

#include <string>

class BackendAdaptor
{
public:
    BackendAdaptor();

    void setConfigFileAndParse(std::string configFile);

private:
    CsvParser csvParser;
    StudentSet studentSet;
};

#endif // BACKENDADAPTOR_H
