QT += testlib
QT += gui
QT += core gui
QT += widgets
QT += testlib

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

VPATH += ../src/

INCLUDEPATH += \
    ../src/algorithm \
    ../src/students \

HEADERS += \
    kernighanlinalgorithmtest.h

SOURCES += \
    students/student.cpp \
    students/studentpreference.cpp \
    students/studentset.cpp \
    students/groupedstudents.cpp \
    algorithm/kernighanlingrouper.cpp \
    algorithm/basegrouper.cpp \
    kernighanlinalgorithmtest.cpp \
    main.cpp

