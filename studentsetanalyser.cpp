#include "studentsetanalyser.h"

#include <math.h>

StudentSetAnalyser::StudentSetAnalyser()
{

}

GroupedStudents StudentSetAnalyser::groupStudents(StudentSet studentSet) {
    const int numGroups = 5;
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
    int existingGroupSize = (int) (*gs.begin()).size();
    int numberGroups = (int) gs.size();
    int remainderSize = (int) gs.sizeRemainder();
    int additionalStudents = (int) ceil(remainderSize / numberGroups);
    int maxGroupSize = existingGroupSize + additionalStudents;

    // For each student in remainder, add to first viable group
    // TODO: Do more than just first, find best group to pust student in
    for (auto studentIt = gs.beginRemainder(); studentIt != gs.endRemainder(); studentIt++) {
        int groupCompatibility = 0;

        for (auto groupIt = gs.begin(); groupIt != gs.end(); groupIt++) {
            if ((int) (*groupIt).size() < maxGroupSize) {
                (*groupIt).push_front(*studentIt);
                break;
            }
        }

        //gs.eraseRemainder(studentIt);
    }
}

int StudentSetAnalyser::calculateStudentCompatability(std::list<Student> studentGroup1,
                                                      std::list<Student> studentGroup2) {
    // TODO: Analyse intire list, not just first
    // TODO: Account for similar preferences between students
    int total = 0;
    bool s2InS1Pref = (*studentGroup1.begin()).isStudentInPreference(*studentGroup2.begin());
    if (s2InS1Pref) {
        total += 2;
    }

    bool s1InS2Pref = (*studentGroup2.begin()).isStudentInPreference(*studentGroup1.begin());
    if (s1InS2Pref) {
        total += 2;
    }

    return total;
}
