#include "mainwindow.h"
#include "ui_mainwindow.h"

#define PATH_SOLAR_SYSTEM "../lab_6/systems/sistema1.txt"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    readSystem();
    ui->Scroll->setRange(-100,100);
    ui->Scroll->setSliderPosition(0);
    //ui->graphicsView->setSceneRect(-400,-300,800,600);
    ui->graphicsView->setSceneRect(-(ui->graphicsView->width()/2),-(ui->graphicsView->height()/2),ui->graphicsView->width(),ui->graphicsView->height());
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
            PosX = (stof(line)) * SCALE;
            contLinea++;
        }else if(contLinea == 2){
            //Posicion inicial en Y
            PosY = (stof(line)) * SCALE;
            contLinea++;
        }else if(contLinea == 3){
            //Masa del cuerpo
            Masa = (stof(line)) * SCALE;
            contLinea++;
        }else if(contLinea == 4){
            //Radio del cuerpo
            Radio = (stof(line)) * SCALE;
            contLinea++;
        }else if(contLinea == 5){
            //Velocidad inicial en X
            V0_x = (stof(line)) * SCALE;
            contLinea++;
        }else if(contLinea == 6){
           //Velocidad inicial en X
           V0_y = (stof(line)) * SCALE;
           if(cuerpo == "1"){
               cuerpoGravitacional = new cuerpoGrav(PosX, PosY, Masa);
               scene->addItem(cuerpoGravitacional);
               cuerpoGravitacional->setPos(cuerpoGravitacional->getX(),-cuerpoGravitacional->getY());
               cout << "Anadiendo cuerpo gravitacional" << endl;
           }else{
               planet = new planeta(PosX, PosY, Masa,V0_x,V0_y, cuerpoGravitacional->getX(), cuerpoGravitacional->getY(), cuerpoGravitacional->getM());
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

void MainWindow::calculatePosition(){
    static int  cont = 0;
    if(ui->Radio_Fast->isChecked()){
        cout << "Rapido " << cont++ << endl;
    }
    for(auto planeta = planets.begin(); planeta != planets.end(); planeta++){
        //(*planeta)->calculatePosition(8640.0f);
        (*planeta)->calculatePosition(1.0f);
        double X = (*planeta)->getX();
        double Y = (*planeta)->getY();
        (*planeta)->setPos(X,-Y);
        if(planeta == planets.begin()){
             cout << *planeta << " = { " << X*100 << " , " << Y*100 << " }" << endl;
        }
    }
   // ui->graphicsView->setSceneRect(-400,-300,800,600);
    ui->graphicsView->setSceneRect(-(ui->graphicsView->width()/2),-(ui->graphicsView->height()/2),ui->graphicsView->width(),ui->graphicsView->height());

}


void MainWindow::on_Start_clicked(){
    //Iniciamos el Timer
    cout << "Comenzo simulacion" << endl;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(calculatePosition()));
    timer->start(10);
}

void MainWindow::on_Scroll_valueChanged(int value){
    static int before =  0;
    if(before > value){
        ui->graphicsView->scale(0.5,0.5);
    }else if(before < value){
        ui->graphicsView->scale(2,2);
    }
    before = value;
}
