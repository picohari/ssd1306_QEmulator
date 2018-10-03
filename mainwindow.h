#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimerEvent>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void loop_menu();
    
    int readButtons(void);

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

    void on_pushButton_LEFT_pressed();
    void on_pushButton_RIGHT_pressed();
    void on_pushButton_UP_pressed();
    void on_pushButton_DOWN_pressed();
    void on_pushButton_OK_pressed();

    void onGroupButtonClicked(int);

private:
    Ui::MainWindow *ui;
    int timerId;

protected:
    void timerEvent(QTimerEvent *event);

};

extern MainWindow *emul_win;


#endif // MAINWINDOW_H
