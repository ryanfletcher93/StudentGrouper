    #ifndef IMPERFECTMERGEGROUPER_H
#define IMPERFECTMERGEGROUPER_H

#include "basegrouper.h"
#include "../students/groupedstudents.h"

#include <memory>

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

    std::unique_ptr<GroupedStudents> groupStudents(StudentSet& studentSet, int numGroups) override;

private:
    std::vector<KernighanLinStudentGroup> initialiseGroups(StudentSet studentSet, int numGroups);

    void calculateCosts();

    int calculateInternalCost(const KernighanStudent& student, const KernighanLinStudentGroup& group);
    std::pair<int, int> calculateExternalCost(const KernighanStudent& student, const KernighanLinStudentGroup& group);

    void swapHighestCostStudents();

    std::pair<KernighanStudent, int> getStudentWithHighestCost();

    void swapStudents(const KernighanStudent& student1, int student1Group,
                      const KernighanStudent& student2, int student2Group);

    std::unique_ptr<GroupedStudents> createGroupedStudentsOutput();


    std::vector<KernighanLinStudentGroup> groups;
};

#endif // IMPERFECTMERGEGROUPER_H
