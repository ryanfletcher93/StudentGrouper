#ifndef GROUPEDCSVPARSER_H
#define GROUPEDCSVPARSER_H

#include "../students/groupedstudents.h"

/**
 * @brief The GroupedCsvParser class
 */
class GroupedCsvParser
{
public:
    GroupedCsvParser();
    GroupedCsvParser(std::string filePath);

    void setFilePath(std::string filePath);

    GroupedStudents parseGroupedFile();

private:
    std::string filePath;
    GroupedStudents groupedStudents;

    void groupStudents(std::vector<std::string> csvContents);

    Student getStudentFromGroupedCsvLine(std::vector<std::string> csvContents, std::string id);
};

#endif // GROUPEDCSVPARSER_H
