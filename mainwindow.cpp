#include <QtGlobal>

#include <QApplication>
#include <QPushButton>
#include <QTimer>


#include <QtTest>
#include <QThread>

#include <unistd.h>
#include <typeinfo>

#include <QDebug>



#include "app_types.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

#include "emulator_ssd1306.h"



#include <Adafruit_Keyboard.h>

#include <MenuSystem.h>


/* Global emulator instance */
MainWindow         *emul_win;

Adafruit_SSD1306   *display;
Adafruit_Keyboard  *emul_kbd;   /* Global keyboard instance */

MenuSystem         *menu_system;


#define PCD8544_CHAR_HEIGHT 10


class MyRenderer : public MenuComponentRenderer {
public:
    

    void render(Menu const& menu) const {

        uint8_t cursor_position = 0;

        uint8_t first_item = 0;
        
        display->clearDisplay();

        // For non-ROOT menu items, display list of menu items
        if (menu.get_name() != "ROOT") {

            display->setFont(&hp58pt8b);
            //display->setFont(NULL);
            display->setTextColor(WHITE, BLACK);
            display->setCursor(0, 4);
            display->print(menu.get_name());

            int ydiff = 16; /* Pixel height to next line */

            MenuComponent const* view_items[16];    /* TODO: Make dynamic here */
            
            // Count elements and find current one 
            for (int i = 0; i < menu.get_num_components(); ++i) {

                    view_items[i] = menu.get_menu_component(i);

                    if( view_items[i]->is_current() ) {
                        cursor_position = i;
                    }

            }

            // Determine starting position in array
            switch (cursor_position) {
                case 0:  first_item = cursor_position - 0; break;
                case 1:  first_item = cursor_position - 1; break;
                default: first_item = cursor_position - 2;
            }

            // Now draw menu items on screen
            for (int i = first_item; i < menu.get_num_components(); ++i) {

                MenuComponent const* cp_m_comp = menu.get_menu_component(i);

                /* Select only MenuItem's */
                if ( dynamic_cast<const     MenuItem*>(cp_m_comp) != NULL ||
                     dynamic_cast<const BackMenuItem*>(cp_m_comp) != NULL ) {

                    /*
                    uint16_t flags = cp_m_comp->read_flags();
                    char tmp[15] = {0};

                    if (cp_m_comp->is_current() && cp_m_comp->read_flags() & MIF_DISABLED) {

                    }
                    */

                    if (cp_m_comp->is_current()) {
                        display->fillRect(0, ydiff-8, 127, 11, WHITE);
                        display->setTextColor(BLACK, WHITE);
                    } else {

                        display->setTextColor(WHITE, BLACK);
                    }

                    display->setFont(&mina10pt8b);
                    display->setCursor(4, ydiff);

                    cp_m_comp->render(*this);
                    
                    //sprintf(tmp, "%d", flags);
                    //display->print(tmp);

                    ydiff += 11;
                }

            }

        // On ROOT-Level, only display content of screens, no menu rendering active
        } else {
            
            //if ( dynamic_cast<const     Menu*>(cp_m_comp) != NULL) {

                menu.get_current_component()->render(*this);
                
            //}
        
        }

        display->display();
    }

    void render_menu_item(MenuItem const& menu_item) const {
        
        display->print(menu_item.get_name());
    }

    void render_back_menu_item(BackMenuItem const& menu_item) const {
        //display->setCursor(0, 1 * PCD8544_CHAR_HEIGHT);
        display->print(menu_item.get_name());
    }

    void render_menu_screen(MenuScreen const& menu_item) const {

        menu_item.show();
    }

    #if 0
    void render_numeric_menu_item(NumericMenuItem const& menu_item) const {
        display->setCursor(0, 1 * PCD8544_CHAR_HEIGHT);
        display->print(menu_item.get_name());
    }
    #endif

    void render_menu(Menu const& menu) const {

        /* Rule to render menus as items inside another menu */

        //display->setFont(&hp58pt8b);
        //display->setTextColor(WHITE, BLACK);
        //display->setCursor(0, 4);
        //display->print(menu.get_name());

        menu.show();
    }
};

MyRenderer my_renderer;





void show_desktop_1(void) {

    display->clearDisplay();
    display->setFont(&mina10pt8b);
    display->setTextColor(WHITE, BLACK);
    display->setCursor(10, 30);
    display->print("Item1 Selectd");
    //display->display();


    display->setFont(&hp58pt8b);
    display->setCursor(50, 62);
    display->print("h  g  g  g");
}

void show_desktop_2(void) {

    display->setFont(&hp58pt8b);
    display->setCursor(50, 62);
    display->print("g  h  g  g");
}

void show_desktop_3(void) {

    display->setFont(&hp58pt8b);
    display->setCursor(50, 62);
    display->print("g  g  h  g");
}

void show_desktop_4(void) {

    display->setFont(&hp58pt8b);
    display->setCursor(50, 62);
    display->print("g  g  g  h");
}


// Menu callback function

