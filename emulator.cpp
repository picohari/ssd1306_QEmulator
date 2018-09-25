/*
emulator.cpp - emulator window implementation

Copyright (C) 2015  Balázs Kóti (ktibalazs@gmail.com)

This file is part of Adafruit SSD1306 OLED screen emulator for development.

Foobar is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "emulator.h"
#include "ui_emulator.h"

#include <QLayout>
#include <QThread>
#include <QDebug>
#include <QFontDatabase>

// Many (but maybe not all) non-AVR board installs define macros
// for compatibility with existing PROGMEM-reading AVR code.
// Do our own checks and defines here for good measure...

#ifndef pgm_read_byte
 #define pgm_read_byte(addr) (*(const unsigned char *)(addr))
#endif
#ifndef pgm_read_word
 #define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif
#ifndef pgm_read_dword
 #define pgm_read_dword(addr) (*(const unsigned long *)(addr))
#endif

// Pointers are a peculiar case...typically 16-bit on AVR boards,
// 32 bits elsewhere.  Try to accommodate both...

#if !defined(__INT_MAX__) || (__INT_MAX__ > 0xFFFF)
 #define pgm_read_pointer(addr) ((void *)pgm_read_dword(addr))
#else
 #define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))
#endif

#define usleep(us) QApplication::processEvents(QEventLoop::AllEvents);\
                    Sleeper::msleep(us/1000);
#define sleep(s) QApplication::processEvents(QEventLoop::AllEvents);\
                    Sleeper::sleep(s);

#include "font/FreeSans12pt7b.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    /* Setup MainWindow */
    ui->setupUi(this);

    QLayout* centralLayout = new QVBoxLayout;
    centralLayout->setSpacing(0);
    centralLayout->setMargin(0);
    ui->centralWidget->setLayout(centralLayout);

    /* Create Emulator Widget */
    Adafruit_SSD1306* emulator = new Adafruit_SSD1306;

    //emulator->show();
    emulator->setEmulatorZoom(2);
    emulator->setSpeedEmulation(false);

    /* Connect Emulator to centralWidget */
    ui->centralWidget->layout()->addWidget(emulator);

    /* Create Window Title and Icon */
    this->setWindowTitle("Adafruit OLED emulator ("
            +QString::number(emulator->device_width()  * emulator->getEmulatorZoom()) + "x"
            +QString::number(emulator->device_height() * emulator->getEmulatorZoom()) + ")");

    this->setWindowIcon(QIcon(":/res/icon"));
    
    /* Resize Window */
    this->setFixedSize(emulator->device_width()  * emulator->getEmulatorZoom(), 
                       emulator->device_height() * emulator->getEmulatorZoom() + 
                       this->menuBar()->size().height() +
                       this->menuBar()->size().height());

    this->statusBar()->setSizeGripEnabled(false);


    /* Initialize Emulator */
    int oled_type = OLED_ADAFRUIT_I2C_128x64;
    if (emulator->oled_is_spi_proto(oled_type)){
        //SPI change parameters to fit to your LCD
        if ( !emulator->init(OLED_SPI_DC,OLED_SPI_RESET,OLED_SPI_CS, oled_type) )
            exit(EXIT_FAILURE);
    }
    else{
        //I2C change parameters to fit to your LCD
        if ( !emulator->init(OLED_I2C_RESET, oled_type) )
            exit(EXIT_FAILURE);
    }
    emulator->begin();


    /* Initialize Screen */
    emulator->clearDisplay();   // clears the screen and buffer

    emulator->setTextSize(1);
    emulator->setTextColor(WHITE);
    

    /* INSERT CODE HERE */

    emulator->setFont(&FreeSans12pt7b);
    emulator->setCursor(0,61);

    static char tmp[36] = {0};
    sprintf(tmp, "%s", "Hallo Welt!");
    emulator->print(tmp);
    //emulator->print("Hallo Welt!");



    /* END CODE */

    emulator->display();

    this->statusBar()->showMessage("Loaded SSD1603");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}






