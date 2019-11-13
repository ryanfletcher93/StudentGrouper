#ifndef GROUPVISUALISER_H
#define GROUPVISUALISER_H

class GroupVisualiser;

#include "groupedstudents.h"
#include "node.h"

#include <QGraphicsView>



class GroupVisualiser : public QGraphicsView
{
    Q_OBJECT

public:
    GroupVisualiser(QWidget *parent = 0);

    void setGroupedStudents(GroupedStudents groupedStudents);

    void setNodePositions();

    /*

    void itemMoved();

public slots:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void scaleView(qreal scaleFactor);

    */

    //void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    std::vector<Node *> nodes;
    GroupedStudents groupedStudents;

    QGraphicsScene *scene;
};

#endif // GROUPVISUALISER_H
