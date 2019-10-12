#include "studentsetanalyser.h"

StudentSetAnalyser::StudentSetAnalyser()
{

}



GroupedStudents StudentSetAnalyser::createOptimalGrouping() {

    std::vector<std::vector<Student>> students;

    GroupedStudents gs(students);
    return gs;
}
