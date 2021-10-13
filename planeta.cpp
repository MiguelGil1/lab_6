#include "planeta.h"

planeta::planeta(double posX, double posY, double masa, double VelX, double VelY,double X_1, double Y_1, double M){
    X_0  = posX;
    Y_0  = posY;
    X    = posX;
    Y    = posY;
    m    = masa;
    V0_X = VelX;
    V0_Y = VelY;
    m2   = M;
    X1   = X_1;
    Y1   = Y_1;
}
QRectF planeta::boundingRect() const{
    return QRectF(X,Y,10,10);
}

void planeta::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void planeta::calculatePosition(){
    double theta =  0;
    if((X -X1) == 0){
        //theta = qAtan((Y - Y1)/(0.0000000000001));
        theta = qAtan2((Y - Y1),0.0000000000001);
    }else{
        //theta = qAtan((Y - Y1)/(X - X1));
        theta = qAtan2((Y - Y1),(X - X1));
    }

    double r2 = ((qPow(X - X1, 2)) + (qPow(Y - Y1, 2)));

    Ax = (((G * m2)/(r2)) * qCos(theta));
    Ay = (((G * m2)/(r2)) * qSin(theta));
}

float planeta::getX() const{
    return X;
}

void planeta::setX(float value){
    X = value;
}

float planeta::getY() const{
    return Y;
}

void planeta::setY(float value){
    Y = value;
}
