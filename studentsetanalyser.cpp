#include "studentsetanalyser.h"

#include <math.h>

StudentSetAnalyser::StudentSetAnalyser()
{

}

GroupedStudents StudentSetAnalyser::groupStudents(StudentSet studentSet, int numGroups) {
    GroupedStudents finalGroupedStudents(studentSet);
    while (floor(finalGroupedStudents.size()/2) > numGroups) {
        finalGroupedStudents = reduceGroups(finalGroupedStudents);
    }

    addGroupsToRemainder(finalGroupedStudents, numGroups);

    addRemainderToRestOfGroup(finalGroupedStudents);

    return finalGroupedStudents;
}

GroupedStudents StudentSetAnalyser::reduceGroups(GroupedStudents groupedStudents) {
    // Store new groups to return
    GroupedStudents reducedGroupedStudents;
    // Perform one halving of student spaces
    while (!(groupedStudents.size() == 0 || groupedStudents.size() == 1)) {
        int maxStudentGroupCompatability = 0;
        std::vector<std::list<std::list<Student>>::iterator> mostCompatibleSecondStudent;

        auto studentIt1 = groupedStudents.begin();
        std::list<std::list<Student>>::iterator studentIt2;
        for (studentIt2 = std::next(groupedStudents.begin(),1); studentIt2 != groupedStudents.end(); studentIt2++) {
            int tempStudentGroupCompatability =
                    StudentSetAnalyser::calculateStudentCompatability(*studentIt1, *studentIt2);

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

    if (groupedStudents.size() == 1) {
        reducedGroupedStudents.addToRemainder(*groupedStudents.begin());
    }

    return reducedGroupedStudents;
}

void StudentSetAnalyser::addGroupsToRemainder(GroupedStudents& gs, int numGroups) {
    // For every group more than the number of groups, add all students to remainder
    int index = 1;
    for (auto studentList = gs.begin(); studentList != gs.end(); studentList++) {
        if (index > numGroups) {
            gs.addToRemainder(*studentList);
            gs.erase(studentList--);
        }
        index++;
    }
}

void StudentSetAnalyser::addRemainderToRestOfGroup(GroupedStudents& gs) {
    // Loop through each student in remainder and assign to best group evenly
    int existingGroupSize = static_cast<int> ((*gs.begin()).size());
    int numberGroups = static_cast<int> (gs.size());
    int remainderSize = static_cast<int> (gs.sizeRemainder());
    int additionalStudents = static_cast<int> (ceil(remainderSize / numberGroups));
    int maxGroupSize = existingGroupSize + additionalStudents;

    // For each student in remainder, add to most viable group
    for (auto remainderIt = gs.beginRemainder(); remainderIt != gs.endRemainder(); remainderIt++) {
        int bestGroupCompatibility = 0;
        std::list<std::list<Student>>::iterator it;
        for (auto groupIt = gs.begin(); groupIt != gs.end(); groupIt++) {
            // Check if group is not fully allocated
            if (static_cast<int> ((*groupIt).size()) < maxGroupSize) {
                int groupCompatability = calculateStudentCompatability(std::list<Student> {*remainderIt}, *groupIt);
                if (groupCompatability > bestGroupCompatibility) {
                    bestGroupCompatibility = groupCompatability;
                    it = groupIt;
                }
            }
        }

        // Add remainder Student to best group
        (*it).push_front(*remainderIt);
    }

    gs.eraseAllRemainders();
}

int StudentSetAnalyser::calculateStudentCompatability(std::list<Student> studentGroup1,
                                                      std::list<Student> studentGroup2) {
    int total = 0;
    for (auto s1 : studentGroup1) {
        for (auto s2 : studentGroup2) {
            total += Student::calculateHappiness(s1, s2);
        }
    }

    return total;
}
