#include "kernighanlinalgorithmtest.h"

#include "../src/students/student.h"
#include "../src/students/studentpreference.h"
#include "../src/students/groupedstudents.h"
#include "../src/algorithm/kernighanlingrouper.h"

#include <cstdlib>
#include <stdexcept>

typedef std::unique_ptr<KernighanLinGrouper> klGrouperUPtr;
typedef std::unique_ptr<GroupedStudents> groupedStudentUPtr;

KernighanLinAlgorithmTest::KernighanLinAlgorithmTest(QObject *parent) : QObject(parent)
{

}

void KernighanLinAlgorithmTest::groupedStudentSizeChecks()
{
    int numStudents = 10;
    int numPreferences = 6;
    int numGroups = 3;

    StudentSet studentSet = createStudentSet(numStudents, numPreferences);

    klGrouperUPtr kernighanLinGrouper = klGrouperUPtr(new KernighanLinGrouper);

    // Check the output has the correct number of groups
    groupedStudentUPtr groupedStudents = kernighanLinGrouper->groupStudents(studentSet, numGroups);
    QVERIFY(groupedStudents->getGroups().size() == (size_t) numGroups);

    // Check if size of each group is evenly split based on students and number of groups
    int lowerGroupSize = std::floor((float) numStudents / (float) numGroups);
    int upperGroupSize = std::ceil((float) numStudents / (float) numGroups);
    for (auto& group : groupedStudents->getGroups())
    {
        int groupSize = group.getStudentList().size();
        QVERIFY(groupSize == lowerGroupSize || groupSize == upperGroupSize);
    }
}

void KernighanLinAlgorithmTest::checkOneGroupIsValid()
{
    int numStudents = 10;
    int numPreferences = 6;
    int numGroups = 1;

    StudentSet studentSet = createStudentSet(numStudents, numPreferences);

    klGrouperUPtr kernighanLinGrouper = klGrouperUPtr(new KernighanLinGrouper);
    groupedStudentUPtr groupedStudents = kernighanLinGrouper->groupStudents(studentSet, numGroups);

    // Check that after calculation
    QVERIFY(groupedStudents->calculateHappinessScore() == studentSet.getHappinessScore());
}

StudentSet KernighanLinAlgorithmTest::createStudentSet(int numStudents, int numPreferences)
{

    if (numPreferences > numStudents)
    {
        throw std::invalid_argument("Cannot create student set with more preferences than students");
        return StudentSet();
    }

    std::vector<Student> listOfStudents;
    for (int i=0; i<numStudents; ++i)
    {
        Student tempStudent("A", "B", "C", i);

        // Create preferences that is random other student ids not equal to current student
        std::vector<int> preference;
        while (preference.size() != (size_t) numPreferences)
        {
            int randomId = rand() % numStudents + 1;
            if (randomId != i && std::find(preference.begin(), preference.end(), randomId) == preference.end())
            {
                preference.push_back(randomId);
            }
        }
        StudentPreference tempStudentPreference(preference);
        tempStudent.setStudentPreference(tempStudentPreference);

        listOfStudents.push_back(tempStudent);
    }

    StudentSet studentSet;
    std::for_each(listOfStudents.begin(),
        listOfStudents.end(),
        [&studentSet](Student student) {studentSet.addStudent(student);}
    );

    return studentSet;
}
