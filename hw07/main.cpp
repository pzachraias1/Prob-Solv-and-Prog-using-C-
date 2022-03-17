#include "Vector.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
    
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    
    double xx = 0.0;
    double yy = 0.0;
    double zz = 0.0;
    
    double mu = 0.0;
    
    cout<<"\nLets add value to Vector 1:\nX = ";
    cin>>x;
    cout<<"Y = ";
    cin>>y;
    cout<<"Z = ";
    cin>>z;
    
    cout<<"\nLets now add value to Vector 2:\nX = ";
    cin>>xx;
    cout<<"Y = ";
    cin>>yy;
    cout<<"Z = ";
    cin>>zz;
    
    Vector v1(x, y, z);
    Vector v2;
    v2.setVector (xx, yy, zz);
    
    cout<<"\nVector 1\tVector 2"<<endl;
    cout<<"X: "<<v1.getX()<<"\t\tX: "<<v2.getX()<<endl;
    cout<<"Y: "<<v1.getY()<<"\t\tY: "<<v2.getY()<<endl;
    cout<<"Z: "<<v1.getZ()<<"\t\tZ: "<<v2.getZ()<<endl;
    
    Vector v3;
    v3 = v1+v2;
    
    cout<<"\nAdding Vectors\nThis is x: "<< v3.getX() <<endl;
    cout<<"This is y: "<< v3.getY() <<endl;
    cout<<"This is z: "<< v3.getZ() <<endl;
    
    Vector v4 = v1-v2;
    
    cout<<"\nSubtracting Vectors\nThis is x: "<< v4.getX() <<endl;
    cout<<"This is y: "<< v4.getY() <<endl;
    cout<<"This is z: "<< v4.getZ() <<endl;
    
    cout<<"\nEnter a number to multiple the Vector 1 with: ";
    cin>>mu;
    
    Vector v5 = v1 * mu;
    
    cout<<"\nMultiplying A vector with a double\nThis is x: "<< v5.getX() <<endl;
    cout<<"This is y: "<< v5.getY() <<endl;
    cout<<"This is z: "<< v5.getZ() <<endl;
    
    double mm;
    mm = v1 * v2;
    
    cout<<"\nMultiplication of the 2 vector: "<< mm<<endl;
    cout<<endl;
    
    v1+=v2;
    cout<<"\nOverloading operator:\nX = "<<v1.getX()<<endl;
    cout<<"Y = " <<v1.getY()<<endl;
    cout<<"Z = " <<v1.getZ()<<endl;
    
    cout << v1 << endl;
    
    /*delete v1;
    delete v2;
    delete v3;
    v1 = nullptr;
    v2 = nullptr;
    v3 = nullptr;*/
}