void on_item1_selected(MenuComponent* p_menu_component) {
    (void) p_menu_component;

    display->clearDisplay();
    display->setTextColor(WHITE, BLACK);
    display->setCursor(0, 3 * PCD8544_CHAR_HEIGHT);
    display->print("Item1 Selectd");
    display->display();
    //delay(1500); // so we can look the result on the LCD
    QTest::qSleep( 2000 );
}

void on_item2_selected(MenuComponent* p_menu_component) {
    (void) p_menu_component;

    display->clearDisplay();
    display->setTextColor(WHITE, BLACK);
    display->setCursor(0, 3 * PCD8544_CHAR_HEIGHT);
    display->print("Item2 Selectd");
    display->display();
    //delay(1500); // so we can look the result on the LCD
    QTest::qSleep( 2000 );
}

void on_item3_selected(MenuComponent* p_menu_component) {
    (void) p_menu_component;

    display->clearDisplay();
    display->setTextColor(WHITE, BLACK);
    display->setCursor(0, 3 * PCD8544_CHAR_HEIGHT);
    display->print("Item3 Selectd");
    display->display();
    //delay(1500); // so we can look the result on the LCD
    QTest::qSleep( 2000 );
}





MenuSystem ms(my_renderer);


    Menu root("ROOT");

    Menu mu1("[ GPS ]: MENU",  nullptr,    &show_desktop_1);
    Menu mu2("[ APRS ]: MENU", nullptr,    &show_desktop_2);
    Menu mu3("[ WIFI ]: MENU", nullptr,    &show_desktop_3);
    Menu mu4("[ SYS ]: MENU",  nullptr,    &show_desktop_4);

//Menu mu2("[ APRS ]: MENU");
//Menu mu3("[ SYS ]: MENU");


    //MenuScreen  dkt1("ONE",             0,                 &show_desktop_1);
    //MenuScreen  dkt2("TWO",             0,                 &show_desktop_2);
    //MenuScreen  dkt3("TRI",             0,                 &show_desktop_3);
    //MenuScreen  dkt4("FOR",             0,                 &show_desktop_4);


    MenuItem mu1_mi1("Enable GPS",      0,              &on_item1_selected);
    MenuItem mu1_mi2("Use GPS TIME",    0,              &on_item2_selected);
    MenuItem mu1_mi3("Set UNITS SI/US", 0,              &on_item2_selected);
    MenuItem mu1_mi4("Set Timezone",    MIF_DISABLED,   &on_item2_selected);
    MenuItem mu1_mi5("Show Satellites", 0,              &on_item2_selected);
    MenuItem mu1_mi6("Edit Refresh",    0,              &on_item2_selected);
    MenuItem mu1_mi7("Configure NMEA",  0,              &on_item2_selected);
BackMenuItem mu1_mi8("Return",          0,              &ms);




void keyboard_handler() {
    keymask_t key;

    key = emul_kbd->kbd_peek();

    if (key & K_UP) {
        ms.prev();
        ms.display();
    }

    if (key & K_DOWN) {
        ms.next();
        ms.display();
    }

    if (key & K_LEFT) {
        if (ms.get_current_menu()->get_name() == "ROOT")
            ms.prev();
        else
            ms.back();
        ms.display();
    }

    if (key & K_RIGHT) {
        if (ms.get_current_menu()->get_name() == "ROOT")
            ms.next();
        else
            ms.select();
        ms.display();
    }

    if (key & K_OK) {
        ms.select();
        ms.display();
    }

}







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /* Build GUI window configured with Qt Creator in file mainwindow.ui */
    ui->setupUi(this);

    /* Set global pointer to this instance */
    emul_win = this;

    /* Create layout for emulator widget */
    QVBoxLayout* verticalLayout = new QVBoxLayout;
    verticalLayout->setSpacing(0);
    verticalLayout->setMargin(0);
    ui->emulatorContainer->setLayout(verticalLayout);

    /* Create Emulator Widget */
    Adafruit_SSD1306 *emulator = new Adafruit_SSD1306;

    /* Set global display pointer to this instance */
    display = emulator;

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

    this->statusBar()->showMessage("Loaded SSD1603..");


    /* Search all buttons and add to a group */
    QButtonGroup* group = new QButtonGroup(this);

    for (int i = 0; i < ui->gridLayout->count(); ++i)
    {
      QWidget *widget = ui->gridLayout->itemAt(i)->widget();
      if (widget != NULL)
      {
        group->addButton(dynamic_cast<QPushButton*>(widget));
      }
    }

    /* Create SLOT for every released button */
    connect(group, SIGNAL(buttonReleased(int)), this, SLOT(onGroupButtonClicked(int)));


    /* Connect Keyboard */
    emul_kbd  = new Adafruit_Keyboard;
    emul_kbd->kbd_init();

    /* Keyboard timer to poll buttons */
    timerId = startTimer(10);


    /* Create Menu */
    menu_system = &ms;

    ms.get_root_menu().add_menu(&root);
    /*
    ms.get_root_menu().add_menu(&mu1);
    ms.get_root_menu().add_menu(&mu2);
    ms.get_root_menu().add_menu(&mu3);
    */
    root.add_menu(&mu1);
    root.add_menu(&mu2);
    root.add_menu(&mu3);
    root.add_menu(&mu4);
    
    //root.add_screen(&dkt1);
    //root.add_screen(&dkt2);
    //root.add_screen(&dkt3);
    //root.add_screen(&dkt4);
    
    mu1.add_item(&mu1_mi1);
    mu1.add_item(&mu1_mi2);
    mu1.add_item(&mu1_mi3);
    mu1.add_item(&mu1_mi4);
    mu1.add_item(&mu1_mi5);
    mu1.add_item(&mu1_mi6);
    mu1.add_item(&mu1_mi7);
    mu1.add_item(&mu1_mi8);

    /* Jump from ROOT menu into first menu */
    ms.select();
    ms.display();



    /* ==> INSERT CODE HERE - BEGIN <== */

    //emulator->clearDisplay();   // clears the screen and buffer
