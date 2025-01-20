#include"box.h"

Box::Box(){};

Box::Box(double lx, double ly, double x0, double y0){
    this->lx = lx;
    this->ly = ly;
    this->x0 = x0;
    this->y0 = y0;
};

void Box::setSides(double lx, double ly){
    this->lx = lx;
    this->ly = ly;
};

void Box::setOrigin(double x0, double y0){
    this->x0 = x0;
    this->y0 = y0;
};

double Box::getSidex(){
    return this->lx;
};

double Box::getSidey(){
    return this->ly;
};