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
    
    double index = 0.0;
    while (index != t){
        v2 = (this->v) + (a*index);
        r2 = (this->d) + (v2*index);
        //std::cout<<"\nVelocity: "<< v2<<"\nPosition: "<< r2 <<std::endl;
        index ++;
    }
    this->v = v2;
    this->d= r2;
}
