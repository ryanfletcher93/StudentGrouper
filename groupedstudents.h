#ifndef GROUPEDSTUDENTS_H
#define GROUPEDSTUDENTS_H

#include "student.h"
#include "studentset.h"

#include <list>
#include <vector>

class StudentSet;

class GroupedStudents
{
public:
    typedef std::list<std::list<Student>>::iterator iterator;
    typedef std::list<std::list<Student>>::const_iterator const_iterator;

    typedef std::list<Student>::iterator remainderIterator;
    typedef std::list<Student>::const_iterator const_remainderIterator;

    GroupedStudents();
    GroupedStudents(StudentSet studentSet);

    std::list<std::list<Student>> getGroupedStudents();

    iterator begin() {
        return groupedStudents.begin();
    }
    iterator end() {
        return groupedStudents.end();
    }

    size_t size() {
        return groupedStudents.size();
    }

    void erase(iterator it) {
        groupedStudents.erase(it);
    }

    void addGroup(std::list<Student> studentList) {
        groupedStudents.push_back(studentList);
    }

    remainderIterator beginRemainder() {
        return remainderStudents.begin();
    }
    remainderIterator endRemainder() {
        return remainderStudents.end();
    }

    size_t sizeRemainder() {
        return remainderStudents.size();
    }

    void eraseRemainder(remainderIterator remainderIt) {
        remainderStudents.erase(remainderIt);
    }

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
