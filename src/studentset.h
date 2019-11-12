#ifndef STUDENTSET_H
#define STUDENTSET_H

#include "groupedstudents.h"
#include "student.h"

#include <vector>

class StudentSet
{
public:
    StudentSet();

    bool isEmpty();

    void addStudent(Student s);

    std::pair<bool, Student&> getStudentById(int id);

    std::vector<Student> getStudentList() {
        return students;
    }

    std::vector<Student> randomize();

    //GroupedStudents createOptimalDistribution();

private:
    std::vector<Student> students;
};

#endif // STUDENTSET_H
