#ifndef STUDENTSETANALYSER_H
#define STUDENTSETANALYSER_H

#include "groupedstudents.h"
#include "studentset.h"

#include <list>

class StudentSetAnalyser
{
public:
    StudentSetAnalyser();

    static GroupedStudents groupStudents(StudentSet studentSet, int numGroups);

    static GroupedStudents reduceGroups(GroupedStudents groupedStudents);

    static void addGroupsToRemainder(GroupedStudents& finalGroupedStudents, int numGroups);

    static void addRemainderToRestOfGroup(GroupedStudents& finalGroupedStudents);

    static int calculateStudentCompatability(std::list<Student> studentGroup1, std::list<Student> studentGroup2);
};

#endif // STUDENTSETANALYSER_H
