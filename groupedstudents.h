#ifndef GROUPEDSTUDENTS_H
#define GROUPEDSTUDENTS_H

#include "student.h"

#include <vector>

class GroupedStudents
{
public:
    GroupedStudents();
    GroupedStudents(std::vector<std::vector<Student>> groupedStudents) :
        groupedStudents(groupedStudents) {}

private:
    std::vector<std::vector<Student>> groupedStudents;
};

#endif // GROUPEDSTUDENTS_H
