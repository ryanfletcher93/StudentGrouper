#include "imperfectmergegrouper.h"

#include <math.h>
#include <iostream>

#include "../students/student.h"
#include "../students/studentset.h"

using std::vector;

ImperfectMergeGrouper::ImperfectMergeGrouper()
{

}

vector<KernighanLinStudentGroup> ImperfectMergeGrouper::initialiseGroups(StudentSet studentSet, int numGroups)
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
        KernighanStudent kStudent;
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

void ImperfectMergeGrouper::calculateCosts()
{
    for (auto& group : groups)
    {
        for (auto& student1 : group.studentGroup)
        {
            student1.InternalCost = 0;
            student1.ExternalCost.clear();

            int a = 1;
            if (student1.student.getStudentId() == -1)
            {
                a = 2;
            }

            // Calculate internal costs
            int internalCost = 0;
            for (auto& student2 : group.studentGroup)
            {
                if (student1.student.getStudentId() != student2.student.getStudentId())
                {
                    if (student1.student.isStudentInPreference(student2.student))
                    {
                        internalCost++;
                    }
                }
            }

            student1.InternalCost = internalCost;

            // Calculate external costs for all other groups
            for (auto& group2 : groups)
            {
                if (group.groupNumber != group2.groupNumber)
                {
                    std::pair<int, int> studentGroup;
                    studentGroup.first = group2.groupNumber;

                    int externalcost = 0;
                    for (auto& student2 : group2.studentGroup)
                    {
                        if (student1.student.isStudentInPreference(student2.student))
                        {
                            externalcost++;
                        }
                    }

                    studentGroup.second = externalcost;
                    student1.ExternalCost.push_back(studentGroup);
                }
            }
        }
    }
}

void ImperfectMergeGrouper::swapHighestCostStudents()
{
    // Get current lowest cost student
    KernighanStudent firstSwappedStudent;
    int firstSwappedStudentGroup = 0;
    int firstCurrentMinCost = -1000;
    for (auto& group : groups)
    {
        for (auto& student : group.studentGroup)
        {
            int cost = 0;
            for (size_t i = 0; i < student.ExternalCost.size(); i++)
            {
                cost += student.ExternalCost[i].second;
            }

            cost -= student.InternalCost;

            if (cost > firstCurrentMinCost)
            {
                firstCurrentMinCost = cost;
                firstSwappedStudent = student;
                firstSwappedStudentGroup = group.groupNumber;
            }

            int a = 1;
            if (student.student.getStudentId() == -1)
            {
                a = 2;
            }
        }
    }

    // Get student that can best be swapped
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

    //
    int secondSwapCost = -1000;
    KernighanStudent secondSwappedStudent;
    int secondSwappedStudentGroup = 0;

    // Get group that with group number swapGroupNum
    auto secondSwapGroup = std::find_if(
        groups.begin(),
        groups.end(),
        [swapGroupNum](KernighanLinStudentGroup& element) {
            return element.groupNumber == swapGroupNum;
        }
    );

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
        //if (externalCostPair != student.ExternalCost.end())
        //{
            cost = externalCostPair->second - student.InternalCost;
        //}

        if (cost > secondSwapCost)
        {
            secondSwapCost = cost;
            secondSwappedStudent = student;
            secondSwappedStudentGroup = secondSwapGroup->groupNumber;
        }
    }

    std::cout << firstSwappedStudentGroup << ", " << firstSwappedStudent.student.getStudentId() << std::endl;
    std::cout << secondSwappedStudentGroup << ", " << secondSwappedStudent.student.getStudentId() << std::endl;

    // Swap students
    for (auto& group : groups)
    {
        int firstStudentId = firstSwappedStudent.student.getStudentId();
        if (group.groupNumber == firstSwappedStudentGroup)
        {
            group.studentGroup.erase(std::remove_if(
                group.studentGroup.begin(),
                group.studentGroup.end(),
                [&firstStudentId](KernighanStudent value) {
                    return value.student.getStudentId() == firstStudentId;
                }
            ), group.studentGroup.end());

            group.studentGroup.push_back(secondSwappedStudent);
        }

        int secondStudentId = secondSwappedStudent.student.getStudentId();
        if (group.groupNumber == secondSwappedStudentGroup)
        {
            group.studentGroup.erase(std::remove_if(
                group.studentGroup.begin(),
                group.studentGroup.end(),
                [&secondStudentId](KernighanStudent value) {
                    return value.student.getStudentId() == secondStudentId;
                }
            ), group.studentGroup.end());

            group.studentGroup.push_back(firstSwappedStudent);
        }

        for (auto student : group.studentGroup)
        {
            int b = 0;
            if (student.student.getStudentId() == -1)
            {
                b = 1;

            }
        }
    }
}

GroupedStudents* ImperfectMergeGrouper::createGroupedStudentsOutput()
{
    GroupedStudents* groupedStudents = new GroupedStudents();

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


GroupedStudents* ImperfectMergeGrouper::groupStudents(StudentSet& studentSet, int numGroups)
{
    this->groups = initialiseGroups(studentSet, numGroups);

    for (int i = 0; i < std::floor(studentSet.getStudentList().size() / 2); ++i)
    {
        calculateCosts();
        swapHighestCostStudents();
    }

    return createGroupedStudentsOutput();
}
