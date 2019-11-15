#include "studentpreference.h"

StudentPreference::StudentPreference()
{

}

StudentPreference::StudentPreference(std::vector<Student> students) {
    this->preferences = students;
}


bool StudentPreference::isStudentInPreferences(Student s) {
    for (auto studentIt : preferences) {
        if (studentIt.getStudentId() == s.getStudentId()) {
            return true;
        }
    }

    return false;
}

std::vector<int> StudentPreference::getPreferencesIds() {
    std::vector<int> ids;
    for (Student s : this->preferences) {
        ids.push_back(s.getStudentId());
    }

    return ids;
}
