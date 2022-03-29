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
        
        
        
        this->sArray[i] = new Satellite s(p, d, v);
        //std::cout << "Position: " << sArray[i]->getPosition()<< "\tVelocity: " << sArray[i]->getVelocity() << std::endl;
    }
    this->p = p;
    this->num = num;
    
}
Fragment::~Fragment(){
    
}

void Fragment:: update(double t){

    Vector r;
    Vector v;
    for (int i = 0; i<this->num; i++){
        r = sArray[i]->getPosition();
        v = sArray[i]->getVelocity();
        Vector a (0.0, 0.0, 0.0);
        if (!p.crash(r, a)){
            sArray[i]->update(t);
            std::cout << "Position: " << r << "\tVelocity: " << v << std::endl;
        }
        else{
            std::cout << "Something is wrong" << std::endl;
        }
    }
     
}
