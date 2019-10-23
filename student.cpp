#include "student.h"

Student::Student() : idNumber(-1)
{

}

Student::Student(std::string firstName, std::string middleName, std::string familyName, int idNumber) :
    firstName(firstName), middleName(middleName), familyName(familyName), idNumber(idNumber) {}

void Student::setStudentPreference(StudentPreference *studentPreference) {
    this->studentPreference = studentPreference;
}

StudentPreference Student::getStudentPreference() {
    return (*studentPreference);
}

bool Student::isStudentInPreference(Student s) {
    return true;
}
