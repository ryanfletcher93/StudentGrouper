#ifndef BIDIRECTIONALEDGE_H
#define BIDIRECTIONALEDGE_H

#include "edge.h"


/**
 * @brief The BidirectionalEdge class
 * Draws a line between two nodes with arrows on both end
 */
class BidirectionalEdge : public Edge
{
public:
    /**
     * @brief BidirectionalEdge
     * Set the source and destination node
     *
     * @param sourceNode
     * @param destNode
     */
    BidirectionalEdge(Node *sourceNode, Node *destNode);

protected:
    /**
     * @brief paint
     * Draw the line with the arrows
     *
     * @param painter
     * @param option
     * @param widget
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // BIDIRECTIONALEDGE_H
