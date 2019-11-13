#ifndef NODE_H
#define NODE_H

class Node;

#include "edge.h"
#include "groupvisualiser.h"

#include <QGraphicsItem>



class Node : public QGraphicsItem
{
public:
    Node() {}
    Node(GroupVisualiser *visualiser);

    //Node(const Node &rhs);

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

private:
    QList<Edge *> edgeList;
    QPointF newPos;
    GroupVisualiser *visualiser;
};

#endif // NODE_H
