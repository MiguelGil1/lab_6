#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>

class planeta : public QGraphicsItem{
public:
    planeta(double posX, double posY, double masa, double VelX, double velY, double X1, double Y1, double M);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void calculatePosition();

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

private:
    double X_0;                    //Posicion inicial en X del planeta
    double Y_0;                    //Posicion inicial en Y del planeta
    double X;                      //Posicion en X del planeta
    double Y;                      //Posicion en Y del planeta
    double m;                      //Masa del planeta
    double V0_X;                   //Velocidad inicial en X del planeta
    double V0_Y;                   //Velocidad inicial en Y del planeta
    double VX;                     //Velocidad en X del planeta
    double VY;                     //Velocidad en Y del planeta
    double Ax;                     //Acelereacion en X del planeta
    double Ay;                     //Aceleracion en Y del planeta
    double m2;                     //Masa del cuerpo masivo
    double X1;                     //Posicion en X del cuerpo masivo
    double Y1;                     //Posicion en Y del cuerpo masivo
    double G = 0.0000000000667384; //Constante de gravitacion Universal
};

#endif // PLANETA_H
