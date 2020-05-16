#include "node.h"

#define TEXT_WIDTH 100
#define TEXT_HEIGHT 20
#define TEXT_OFFSET 20

Node::Node(GroupVisualiser *visualiser, Student student) :
    visualiser(visualiser), student(student)
{
    setZValue(-1);
}

QRectF Node::boundingRect() const {
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath Node::shape() const {
    QPainterPath path;
    path.addEllipse(-10, -10, 20, 20);
    return path;
}

void Node::addEdge(Edge *edge)
{
    edgeList.push_back(edge);
    edge->adjust();
}

QList<Edge *> Node::edges() const
{
    return edgeList;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    // Do not use option
    (void)option;

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7, -7, 20, 20);

    QRadialGradient gradient(-3, -3, 10);
    gradient.setColorAt(0, Qt::yellow);
    gradient.setColorAt(1, Qt::yellow);
    painter->setBrush(gradient);

    QString studentName = QString::fromStdString(student.getFirstName() + " " + student.getFamilyName());

    painter->setPen(QPen(Qt::black, 0));
    painter->drawEllipse(-10, -10, 20, 20);

    int textX;
    int textY;
    int flag;
    if (cos(angle) > 0) {
        textX = TEXT_OFFSET * cos(angle);
        flag = Qt::AlignLeft;
    } else {
        textX = TEXT_OFFSET * cos(angle) - TEXT_WIDTH;
        flag = Qt::AlignRight;
    }

    if (sin(angle) > 0) {
        textY = TEXT_OFFSET * sin(angle);
    } else {
        textY = TEXT_OFFSET * sin(angle) - TEXT_HEIGHT;
    }

    painter->drawText(textX, textY, TEXT_WIDTH, TEXT_HEIGHT, flag, studentName);
}
