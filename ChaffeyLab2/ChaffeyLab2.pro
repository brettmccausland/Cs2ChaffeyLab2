TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fprocess.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fprocess.h

