#-------------------------------------------------
#
# Project created by QtCreator 2017-01-27T23:15:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    card.cpp

HEADERS  += mainwindow.h \
defines.h \
    player.h \
    card.h

FORMS    += mainwindow.ui

DISTFILES += \
    cards/0_0.png \
    cards/0_1.png \
    cards/0_10.png \
    cards/0_11.png \
    cards/0_12.png \
    cards/0_2.png \
    cards/0_3.png \
    cards/0_4.png \
    cards/0_5.png \
    cards/0_6.png \
    cards/0_7.png \
    cards/0_8.png \
    cards/0_9.png \
    cards/1_0.png \
    cards/1_1.png \
    cards/1_10.png \
    cards/1_12.png \
    cards/1_2.png \
    cards/1_3.png \
    cards/1_4.png \
    cards/1_5.png \
    cards/1_6.png \
    cards/1_7.png \
    cards/1_8.png \
    cards/1_9.png \
    cards/2_0.png \
    cards/2_1.png \
    cards/2_10.png \
    cards/2_11.png \
    cards/2_12.png \
    cards/2_2.png \
    cards/2_3.png \
    cards/2_4.png \
    cards/2_5.png \
    cards/2_6.png \
    cards/2_7.png \
    cards/2_8.png \
    cards/2_9.png \
    cards/3_0.png \
    cards/3_1.png \
    cards/3_10.png \
    cards/3_11.png \
    cards/3_12.png \
    cards/3_2.png \
    cards/3_3.png \
    cards/3_4.png \
    cards/3_5.png \
    cards/3_6.png \
    cards/3_7.png \
    cards/3_8.png \
    cards/3_9.png
