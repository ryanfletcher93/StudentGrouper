#ifndef STUDENT_H
#define STUDENT_H

#include "studentpreference.h"

#include <string>

/**
 * @brief The Student class
 * Define the properties and methods required of a Student
 */
class Student
{
public:
    /**
     * @brief Student
     * Inistialise the student with default values
     */
    Student();

    /**
     * @brief Student
     * Initialise the student with values
     *
     * @param firstName
     * @param middleName
     * @param familyName
     * @param idNumber
     */
    Student(std::string firstName, std::string middleName, std::string familyName, int idNumber);

    /**
     * @brief isStudentInPreference
     * Returns true if @param s is in students preferences
     *
     * @param s
     * @return
     */
    bool isStudentInPreference(Student s) const;

    /**
     * @brief calculateHappiness
     * Returns the happiness score of two students
     *
     * @param s1
     * @param s2
     * @return
     */
    static int calculateHappiness(Student s1, Student s2);

    /// Set and get student preferences
    void setStudentPreference(StudentPreference studentPreference);
    StudentPreference getStudentPreference() const;

    /// Get methods for the Student variables
    int getStudentId() const {
        return idNumber;
    }
    std::string getFirstName() const {
        return firstName;
    }
    std::string getMiddleName() const {
        return middleName;
    }
    std::string getFamilyName() const {
        return familyName;
    }

private:
    std::string firstName;
    std::string middleName;
    std::string familyName;

    int idNumber;

    StudentPreference studentPreference;
};

#endif // STUDENT_H
