#include "kernighanlingrouper.h"

#include <math.h>
#include <iostream>

#include "../students/student.h"
#include "../students/studentset.h"

using std::vector;

KernighanLinGrouper::KernighanLinGrouper()
{

}

vector<KernighanLinStudentGroup> KernighanLinGrouper::initialiseGroups(StudentSet studentSet, int numGroups)
{
    vector<KernighanLinStudentGroup> groups;

    studentSet.randomize();

    int groupSize = floor(studentSet.getStudentList().size() / numGroups);
    int numGroupsWithExtraPerson = studentSet.getStudentList().size() % numGroups;

    int groupCounter = 0;
    int studentCounter = 0;
    KernighanLinStudentGroup tempGroup;
    for (auto& student : studentSet.getStudentList())
    {
        KernighanLinStudent kStudent;
        kStudent.student = student;
        tempGroup.studentGroup.push_back(kStudent);

        if ((groupCounter < numGroupsWithExtraPerson && studentCounter == groupSize)
                || (groupCounter >= numGroupsWithExtraPerson && studentCounter == groupSize - 1))
        {
            groups.push_back(tempGroup);
            tempGroup.groupNumber++;
            tempGroup.studentGroup.clear();

            groupCounter++;
            studentCounter = 0;
        }
        else
        {
            studentCounter++;
        }
    }

    return groups;
}

void KernighanLinGrouper::calculateCosts()
{
    for (auto& group : groups)
    {
        for (auto& student : group.studentGroup)
        {
            student.InternalCost = calculateInternalCost(student, group);

            // Calculate external costs for all other groups
            student.ExternalCost.clear();
            std::for_each(
                groups.begin(),
                groups.end(),
                [this, &student](KernighanLinStudentGroup& group){
                    student.ExternalCost.push_back(calculateExternalCost(student, group));
                }
            );
        }
    }
}

int KernighanLinGrouper::calculateInternalCost(const KernighanLinStudent& student,
                                                 const KernighanLinStudentGroup& group)
{
    // Calculate internal costs
    int internalCost = 0;
    for (auto& internalStudent : group.studentGroup)
    {
        if (student.student.getStudentId() != internalStudent.student.getStudentId())
        {
            if (student.student.isStudentInPreference(internalStudent.student))
            {
                internalCost++;
            }
        }
    }

    return internalCost;
}

std::pair<int, int> KernighanLinGrouper::calculateExternalCost(const KernighanLinStudent& student,
                                                                 const KernighanLinStudentGroup& group)
{
    std::pair<int, int> groupCost;
    groupCost.first = group.groupNumber;

    int externalcost = 0;
    for (auto& student2 : group.studentGroup)
    {
        if (student.student.isStudentInPreference(student2.student))
        {
            externalcost++;
        }
    }

    groupCost.second = externalcost;

    return groupCost;
}

void KernighanLinGrouper::swapHighestCostStudents()
{
    // Get current student that should be swapped based on its internal and external cost
    std::pair<KernighanLinStudent, int> studentResult = getStudentWithHighestCost();
    KernighanLinStudent firstSwappedStudent = studentResult.first;
    int firstSwappedStudentGroup = studentResult.second;

    // Get group that firstSwappedStudent should be swapped into
    int swapGroupNum = 0;
    int swapGroupCost = -1000;
    for (auto& costPair : firstSwappedStudent.ExternalCost)
    {
        if (costPair.second > swapGroupCost)
        {
            swapGroupNum = costPair.first;
            swapGroupCost = costPair.second;
        }
    }

    // Get group that with group number swapGroupNum
    auto secondSwapGroup = std::find_if(
        groups.begin(),
        groups.end(),
        [swapGroupNum](KernighanLinStudentGroup& element) {
            return element.groupNumber == swapGroupNum;
        }
    );

    // Find best student in secondSwapGroup to swap with firstSwappedStudent
    int secondSwapCost = -1000;
    KernighanLinStudent secondSwappedStudent;
    int secondSwappedStudentGroup = 0;
    for (auto& student : secondSwapGroup->studentGroup)
    {
        // Get external cost of first student group
        auto externalCostPair = std::find_if(
            student.ExternalCost.begin(),
            student.ExternalCost.end(),
            [firstSwappedStudentGroup](const std::pair<int, int>& element) {
                return element.first == firstSwappedStudentGroup;
            }
        );

        int cost = 0;
        cost = externalCostPair->second - student.InternalCost;

        if (cost > secondSwapCost)
        {
            secondSwapCost = cost;
            secondSwappedStudent = student;
            secondSwappedStudentGroup = secondSwapGroup->groupNumber;
        }
    }

    // Swap students
    swapStudents(firstSwappedStudent, firstSwappedStudentGroup,
                 secondSwappedStudent, secondSwappedStudentGroup);
}

std::pair<KernighanLinStudent, int> KernighanLinGrouper::getStudentWithHighestCost()
{
    KernighanLinStudent highestCostStudent;
    int highestCostStudentGroup = 0;
    int currHighestStudentCost = -1000;
    for (auto& group : groups)
    {
        for (auto& student : group.studentGroup)
        {
            int cost = 0;
            std::for_each(student.ExternalCost.begin(), student.ExternalCost.end(),
                          [&cost](std::pair<int, int> externalCost) {cost += externalCost.second;}
            );

            cost -= student.InternalCost;

            if (cost > currHighestStudentCost)
            {
                currHighestStudentCost = cost;
                highestCostStudent = student;
                highestCostStudentGroup = group.groupNumber;
            }
        }
    }

    return std::pair<KernighanLinStudent, int>(highestCostStudent, highestCostStudentGroup);
}

void KernighanLinGrouper::swapStudents(const KernighanLinStudent& student1, int student1Group,
                                         const KernighanLinStudent& student2, int student2Group)
{
    // Swap students
    for (auto& group : groups)
    {
        int firstStudentId = student1.student.getStudentId();
        if (group.groupNumber == student1Group)
        {
            group.studentGroup.erase(std::remove_if(
                group.studentGroup.begin(),
                group.studentGroup.end(),
                [&firstStudentId](KernighanLinStudent value) {
                    return value.student.getStudentId() == firstStudentId;
                }
            ), group.studentGroup.end());

            group.studentGroup.push_back(student2);
        }

        int secondStudentId = student2.student.getStudentId();
        if (group.groupNumber == student2Group)
        {
            group.studentGroup.erase(std::remove_if(
                group.studentGroup.begin(),
                group.studentGroup.end(),
                [&secondStudentId](KernighanLinStudent value) {
                    return value.student.getStudentId() == secondStudentId;
                }
            ), group.studentGroup.end());

            group.studentGroup.push_back(student1);
        }
    }
}

std::unique_ptr<GroupedStudents> KernighanLinGrouper::createGroupedStudentsOutput()
{
    auto groupedStudents = std::unique_ptr<GroupedStudents>(new GroupedStudents());

    for (auto& group : groups)
    {
        StudentSet studentSet;
        for (auto& student : group.studentGroup)
        {
            studentSet.addStudent(student.student);
        }

        groupedStudents->addGroup(studentSet);
    }

    return groupedStudents;
}


std::unique_ptr<GroupedStudents> KernighanLinGrouper::groupStudents(StudentSet& studentSet, int numGroups)
{
    this->groups = initialiseGroups(studentSet, numGroups);

    for (int i = 0; i < std::floor(studentSet.getStudentList().size() / 2); ++i)
    {
        calculateCosts();
        swapHighestCostStudents();
    }

    return createGroupedStudentsOutput();
}
