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
        
        
        
        this->sArray[i] = new Satellite(p, d, v);
        //std::cout << "Position: " << sArray[i]->getPosition()<< "\tVelocity: " << sArray[i]->getVelocity() << std::endl;
    }
    this->p = p;
    this->num = num;
    
}
Fragment::~Fragment(){
    
}

void Fragment:: update(double t){

    for (int i = 0; i<this->num; i++){
        sArray[i]->update(t);
        //std::cout << std::endl;
        //std::cout<<i+1 << ". Position: " << sArray[i]->getPosition() << "\tVelocity: " << sArray[i]->getVelocity() << std::endl;
    }
     
}

double Fragment:: distance(Satellite s){
    double distance;
    double min;
    double curr;
    Vector r1 = s.getPosition();
    Vector r2 (0.0, 0.0, 0.0);
    
    min = (r1)*(r1);
    
    for (int i = 0; i< this->num; i++){
        r2 = this->sArray[i]->getPosition();
        curr = (r1-r2)*(r1-r2);
        
        //std::cout << "r1: " << r1 << "\tr2: " << r2 << std::endl;
        
        if (min > curr){
            min = curr;
            //std::cout << "New Minimum: " << min << std::endl;
        }
        
        //std::cout << i+1<<". Test: "<<curr << std::endl;
    }
    
    distance = pow(min, 0.5);
    return distance;
    //std::cout << "" << std::endl;
    //std::cout <<"Distance: "<<distance << std::endl;
}
