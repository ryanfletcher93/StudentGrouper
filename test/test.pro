QT += testlib
QT += gui
QT += core gui
QT += widgets

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

VPATH += ../src

HEADERS += \
    backendadaptor.h \
    basegrouper.h \
    bidirectionaledge.h \
    csvparser.h \
    edge.h \
    groupedcsvparser.h \
    groupedstudents.h \
    groupvisualiser.h \
    imperfectmergegrouper.h \
    node.h \
    student.h \
    studentgroup.h \
    studentpreference.h \
    studentset.h \
    unidirectionaledge.h

SOURCES += \
    tst_studentgroupertestcase.cpp \
    backendadaptor.cpp \
    basegrouper.cpp \
    bidirectionaledge.cpp \
    csvparser.cpp \
    edge.cpp \
    groupedcsvparser.cpp \
    groupedstudents.cpp \
    groupvisualiser.cpp \
    imperfectmergegrouper.cpp \
    node.cpp \
    student.cpp \
    studentgroup.cpp \
    studentpreference.cpp \
    studentset.cpp \
    unidirectionaledge.cpp

