#ifndef STUDENT_H
#define STUDENT_H

#include "studentpreference.h"

#include <string>

class StudentPreference;

class Student
{
public:
    Student();

    Student(std::string firstName, std::string middleName, std::string familyName, int idNumber);

    bool isStudentInPreference(Student s);

    static int calculateHappiness(Student s1, Student s2);

    void setStudentPreference(StudentPreference *studentPreference);
    StudentPreference getStudentPreference();

    int getStudentId() {
        return idNumber;
    }
    std::string getFirstName() {
        return firstName;
    }
    std::string getMiddleName() {
        return middleName;
    }
    std::string getFamilyName() {
        return familyName;
    }

private:
    std::string firstName;
    std::string middleName;
    std::string familyName;

    int idNumber;

    StudentPreference *studentPreference;
};

#endif // STUDENT_H
