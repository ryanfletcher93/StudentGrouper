#include "imperfectmergegrouper.h"

#include "math.h"

ImperfectMergeGrouper::ImperfectMergeGrouper()
{

}

GroupedStudents ImperfectMergeGrouper::groupStudents() {




    return finalGroupedStudents;
}

int ImperfectMergeGrouper::calculateStudentCompatability(StudentSet studentSet1,
                                                         StudentSet studentSet2) {
    int total = 0;
    for (auto s1 : studentSet1.getStudentList()) {
        for (auto s2 : studentSet2.getStudentList()) {
            total += Student::calculateHappiness(s1, s2);
        }
    }

    return total;
}
