#ifndef STUDENT_H
#define STUDENT_H

#include "studentpreference.h"

#include <string>

class Student
{
public:
    Student();

    Student(std::string firstName, std::string middleName, std::string familyName, int idNumber);

    void setStudentPreference(StudentPreference studentPreference) {
        this->studentPreference = studentPreference;
    }
    StudentPreference getStudentPreference() {
        return studentPreference;
    }

    int getStudentId() {
        return idNumber;
    }

private:
    std::string firstName;
    std::string middleName;
    std::string familyName;

    const int idNumber;

    StudentPreference studentPreference;
};

#endif // STUDENT_H
