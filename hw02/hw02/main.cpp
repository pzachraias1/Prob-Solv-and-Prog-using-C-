#include <cstdio>
#include <cmath>
#include "function.h"
#include <cstdlib>
#include <ctime>

int main(int argc, const char * argv[]) {
    //Initializing and declarating the variables
    double x, vx, ax; //the displacement, velocity, and acceleration of horizontal axis
    double y, vy, ay; //displacement, celocity, and acceleration of the vertical axis
    vx = 0;
    vy = 0;
    x = 0;
    y = 0;
    
    srand((unsigned)time(0));
    double degree;
    degree = rand()%90 + 1;
    double angle;
    angle = degreeToRadian(degree);
    
    double iniV = 250.0;// initial velocity of the muzzle when it fire
    
    
    double t = 0.0;// counter for the time
    double  dt = 1.0;// the amount of sec that time change or increae
    
    double m = 30.0; //mass of the object that is being thrown or fired
    double dc = 0.45; //drag coefficient
    double A = 0.03; // area of the object
    double p = 1.2;// density of the air
    const double g = 9.81;
    
    vx = iniV*cos(angle);
    vy = iniV*sin(angle);
    
    double v;
    double d;
    
    /**
    v = getVelocity(vx, vy);//velocity
    d = getDrag(dc, A, p, v, m);//drag
    ax = getXAcceleration(d, vx, v);
    ay = getYAcceleration(d, vy, v, g);
    vx = getXVelocity(vx, ax, t);
    vy = getYVelocity(vy, ay, t);
    x = getX(x, vx, t);
    y = getY(y, vy, t);
     */
    
    int counter =1;
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
        
        if (y<=0){
            counter++;
        }
     
        printf("At time: %.2f sec --> (%.2f, %.2f)\n",t,x,y);
        
    }
    
    printf("\nTherefore, when time is at %.2f second, then the cannon ball will be on the ground at %.2f meters away\n", t, x);
    printf("when the angle of the cannon is %.2f degree\n", degree);

}
