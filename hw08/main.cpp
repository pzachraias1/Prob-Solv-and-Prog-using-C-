#include <iostream>
#include "Planet.h"
#include "Vector.h"
#include "Satellite.h"
#include "Fragment.h"
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    
    const float M = 5.972e24;// 00000000000000000000; //mass of earth
    const double rp = 6.378e6; //radius of earth
    
    double x = (400000.0 + rp);
    double y = 0.0;
    double z = 0.0;
    
    Vector r (-x, y, z);
    Vector v (0.0, -7660.0, 0.0);
    Vector g(0.0, 0.0, 0.0);
    
    
    Planet p (M, rp);
    
    //A and a little B----------------------------------------
    if (!p.crash (r, g)){
        cout<< "\nGravity acceleration:"<<g <<endl;
        
    }
    else{
        cout << "It is crashing"<<endl;
    }
    
    //B-------------------------------------------
    double t = 1.0;
    const int numFragment = 20;
    const int timeInterval = 86400;
    
    Satellite s(p, r, v);
    for (int i = 0; i<10; i++){
        s.update(t);
        //cout << "\nSatellite:\nPosition: " << s.getPosition() << "\nVelocity: " << s.getVelocity()<< endl;
    }
    v = s.getVelocity();
    r = s.getPosition();
    
    cout << "\nSatellite Original:\nPosition: " << r << "\nVelocity: " << v << endl;
    
    
    
    Fragment f(p, r, v, 30.0, numFragment);
    
    
    for (int i = 0; i < timeInterval -10; i++){
        //cout << "\nInterval " << i +1 << endl;
        f.update(t);
    }
    
    cout << endl;
    
    double xx = 400000.0 + rp;
    double yy = 0.0;
    double zz = 0.0;
    
    Vector r2 (xx, yy, zz);
    Vector v2 (0.0, 7660.0, 0.0);
    
    Satellite s2(p, r2, v2);
    for (int i = 0; i<timeInterval; i++){
        s2.update(t);
    }
    v2 = s2.getVelocity();
    r2 = s2.getPosition();
    cout << "\nSatellite Opposite side of the world:\nPosition: " << r2 << "\nVelocity: " << v2 << endl;
    
    double distance = f.distance(s2);
    cout << "\n" << distance << " meters, is the distance between the nearest Fragment and " << r2 << endl;
    
    
     
}
