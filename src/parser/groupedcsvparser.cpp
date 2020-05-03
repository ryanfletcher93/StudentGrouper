#include "groupedcsvparser.h"

#include<iostream>
#include <fstream>
#include <sstream>
#include<map>

GroupedCsvParser::GroupedCsvParser()
{

}

GroupedCsvParser::GroupedCsvParser(std::string filePath)  :
    filePath(filePath)
{
}

void GroupedCsvParser::setFilePath(std::string filePath) {
    this->filePath = filePath;
}

GroupedStudents GroupedCsvParser::parseGroupedFile() {
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

        groupStudents(csvContents);
    }
    else {
        std::cout << "Could not open file" << std::endl;
        std::cout << filePath << std::endl;
    }

    return this->groupedStudents;
}


void GroupedCsvParser::groupStudents(std::vector<std::string> csvContents) {
    std::map<int, StudentSet> m;
    for (std::string line : csvContents) {
        std::stringstream ss(line);
        std::string token;

        std::vector<std::string> tokenisedLine;
        while (std::getline(ss, token, ',')) {
            tokenisedLine.push_back(token);
        }

        if (tokenisedLine.size() != 11) {
            throw "Invalid tokenised csv line length";
        }

        std::vector<std::string> prefs;
        std::string groupStr = tokenisedLine[0];
        std::string idStr = tokenisedLine[1];
        std::string firstName = tokenisedLine[2];
        std::string middleName = tokenisedLine[3];
        std::string familyName = tokenisedLine[4];
        prefs.push_back(tokenisedLine[5]);
        prefs.push_back(tokenisedLine[6]);
        prefs.push_back(tokenisedLine[7]);
        prefs.push_back(tokenisedLine[8]);
        prefs.push_back(tokenisedLine[9]);
        prefs.push_back(tokenisedLine[10]);

        int group = std::stoi(groupStr);
        int id = std::stoi(idStr);

        Student s(firstName, middleName, familyName, id);
        std::vector<Student> studentPrefs;
        for (std::string pref : prefs) {
            studentPrefs.push_back(getStudentFromGroupedCsvLine(csvContents, pref));
        }
        StudentPreference *sP = new StudentPreference(studentPrefs);
        s.setStudentPreference(sP);

        m[group].addStudent(s);
    }

    for (auto mapIt = m.begin(); mapIt != m.end(); mapIt++) {
        this->groupedStudents.addGroup(mapIt->second);
    }
}

Student GroupedCsvParser::getStudentFromGroupedCsvLine(std::vector<std::string> csvContents, std::string idParam) {
    for (std::string line : csvContents) {
        std::stringstream ss(line);
        std::string token;

        std::vector<std::string> tokenisedLine;
        while (std::getline(ss, token, ',')) {
            tokenisedLine.push_back(token);
        }

        if (tokenisedLine.size() != 11) {
            throw "Invalid tokenised csv line length";
        }

        std::vector<std::string> prefs;
        std::string groupStr = tokenisedLine[0];
        std::string idStr = tokenisedLine[1];
        std::string firstName = tokenisedLine[2];
        std::string middleName = tokenisedLine[3];
        std::string familyName = tokenisedLine[4];

        int id = std::stoi(idStr);

        if (idStr == idParam) {
            return Student(firstName, middleName, familyName, id);
        }
    }
}
