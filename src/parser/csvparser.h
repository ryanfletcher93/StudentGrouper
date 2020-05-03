#ifndef CSVPARSER_H
#define CSVPARSER_H

#include "studentset.h"
#include "student.h"

#include <string>
#include <vector>
#include <memory>

class CsvParser
{
public:
    CsvParser();
    CsvParser(std::string filePath);

    void setFilePath(std::string filePath) {
        this->filePath = filePath;
    }

    StudentSet parseFile();

private:
    std::string filePath = "";

    void addStudents(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet);
    void addStudentPreferences(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet);

    Student getStudentFromCsvFile(std::string line);
};

#endif // CSVPARSER_H
