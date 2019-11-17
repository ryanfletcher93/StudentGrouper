#ifndef GROUPEDSTUDENTS_H
#define GROUPEDSTUDENTS_H

#include "student.h"
#include "studentgroup.h"
#include "studentset.h"

#include <list>
#include <vector>

class StudentSet;

/**
 * @brief The GroupedStudents class
 * The GroupedStudents class is responsible for taking in students
 * and forming them into groups. The remainder groups is the students
 * that would not fit evenly into the groupa and is allocated at the end
 */
class GroupedStudents
{
public:
    /// Define iterators for the groups
    typedef std::list<StudentGroup>::iterator iterator;

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

    // Setup group iterators
    iterator begin() {
        return groupedStudents.begin();
    }
    iterator end() {
        return groupedStudents.end();
    }

    /**
     * @brief getRemainder
     * Get the remainder students as a list
     *
     * @return
     */
    StudentGroup getRemainder() {
        return remainderStudents;
    }

    /**
     * @brief size
     * Return the number of groups
     *
     * @return
     */
    size_t size() {
        return groupedStudents.size();
    }

    /**
     * @brief erase
     * Erase the student group at @param it
     *
     * @param it
     */
    void erase(iterator it) {
        groupedStudents.erase(it);
    }

    /**
     * @brief addGroup
     * Add a student group to groupedStudents
     *
     * @param studentList
     */
    void addGroup(StudentGroup studentList) {
        groupedStudents.push_back(studentList);
    }

    /// Setup remainder iterators
    StudentGroup::iterator beginRemainder() {
        return remainderStudents.begin();
    }
    StudentGroup::iterator endRemainder() {
        return remainderStudents.end();
    }

    /**
     * @brief sizeRemainder
     *
     *
     * @return
     */
    size_t sizeRemainder() {
        return remainderStudents.size();
    }

    void eraseRemainder(StudentGroup::iterator remainderIt) {
        remainderStudents.erase(remainderIt);
    }

    /**
     * @brief eraseAllRemainders
     * Remove all remaining iterators
     */
    void eraseAllRemainders() {
        remainderStudents.eraseAll();
    }

    /**
     * @brief addToRemainder
     * Add a student to the remainders
     *
     * @param studentList
     */
    void addToRemainder(StudentGroup studentList) {
        for (auto s : studentList) {
            remainderStudents.addStudent(s);
        }
    }

private:
    std::list<StudentGroup> groupedStudents;
    StudentGroup remainderStudents;
};

#endif // GROUPEDSTUDENTS_H
