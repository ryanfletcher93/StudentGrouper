#include "groupedstudents.h"

GroupedStudents::GroupedStudents()
{

}

GroupedStudents::GroupedStudents(StudentSet studentSet) {
    for (auto s : studentSet.getStudentList()) {
        this->groupedStudents.push_front(std::list<Student> {s});
    }
}

std::list<std::list<Student>> GroupedStudents::getGroupedStudents() {
    return this->groupedStudents;
}
