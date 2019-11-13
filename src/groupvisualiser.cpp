#include "bidirectionaledge.h"
#include "groupvisualiser.h"
#include "unidirectionaledge.h"

#include <math.h>

#define RADIUS 500
#define DEG_CIRCLE 360
#define PI 3.14159265

GroupVisualiser::GroupVisualiser(QWidget* parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setMinimumSize(1000, 900);
    setWindowTitle(tr("Grouped Students"));
}

void GroupVisualiser::setGroupedStudents(GroupedStudents groupedStudents) {
    this->groupedStudents = groupedStudents;
}

void GroupVisualiser::setNodePositions() {
    // If nothing in
    if (groupedStudents.begin() == groupedStudents.end()) {
        return;
    }

    std::list<Student> group = *(groupedStudents.begin());

    int numNodes = static_cast<int>(group.size());
    double nodeAngleDeg = DEG_CIRCLE / numNodes;

    int nodeCount=0;
    for (auto it = group.begin(); it != group.end(); it++) {
        Node *n = new Node(this, *it);

        // Get the node position using angles in radians
        double xPos, yPos;
        xPos = RADIUS * cos(nodeCount * nodeAngleDeg * PI / 180);
        yPos = RADIUS * sin(nodeCount * nodeAngleDeg * PI / 180);

        n->setPos(xPos, yPos);

        nodes.push_back(n);
        scene->addItem(n);

        drawNodeEdges(n);

        nodeCount++;
    }
}

void GroupVisualiser::drawNodeEdges(Node *n) {
    Student s1 = n->getStudent();

    for (auto node : nodes) {
        Student s2 = node->getStudent();
        if (s1.isStudentInPreference(s2) && s2.isStudentInPreference(s1)) {
            scene->addItem(new BidirectionalEdge(n, node));
        }
        else if (s1.isStudentInPreference(s2)) {
            scene->addItem(new UnidirectionalEdge(n, node));
        }
        else if (s2.isStudentInPreference(s1)) {
            scene->addItem(new UnidirectionalEdge(node, n));
        }
    }
}

/*
void GroupVisualiser::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    sceneRect.width() - 4, sceneRect.height() - 4);
    QString message(tr("Click and drag the nodes around, and zoom with the mouse "
                       "wheel or the '+' and '-' keys"));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), message);
    painter->setPen(Qt::black);
    painter->drawText(textRect, message);
}
*/
