#include "Vector.h"

//using namespace std;

Vector::Vector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(){
    
}

void Vector::setVector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::~Vector(){
    
}

double Vector::getX() const{
    return x;
}

double Vector::getY() const{
    return y;
}

double Vector::getZ() const{
    return z;
}

Vector Vector::add(Vector v1, Vector v2){
    
    Vector answer;
    
    x = v1.getX() + v2.getX();
    y = v1.getY() + v2.getY();
    z = v1.getZ() + v2.getZ();
    
    answer.setVector(x, y, z);
    
    return answer;
    
}

Vector Vector::subtract(Vector v1, Vector v2){
    Vector answer;
    
    x = v1.getX() - v2.getX();
    y = v1.getY() - v2.getY();
    z = v1.getZ() - v2.getZ();
    
    answer.setVector(x, y, z);
    
    return answer;
}

Vector Vector::multiplyDouble(Vector v, double num){
    Vector answer;
    
    x = v.getX() * num;
    y = v.getY() * num;
    z = v.getZ() * num;
    
    
    return answer;
}

double Vector::vectorMultiply(Vector v1, Vector v2){
    double num =0;
    
    num = (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() + v2.getZ());
    
    return num;
}
