QT += core gui widgets

CONFIG += ordered

VPATH += \
    $$PWD/algorithm \
    $$PWD/gui \
    $$PWD/parser \
    $$PWD/students \
    $$PWD/app

SOURCES += \
    progressupdator.cpp \
    algorithmbackend.cpp \
    basegrouper.cpp \
    kernighanlingrouper.cpp \
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
    progressupdator.h \
    algorithmbackend.h \
    basegrouper.h \
    kernighanlingrouper.h \
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
