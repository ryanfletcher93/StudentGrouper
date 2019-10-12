#include "csvparser.h"

#include <iostream>
#include <fstream>
#include <sstream>

CsvParser::CsvParser()
{

}

CsvParser::CsvParser(std::string filePath) : filePath(filePath) {

}

StudentSet CsvParser::parseFile() {
    std::unique_ptr<StudentSet> studentSet(new StudentSet());

    std::vector<std::string> csvContents;

    std::filebuf fb;
    if (fb.open(filePath, std::ios::in)) {
        std::istream is(&fb);

        std::string line;
        while (!is.eof()) {
            std::getline(is, line);
            if (line == "") {
                break;
            }
            else if (is.bad() || is.fail()) {
                std::cout << "Could not open file" << std::endl;
                std::cout << filePath << std::endl;
                break;
            }

            csvContents.push_back(line);
        }

        fb.close();

        addStudents(csvContents, studentSet);
        addStudentPreferences(csvContents, studentSet);
    }
    else {
        std::cout << "Could not open file" << std::endl;
        std::cout << filePath << std::endl;
    }

    StudentSet s = *studentSet;
    return s;
}

void CsvParser::addStudents(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet) {
    for (std::string line : csvContents) {
        Student s = this->getStudentFromCsvFile(line);
        studentSet->addStudent(s);
    }
}

void CsvParser::addStudentPreferences(std::vector<std::string> csvContents, std::unique_ptr<StudentSet>& studentSet) {
    Student currStudent;
    StudentPreference studentPreference;
    for (std::string line : csvContents) {
        //TODO: Get specify student preference here

        std::pair<bool, Student&> currStudent = studentSet->getStudentById(1);
        if (currStudent.first) {
            currStudent.second.setStudentPreference(studentPreference);
        }
        else {
            throw "Could not find student";
        }
    }
}

Student CsvParser::getStudentFromCsvFile(std::string line) {
    std::stringstream ss(line);
    std::string token;

    std::vector<std::string> tokenisedLine;
    while (std::getline(ss, token, ',')) {
        tokenisedLine.push_back(token);
    }

    if (tokenisedLine.size() != 4) {
        throw "Invalid tokenised csv line length";
    }

    std::string givenName, middleName, familyName, idStr;
    givenName = tokenisedLine[0];
    middleName = tokenisedLine[1];
    familyName = tokenisedLine[2];
    idStr = tokenisedLine[3];

    int id = std::stoi(idStr);

    Student s(givenName, middleName, familyName, id);

    return s;
}
