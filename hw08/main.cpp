#include <iostream>
#include "Planet.h"
#include "Vector.h"
#include "Satellite.h"
#include "Fragment.h"
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    
    float M = 5.9736e24;// 00000000000000000000; //mass of earth
    double rp = 6371000; //radius of earth
    
    double x = 400000.0;
    double y = 0.0;
    double z = 0.0;
    
    Vector r (x, y, z);
    Vector g(0.0, 0.0, 0.0);
    Vector v (0.0, 7660.0, 0.0);
    
    Planet p (M, rp);
    
    if (!p.crash (r, g)){
        cout<< "\nGravity acceleration:"<<g <<endl;
        
    }
    else{
        cout << "It is crashing"<<endl;
    }
    
    double t = 1.0;
    Satellite s(p, r, v);
    for (int i = 0; i<10; i++){
        s.update(t);
        cout << "\nSatellite:\nPosition: " << s.getPosition() << "\nVelocity: " << s.getVelocity()<< endl;
    }
    v = s.getVelocity();
    r = s.getPosition();
    
    //cout << "\nSatellite:\nPosition: " << r << "\nVelocity: " << v << endl;
    
    Fragment f(p, r, v, 2.0, 5);
    f.update(1.0);
}
