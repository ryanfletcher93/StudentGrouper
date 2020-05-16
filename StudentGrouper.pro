TEMPLATE = subdirs

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += ordered

CONFIG += c++14

VPATH += \
    $$PWD/src/gui \
    $$PWD/src/algorithm \
    $$PWD/src/parser \
    $$PWD/src/students \
    $$PWD/src/app

SUBDIRS += \
    src \
    test

INCLUDEPATH += C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googletest\\include \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock \
    C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\google-test\\googlemock\\include

# Default rules for deployment.
target.path = .\\src\\bin
# else: unix:!android: target.path = C:\\Users\\Ryan\ Fletcher\\Documents\\Programming\ Projects\\Qt\\StudentGrouper\\bin
!isEmpty(target.path): INSTALLS += target
