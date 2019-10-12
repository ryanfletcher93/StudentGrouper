#include "studentset.h"

StudentSet::StudentSet()
{

}

void StudentSet::addStudent(Student s) {
    this->students.push_back(s);
}

std::pair<bool, Student&> StudentSet::getStudentById(int id) {
    Student returnStudent;
    std::pair<bool, Student&> defaultReturn(false, returnStudent);
    for (Student& s : this->students) {
        if (s.getStudentId() == id) {
            std::pair<bool, Student&> foundRes(true, s);
            return foundRes;
        }
    }

    return defaultReturn;
}
