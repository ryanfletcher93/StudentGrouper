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
