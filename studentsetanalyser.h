#ifndef STUDENTSETANALYSER_H
#define STUDENTSETANALYSER_H

#include "groupedstudents.h"



class StudentSetAnalyser
{
public:
    StudentSetAnalyser();

    static GroupedStudents createOptimalGrouping();
};

#endif // STUDENTSETANALYSER_H