Adafruit_SSD1306::Adafruit_SSD1306(QWidget *parent) : 

    QWidget(parent)
{

    //create the buffer
    buffer = new QPixmap*[2];
    for (int i = 0; i < 2; ++i) {
        buffer[i] = new QPixmap(screenWidth,screenHeight);
        buffer[i]->fill(BLACK);
    }

    writeBuffer = buffer[0];
    dispBuffer = buffer[1];
    writeBufferID = 0;
    dispBufferID = 1;

    //initialite
    screenWidth = 128;
    screenHeight = 64;

    emulatorZoom = 2;

    cursorX = 0;
    cursorY = 0;
    textColor = BLACK;
    textSize = 1;

    //checkers
    began = false;
    initialized = false;

    speedEmultaion = true;

    // Qt based font
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/font/pixelmix");
    pixelFont.setFamily("pixelmix");
    pixelFont.setStyleStrategy(QFont::NoAntialias);
    pixelFont.setStyleHint(QFont::Monospace);
    //pixelFont.setPointSize(10);
    pixelFont.setFixedPitch(true);
    pixelFont.setPixelSize(8);

    // Adafruit fonts (via drawPixel)
    wrap      = true;
    gfxFont   = NULL;
}

Adafruit_SSD1306::~Adafruit_SSD1306()
{

}

void Adafruit_SSD1306::paintEvent(QPaintEvent *){
    //speed emulation
    //if(speedEmultaion)
    //    Sleeper::msleep(40);

    //draw screen
    QPainter p( this );
    p.drawPixmap(0,0,screenWidth*emulatorZoom,
                 screenHeight*emulatorZoom,*buffer[dispBufferID]);
}

void Adafruit_SSD1306::checkState(){
    QMessageBox* msg = new QMessageBox;
    msg->setText(QString("DEVELOPMENT WARNING"));
    if(!initialized){
        msg->setInformativeText("You forgot 'init(...)'!");
        msg->exec();
    }
    if(!began){
        msg->setInformativeText(QString("You forgot 'begin()'!"));
        msg->exec();
    }
}





bool Adafruit_SSD1306::oled_is_spi_proto(int device){
    //NOT SPI
    return false;
}

bool Adafruit_SSD1306::init(int a, int b, int c, int oled_type){
    return init(b,oled_type);
}

bool Adafruit_SSD1306::init(int a, int oled_type){

    switch(oled_type){
        case OLED_ADAFRUIT_SPI_128x32:
        case OLED_ADAFRUIT_I2C_128x32:
            screenWidth = 128;
            screenHeight = 32;
            break;
        case OLED_ADAFRUIT_SPI_128x64:
        case OLED_ADAFRUIT_I2C_128x64:
        default:
            screenWidth = 128;
            screenHeight = 64;
            break;
    }

/*
    this->setWindowTitle("Adafruit OLED emulator ("
                         +QString::number(screenWidth * emulatorZoom)+"x"
                         +QString::number(screenHeight * emulatorZoom)+")");
*/

    //create the buffer
    for (int i = 0; i < 2; ++i) {
        buffer[i] = new QPixmap(screenWidth,screenHeight);
        buffer[i]->fill(BLACK);
    }

    writeBuffer = buffer[0];
    dispBuffer = buffer[1];
    writeBufferID = 0;
    dispBufferID = 1;

/*
    //set screen size
    this->setFixedSize(screenWidth*emulatorZoom,
                       screenHeight*emulatorZoom);
*/
    //successfully initialized
    this->initialized = true;
    return true;
}

void Adafruit_SSD1306::begin(){
    this->began = true;
    return;
}

void Adafruit_SSD1306::close(){
    this->began = false;
    return;
}

void Adafruit_SSD1306::display(){
    checkState();

    //swap buffers
    int temp = dispBufferID;
    dispBufferID = writeBufferID;
    writeBufferID = temp;

    //set active write buffer
    writeBuffer = buffer[writeBufferID];
    dispBuffer = buffer[dispBufferID];

    //copy actual screen to new buffer
    QPainter p(writeBuffer);
    p.drawPixmap(0,0,screenWidth,screenHeight,*dispBuffer);

    this->repaint();
}

