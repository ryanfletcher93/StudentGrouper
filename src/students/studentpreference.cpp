#include "studentpreference.h"
#include "student.h"

#include <algorithm>

StudentPreference::StudentPreference()
{

}

StudentPreference::StudentPreference(std::vector<Student> students) {
    std::vector<int> tempPreference;
    std::for_each(
        students.begin(),
        students.end(),
        [&tempPreference](Student& student) {tempPreference.push_back(student.getStudentId());}
    );

    preferences = tempPreference;
}


bool StudentPreference::isStudentInPreferences(Student s) const {
    for (auto studentId : preferences) {
        if (studentId == s.getStudentId()) {
            return true;
        }
    }

    return false;
}

std::vector<int> StudentPreference::getPreferencesIds() const {
    return this->preferences;
}
