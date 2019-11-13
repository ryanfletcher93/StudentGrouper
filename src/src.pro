QT       += core gui

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
    backendadaptor.cpp \
    basegrouper.cpp \
    csvparser.cpp \
    edge.cpp \
    groupedstudents.cpp \
    groupvisualiser.cpp \
    imperfectmergegrouper.cpp \
    main.cpp \
    mainwindow.cpp \
    node.cpp \
    student.cpp \
    studentpreference.cpp \
    studentset.cpp \

HEADERS += \
    backendadaptor.h \
    basegrouper.h \
    csvparser.h \
    edge.h \
    groupedstudents.h \
    groupvisualiser.h \
    imperfectmergegrouper.h \
    mainwindow.h \
    node.h \
    student.h \
    studentpreference.h \
    studentset.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest\\include \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock\\include

# Default rules for deployment.
target.path = C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\src\\bin
# else: unix:!android: target.path = C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\bin
!isEmpty(target.path): INSTALLS += target
