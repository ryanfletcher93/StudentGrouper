#include "groupvisualiser.h"
#include "bidirectionaledge.h"
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

void GroupVisualiser::setStudentGroup(StudentGroup studentGroup) {
    this->studentGroup = studentGroup;
}

void GroupVisualiser::setNodePositions() {
    // If nothing in
    if (studentGroup.begin() == studentGroup.end()) {
        return;
    }

    int numNodes = static_cast<int>(studentGroup.size());
    double nodeAngleDeg = DEG_CIRCLE / numNodes;

    int nodeCount=0;
    for (auto it = studentGroup.begin(); it != studentGroup.end(); it++) {
        Node *n = new Node(this, *it);

        // Get the node position using angles in radians
        double xPos, yPos;
        double angle = nodeCount * nodeAngleDeg * PI / 180;
        xPos = RADIUS * cos(angle);
        yPos = RADIUS * sin(angle);

        n->setPos(xPos, yPos);
        n->setAngle(angle);

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

        if (s1.getStudentId() == s2.getStudentId()) {
            continue;
        }

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

void GroupVisualiser::setGroupIdentifier(std::string groupString) {
    this->groupString = groupString;
    setWindowTitle(tr(groupString.c_str()));
}
