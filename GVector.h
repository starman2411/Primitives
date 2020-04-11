//
// Created by mi on 01.04.2020.
//

#ifndef LINAL_GVECTOR_H
#define LINAL_GVECTOR_H

#include "point.h"

class GVector{
private:
    double x, y;
public:
    GVector(){
    x=0;
    y=0;
    }

    GVector(Point a, Point b){
x = a.getX() - b.getX();
y = a.getY() - b.getY();
}

    GVector(double x, double y) {
    this->x = x;
    this->y = y;
}



double getX(){
    return x;
}

double getY(){
    return y;
}

void setX(double x){
    this->x=x;
    }
void setY(double y){
    this->y=y;
    }

GVector& operator +(GVector& v){
    GVector*a =new GVector(x + v.getX(), y + v.getY());
    return *a;
}

GVector& operator -(GVector& v){
    GVector a(x - v.getX(), y - v.getY());
    GVector &ref = a;
    return ref;
}

GVector operator *(double a) {
    return GVector(x * a, y * a);
}

GVector& operator =(GVector& v){
    x = v.getX();
    y = v.getY();
    return(*this);
}


};






#endif //LINAL_GVECTOR_H
