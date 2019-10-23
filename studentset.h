#ifndef STUDENTSET_H
#define STUDENTSET_H

#include "groupedstudents.h"
#include "student.h"

#include <vector>

class StudentSet
{
public:
    StudentSet();

    void addStudent(Student s);

    std::pair<bool, Student&> getStudentById(int id);

    std::vector<Student> getStudentList() {
        return students;
    }

    //GroupedStudents createOptimalDistribution();

private:
    std::vector<Student> students;
};

#endif // STUDENTSET_H
