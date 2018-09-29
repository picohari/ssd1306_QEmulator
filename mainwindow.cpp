

#include "app_types.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "emulator.h"

#include "aboutdialog.h"
#include "ui_aboutdialog.h"


/* Include font files here */
#include "font/FreeSans12pt7b.h"
#include "font/FreeSans9pt7b.h"
#include "font/mina.h"

//#include <Adafruit_GFX_Menu.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create layout for emulator widget */
    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->setSpacing(0);
    verticalLayout->setMargin(0);
    ui->emulatorContainer->setLayout(verticalLayout);

    /* Create Emulator Widget */
    Adafruit_SSD1306 *emulator = new Adafruit_SSD1306;
    //emulator = new Adafruit_SSD1306;

    /* Set some default parameter */
    emulator->setEmulatorZoom(2);           /* Set zooming level */
    emulator->setSpeedEmulation(false);     /* Set simulation speed */

    /* Connect Emulator to centralWidget */
    ui->emulatorContainer->layout()->addWidget(emulator);

    /* Create Window Title and Icon */
    this->setWindowTitle("Adafruit OLED emulator ("
            +QString::number(emulator->device_width()  * emulator->getEmulatorZoom()) + "x"
            +QString::number(emulator->device_height() * emulator->getEmulatorZoom()) + ")");

    this->setWindowIcon(QIcon(":/res/icon"));
    
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

    /* Get size of keypad so we can determine total height of window */
    QMargins keypad_margins = ui->gridLayout->contentsMargins();
    int keypad_height = ui->gridLayout->sizeHint().height() + 
                        keypad_margins.top() +
                        keypad_margins.bottom();

    //qDebug("%d", margins.top());

    /* Resize Window */
    this->setFixedSize(emulator->device_width()  * emulator->getEmulatorZoom(), 
                       emulator->device_height() * emulator->getEmulatorZoom() + 
                       this->menuBar()->size().height() +
                       this->statusBar()->size().height() +  keypad_height );

    this->statusBar()->setSizeGripEnabled(false);

    this->statusBar()->showMessage("Loaded SSD1603");

#if 1
    /* ==> INSERT CODE HERE - BEGIN <== */

    /* Initialize Screen */
    emulator->clearDisplay();   // clears the screen and buffer

    // Set default color and size
    emulator->setTextSize(1);
    emulator->setTextColor(WHITE);

    // Using Adafruit fonts
    emulator->setFont(&FreeSans12pt7b);
    emulator->setCursor(7,31);
    static char tmp[36] = {0};
    sprintf(tmp, "%s", "Hallo Welt!");
    emulator->print(tmp);
    
    // Using glcdfont
    emulator->setFont(&mina10pt8b);
    emulator->setCursor(0, 10);
    sprintf(tmp, "%s", "All your base are us!");
    emulator->print(tmp);
    
    // Use of standard text
    //emulator->setFont(NULL);
    //emulator->print("All your base are us");

    emulator->drawPixel(0, 0, WHITE);
    emulator->drawPixel(127, 0, WHITE);
    emulator->drawPixel(0, 63, WHITE);
    emulator->drawPixel(127, 63, WHITE);

    /* Must be called at the end to refresh the display */
    emulator->display();
    /* ==> INSERT CODE HERE - END <== */
#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}


void MainWindow::on_pushButton_LEFT_clicked()
{
    qDebug("LEFT");
}

void MainWindow::on_pushButton_RIGHT_clicked()
{
    qDebug("RIGHT");
}

void MainWindow::on_pushButton_UP_clicked()
{
    qDebug("UP");
}

void MainWindow::on_pushButton_DOWN_clicked()
{
    qDebug("DOWN");
}

void MainWindow::on_pushButton_OK_clicked()
{
    qDebug("OK");
}
