#include "Vector.h"
#include <iostream>

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
    return this->x;
}

double Vector::getY() const{
    return this->y;
}

double Vector::getZ() const{
    return this->z;
}

Vector Vector::operator+(const Vector& v)const{
    
    Vector answer;
    
    double xx = x + v.getX();
    double yy = y + v.getY();
    double zz = z + v.getZ();
    
    answer.setVector(xx, yy, zz);
    
    return answer;
    
}

Vector Vector::operator-(const Vector& v)const{
    Vector answer;
    
    double xx = x - v.getX();
    double yy = y - v.getY();
    double zz = z - v.getZ();
    
    answer.setVector(xx, yy, zz);
    
    return answer;
}

Vector Vector::operator*(const double num)const{
    Vector answer;
    
    double xx = x * num;
    double yy = y * num;
    double zz = z * num;
    
    answer.setVector(xx, yy, zz);
    
    return answer;
}

double Vector::operator*(const Vector& v)const{
    
    double answer;
    
    double xx = x * v.getX();
    double yy = y * v.getY();
    double zz = z * v.getZ();
    
    answer = xx + yy + zz;
    
    return answer;
}

const Vector& Vector::operator+=(const Vector& v){
    
    x += v.getX();
    y += v.getY();
    z += v.getZ();
    
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector& v){
    
    out <<"(" <<v.getX()<< ", " << v.getY()<<", " << v.getZ()<<")";
    return out;
}
