#include <iostream>
#include "Planet.h"
#include "Vector.h"
#include "Satellite.h"
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
    for (int i = 0; i<20; i++){
        s.update(t, g);
        cout << "\nSatellite:\nPosition: " << s.getPosition() << "\nVelocity: " << s.getVelocity()<< endl;
    }
    
    
    /**
    cout<< "\nInternational Space Station (ISS):"<< endl;
    Vector rISS (400000.0, 0.0, 0.0);
    Vector vISS (0.0, 7660.0, 0.0);
    Vector aISS (0.0, 0.0, 0.0);
    
    
    if (!p.crash (rISS, aISS)){
        cout<< "Gravity acceleration:"<<aISS <<endl;
        double tISS = 20.0;
        Satellite sISS(p, rISS, vISS);
        for (int i = 0; i<10; i++){
            s.update(tISS, aISS);
        }
        cout << "\nISS:\nPosition: " << sISS.getPosition() << "\nVelocity: " << sISS.getVelocity()<< endl;
    }
    else {
        cout << "It is crashing"<<endl;
    }
     */
    
}