void Adafruit_SSD1306::clearDisplay(){
    QPainter p(writeBuffer);
    p.setPen(Qt::black);
    p.setBrush(Qt::black);
    p.drawRect(0,0,writeBuffer->width(),writeBuffer->height());
}

void Adafruit_SSD1306::drawPixel(int x, int y, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.drawPoint(x,y);
}

void Adafruit_SSD1306::drawLine(int x0, int y0, int x1, int y1, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.drawLine(x0,y0,x1,y1);
}

void Adafruit_SSD1306::drawRect(int x, int y, int w, int h, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.setBrush(Qt::NoBrush);
    p.drawRect(x,y,w,h);
}

void Adafruit_SSD1306::fillRect(int x, int y, int w, int h, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.setBrush(color);
    p.drawRect(x,y,w,h);
}

void Adafruit_SSD1306::drawCircle(int x, int y, int r, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.setBrush(Qt::NoBrush);
    QPoint center(x,y);
    p.drawEllipse(center,r,r);
}

void Adafruit_SSD1306::fillCircle(int x, int y, int r, QColor color){
    QPainter p(writeBuffer);
    p.setPen(color);
    p.setBrush(color);
    QPoint center(x,y);
    p.drawEllipse(center,r,r);
}

void Adafruit_SSD1306::drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, QColor color){
    //check if size is valid
    if(w%8 != 0 || h%8 != 0){
        qWarning() << "Width and Height of bitmap shold be multiply of 8 (widht % 8 = 0)";
        return;
    }

    //GENERATE PIXMAP FROM BITMAP
    QPixmap temp(w,h);
    temp.fill(Qt::transparent);

    QPainter tempPaint(&temp);
    tempPaint.setPen(color);

    for(int i = 0; i < w*h; i++){
        bool value = (bitmap[i/8] >> (7-(i%8))) & 0x01 == 0x01 ? true : false;
        if(value){
            tempPaint.drawPoint(i%w,i/w);
        }
    }

    QPainter p(writeBuffer);
    p.drawPixmap(x,y,w,h,temp);
}

void Adafruit_SSD1306::setCursor(int x, int y){
    this->cursorX = x;
    this->cursorY = y;
}

void Adafruit_SSD1306::setTextColor(QColor color){
    this->textColor = color;
}

void Adafruit_SSD1306::setTextSize(int size){
    this->textSize = size;
    pixelFont.setPixelSize(8*textSize);
}

void Adafruit_SSD1306::setFont(const GFXfont *f) {

    if(f) {            // Font struct pointer passed in?
        if(!gfxFont) { // And no current font struct?
            // Switching from classic to new font behavior.
            // Move cursor pos down 6 pixels so it's on baseline.
            cursorY += 6;
        }
    } else if(gfxFont) { // NULL passed.  Current font struct defined?
        // Switching from new to classic font behavior.
        // Move cursor pos up 6 pixels so it's at top-left of char.
        cursorY -= 6;
    }

    gfxFont = (GFXfont *)f;
}

void Adafruit_SSD1306::println(){

    cursorY += 8;
    cursorX =  0;          // Advance x one char
}

void Adafruit_SSD1306::print(const char *string){

/*
    // Use pixelmix font
    QString s(string);

    QPainter p(writeBuffer);
    p.setPen(textColor);
    p.setFont(pixelFont);
    p.drawText(cursorX,cursorY+7*textSize,s);
*/

    // Use Adafruit variable font
    uint8_t i;

    while (string[i] != '\0')
        write(string[i++]);
}

