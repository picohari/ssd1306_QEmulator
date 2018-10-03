/*
emulator.h - emulator window class header

Copyright (C) 2015  Balázs Kóti (ktibalazs@gmail.com)
Copyright (C) 2018  DK6YF (picohari@gmail.com)

This file is part of Adafruit SSD1306 OLED screen emulator for development.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/



#ifndef EMULATOR_H
#define EMULATOR_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QThread>
#include <QFont>

#include <QMessageBox>

#include <QDebug>

#include "../../libraries/Adafruit_GFX_Library/gfxfont.h"

//colors
#define BLACK QColor(0,0,0)
#define WHITE QColor(222,239,232)

//fake constants
#define OLED_SPI_RESET              0
#define OLED_SPI_DC                 0
#define OLED_SPI_CS0                0
#define OLED_SPI_CS1                0
#define OLED_SPI_CS                 0
#define OLED_I2C_RESET              0
#define ADAFRUIT_I2C_ADDRESS        0
#define SEEEED_I2C_ADDRESS          0
#define	OLED_ADAFRUIT_SPI_128x32	0
#define	OLED_ADAFRUIT_SPI_128x64	1
#define	OLED_ADAFRUIT_I2C_128x32	2
#define	OLED_ADAFRUIT_I2C_128x64	3
#define	OLED_SEEED_I2C_128x64		4
#define	OLED_SEEED_I2C_96x96        5
#define OLED_LAST_OLED				6 /* always last type, used in code to end array */

#define SSD1306_LCDWIDTH            128
#define SSD1306_LCDHEIGHT           64

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};


class Adafruit_SSD1306 : public QWidget
{
    Q_OBJECT

public:
    Adafruit_SSD1306(QWidget *parent = 0);
    ~Adafruit_SSD1306();

    void checkState();
    void setEmulatorZoom(int z);
    void setSpeedEmulation(bool enable);

    bool oled_is_spi_proto(int device);
    bool init(int a, int b, int c, int oled_type);
    bool init(int a, int oled_type);

    void begin();
    void close();

    void clearDisplay();

    void drawPixel(int x,int y, QColor color);
    void drawLine(int x0, int y0, int x1, int y1, QColor color);
    void drawRect(int x, int y, int w, int h, QColor color);
    void fillRect(int x, int y, int w, int h, QColor color);
    void drawCircle(int x, int y, int r, QColor color);
    void fillCircle(int x, int y, int r, QColor color);
    void drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, QColor color);
    void drawChar(int16_t x, int16_t y, unsigned char c, QColor color, QColor bg, uint8_t size);

    void drawPixel(int x,int y, int color);
    void drawLine(int x0, int y0, int x1, int y1, int color);
    void drawRect(int x, int y, int w, int h, int color);
    void fillRect(int x, int y, int w, int h, int color);
    void drawCircle(int x, int y, int r, int color);
    void fillCircle(int x, int y, int r, int color);
    void drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, int color);

    //font drawing
    void setCursor(int x, int y);
    void setTextColor(QColor color);
    void setTextSize(int size);
    void print(const char * string);
    size_t write(uint8_t c);
    void println();
    void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
    void setFont(const GFXfont *f);

    //device height/width
    int device_height();
    int device_width();

    void setRotation(int r);
    int getEmulatorZoom();
    void display();


protected:
    GFXfont     *gfxFont;       ///< Pointer to special font
    bool        wrap;           ///< If set, 'wrap' text at right edge of display

    void paintEvent ( QPaintEvent* );
    //void keyPressEvent ( QKeyEvent* );


private:
    QPixmap** buffer;
    QPixmap *writeBuffer,*dispBuffer;
    int dispBufferID,writeBufferID;

    //screen
    int screenWidth, screenHeight;
    int emulatorZoom;

    //fonts and text writing
    QFont pixelFont;
    int cursorX, cursorY;
    QColor textColor;
    int textSize;

    //checkers
    bool began;
    bool initialized;

    //speed emulation
    bool speedEmultaion;

};


/* Pointer to current display driver instance */
extern Adafruit_SSD1306 *display;

#endif // EMULATOR_H
