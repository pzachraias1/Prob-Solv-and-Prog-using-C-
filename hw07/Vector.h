#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
    double x;
    double y;
    double z;
    double m;
    
public:
    Vector(double x, double y, double z);
    Vector();
    virtual ~Vector();
    
    void setVector(double x, double y, double z);
    
    double getX() const;
    double getY() const;
    double getZ() const;
    
    Vector add(Vector v1, Vector v2);
    Vector subtract(Vector v1, Vector v2);
    Vector multiplyDouble(Vector v, double num);
    double vectorMultiply(Vector v1, Vector v2);
};

#endif