void Adafruit_SSD1306::drawChar(int16_t x, int16_t y, unsigned char c, QColor color, QColor bg, uint8_t size) {

    #include "glcdfont.c"

    if(!gfxFont) { // 'Classic' built-in font

        if((x >= screenWidth)            || // Clip right
           (y >= screenHeight)           || // Clip bottom
           ((x + 6 * size - 1) < 0)      || // Clip left
           ((y + 8 * size - 1) < 0))        // Clip top
            return;

        if(true && (c >= 176)) c++; // Handle 'classic' charset behavior

        //startWrite();
        for(uint8_t i=0; i<5; i++ ) { // Char bitmap = 5 columns
            
            uint8_t line = pgm_read_byte(&font[c * 5 + i]);
            
            for(int8_t j=0; j<8; j++, line >>= 1) {
                if(line & 1) {
                    if(size == 1)
                        drawPixel(x+i, y+j, color);
                    else
                        fillRect(x+i*size, y+j*size, size, size, color);
                } else if(bg != color) {
                    if(size == 1)
                        drawPixel(x+i, y+j, bg);
                    else
                        fillRect(x+i*size, y+j*size, size, size, bg);
                }
            }
        }
        if(bg != color) { // If opaque, draw vertical line for last column
            if(size == 1) drawLine(x+5, y, x+5, y+8, bg);
            else          fillRect(x+5*size, y, size, 8*size, bg);
        }
        //endWrite();


    } else { // Custom font

        // Character is assumed previously filtered by write() to eliminate
        // newlines, returns, non-printable characters, etc.  Calling
        // drawChar() directly with 'bad' characters of font may cause mayhem!

        c -= (uint8_t)pgm_read_byte(&gfxFont->first);
        GFXglyph *glyph  = &(((GFXglyph *)pgm_read_pointer(&gfxFont->glyph))[c]);
        unsigned int  *bitmap = (unsigned int *)pgm_read_pointer(&gfxFont->bitmap);

        uint16_t bo = pgm_read_word(&glyph->bitmapOffset);
        uint8_t  w  = pgm_read_byte(&glyph->width),
                 h  = pgm_read_byte(&glyph->height);
        int8_t   xo = pgm_read_byte(&glyph->xOffset),
                 yo = pgm_read_byte(&glyph->yOffset);
        uint8_t  xx, yy, bits = 0, bit = 0;
        int16_t  xo16 = 0, yo16 = 0;

        if(size > 1) {
            xo16 = xo;
            yo16 = yo;
        }

        // Todo: Add character clipping here

        // NOTE: THERE IS NO 'BACKGROUND' COLOR OPTION ON CUSTOM FONTS.
        // THIS IS ON PURPOSE AND BY DESIGN.  The background color feature
        // has typically been used with the 'classic' font to overwrite old
        // screen contents with new data.  This ONLY works because the
        // characters are a uniform size; it's not a sensible thing to do with
        // proportionally-spaced fonts with glyphs of varying sizes (and that
        // may overlap).  To replace previously-drawn text when using a custom
        // font, use the getTextBounds() function to determine the smallest
        // rectangle encompassing a string, erase the area with fillRect(),
        // then draw new text.  This WILL infortunately 'blink' the text, but
        // is unavoidable.  Drawing 'background' pixels will NOT fix this,
        // only creates a new set of problems.  Have an idea to work around
        // this (a canvas object type for MCUs that can afford the RAM and
        // displays supporting setAddrWindow() and pushColors()), but haven't
        // implemented this yet.

        //startWrite();
        for(yy=0; yy<h; yy++) {
            for(xx=0; xx<w; xx++) {
                if(!(bit++ & 7)) {
                    bits = pgm_read_byte(&bitmap[bo++]);
                }
                if(bits & 0x80) {
                    if(size == 1) {
                        drawPixel(x+xo+xx, y+yo+yy, color);
                    } else {
                        fillRect(x+(xo16+xx)*size, y+(yo16+yy)*size,
                          size, size, color);
                    }
                }
                bits <<= 1;
            }
        }
        //endWrite();

    } // End classic vs custom font

}

