#ifndef BACKENDADAPTOR_H
#define BACKENDADAPTOR_H

#include "csvparser.h"
#include "groupedcsvparser.h"

#include <string>

/**
 * @brief The BackendAdaptor class
 * Provides interface between the MainWindow GUI and the backend logic
 * TODO: Reorder logic to only have interface, no backend logic in this class
 */
class BackendAdaptor
{
public:
    BackendAdaptor();

    /**
     * @brief parseConfigFile
     * Use CsvParser to parse the config file and populate the
     * StudentSet object
     *
     * @param configFile
     */
    void parseConfigFile(std::string configFile);


    /**
     * @brief parseGroupedConfigFile
     * Use GroupedCsvParser to parse the grouped config file and
     * return the grouped students object
     *
     * @param configFile
     * @return
     */
    GroupedStudents parseGroupedConfigFile(std::string configFile);


    /**
     * @brief hasValidUngroupedInputFile
     * Returns true if an ungrouped config file has successfully loaded
     *
     * @return
     */
    bool hasValidUngroupedInputFile();


    /**
     * @brief writeOutputToFile
     * Write the grouped student output to a csv file
     *
     * @param filePath
     * @param groupedStudents
     */
    void writeOutputToFile(std::string filePath, GroupedStudents groupedStudents);


    /**
     * @brief getStudentSet
     * TODO: Remove this and abstract the grouping by using a BasicGrouper
     *
     * @return
     */
    StudentSet getStudentSet();

private:
    std::string createCsvLineFromStudent(Student s);

    CsvParser csvParser;
    GroupedCsvParser groupedCsvParser;
    StudentSet studentSet;
    GroupedStudents groupedStudents;
};

#endif // BACKENDADAPTOR_H
