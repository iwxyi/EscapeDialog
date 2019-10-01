#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(200, 200);

    btn = new QPushButton("dialog", this);
    btn->move(100, 100);
    connect(btn, &QPushButton::clicked, [=]{
       EscapeDialog dia("title", "msg", "esc", "nor", this);
       if (dia.exec())
           qDebug() << "Dialog:Accept";
       else
           qDebug() << "Dialog:Reject";
    });
}

MainWindow::~MainWindow()
{

}

