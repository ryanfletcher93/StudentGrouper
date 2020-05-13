#include "student.h"

Student::Student() : idNumber(-1)
{

}

Student::Student(std::string firstName, std::string middleName, std::string familyName, int idNumber) :
    firstName(firstName), middleName(middleName), familyName(familyName), idNumber(idNumber) {}


void Student::setStudentPreference(StudentPreference studentPreference) {
    this->studentPreference = studentPreference;
}

StudentPreference Student::getStudentPreference() {
    return studentPreference;
}

bool Student::isStudentInPreference(Student s) {
    return this->studentPreference.isStudentInPreferences(s);
}


int Student::calculateHappiness(Student s1, Student s2) {
    int total = 0;

    if (s1.getStudentId() != s2.getStudentId()) {
        if (s1.isStudentInPreference(s2)) {
            total += 1;
        }

        if (s2.isStudentInPreference(s1)) {
            total += 1;
        }
    }

    return total;
}
