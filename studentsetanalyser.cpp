#include "studentsetanalyser.h"



StudentSetAnalyser::StudentSetAnalyser()
{

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
        combinedGroups.insert(combinedGroups.end(), groupedStudents.begin()->begin(), ++groupedStudents.begin()->begin());
        combinedGroups.insert(combinedGroups.end(), secondGroup.begin(), secondGroup.end());

        // Add to groupedStudents
        reducedGroupedStudents.addGroup(combinedGroups);

        groupedStudents.erase(groupedStudents.begin());
        groupedStudents.erase(mostCompatibleSecondStudent.at(0));
    }

    return reducedGroupedStudents;
}

int StudentSetAnalyser::calculateStudentCompatability(std::list<Student> studentGroup1,
                                                      std::list<Student> studentGroup2) {
    // TODO: Actually implement correct checking of compatability for groups
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
