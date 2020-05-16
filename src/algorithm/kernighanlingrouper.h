#ifndef KERNIGHANLINGROUPER_H
#define KERNIGHANLINGROUPER_H

#include "basegrouper.h"
#include "../students/groupedstudents.h"

#include <memory>

struct KernighanLinStudent {
    Student student;
    std::vector<std::pair<int, int>> ExternalCost;
    int InternalCost = 0;
};

struct KernighanLinStudentGroup {
    std::vector<KernighanLinStudent> studentGroup;
    int groupNumber = 0;
};

/**
 * @brief The ImperfectMergeGrouper class
 * Group the students based on a merge algorithm
 */
class KernighanLinGrouper : public BaseGrouper
{
public:
    KernighanLinGrouper();

    std::unique_ptr<GroupedStudents> groupStudents(StudentSet& studentSet, int numGroups) override;

private:
    std::vector<KernighanLinStudentGroup> initialiseGroups(StudentSet studentSet, int numGroups);

    void calculateCosts();

    int calculateInternalCost(const KernighanLinStudent& student, const KernighanLinStudentGroup& group);
    std::pair<int, int> calculateExternalCost(const KernighanLinStudent& student, const KernighanLinStudentGroup& group);

    void swapHighestCostStudents();

    std::pair<KernighanLinStudent, int> getStudentWithHighestCost();

    void swapStudents(const KernighanLinStudent& student1, int student1Group,
                      const KernighanLinStudent& student2, int student2Group);

    std::unique_ptr<GroupedStudents> createGroupedStudentsOutput();


    std::vector<KernighanLinStudentGroup> groups;
};

#endif // KERNIGHANLINGROUPER_H
