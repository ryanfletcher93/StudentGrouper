#include "algorithmbackend.h"

#include "../algorithm/kernighanlingrouper.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>

AlgorithmBackend::AlgorithmBackend()
{

}


bool AlgorithmBackend::parseConfigFile(std::string configFile)
{
    bool isLoadSuccessful = false;

    try {
        this->studentSet = csvParser.parseFile(configFile);
        isLoadSuccessful = true;
    }
    catch (...) {

    }

    return isLoadSuccessful;
}


std::unique_ptr<GroupedStudents> AlgorithmBackend::parseGroupedConfigFile(std::string configFile)
{
    std::unique_ptr<GroupedStudents> groupedStudents;
    try {
        groupedStudents = groupedCsvParser.parseGroupedFile(configFile);
    }
    catch (...) {
        QMessageBox box;
        box.setText("Invalid input csv, please check and enter again");
        box.exec();
    }

    return groupedStudents;
}


bool AlgorithmBackend::hasValidUngroupedInputFile()
{
    return !this->studentSet.isEmpty();
}


std::unique_ptr<GroupedStudents> AlgorithmBackend::groupStudents(BaseGrouper *groupingAlgorithm, int numGroups)
{
    return groupingAlgorithm->groupStudents(this->studentSet, numGroups);
}


void AlgorithmBackend::writeOutputToFile(std::string filePath, GroupedStudents groupedStudents)
{
    if (groupedStudents.isEmpty()) {
        throw "No output to generate";
    }

    std::string outputLines = "";
    int groupId = 1;
    for (auto groupIt : groupedStudents.getGroups()) {
        for (auto s : groupIt.getStudentList()) {
            outputLines += std::to_string(groupId) + "," + createCsvLineFromStudent(s) + "\n";
        }
        groupId++;
    }

    std::ofstream fout;
    fout.open(filePath);
    fout << outputLines;
    fout.close();
}


std::string AlgorithmBackend::createCsvLineFromStudent(Student s)
{
    std::string studentString = "";

    studentString += std::to_string(s.getStudentId()) + "," + s.getFirstName() +
            "," + s.getMiddleName() + "," + s.getFamilyName();

    for (int preferenceId : s.getStudentPreference().getPreferencesIds()) {
        studentString += "," + std::to_string(preferenceId);
    }

    return studentString;
}


StudentSet AlgorithmBackend::getStudentSet()
{
    return studentSet;
}
