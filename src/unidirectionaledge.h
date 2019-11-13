#ifndef UNIDIRECTIONALEDGE_H
#define UNIDIRECTIONALEDGE_H

#include "edge.h"



class UnidirectionalEdge : public Edge
{
public:
    UnidirectionalEdge(Node *source, Node *dest);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // UNIDIRECTIONALEDGE_H
