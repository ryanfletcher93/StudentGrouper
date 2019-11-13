#ifndef IMPERFECTMERGEGROUPER_H
#define IMPERFECTMERGEGROUPER_H

#include "groupedstudents.h"

#include <basegrouper.h>

class ImperfectMergeGrouper : public BaseGrouper
{
public:
    ImperfectMergeGrouper();

    GroupedStudents groupStudents() override;

private:
    GroupedStudents reduceGroups(GroupedStudents groupedStudents);

    void addGroupsToRemainder();

    void addRemainderToRestOfGroup();

    static int calculateStudentCompatability(std::list<Student> studentGroup1, std::list<Student> studentGroup2);
};

#endif // IMPERFECTMERGEGROUPER_H
