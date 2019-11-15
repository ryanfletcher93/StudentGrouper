#include "groupedstudents.h"

GroupedStudents::GroupedStudents()
{

}

GroupedStudents::GroupedStudents(StudentSet studentSet) {
    for (auto s : studentSet.getStudentList()) {
        this->groupedStudents.push_front(std::list<Student> {s});
    }
}

bool GroupedStudents::isEmpty() {
    return this->groupedStudents.size() == 0;
}

int GroupedStudents::calculateHappinessScore() {
    int total = 0;

    for (auto studentGroupIt : this->groupedStudents) {
        for (auto s1 : (studentGroupIt)) {
            for (auto s2 : studentGroupIt) {
                total += Student::calculateHappiness(s1, s2);
            }
        }
    }

    return total;
}
