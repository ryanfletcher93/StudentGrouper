#ifndef NODE_H
#define NODE_H

class Node;

#include "edge.h"
#include "groupvisualiser.h"

#include <QGraphicsItem>

/**
 * @brief The Node class
 * Node class to define the visual representation of a node
 */
class Node : public QGraphicsItem
{
public:
    Node() {}
    Node(GroupVisualiser *visualiser, Student s);

    /**
     * @brief addEdge
     * Add edge
     *
     * @param edge
     */
    void addEdge(Edge *edge);

    /**
     * @brief edges
     * Return the edges
     *
     * @return
     */
    QList<Edge *> edges() const;

    /**
     * @brief boundingRect
     * Create bounding rectangle for node
     *
     * @return
     */
    QRectF boundingRect() const override;

    /**
     * @brief shape
     * Define shape of node as an ellipse
     *
     * @return
     */
    QPainterPath shape() const override;

    /**
     * @brief paint
     * Paint the node
     *
     * @param painter
     * @param option
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    /**
     * @brief setAngle
     * Set angle in radians
     *
     * @param angle
     */
    void setAngle(double angle) {
        this->angle = angle;
    }

    /**
     * @brief getStudent
     * Get student
     *
     * @return
     */
    Student getStudent() {
        return student;
    }

private:
    QList<Edge *> edgeList;
    QPointF newPos;
    GroupVisualiser *visualiser;
    Student student;
    double angle;
};

#endif // NODE_H
