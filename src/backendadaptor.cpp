#include "backendadaptor.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>

BackendAdaptor::BackendAdaptor()
{

}

void BackendAdaptor::setConfigFileAndParse(std::string configFile) {
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

bool BackendAdaptor::hasValidInputFile() {
    return !this->studentSet.isEmpty();
}

void BackendAdaptor::writeOutputToFile(std::string filePath, GroupedStudents groupedStudents) {
    if (groupedStudents.isEmpty()) {
        throw "No output to generate";
    }

    std::string outputLines = "";
    int groupId = 1;
    for (auto studentClass : groupedStudents.getGroupedStudents()) {
        for (Student s : studentClass) {
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

    return studentString;
}

StudentSet BackendAdaptor::getStudentSet() {
    return studentSet;
}
