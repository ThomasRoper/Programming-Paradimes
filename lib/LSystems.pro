#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T13:13:08
#
#-------------------------------------------------

QT       -= gui

TARGET = LSystems
TEMPLATE = lib

DEFINES += LSYSTEMS_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        lsystems.cpp \
    turtle.cpp \
    system.cpp

HEADERS += \
        lsystems.h \
        lsystems_global.h \ 
    turtle.h \
    vec3.h \
    system.h

unix {
    target.path = .
    INSTALLS += target
}
