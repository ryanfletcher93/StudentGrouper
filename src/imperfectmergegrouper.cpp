#include "imperfectmergegrouper.h"

ImperfectMergeGrouper::ImperfectMergeGrouper()
{

}

GroupedStudents ImperfectMergeGrouper::groupStudents() {
    GroupedStudents groupedStudents = GroupedStudents(ss);
    while (floor(groupedStudents.size()/2) > numGroups) {
        groupedStudents = reduceGroups(groupedStudents);
    }

    this->finalGroupedStudents = groupedStudents;

    addGroupsToRemainder();

    addRemainderToRestOfGroup();

    return finalGroupedStudents;
}

GroupedStudents ImperfectMergeGrouper::reduceGroups(GroupedStudents groupedStudents) {
    // Store new groups to return
    GroupedStudents reducedGroupedStudents;
    // Perform one halving of student spaces
    while (!(groupedStudents.size() == 0 || groupedStudents.size() == 1)) {
        int maxStudentGroupCompatability = 0;
        std::vector<std::list<std::list<Student>>::iterator> mostCompatibleSecondStudent;

        auto studentIt1 = groupedStudents.begin();
        for (auto studentIt2 = std::next(groupedStudents.begin(),1); studentIt2 != groupedStudents.end(); studentIt2++) {
            int tempStudentGroupCompatability =
                    calculateStudentCompatability(*studentIt1, *studentIt2);

            std::list<std::list<Student>>::iterator tempIt2 = studentIt2;
            // Create list of most compatible groups, if compatability higher then clear and add
            if (tempStudentGroupCompatability > maxStudentGroupCompatability) {
                mostCompatibleSecondStudent.clear();
                mostCompatibleSecondStudent.push_back(tempIt2);
                maxStudentGroupCompatability = tempStudentGroupCompatability;
            }
            else if (tempStudentGroupCompatability == maxStudentGroupCompatability) {
                mostCompatibleSecondStudent.push_back(tempIt2);
            }
        }

        // Decide on what pair to group
        std::list<Student> secondGroup = *(mostCompatibleSecondStudent.at(0));

        // Combine groups
        std::list<Student> combinedGroups;
        combinedGroups.insert(combinedGroups.end(), groupedStudents.begin()->begin(), groupedStudents.begin()->end());
        combinedGroups.insert(combinedGroups.end(), secondGroup.begin(), secondGroup.end());

        // Add to groupedStudents
        reducedGroupedStudents.addGroup(combinedGroups);

        groupedStudents.erase(groupedStudents.begin());
        groupedStudents.erase(mostCompatibleSecondStudent.at(0));
    }

    reducedGroupedStudents.addToRemainder(groupedStudents.getRemainder());
    if (groupedStudents.size() == 1) {
        reducedGroupedStudents.addToRemainder(*groupedStudents.begin());
    }

    return reducedGroupedStudents;
}

void ImperfectMergeGrouper::addGroupsToRemainder() {
    // For every group more than the number of groups, add all students to remainder
    int index = 1;
    for (auto studentList = finalGroupedStudents.begin(); studentList != finalGroupedStudents.end(); studentList++) {
        if (index > numGroups) {
            finalGroupedStudents.addToRemainder(*studentList);
            finalGroupedStudents.erase(studentList--);
        }
        index++;
    }
}

void ImperfectMergeGrouper::addRemainderToRestOfGroup() {
    // Loop through each student in remainder and assign to best group evenly
    int currGroupSize = static_cast<int> ((*finalGroupedStudents.begin()).size());
    int numberGroups = static_cast<int> (finalGroupedStudents.size());
    int remainderSize = static_cast<int> (finalGroupedStudents.sizeRemainder());
    double ceilAdditionalStudents = ceil(static_cast<double> (remainderSize) / static_cast<double> (numberGroups));
    int additionalStudents = static_cast<int>(ceilAdditionalStudents);
    int maxGroupSize = currGroupSize + additionalStudents;

    // For each student in remainder, add to most viable group
    int numRemainders = 0;
    for (auto remainderIt = finalGroupedStudents.beginRemainder(); remainderIt != finalGroupedStudents.endRemainder(); remainderIt++) {
        numRemainders++;
        int bestGroupCompatibility = -1;

        std::list<std::list<Student>>::iterator it;
        for (auto groupIt = finalGroupedStudents.begin(); groupIt != finalGroupedStudents.end();) {
            // Check if group is not fully allocated
            if (static_cast<int> ((*groupIt).size()) < maxGroupSize) {
                int groupCompatability = calculateStudentCompatability(std::list<Student> {*remainderIt}, *groupIt);
                if (groupCompatability > bestGroupCompatibility) {
                    bestGroupCompatibility = groupCompatability;
                    it = groupIt;
                }
            }

            groupIt++;
        }

        // Add remainder Student to best group
        (*it).push_front(*remainderIt);
    }

    finalGroupedStudents.eraseAllRemainders();
}

int ImperfectMergeGrouper::calculateStudentCompatability(std::list<Student> studentGroup1,
                                                          std::list<Student> studentGroup2) {
    int total = 0;
    for (auto s1 : studentGroup1) {
        for (auto s2 : studentGroup2) {
            total += Student::calculateHappiness(s1, s2);
        }
    }

    return total;
}
