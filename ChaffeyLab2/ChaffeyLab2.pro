TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    fprocess.h \
    courses.h \
    node.h \
    ccc_empl.h \
    staff.h

