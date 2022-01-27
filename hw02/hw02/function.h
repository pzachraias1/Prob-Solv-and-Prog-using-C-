#ifndef FUNCTION_H
#define FUNCTION_H

/**
double x, vx, ax; //the displacement, velocity, and acceleration of horizontal axis
double y, vy, ay;

double iniV;
double angle;

double t;// counter for the time
double  dt;// the amount of sec that time change or increae

double m; //mass of the object that is being thrown or fired
double dc; //drag coefficient
double A; // area of the object
double p;// density of the air
double g;
double v;
double d;
int counter;
*/
 
double getDrag (double coefficientDrag, double Area, double density, double velocity, double mass);

double getVelocity(double xVelocity, double yVelocity);

double getXAcceleration (double drag, double xVelocity, double velocity);

double getYAcceleration (double drag, double yVelocity, double velocity, double gravity);

double getXVelocity (double velocityX, double accelerationX, double time);

double getYVelocity (double velocityY, double accelerationY, double time);

double getX (double x, double VelocityX, double time);

double getY (double y, double VelocityY, double time);

double degreeToRadian (double angle);

double range(double degree);



#endif
