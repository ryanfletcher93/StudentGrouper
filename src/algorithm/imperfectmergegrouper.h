#ifndef IMPERFECTMERGEGROUPER_H
#define IMPERFECTMERGEGROUPER_H

#include "groupedstudents.h"

#include "basegrouper.h"

/**
 * @brief The ImperfectMergeGrouper class
 * Group the students based on a merge algorithm
 */
class ImperfectMergeGrouper : public BaseGrouper
{
public:
    ImperfectMergeGrouper();

    /**
     * @brief groupStudents
     * A log2 merge grouping algorithm where each student
     * is placed in a group, then the groups are halved and
     * merged together, and any remainders are added
     * at the end.
     *
     * @param groupedStudents
     * @return
     */
    GroupedStudents groupStudents() override;

private:

    /**
     * @brief calculateStudentCompatability
     * Calculate how compatible the student groups
     * TODO: Find a better place for this (i.e. not static)
     *
     * @param studentGroup1
     * @param studentGroup2
     * @return
     */
    static int calculateStudentCompatability(StudentSet studentGroup1, StudentSet studentGroup2);
};

#endif // IMPERFECTMERGEGROUPER_H
