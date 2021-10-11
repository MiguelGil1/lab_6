#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_SOLAR_SYSTEM "../lab_6/systems/sistema.txt"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

