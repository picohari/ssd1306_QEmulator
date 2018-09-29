#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

    void on_pushButton_LEFT_clicked();
    void on_pushButton_RIGHT_clicked();
    void on_pushButton_UP_clicked();
    void on_pushButton_DOWN_clicked();
    void on_pushButton_OK_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
