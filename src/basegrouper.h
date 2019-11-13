#ifndef BASEGROUPER_H
#define BASEGROUPER_H

#include "groupedstudents.h"



class BaseGrouper
{
public:
    BaseGrouper();
    virtual ~BaseGrouper() {}

    virtual void setNumberGroups(int numGroups) {
        this->numGroups = numGroups;
    }

    virtual void setStudentSet(StudentSet studentSet) {
        this->ss = studentSet;
    }

    virtual GroupedStudents groupStudents() = 0;

protected:
    int numGroups;
    StudentSet ss;

    GroupedStudents finalGroupedStudents;

private:

};

#endif // BASEGROUPER_H
