#include "studentset.h"

#include <algorithm>

StudentSet::StudentSet()
{

}

bool StudentSet::isEmpty() {
    return students.size() == 0;
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

std::vector<Student> StudentSet::randomize() {
    std::random_shuffle(students.begin(), students.end());
    return this->students;
}