#if 0
    /* Initialize Screen */

    // Set default color and size
    emulator->setTextSize(1);
    //emulator->setTextColor(BLACK, WHITE);

    // Using Adafruit fonts
    emulator->setFont(&FreeSans12pt7b);
    emulator->setCursor(7,40);
    static char tmp[36] = {0};
    sprintf(tmp, "%s", "Hallo Welt!");
    emulator->print(tmp);
    
    // Using glcdfont
    emulator->setFont(&hp58pt8b);
    //emulator->setFont(&mina10pt8b);
    sprintf(tmp, "%s", "THIS IS HP5 FONT!");
    //sprintf(tmp, "%s", "All your base are us!");
    emulator->print(tmp);
#endif
    
    // Use of standard text
    emulator->setTextColor(WHITE, BLACK);
    emulator->setCursor(0, 10);
    emulator->setFont(NULL);
    //emulator->print("All your base are us");

#if 0
    emulator->drawPixel(0, 0, WHITE);
    emulator->drawPixel(127, 0, WHITE);
    emulator->drawPixel(0, 63, WHITE);
    emulator->drawPixel(127, 63, WHITE);
#endif

    /* Must be called at the end to refresh the display */
    ms.display();
    emulator->display();

    /* ==> INSERT CODE HERE - END <== */

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::loop_menu()
{
  keyboard_handler();
}






/* Called by timer */
void MainWindow::timerEvent(QTimerEvent *event)
{
    (void) event;

    Adafruit_Keyboard *poll_kbd = new Adafruit_Keyboard();

    poll_kbd->kbd_poll();
}


/* Keyboard emulation

   This function emulates the pressed buttons on a real keyboard and returns
   a specific type keymask_t for keyboard driver.
*/
int MainWindow::readButtons(void)
{
    /* Search all buttons and add to a group */
    QPushButton* button = new QPushButton(this);

    QString objName = NULL;

    int keymask = 0;

    for (int i = 0; i < ui->gridLayout->count(); ++i)
    {
      QWidget *widget = ui->gridLayout->itemAt(i)->widget();
      if (widget != NULL)
      {
        button = dynamic_cast<QPushButton*>(widget);
        if (button->isDown()) {
            objName = widget->objectName();

            if       (objName == "pushButton_UP")       keymask |= (K_UP);
            else if  (objName == "pushButton_DOWN")     keymask |= (K_DOWN);
            else if  (objName == "pushButton_LEFT")     keymask |= (K_LEFT);
            else if  (objName == "pushButton_RIGHT")    keymask |= (K_RIGHT);
            else if  (objName == "pushButton_OK")       keymask |= (K_OK);

            //qDebug("%s", qPrintable(objName));
        }
      }
    }

    return keymask;
}





















/* SLOT Functions for GUI interaction */

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dlg(this);
    dlg.exec();
}


/* SLOT Functions for BUTTON interactions */
#define DISABLE_SLOT_MSG    0

void MainWindow::on_pushButton_LEFT_pressed()
{
    ui->statusBar->showMessage("Press LEFT");
    #if DISABLE_SLOT_MSG
    qDebug("LEFT");
    #endif
}

void MainWindow::on_pushButton_RIGHT_pressed()
{
    ui->statusBar->showMessage("Press RIGHT");
    #if DISABLE_SLOT_MSG
    qDebug("RIGHT");
    #endif
}

void MainWindow::on_pushButton_UP_pressed()
{
    ui->statusBar->showMessage("Press UP");
    #if DISABLE_SLOT_MSG
    qDebug("UP");
    #endif
}

void MainWindow::on_pushButton_DOWN_pressed()
{
    ui->statusBar->showMessage("Press DOWN");
    #if DISABLE_SLOT_MSG
    qDebug("DOWN");
    #endif
}

void MainWindow::on_pushButton_OK_pressed()
{
    ui->statusBar->showMessage("Press OK");
    #if DISABLE_SLOT_MSG
    qDebug("OK");
    #endif
}

void MainWindow::onGroupButtonClicked(int)
{
    ui->statusBar->clearMessage();
    #if DISABLE_SLOT_MSG
    qDebug("Released!");
    #endif
}




