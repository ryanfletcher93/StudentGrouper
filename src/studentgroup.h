#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H

#include "student.h"

#include <list>

class StudentGroup
{
public:
    /// Define iterators for the groups
    typedef std::list<Student>::iterator iterator;
    typedef std::list<Student>::const_iterator const_iterator;

    StudentGroup();
    StudentGroup(Student s) {
        studentGroup.push_front(s);
    }

    void addStudent(Student s);

    iterator begin() {
        return studentGroup.begin();
    }
    iterator end() {
        return studentGroup.end();
    }

    void insert(iterator insertLocation, iterator insertBegin, iterator insertEnd) {
        studentGroup.insert(insertLocation, insertBegin, insertEnd);
    }

    void erase(iterator it) {
        studentGroup.erase(it);
    }

    void eraseAll() {
        studentGroup.clear();
    }

    size_t size() {
        return studentGroup.size();
    }

private:
    std::list<Student> studentGroup;
};

#endif // STUDENTGROUP_H
