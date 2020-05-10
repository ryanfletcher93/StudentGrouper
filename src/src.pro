QT += core gui widgets

CONFIG += ordered

CONFIG += c++11

VPATH += \
    $$PWD/algorithm \
    $$PWD/gui \
    $$PWD/parser \
    $$PWD/students \
    $$PWD/app

SOURCES += \
    algorithmbackend.cpp \
    basegrouper.cpp \
    imperfectmergegrouper.cpp \
    kernighanlinalgorithm.cpp \
    main.cpp \
    bidirectionaledge.cpp \
    edge.cpp \
    groupvisualiser.cpp \
    node.cpp \
    unidirectionaledge.cpp \
    mainwindow.cpp \
    csvparser.cpp \
    groupedcsvparser.cpp \
    groupedstudents.cpp \
    student.cpp \
    studentpreference.cpp \
    studentset.cpp


HEADERS += \
    algorithmbackend.h \
    basegrouper.h \
    imperfectmergegrouper.h \
    kernighanlinalgorithm.h \
    bidirectionaledge.h \
    edge.h \
    groupvisualiser.h \
    node.h \
    unidirectionaledge.h \
    mainwindow.h \
    csvparser.h \
    groupedcsvparser.h \
    groupedstudents.h \
    student.h \
    studentpreference.h \
    studentset.h

FORMS += \
    mainwindow.ui
