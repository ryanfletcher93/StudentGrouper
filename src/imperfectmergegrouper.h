#ifndef IMPERFECTMERGEGROUPER_H
#define IMPERFECTMERGEGROUPER_H

#include "groupedstudents.h"

#include <basegrouper.h>

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
     * @brief reduceGroups
     * Merge the groups with naive most compatible groups
     *
     * @param groupedStudents
     * @return
     */
    GroupedStudents reduceGroups(GroupedStudents groupedStudents);

    /**
     * @brief addGroupsToRemainder
     * Add any relevant groups to remainder
     */
    void addGroupsToRemainder();

    /**
     * @brief addRemainderToRestOfGroup
     * Add any remaining groups to existing groups evenly
     */
    void addRemainderToRestOfGroup();

    /**
     * @brief calculateStudentCompatability
     * Calculate how compatible the student groups
     * TODO: Find a better place for this (i.e. not static)
     * TODO: Create student group instead of raw std::list<Student>
     *
     * @param studentGroup1
     * @param studentGroup2
     * @return
     */
    static int calculateStudentCompatability(std::list<Student> studentGroup1, std::list<Student> studentGroup2);
};

#endif // IMPERFECTMERGEGROUPER_H
