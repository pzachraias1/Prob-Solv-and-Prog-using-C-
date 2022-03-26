#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector
{
private:
    double x;
    double y;
    double z;
    
public:
    Vector(double x, double y, double z);
    Vector();
    virtual ~Vector();
    
    void setVector(double x, double y, double z);
    
    double getX() const;
    double getY() const;
    double getZ() const;
    
    Vector operator+(const Vector& v)const;
    Vector operator-(const Vector& v)const;
    const Vector& operator+=(const Vector& v);
    Vector operator*(const double num)const ;
    double operator*(const Vector& v)const;
    
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
};

#endif
