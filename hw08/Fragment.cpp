#include "Satellite.h"
#include "Vector.h"
#include "Fragment.h"
#include <iostream>
#include <cmath>


Fragment::Fragment (const Planet& p, Vector& d, Vector& v, double ve, int num){
    //Satellite *sArray[num];
    
    std::cout << std::endl;
    for (int i =0; i< num; i++){
        auto z = 2.0 *((double)rand()/(double)RAND_MAX)-1.0;
        
        auto angle = 2.0 * M_PI * ((double)rand()/(double )RAND_MAX);
        auto x = sqrt (1.0 - z *z)*cos(angle);
        auto y = sqrt (1.0 - z *z)*sin(angle);
        
        Vector vhat(x, y, z);
        
        v = v + (vhat*ve);
        
        Satellite s (p, d, v);
        
        this->sArray[i] = &s;
        std::cout << "Position: " << sArray[i]->getPosition()<< "\tVelocity: " << sArray[i]->getVelocity() << std::endl;
    }
    this->p = p;
    this->num = num;
    
}
Fragment::~Fragment(){
    
}

void Fragment:: update(double t){

    //Vector r = sArray[0]->getPosition();
    //Vector v = sArray[0]->getVelocity();
    //v = sArray[1]->getVelocity();
    for (int i = 0; i<this->num; i++){
        Vector r = sArray[i]->getPosition();
        Vector v = sArray[i]->getVelocity();
        //r = sArray[i]->getPosition();
        //v = sArray[i]->getVelocity();
        Vector a (0.0, 0.0, 0.0);
        //std::cout << r << std::endl;
        //std::cout << "Position: " << r << "\tVelocity: " << v << std::endl;
        if (!p.crash(r, a)){
            sArray[i]->update(t);
            std::cout << "Position: " << r << "\tVelocity: " << v << std::endl;
        }
        else {
            std::cout << "Nothing is happening here" << std::endl;
        }
    }
     
}
