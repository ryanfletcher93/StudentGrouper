#ifndef GROUPEDSTUDENTS_H
#define GROUPEDSTUDENTS_H

#include "student.h"
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
    typedef std::list<std::list<Student>>::iterator iterator;
    typedef std::list<std::list<Student>>::const_iterator const_iterator;

    /// Define iterators for the remainder groups
    typedef std::list<Student>::iterator remainderIterator;
    typedef std::list<Student>::const_iterator const_remainderIterator;

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
    void addGroup(std::list<Student> studentList) {
        groupedStudents.push_back(studentList);
    }

    /// Setup remainder iterators
    remainderIterator beginRemainder() {
        return remainderStudents.begin();
    }
    remainderIterator endRemainder() {
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

    void eraseRemainder(remainderIterator remainderIt) {
        remainderStudents.erase(remainderIt);
    }

    /**
     * @brief eraseAllRemainders
     * Remove all remaining iterators
     */
    void eraseAllRemainders() {
        remainderStudents.clear();
    }

    /**
     * @brief addToRemainder
     * Add a student to the remainders
     *
     * @param studentList
     */
    void addToRemainder(std::list<Student> studentList) {
        for (auto s : studentList) {
            remainderStudents.push_back(s);
        }
    }

private:
    std::list<std::list<Student>> groupedStudents;
    std::list<Student> remainderStudents;
};

#endif // GROUPEDSTUDENTS_H
