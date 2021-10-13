#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_SOLAR_SYSTEM "../lab_6/systems/sistema1.txt"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    readSystem();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::readSystem(){
    ifstream file;

    file.open(PATH_SOLAR_SYSTEM);
    string line = "";
    int contLinea = 0;

    string cuerpo = "";
    double PosX, PosY, Masa, Radio, V0_x, V0_y;

    while(!file.eof()){
        file >> line;
        if(contLinea == 0){
            //Numero de cuerpo
            cuerpo = line;
            contLinea++;
        }else if(contLinea == 1){
            //Posicion inicial en X
            PosX = stof(line);
            contLinea++;
        }else if(contLinea == 2){
            //Posicion inicial en Y
            PosY = stof(line);
            contLinea++;
        }else if(contLinea == 3){
            //Masa del cuerpo
            Masa = stof(line);
            contLinea++;
        }else if(contLinea == 4){
            //Radio del cuerpo
            Radio = stof(line);
            contLinea++;
        }else if(contLinea == 5){
            //Velocidad inicial en X
            V0_x = stof(line);
            contLinea++;
        }else if(contLinea == 6){
           //Velocidad inicial en X
           V0_y = stof(line);
           if(cuerpo == "1"){
               cuerpoGravitacional = new cuerpoGrav(PosX, PosY, Masa);
               scene->addItem(cuerpoGravitacional);
               cout << "Anadiendo cuerpo gravitacional" << endl;
           }else{
               planet = new planeta(PosX, PosY, Masa,V0_x,V0_y);
               scene->addItem(planet);
               planets.push_back(planet);
               cout << "Anadiendo planeta" << endl;
           }
           cout << "Cuerpo numero " << cuerpo << endl;
           cout << "   Posicion inicial en X = " << PosX << endl;
           cout << "   Posicion inicial en Y = " << PosY << endl;
           cout << "   Masa = " << Masa << endl;
           cout << "   Radio = " << Radio << endl;
           cout << "   Velocidad inicial en X = " << V0_x << endl;
           cout << "   Velocidad inicial en y = " << V0_y << endl;
           contLinea = 0;
        }      
    }
    file.close();
}

