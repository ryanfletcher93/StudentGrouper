#ifndef GROUPEDCSVPARSER_H
#define GROUPEDCSVPARSER_H

#include "../students/groupedstudents.h"

#include <memory>

/**
 * @brief The GroupedCsvParser class
 */
class GroupedCsvParser
{
public:
    GroupedCsvParser();

    std::unique_ptr<GroupedStudents> parseGroupedFile(std::string filePath);

private:
    std::unique_ptr<GroupedStudents> groupStudents(std::vector<std::string> csvContents);

    Student getStudentFromGroupedCsvLine(std::vector<std::string> csvContents, std::string id);
};

#endif // GROUPEDCSVPARSER_H
