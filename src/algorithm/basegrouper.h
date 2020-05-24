#ifndef BASEGROUPER_H
#define BASEGROUPER_H

#include "../gui/progressupdator.h"
#include "../students/studentset.h"
#include "../students/groupedstudents.h"

#include <QObject>

#include <memory>


/**
 * @brief The BaseGrouper class
 * An abstract class to allow different grouping strategies
 */
class BaseGrouper
{
public:

    virtual ~BaseGrouper() {}
    /**
     * @brief groupStudents
     * Pure virtual method to allow subclasses to define grouping
     *
     * @return
     */
    virtual std::unique_ptr<GroupedStudents> groupStudents(StudentSet& studentSet, int numGroups,
                                                           ProgressUpdator* progressUpdator) = 0;

private:

};

#endif // BASEGROUPER_H
