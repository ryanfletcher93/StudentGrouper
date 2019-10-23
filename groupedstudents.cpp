#include "groupedstudents.h"

GroupedStudents::GroupedStudents()
{

}

std::list<std::list<Student>> GroupedStudents::getGroupedStudents() {
    return this->groupedStudents;
}
