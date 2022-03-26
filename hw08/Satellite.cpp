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

Vector Satellite:: getPosition(){
    return this->d;
}

Vector Satellite:: getVelocity(){
    return this->v;
}

void Satellite:: setValue(Vector& d, Vector& v){
    this->d = d;
    this->v = v;
}

Satellite Satellite:: update(double t, const Vector& a){
    Satellite answer;
    
    Vector v2 = (this->v) + (a*t);
    Vector r2 = (this->d) + (v2*t);
    answer.setValue(r2, v2);
    
    return answer;
}
