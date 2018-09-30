#-------------------------------------------------
#
# Project created by QtCreator 2018-09-23T22:09:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SSD1306_Emulator
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


SOURCES += \
    main.cpp \
    emulator.cpp \
    glcdfont.c \
    aboutdialog.cpp \
    mainwindow.cpp \
    ../../libraries/Adafruit_GFX_Menu/Adafruit_GFX_Menu.cpp \

HEADERS += \
    emulator.h \
    gfxfont.h \
    aboutdialog.h \
    app_types.h \
    mainwindow.h \
    ../../libraries/Adafruit_GFX_Menu/Adafruit_GFX_Menu.h \

INCLUDEPATH += \
    ../../libraries/Adafruit_GFX_Menu/ \
    ../../libraries/Adafruit_GFX_Library/ \
    ../../libraries/Adafruit_SSD1306/ \

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \

RESOURCES += \
    emulator.qrc \
    about.qrc



DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M:%S')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%d.%m.%y')\\\"
