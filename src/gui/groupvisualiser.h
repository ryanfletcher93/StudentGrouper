 #ifndef GROUPVISUALISER_H
#define GROUPVISUALISER_H

class GroupVisualiser;

#include "groupedstudents.h"
#include "studentset.h"
#include "node.h"

#include <QGraphicsView>

/**
 * @brief The GroupVisualiser class
 * Responsible for drawing the set of nodes and edges to
 * represent the student preferences in each group
 */
class GroupVisualiser : public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * @brief GroupVisualiser
     * Initialise all relevant variables, @param parent
     * is passed to the constructor for QGraphicsView
     *
     * @param parent
     */
    GroupVisualiser(QWidget *parent = 0);

    /**
     * @brief setStudentGroup
     * Set the student group to visualise
     *
     * @param studentGroup
     */
    void setStudentGroup(StudentSet studentSet);

    /**
     * @brief setNodePositions
     * Set the positions of the node
     */
    void setNodePositions();

    /**
     * @brief setGroupIdentifier
     * Set the label for the group to be displayed ot user
     *
     * @param groupString
     */
    void setGroupIdentifier(std::string groupString);

private:
    /**
     * @brief drawNodeEdges
     * Create each node edge
     *
     * @param node
     */
    void drawNodeEdges(Node *node);

    std::vector<Node *> nodes;
    StudentSet studentSet;
    std::string groupString;

    QGraphicsScene *scene;
};

#endif // GROUPVISUALISER_H
