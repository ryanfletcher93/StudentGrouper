#include "kernighanlinalgorithm.h"

#include "../students/student.h"
#include "../students/studentset.h"

/*

using std::vector;

vector<KernighanLinStudentGroup> KernighanLinAlgorithm::initialiseGroups(StudentSet studentSet, int numGroups)
{
    vector<KernighanLinStudentGroup> groups;
    for (int i = 0; i < numGroups; i++)
    {
        KernighanLinStudentGroup tempGroup;
        groups.push_back(tempGroup);
    }

    return groups;
}

void KernighanLinAlgorithm::calculateCosts()
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
                    studentGroup.first = group.groupNumber;

                    int externalcost = 0;
                    for (auto& student2 : group.studentGroup)
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

void KernighanLinAlgorithm::swapHighestCostStudents()
{

}

GroupedStudents KernighanLinAlgorithm::createGroupedStudentsOutput()
{
    GroupedStudents groupedStudents;

    for (auto& group : groups)
    {
        StudentSet studentSet;
        for (auto& student : group.studentGroup)
        {
            studentSet.addStudent(student.student);
        }

        groupedStudents.addGroup(studentSet);
    }

    return groupedStudents;
}


GroupedStudents KernighanLinAlgorithm::groupStudents(StudentSet studentSet, int numGroups)
{
    this->groups = initialiseGroups(studentSet, numGroups);

    calculateCosts();

    swapHighestCostStudents();

    return createGroupedStudentsOutput();
}

*/
