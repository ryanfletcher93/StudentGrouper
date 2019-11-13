#ifndef BIDIRECTIONALEDGE_H
#define BIDIRECTIONALEDGE_H

#include "edge.h"



class BidirectionalEdge : public Edge
{
public:
    BidirectionalEdge(Node *sourceNode, Node *destNode);

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // BIDIRECTIONALEDGE_H
