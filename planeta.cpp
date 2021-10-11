#include "planeta.h"

planeta::planeta(float posX, float posY, float masa, float VelX, float VelY){
    X_0  = posX;
    Y_0  = posY;
    m    = masa;
    V0_X = VelX;
    V0_Y = VelY;
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
