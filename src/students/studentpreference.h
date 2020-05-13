#ifndef STUDENTPREFERENCE_H
#define STUDENTPREFERENCE_H

#include <array>
#include <vector>

class Student;

/**
 * @brief The StudentPreference class
 * StudentPreferences holds the list of students that
 * another student has preferred
 */
class StudentPreference
{
public:
    /// Constructors for student preferences
    StudentPreference();
    StudentPreference(std::vector<Student> students);

    /**
     * @brief isStudentInPreferences
     * Return whether @param s is in this students preferences
     *
     * @param s
     * @return
     */
    bool isStudentInPreferences(Student s);

    /**
     * @brief getPreferencesIds
     * Get the student IDs of the preferenced students
     *
     * @return
     */
    std::vector<int> getPreferencesIds();

private:
    std::vector<int> preferences;
};

#endif // STUDENTPREFERENCE_H
