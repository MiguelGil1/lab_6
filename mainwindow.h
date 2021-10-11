#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>

#include "planeta.h"

#include <iostream>
using namespace std;
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();   

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;//Declaracion de la escena

    planeta *planet;
    vector<planeta *> planets;
};
#endif // MAINWINDOW_H
