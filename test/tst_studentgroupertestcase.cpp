#include <QtTest>

#include "../src/csvparser.h"
#include "../src/studentset.h"
#include "../src/groupedstudents.h"
#include "../src/basegrouper.h"
#include "../src/imperfectmergegrouper.h"

class StudentGrouperTestCase : public QObject
{
    Q_OBJECT

public:
    StudentGrouperTestCase();
    ~StudentGrouperTestCase();

private slots:
    void groupedStudentSizeTest();
    void numStudentsInEachGroupTest();

private:
    std::string csvFilePath = "C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\test\\mockCsvInput.csv";

    StudentSet ss;
    GroupedStudents gs;
};

StudentGrouperTestCase::StudentGrouperTestCase()
{
    CsvParser csvP;
    csvP.setFilePath(csvFilePath);
    ss = csvP.parseFile();

    BaseGrouper *bg = new ImperfectMergeGrouper();
    bg->setStudentSet(ss);
    bg->setNumberGroups(5);

    gs = bg->groupStudents();
}

StudentGrouperTestCase::~StudentGrouperTestCase()
{

}

void StudentGrouperTestCase::groupedStudentSizeTest()
{
    QVERIFY(gs.size() == 5);
}

void StudentGrouperTestCase::numStudentsInEachGroupTest()
{
    for (auto gsIt = gs.begin(); gsIt != gs.end(); gsIt++) {
        QVERIFY((*gsIt).size() == 24);
    }
}

QTEST_APPLESS_MAIN(StudentGrouperTestCase)

#include "tst_studentgroupertestcase.moc"

