#include <cstdio>
#include <cmath>

int main(int argc, const char * argv[]) {
    double y = 1000; //height above ground
    double v = 0; // velocity of the falling object
    
    double time = 0; // time it take for the object to reach the ground
    double dt = 1.0; //change in time
    
    double g = -9.81; //gravity
    double C = 1.0; //drag coefficient
    double A = 1.0; //Area of the Object
    double p = 1.2; //denisty of the air
    double m = 80.0; //mass of the object
    
    double a; //accelation
    
    //a = -g+(0.5*C*A*p*(pow(v,2.0)/m));
    //printf("%.2lf this is the area\n", a);

    
    //y = y-v*dt;

    //while loop of the falling
    while (y >= 0.0){
        a = -g+(0.5*C*A*p*(pow(v,2.0)/m));
        time += dt;
        
        v = v+a*dt; //change in velocity
        y = y-v*dt; //change in position or height of the object
        printf("%.2lf m %.2lf sec\n", y, time);
    }
    printf("\nFinal : %.2lf sec\n",  time);
}
