#include <iostream>
#include "Planet.h"
#include "Vector.h"
#include "Satellite.h"
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    
    float M = 5.9736e24;// 00000000000000000000; //mass of earth
    double rp = 6371000; //radius of earth
    
    double x = 20000000.0;
    double y = 20000000.0;
    double z = 20000000.0;
    
    Vector r (x, y, z);
    Vector g(0.0, 0.0, 0.0);
    Vector v (0.0, 0.0, 0.0);
    
    Planet p (M, rp);
    
    if (!p.crash (r, g)){
        cout<< "Gravity acceleration: "<<g <<endl;
        
    }
    else{
        cout << "It is crashing"<<endl;
    }
    
    double t = 20;
    Satellite s(p, r, v);
    s.update(t, g);
    cout << "\nSatellite:\nPosition: " << s.getPosition() << "\nVelocity: " << s.getVelocity()<< endl;
}
