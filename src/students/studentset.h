#ifndef STUDENTSET_H
#define STUDENTSET_H

#include "student.h"

#include <algorithm>

#include <vector>

/**
 * @brief The StudentSet class
 *
 */
class StudentSet
{
public:
    // Constructor for student set
    StudentSet();

    /**
     * @brief isEmpty
     * Returns whether there are any students in this set
     *
     * @return
     */
    bool isEmpty();

    /**
     * @brief addStudent
     *
     *
     * @param s
     */
    void addStudent(Student s);

    /**
     * @brief getStudentById
     * Add student to StudentSet
     *
     * @param id
     * @return
     */
    std::pair<bool, Student&> getStudentById(int id);

    /**
     * @brief getStudentList
     * Gets the student based on its id
     *
     * @return
     */
    std::vector<Student> getStudentList() {
        return students;
    }

    void randomize() {
        std::random_shuffle(students.begin(), students.end());
    }

    /**
      *
      */
    int getHappinessScore();

private:
    std::vector<Student> students;
};

#endif // STUDENTSET_H
