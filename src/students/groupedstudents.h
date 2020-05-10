#ifndef GROUPEDSTUDENTS_H
#define GROUPEDSTUDENTS_H

#include "student.h"
#include "studentset.h"

#include <list>
#include <vector>

/**
 * @brief The GroupedStudents class
 * The GroupedStudents class is responsible for taking in students
 * and forming them into groups. The remainder groups is the students
 * that would not fit evenly into the groupa and is allocated at the end
 */
class GroupedStudents
{
public:
    GroupedStudents();
    GroupedStudents(StudentSet studentSet);

    /**
     * @brief isEmpty
     * Returns whether there are no groups
     *
     * @return
     */
    bool isEmpty();

    int calculateHappinessScore();

    /**
     * @brief addGroup
     * Add a student group to groupedStudents
     *
     * @param studentList
     */
    void addGroup(StudentSet studentSet) {
        groupedStudents.push_back(studentSet);
    }

    std::vector<StudentSet> getGroups() {
        return groupedStudents;
    }

private:
    std::vector<StudentSet> groupedStudents;
};

#endif // GROUPEDSTUDENTS_H
