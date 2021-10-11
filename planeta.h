#ifndef PLANETA_H
#define PLANETA_H

#include <QGraphicsItem>

class planeta : public QGraphicsItem{
public:
    planeta(float posX, float posY, float masa, float VelX, float velY);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

private:
    float X_0;
    float Y_0;
    float X;
    float Y;
    float m;
    float V0_X;
    float V0_Y;
    float Ax;
    float Ay;
    double G = 0.0000000000667384;
};

#endif // PLANETA_H
