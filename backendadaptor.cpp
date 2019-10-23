#include "backendadaptor.h"

#include <iostream>
#include <fstream>

BackendAdaptor::BackendAdaptor()
{

}

void BackendAdaptor::setConfigFileAndParse(std::string configFile) {
    csvParser.setFilePath(configFile);

    this->studentSet = csvParser.parseFile();
}

void BackendAdaptor::writeOutputToFile(std::string filePath, GroupedStudents groupedStudents) {
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

GroupedStudents BackendAdaptor::convertStudentSetToGroupedStudents(StudentSet ss) {
    std::vector<Student> students = ss.getStudentList();

    GroupedStudents gs;
    for (auto s : students) {
        gs.addGroup(std::list<Student> { s });
    }

    return gs;
}
