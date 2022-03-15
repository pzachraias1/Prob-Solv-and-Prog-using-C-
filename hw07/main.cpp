#include "Vector.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    
    double x = 5.0;
    double y = 3.0;
    double z = 7.0;
    
    double xx = 2.5;
    double yy = 3.0;
    double zz = 12.3;
    
    /*cout<<"X = ";
    cin>>x;
    cout<< "Y = ";
    cin>>y;
    cout<<"Z = ";
    cin>>z;*/
    
    Vector v1(x, y, z);
    Vector v2;
    v2.setVector (xx, yy, zz);
    
    Vector v3;
    v3.subtract(v1, v2);
    
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
