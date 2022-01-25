#ifndef function_h
#define function_h

double getDrag (double coefficientDrag, double Area, double density, double velocity, double mass);

double getVelocity(double xVelocity, double yVelocity);

double getXAcceleration (double drag, double xVelocity, double velocity);

double getYAcceleration (double drag, double yVelocity, double velocity, double gravity);

double getXVelocity (double velocityX, double accelerationX, double time);

double getYVelocity (double velocityY, double accelerationY, double time);

double getX (double x, double VelocityX, double time);

double getY (double y, double VelocityY, double time);

double degreeToRadian (double angle);

#endif
