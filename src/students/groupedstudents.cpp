#include "groupedstudents.h"

GroupedStudents::GroupedStudents()
{

}

GroupedStudents::GroupedStudents(StudentSet studentSet)
{
    this->groupedStudents.push_back(studentSet);
}

bool GroupedStudents::isEmpty()
{
    return this->groupedStudents.size() == 0;
}

int GroupedStudents::calculateHappinessScore()
{
    int total = 0;

    for (auto studentSet : groupedStudents) {
        total += studentSet.getHappinessScore();
    }

    return total;
}
