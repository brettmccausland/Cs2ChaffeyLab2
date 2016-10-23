TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fprocess.cpp \
    courses.cpp \
    node.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fprocess.h \
    courses.h \
    node.h

