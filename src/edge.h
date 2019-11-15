#ifndef EDGE_H
#define EDGE_H

class Edge;

#include "node.h"

#include <QGraphicsItem>


/**
 * @brief The Edge class
 * Abstract class to provide common features for edges with different arrow types
 */
class Edge : public QGraphicsItem
{
public:
    /**
     * @brief Edge
     * Set the edge source and destination node
     *
     * @param sourceNode
     * @param destNode
     */
    Edge(Node *sourceNode, Node *destNode);

    Node *sourceNode() const;
    Node *destNode() const;


    /**
     * @brief adjust
     * Set the source and destination node points
     */
    void adjust();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }

protected:
    /**
     * @brief boundingRect
     * Define bounding rectangle for the edge
     * TODO: Override this for each arrow type
     *
     * @return
     */
    QRectF boundingRect() const override;


    /**
     * @brief paint
     * Define method for subclasses to define how the line is drawn
     *
     * @param painter
     * @param option
     * @param widget
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override = 0;

    Node *source, *dest;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
};

#endif // EDGE_H
