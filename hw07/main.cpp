#include "Vector.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    
    double x = 12.0;
    double y = 3.0;
    double z = 6.7;
    
    double xx = 12.5;
    double yy = 2.0;
    double zz = 10.3;
    
    Vector v1(x, y, z);
    Vector v2;
    v2.setVector (xx, yy, zz);
    
    Vector v3;
    v3.add(v1, v2);
    
    cout<<"This is x: "<< v3.getX() <<endl;
    cout<<"This is y: "<< v3.getY() <<endl;
    cout<<"This is z: "<< v3.getZ() <<endl;
    
    double test;
    test = v3.vectorMultiply(v1, v2);
    
    cout<<"\nThis is the Test: "<< test<<endl;
    
    /*delete v1;
    delete v2;
    delete v3;
    v1 = nullptr;
    v2 = nullptr;
    v3 = nullptr;*/
}
