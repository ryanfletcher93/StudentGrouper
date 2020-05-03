#ifndef UNIDIRECTIONALEDGE_H
#define UNIDIRECTIONALEDGE_H

#include "edge.h"


/**
 * @brief The UnidirectionalEdge class
 * Draws a line between two nodes with arrows on the destination end
 */
class UnidirectionalEdge : public Edge
{
public:
    /**
     * @brief UnidirectionalEdge
     * Set the source and destination node
     *
     * @param source
     * @param dest
     */
    UnidirectionalEdge(Node *source, Node *dest);

protected:
    /**
     * @brief paint
     * Draw the line with one arrow at the destination end
     *
     * @param painter
     * @param option
     * @param widget
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // UNIDIRECTIONALEDGE_H
