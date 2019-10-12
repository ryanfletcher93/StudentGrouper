#include "student.h"

Student::Student() : idNumber(-1)
{

}

Student::Student(std::string firstName, std::string middleName, std::string familyName, int idNumber) :
    firstName(firstName), middleName(middleName), familyName(familyName), idNumber(idNumber) {}
