#include "studentgroup.h"

StudentGroup::StudentGroup()
{

}

void StudentGroup::addStudent(Student s) {
    studentGroup.push_front(s);
}
