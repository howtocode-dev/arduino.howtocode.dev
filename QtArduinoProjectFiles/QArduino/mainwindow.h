#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>


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
    void on_ledOn_clicked();

    void on_ledOff_clicked();

    void on_connectArduino_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
};

#endif // MAINWINDOW_H