size_t Adafruit_SSD1306::write(uint8_t c){

/*
    //QString s = QChar((char)c);
    //QString s = QChar(c).toAscii();
    QString s = QChar(c);

    QPainter p(writeBuffer);
    p.setPen(textColor);
    p.setFont(pixelFont);
    p.drawText(cursorX, cursorY+7*textSize, s);
    cursorX += 6;          // Advance x one char
*/

    if(!gfxFont) { // 'Classic' built-in font

        if(c == '\n') {                        // Newline?
            cursorX  = 0;                     // Reset x to zero,
            cursorY += textSize * 8;          // advance y one line
        } else if(c != '\r') {                 // Ignore carriage returns
            if(wrap && ((cursorX + textSize * 6) > screenWidth)) { // Off right?
                cursorX  = 0;                 // Reset x to zero,
                cursorY += textSize * 8;      // advance y one line
            }
            drawChar(cursorX, cursorY, c, WHITE, BLACK, textSize);
            cursorX += textSize * 6;          // Advance x one char
        }

    } else { // Custom font

        if(c == '\n') {
            cursorX  = 0;
            cursorY += (int16_t)textSize *
                        (uint8_t)pgm_read_byte(&gfxFont->yAdvance);
        } else if(c != '\r') {
            uint8_t first = pgm_read_byte(&gfxFont->first);
            if((c >= first) && (c <= (uint8_t)pgm_read_byte(&gfxFont->last))) {
                GFXglyph *glyph = &(((GFXglyph *)pgm_read_pointer(
                  &gfxFont->glyph))[c - first]);
                uint8_t   w     = pgm_read_byte(&glyph->width),
                          h     = pgm_read_byte(&glyph->height);
                if((w > 0) && (h > 0)) { // Is there an associated bitmap?
                    int16_t xo = (int8_t)pgm_read_byte(&glyph->xOffset); // sic
                    if(wrap && ((cursorX + textSize * (xo + w)) > screenWidth)) {
                        cursorX  = 0;
                        cursorY += (int16_t)textSize *
                          (uint8_t)pgm_read_byte(&gfxFont->yAdvance);
                    }
                    drawChar(cursorX, cursorY, c, WHITE, BLACK, textSize);
                }
                cursorX += (uint8_t)pgm_read_byte(&glyph->xAdvance) * (int16_t)textSize;
            }
        }

    }

    return 1;
}















void Adafruit_SSD1306::drawPixel(int x,int y, int color){
    if(color)
        drawPixel(x,y,WHITE);
    else
        drawPixel(x,y,BLACK);
}

void Adafruit_SSD1306::drawLine(int x0, int y0, int x1, int y1, int color){
    if(color)
        drawLine(x0,y0,x1,y1,WHITE);
    else
        drawLine(x0,y0,x1,y1,BLACK);
}

void Adafruit_SSD1306::drawRect(int x, int y, int w, int h, int color){
    if(color)
        drawRect(x,y,w,h,WHITE);
    else
        drawRect(x,y,w,h,BLACK);
}

void Adafruit_SSD1306::fillRect(int x, int y, int w, int h, int color){
    if(color)
        fillRect(x,y,w,h,WHITE);
    else
        fillRect(x,y,w,h,BLACK);
}

void Adafruit_SSD1306::drawCircle(int x, int y, int r, int color){
    if(color)
        drawCircle(x,y,r,WHITE);
    else
        drawCircle(x,y,r,BLACK);
}

void Adafruit_SSD1306::fillCircle(int x, int y, int r, int color){
    if(color)
        fillCircle(x,y,r,WHITE);
    else
        fillCircle(x,y,r,BLACK);
}

void Adafruit_SSD1306::drawBitmap(int x, int y, const unsigned char *bitmap, int w, int h, int color){
    if(color)
        drawBitmap(x,y,bitmap,w,h,WHITE);
    else
        drawBitmap(x,y,bitmap,w,h,BLACK);
}


/* UTILS */

void Adafruit_SSD1306::setRotation(int r){
    //no rotation in development
    return;
}

int Adafruit_SSD1306::device_width(){
    return screenWidth;
}

int Adafruit_SSD1306::device_height(){
    return screenHeight;
}

void Adafruit_SSD1306::setSpeedEmulation(bool enable){
    this->speedEmultaion = enable;
}

int Adafruit_SSD1306::getEmulatorZoom(){
    return emulatorZoom;
}

void Adafruit_SSD1306::setEmulatorZoom(int z){
    //set zoom
    emulatorZoom = z;

/*
    //set screen size
    this->setFixedSize(screenWidth  * emulatorZoom,
                       screenHeight * emulatorZoom);
*/
}

