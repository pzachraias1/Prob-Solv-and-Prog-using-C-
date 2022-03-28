#ifndef SATELLITE_H
#define SATELLITE_H
#include "Vector.h"
#include "Planet.h"

class Satellite {

private:
    Planet p;
    Vector d;
    Vector v;

public:
    Satellite (const Planet& p, const Vector& d, const Vector& v);
    Satellite ();
    virtual ~Satellite();
    
    Vector getPosition();
    Vector getVelocity();
    
    void setValue (Vector& d, Vector& v);
    void update(double t);
};

#endif
