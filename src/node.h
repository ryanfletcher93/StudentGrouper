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
    Node(GroupVisualiser *visualiser, Student s);

    void addEdge(Edge *edge);
    QList<Edge *> edges() const;

    QRectF boundingRect() const override;

    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) override;

    Student getStudent() {
        return student;
    }

private:
    QList<Edge *> edgeList;
    QPointF newPos;
    GroupVisualiser *visualiser;
    Student student;
};

#endif // NODE_H
