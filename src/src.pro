QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithm/algorithmbackend.cpp \
    algorithm/basegrouper.cpp \
    algorithm/imperfectmergegrouper.cpp \
    algorithmbackend.cpp \
    basegrouper.cpp \
    bidirectionaledge.cpp \
    csvparser.cpp \
    edge.cpp \
    groupedcsvparser.cpp \
    groupedstudents.cpp \
    groupvisualiser.cpp \
    gui/bidirectionaledge.cpp \
    gui/edge.cpp \
    gui/groupvisualiser.cpp \
    gui/mainwindow.cpp \
    gui/node.cpp \
    gui/unidirectionaledge.cpp \
    imperfectmergegrouper.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    parser/csvparser.cpp \
    parser/groupedcsvparser.cpp \
    student.cpp \
    studentpreference.cpp \
    students/groupedstudents.cpp \
    students/student.cpp \
    students/studentpreference.cpp \
    students/studentset.cpp \
    students/studentsetanalyser.cpp \
    studentset.cpp \
    unidirectionaledge.cpp

HEADERS += \
    algorithm/algorithmbackend.h \
    algorithm/basegrouper.h \
    algorithm/imperfectmergegrouper.h \
    algorithmbackend.h \
    basegrouper.h \
    bidirectionaledge.h \
    csvparser.h \
    edge.h \
    groupedcsvparser.h \
    groupedstudents.h \
    groupvisualiser.h \
    gui/bidirectionaledge.h \
    gui/edge.h \
    gui/groupvisualiser.h \
    gui/mainwindow.h \
    gui/node.h \
    gui/unidirectionaledge.h \
    imperfectmergegrouper.h \
    mainwindow.h \
    node.h \
    parser/csvparser.h \
    parser/groupedcsvparser.h \
    student.h \
    studentpreference.h \
    students/groupedstudents.h \
    students/student.h \
    students/studentpreference.h \
    students/studentset.h \
    studentset.h \
    unidirectionaledge.h

FORMS += \
    gui/mainwindow.ui \
    mainwindow.ui

INCLUDEPATH += C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest\\include \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock\\include

# Default rules for deployment.
target.path = C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\src\\bin
# else: unix:!android: target.path = C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\bin
!isEmpty(target.path): INSTALLS += target
