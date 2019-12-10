#-------------------------------------------------
#
# Project created by QtCreator 2019-01-04T20:43:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Citadel_Defence
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    staticobject.cpp \
    movingobject.cpp \
    game.cpp \
    orc.cpp \
    knight.cpp \
    goblin.cpp \
    catapult.cpp \
    ram.cpp \
    barricade.cpp \
    citadel.cpp \
    attack.cpp \
    orcfactory.cpp \
    goblinfactory.cpp \
    barricadefactory.cpp \
    knightfactory.cpp \
    catapultfactory.cpp \
    ramfactory.cpp

HEADERS += \
        widget.h \
    staticobject.h \
    movingobject.h \
    drawable.h \
    positional.h \
    game.h \
    moveable.h \
    attack.h \
    orc.h \
    knight.h \
    goblin.h \
    catapult.h \
    ram.h \
    barricade.h \
    citadel.h \
    unitfactory.h \
    orcfactory.h \
    goblinfactory.h \
    barricadefactory.h \
    knightfactory.h \
    catapultfactory.h \
    ramfactory.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    textures.qrc
