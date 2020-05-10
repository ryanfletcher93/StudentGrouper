#include "imperfectmergegrouper.h"

#include <math.h>

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

    int groupCounter = 0;
    int studentCounter = 0;
    int groupSize = floor(studentSet.getStudentList().size() / numGroups);
    int studentIndex = 0;
    KernighanLinStudentGroup tempGroup;
    for (auto& student : studentSet.getStudentList())
    {
        KernighanStudent kStudent;
        kStudent.student = student;
        tempGroup.studentGroup.push_back(kStudent);
        studentIndex++;

        if (studentCounter == groupSize - 1)
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
    int firstCurrentMinCost = 1000000;
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

            if (cost < firstCurrentMinCost)
            {
                firstCurrentMinCost = cost;
                firstSwappedStudent = student;
                firstSwappedStudentGroup = group.groupNumber;
            }
        }
    }

    // Get student that can best be swapped
    int minGroupNum = 0;
    int minGroupCost = 10000000;
    for (auto& costPair : firstSwappedStudent.ExternalCost)
    {
        if (costPair.second < minGroupCost)
        {
            minGroupNum = costPair.first;
        }
    }

    int secondMinCost = 100000;
    KernighanStudent secondSwappedStudent;
    int secondSwappedStudentGroup = 0;
    for (auto& group : groups)
    {
        if (group.groupNumber == minGroupNum)
        {
            for (auto& student : group.studentGroup)
            {
                int cost = 0;
                for (size_t i = 0; i < student.ExternalCost.size(); i++)
                {
                    cost += student.ExternalCost[i].second;
                }

                cost -= student.InternalCost;

                if (cost < secondMinCost)
                {
                    secondMinCost = cost;
                    secondSwappedStudent = student;
                    secondSwappedStudentGroup = group.groupNumber;
                }
            }
        }
    }

    for (auto& group : groups)
    {
        for (auto studentIt = group.studentGroup.begin(); studentIt != group.studentGroup.end(); /*studentIt++*/)
        {
            if (studentIt->student.getStudentId() == firstSwappedStudent.student.getStudentId()
                || studentIt->student.getStudentId() == secondSwappedStudent.student.getStudentId())
            {
                studentIt = group.studentGroup.erase(studentIt);
            }
            else
            {
                ++studentIt;
            }
        }

        if (group.groupNumber == firstSwappedStudentGroup)
        {
            group.studentGroup.push_back(secondSwappedStudent);
        }

        if (group.groupNumber == secondSwappedStudentGroup)
        {
            group.studentGroup.push_back(firstSwappedStudent);
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

    calculateCosts();

    for (int i = 0; i < 100; ++i)
    {
        swapHighestCostStudents();
    }

    return createGroupedStudentsOutput();
}
