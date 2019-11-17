#include "groupedstudents.h"

GroupedStudents::GroupedStudents()
{

}

GroupedStudents::GroupedStudents(StudentSet studentSet) {
    for (auto s : studentSet.getStudentList()) {
        this->groupedStudents.push_front(StudentGroup(s));
    }
}

bool GroupedStudents::isEmpty() {
    return this->groupedStudents.size() == 0;
}

int GroupedStudents::calculateHappinessScore() {
    int total = 0;

    for (auto studentGroupIt : this->groupedStudents) {
        for (auto s1 : studentGroupIt) {
            for (auto s2 : studentGroupIt) {
                if (s1.isStudentInPreference(s2)) {
                    total += 1;
                }
            }
        }
    }

    return total;
}
