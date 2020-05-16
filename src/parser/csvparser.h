#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "../students/studentset.h"
#include "../students/student.h"

#include <string>
#include <vector>
#include <memory>

class CsvParser
{
public:
    CsvParser();

    StudentSet parseFile(std::string filePath);

private:
    void addStudents(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet);
    void addStudentPreferences(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet);

    Student getStudentFromCsvFile(std::string line);
};

#endif // CSVPARSER_H
