#include <iostream>
#include <cmath>
#include "Planet.h"
//#include "Vector.h"
class Vector;

Planet::Planet(const float M, const double rp){
    this->M = M;
    this->rp = rp;

}

Planet::Planet (){
    
}

Planet::~Planet(){
    
}

bool Planet:: crash (const Vector& r, Vector& g){
    
    double r2 = r * r;
    
    if (r2<pow(rp,1)){
        return true;
    }
    else {
        g = r*((this->G)*(this->M)/(pow(r2, 1.5)));
        return false;
    }
}

double Planet:: getG (){
    return this->G;
}
