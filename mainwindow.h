#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "escapedialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* btn;
};
#endif // MAINWINDOW_H
