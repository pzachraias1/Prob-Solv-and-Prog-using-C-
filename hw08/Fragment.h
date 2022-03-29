#ifndef FRAGMENT_H
#define FRAGMENT_H
#include "Satellite.h"
#include "Vector.h"
#include "Planet.h"

class Fragment {

private:
    Planet p;
    int num;
    Satellite* sArray [];
    
public:
    Fragment (const Planet& p, Vector& d, Vector& v, double ve, int num);
    virtual ~Fragment();
    
    void update(double t);
    void distance(Satellite s);
};

#endif
