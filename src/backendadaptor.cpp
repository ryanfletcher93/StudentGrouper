#include "backendadaptor.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>

BackendAdaptor::BackendAdaptor()
{

}

void BackendAdaptor::parseConfigFile(std::string configFile) {
    csvParser.setFilePath(configFile);

    try {
        this->studentSet = csvParser.parseFile();
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }
}

GroupedStudents BackendAdaptor::parseGroupedConfigFile(std::string configFile) {
    groupedCsvParser.setFilePath(configFile);

    try {
        this->groupedStudents = groupedCsvParser.parseGroupedFile();
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }

    return this->groupedStudents;
}

bool BackendAdaptor::hasValidUngroupedInputFile() {
    return !this->studentSet.isEmpty();
}

void BackendAdaptor::writeOutputToFile(std::string filePath, GroupedStudents groupedStudents) {
    if (groupedStudents.isEmpty()) {
        throw "No output to generate";
    }

    std::string outputLines = "";
    int groupId = 1;
    for (auto groupIt = groupedStudents.begin(); groupIt != groupedStudents.end(); groupIt++) {
        for (Student s : *groupIt) {
            outputLines += std::to_string(groupId) + "," + createCsvLineFromStudent(s) + "\n";
        }
        groupId++;
    }

    std::ofstream fout;
    fout.open(filePath);
    fout << outputLines;
    fout.close();
}

std::string BackendAdaptor::createCsvLineFromStudent(Student s) {
    std::string studentString = "";

    studentString += std::to_string(s.getStudentId()) + "," + s.getFirstName() +
            "," + s.getMiddleName() + "," + s.getFamilyName();

    for (int preferenceId : s.getStudentPreference().getPreferencesIds()) {
        studentString += "," + std::to_string(preferenceId);
    }

    return studentString;
}

StudentSet BackendAdaptor::getStudentSet() {
    return studentSet;
}
