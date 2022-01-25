#include "function.h"
#include <cmath>

double getDrag (double coefficientDrag, double Area, double density, double velocity, double mass){
    double D = (0.5*coefficientDrag*Area*density*(pow(velocity,2.0)))/mass;
    return D;
}

double getVelocity(double xVelocity, double yVelocity){
    double v;
    double sum = (pow(xVelocity, 2.0)) + (pow(yVelocity, 2.0));
    
    v = sqrt(sum);
    
    return v;
}

double getXAcceleration (double drag, double xVelocity, double velocity){
    double ax;
    ax = ((-drag)*xVelocity)/velocity;
    return ax;
}

double getYAcceleration (double drag, double yVelocity, double velocity, double gravity){
    double ay;
    ay = -gravity - ((drag*yVelocity)/velocity);
    
    return ay;
}

double getXVelocity (double velocityX, double accelerationX, double time){
    double v;
    v = velocityX + (accelerationX*time);
    
    return v;
}

double getYVelocity (double velocityY, double accelerationY, double time){
    double v;
    v = velocityY + (accelerationY*time);
    
    return v;
}

double getX (double x, double VelocityX, double time){
    double xLocation;
    xLocation = x + (VelocityX*time);
    
    return xLocation;
}

double getY (double y, double VelocityY, double time){
    double yLocation;
    yLocation = y+ (VelocityY*time);
    
    return yLocation;
}

double degreeToRadian (double angle){
    double rad = angle*(M_PI/180.0);
    return rad;
}
