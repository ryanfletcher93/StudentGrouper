#include "csvparser.h"

#include <iostream>
#include <fstream>
#include <sstream>

CsvParser::CsvParser()
{

}

StudentSet CsvParser::parseFile(std::string filePath) {
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
    for (std::string line : csvContents) {
        std::stringstream ss(line);
        std::string token;

        std::vector<std::string> tokenisedLine;
        while (std::getline(ss, token, ',')) {
            tokenisedLine.push_back(token);
        }

        if (tokenisedLine.size() != 10) {
            throw "Invalid tokenised csv line length";
        }

        int currStudentId = std::stoi(tokenisedLine.at(0));

        std::pair<bool, Student&> currStudentPair = studentSet->getStudentById(currStudentId);
        Student &student = currStudentPair.second;
        if (!currStudentPair.first) {
            std::string message = "Could not find student with id " + std::to_string(currStudentId);
            throw message;
        }

        std::vector<Student> preferredStudents;
        for (int i=4; i<10; i++) {
            std::string studentId = tokenisedLine.at(i);
            int id = std::stoi(studentId);
            auto currStudentPreferencePair = studentSet->getStudentById(id);

            if (!currStudentPreferencePair.first) {
                std::string message = "Could not find student with id " + std::to_string(id);
                throw message;
            }

            preferredStudents.push_back(currStudentPreferencePair.second);
        }

        StudentPreference studentPreference(preferredStudents);
        student.setStudentPreference(studentPreference);
    }
}

Student CsvParser::getStudentFromCsvFile(std::string line) {
    std::stringstream ss(line);
    std::string token;

    std::vector<std::string> tokenisedLine;
    while (std::getline(ss, token, ',')) {
        tokenisedLine.push_back(token);
    }

    if (tokenisedLine.size() != 10) {
        throw "Invalid tokenised csv line length";
    }

    std::string givenName, middleName, familyName, idStr;
    idStr = tokenisedLine[0];
    givenName = tokenisedLine[1];
    middleName = tokenisedLine[2];
    familyName = tokenisedLine[3];

    int id = std::stoi(idStr);

    Student s(givenName, middleName, familyName, id);

    return s;
}
