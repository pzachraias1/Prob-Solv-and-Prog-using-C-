#include "range.h"
#include "formula.h"
#include <cmath>
#include <cstdio>

double x, vx, ax; //the displacement, velocity, and acceleration of horizontal axis
double y, vy, ay;

double iniV;// initial velocity
double angle;// angle

double t;// counter for the time
double  dt;// the amount of sec that time change or increae

double m; //mass of the object that is being thrown or fired
double dc; //drag coefficient
double A; // area of the object
double p;// density of the air
double g;// gravity
double v;// velocity
double d;// drag
int counter;
double max;

double degreeToRadian (double angle){
    double rad = angle*(M_PI/180.0);
    return rad;
}

void distHeight(double degree){
    
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
   
   max = 0.0;
    
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
        
        if (max < y){
            max = y;
        }
        
        if (y<=0.0){
            counter++;
        }
    }
    printf("Angle: %.2f\n", degree);
    printf("Distance: %.2f\n", x);
    printf("Max Height: %.2f\n\n", max);
    
}


