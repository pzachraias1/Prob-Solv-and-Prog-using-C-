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

/**
double range(double degree){
    
   // double x, vx, ax; //the displacement, velocity, and acceleration of horizontal axis
   // double y, vy, ay; //displacement, celocity, and acceleration of the vertical axis
    vx = 0;
    vy = 0;
    x = 0;
    y = 0;
    
    iniV = 250.0;// initial velocity of the muzzle when it fire
    
    angle = degreeToRadian(degree);
    
    
     t = 0.0;// counter for the time
    dt = 1.0;// the amount of sec that time change or increae
    
    m = 30.0; //mass of the object that is being thrown or fired
    dc = 0.45; //drag coefficient
    A = 0.03; // area of the object
    p = 1.2;// density of the air
    g = 9.81;
    
    vx = iniV*cos(angle);
    vy = iniV*sin(angle);
    
    counter =1;
    while (counter ==1){
        t +=dt;
        v = getVelocity(vx, vy);//velocity
        d = getDrag(dc, A, p, v, m);//drag
        ax = getXAcceleration(d, vx, v);
        ay = getYAcceleration(d, vy, v, g);
        vx = getXVelocity(vx, ax, t);
        vy = getYVelocity(vy, ay, t);
        x = getX(x, vx, t);
        y = getY(y, vy, t);
        
        if (y<=0.0){
            counter++;
        }
    }
    
    return x;
}
*/
