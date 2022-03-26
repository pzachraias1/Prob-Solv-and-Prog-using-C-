#include <iostream>
#include <cmath>
#include "Satellite.h"
class Planet;
class Vector;


Satellite::Satellite (const Planet& p, const Vector& d, const Vector& v){
    this->p = p;
    this->d = d;
    this->v = v;
}
Satellite::Satellite (){
    
}

Satellite::~Satellite(){
    
}
void Satellite:: setValue(Vector& d, Vector& v){
    this->d = d;
    this->v = v;
}

Vector Satellite:: getPosition(){
    return this->d;
}

Vector Satellite:: getVelocity(){
    return this->v;
}

void Satellite:: update(double t, const Vector& a){
    Vector v2;
    Vector r2;
    
    v2 = (this->v) + (a*t);
    r2 = (this->d) + (v2*t);
    
    this->v = v2;
    this->d= r2;
}
