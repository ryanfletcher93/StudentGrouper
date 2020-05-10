#ifndef ALGORITHMBACKEND_H
#define ALGORITHMBACKEND_H

#include "../parser/csvparser.h"
#include "../parser/groupedcsvparser.h"
#include "../algorithm/basegrouper.h"
#include "../algorithm/kernighanlinalgorithm.h"
#include "../students/groupedstudents.h"

#include <string>

/**
 * @brief The BackendAdaptor class
 * Provides interface between the MainWindow GUI and the backend logic
 * TODO: Reorder logic to only have interface, no backend logic in this class
 */
class AlgorithmBackend
{
public:
    AlgorithmBackend();

    /**
     * @brief parseConfigFile
     * Use CsvParser to parse the config file and populate the
     * StudentSet object
     *
     * @param configFile
     */
    bool parseConfigFile(std::string configFile);


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
      * @brief gropuStudnets
      *
      */
    GroupedStudents* groupStudents(BaseGrouper* groupingAlgorithm, int numGroups);


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

    GroupedStudents configStudents;

    CsvParser csvParser;
    GroupedCsvParser groupedCsvParser;
    StudentSet studentSet;
    GroupedStudents groupedStudents;
};

#endif // ALGORITHMBACKEND_H
