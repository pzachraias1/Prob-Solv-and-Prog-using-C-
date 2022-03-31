#ifndef PLANET_H
#define PLANET_H
#include <iostream>
#include "Vector.h"

class Planet {

private:
    double G = 6.67408e-11; //Gravitational constant
    float M; //mass of the planet
    double rp; //radius of the planet

public:
    //static const double G; //= 0.000000000066742; //Gravitational constant
    Planet(const float M, const double rp);
    Planet ();
    virtual ~Planet();
    
    bool crash(const Vector& r, Vector& g);
    double getG ();
    
};

#endif
