    #ifndef IMPERFECTMERGEGROUPER_H
#define IMPERFECTMERGEGROUPER_H

#include "basegrouper.h"
#include "../students/groupedstudents.h"

struct KernighanStudent {
    Student student;
    std::vector<std::pair<int, int>> ExternalCost;
    int InternalCost = 0;
};

struct KernighanLinStudentGroup {
    std::vector<KernighanStudent> studentGroup;
    int groupNumber = 0;
};

/**
 * @brief The ImperfectMergeGrouper class
 * Group the students based on a merge algorithm
 */
class ImperfectMergeGrouper : public BaseGrouper
{
public:
    ImperfectMergeGrouper();

    GroupedStudents* groupStudents(StudentSet& studentSet, int numGroups) override;

private:
    std::vector<KernighanLinStudentGroup> initialiseGroups(StudentSet studentSet, int numGroups);

    void calculateCosts();

    void swapHighestCostStudents();

    GroupedStudents* createGroupedStudentsOutput();


    std::vector<KernighanLinStudentGroup> groups;
};

#endif // IMPERFECTMERGEGROUPER_H
