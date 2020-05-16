QT += testlib
QT += gui
QT += core gui
QT += widgets

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

VPATH += ../src

SOURCES += \
    algorithm/algorithmbackend.cpp \
    algorithm/basegrouper.cpp \
    algorithm/kernighanlingrouper.cpp \
    gui/bidirectionaledge.cpp \
    gui/edge.cpp \
    gui/groupvisualiser.cpp \
    gui/node.cpp \
    gui/unidirectionaledge.cpp \
    gui/mainwindow.cpp \
    app/main.cpp \
    parser/csvparser.cpp \
    parser/groupedcsvparser.cpp \
    students/groupedstudents.cpp \
    students/student.cpp \
    students/studentpreference.cpp \
    students/studentset.cpp

HEADERS += \
    algorithm/algorithmbackend.h \
    algorithm/basegrouper.h \
    algorithm/kernighanlingrouper.h \
    gui/bidirectionaledge.h \
    gui/edge.h \
    gui/groupvisualiser.h \
    gui/node.h \
    gui/unidirectionaledge.h \
    gui/mainwindow.h \
    parser/csvparser.h \
    parser/groupedcsvparser.h \
    students/groupedstudents.h \
    students/student.h \
    students/studentpreference.h \
    students/studentset.h

