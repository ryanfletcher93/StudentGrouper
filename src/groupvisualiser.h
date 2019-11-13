#ifndef GROUPVISUALISER_H
#define GROUPVISUALISER_H

class GroupVisualiser;

#include "node.h"

#include <QGraphicsView>



class GroupVisualiser : public QGraphicsView
{
    Q_OBJECT

public:
    GroupVisualiser(QWidget *parent = 0);

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

    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    Node *centreNode;
};

#endif // GROUPVISUALISER_H
