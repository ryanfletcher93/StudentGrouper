#ifndef STUDENTPREFERENCE_H
#define STUDENTPREFERENCE_H

#include "student.h"

#include <array>
#include <vector>

class Student;

class StudentPreference
{
public:
    StudentPreference();
    StudentPreference(std::vector<Student> students);

    bool isStudentInPreferences(Student s);

private:
    std::vector<Student> preferences;
};

#endif // STUDENTPREFERENCE_H
