#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    arduino->setPortName("COM12");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ledOn_clicked()
{
    qDebug() << "Led is on" << "\n";
    ui->ledStatus->setText("Led Is On");
    arduino->write("a");
}

void MainWindow::on_ledOff_clicked()
{
    qDebug() << "Led is off" << "\n";
    ui->ledStatus->setText("Led is Off");
    arduino->write("s");
}

void MainWindow::on_connectArduino_clicked()
{
    arduino->close();
    if (arduino->open(QIODevice::ReadWrite)){
        arduino->setBaudRate(QSerialPort::Baud9600);
            arduino->setDataBits(QSerialPort::Data8);
            arduino->setParity(QSerialPort::NoParity);
            arduino->setStopBits(QSerialPort::OneStop);
            // Skipping hw/sw control
            arduino->setFlowControl(QSerialPort::NoFlowControl);
            QMessageBox::information(this, "Connection successful", "Successfully connected to arduino");
    } else {
        QMessageBox::warning(this, "Connection Failed", "Retry");
    }

}
