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

#CONFIG  += qtestlib

SOURCES += \
    main.cpp \
    aboutdialog.cpp \
    mainwindow.cpp \
    emulator_ssd1306.cpp \
    # emulator_keypad.cpp \
    ../../libraries/Adafruit_GFX_Library/glcdfont.c \
    ../../libraries/Adafruit_GFX_Menu/Adafruit_GFX_Menu.cpp \
    ../../libraries/Adafruit_Keyboard/Adafruit_Keyboard.cpp \

HEADERS += \
    aboutdialog.h \
    app_types.h \
    mainwindow.h \
    emulator_ssd1306.h \
    # emulator_keypad.h \
    ../../libraries/Adafruit_GFX_Library/gfxfont.h \
    ../../libraries/Adafruit_GFX_Menu/Adafruit_GFX_Menu.h \
    ../../libraries/Adafruit_Keyboard/Adafruit_Keyboard.h \
    ../../libraries/Adafruit_Keyboard/list.h

INCLUDEPATH += \
    ../../libraries/Adafruit_GFX_Menu/ \
    ../../libraries/Adafruit_GFX_Library/ \     # font.h
    ../../libraries/Adafruit_SSD1306/ \
    ../../libraries/Adafruit_Keyboard/ \

FORMS += \
    aboutdialog.ui \
    mainwindow.ui \

RESOURCES += \
    emulator.qrc \
    about.qrc



DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M:%S')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%d.%m.%y')\\\"
