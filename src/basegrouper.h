#ifndef BASEGROUPER_H
#define BASEGROUPER_H

#include "groupedstudents.h"


/**
 * @brief The BaseGrouper class
 * An abstract class to allow different grouping strategies
 */
class BaseGrouper
{
public:
    BaseGrouper();
    virtual ~BaseGrouper() {}


    /**
     * @brief setNumberGroups
     * Set the number of groups to be grouped
     *
     * @param numGroups
     */
    virtual void setNumberGroups(int numGroups) {
        this->numGroups = numGroups;
    }


    /**
     * @brief setStudentSet
     * Set the StudentSet to be used in grouping
     *
     * @param studentSet
     */
    virtual void setStudentSet(StudentSet studentSet) {
        this->ss = studentSet;
    }


    /**
     * @brief groupStudents
     * Pure virtual method to allow subclasses to define grouping
     *
     * @return
     */
    virtual GroupedStudents groupStudents() = 0;

protected:
    int numGroups;
    StudentSet ss;
    GroupedStudents finalGroupedStudents;

private:

};

#endif // BASEGROUPER_H
