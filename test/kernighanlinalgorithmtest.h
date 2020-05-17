#ifndef KERNIGHANLINALGORITHMTEST_H
#define KERNIGHANLINALGORITHMTEST_H

#include <QObject>
#include <QtTest>

#include "../src/algorithm/kernighanlingrouper.h"

#include "../src/students/studentset.h"

class KernighanLinAlgorithmTest : public QObject
{
    Q_OBJECT
public:
    explicit KernighanLinAlgorithmTest(QObject *parent = nullptr);

private slots:
    void groupedStudentSizeChecks();

    void checkOneGroupIsValid();

private:
    StudentSet createStudentSet(int numStudents, int numPreferences);;

};

//#include "testqstring.moc"

#endif // KERNIGHANLINALGORITHMTEST_H
