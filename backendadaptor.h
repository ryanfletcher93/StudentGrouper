#ifndef BACKENDADAPTOR_H
#define BACKENDADAPTOR_H

#include "csvparser.h"

#include <string>

class BackendAdaptor
{
public:
    BackendAdaptor();

    void setConfigFileAndParse(std::string configFile);

    void writeOutputToFile(std::string filePath, GroupedStudents groupedStudents);

    StudentSet getStudentSet();

    GroupedStudents convertStudentSetToGroupedStudents(StudentSet ss);

private:
    std::string createCsvLineFromStudent(Student s);

    CsvParser csvParser;
    StudentSet studentSet;
};

#endif // BACKENDADAPTOR_H
