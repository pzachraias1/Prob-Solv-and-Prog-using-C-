#include <cstdio>
#include <cmath>
#include "formula.h"
#include "range.h"


int main(int argc, const char * argv[]) {
    
    double angle = 0.0;
    
    double max =0.0;
    double distance =0.0;
    
    double *ptrMax = &max;
    double *ptrDistance = &distance;
    
    FILE* fp = fopen("Cannon_Angle_Guide.txt","w");
    
    while (angle <= 90.0){
        max = 0;
        distance=0;
        
        distHeight(angle, &max, &distance);

        printf("Angle: %.2f\n",angle);
        printf("Max Height: %.2f meters\n", *ptrMax);
        printf("Distance: %.2f meters\n\n", *ptrDistance);
        
        fprintf(fp, "Angle: %.2f\n",angle);
        fprintf(fp, "Max Height: %.2f meters\n", *ptrMax);
        fprintf(fp, "Distance: %.2f meters\n\n", *ptrDistance);
        
        angle ++;
    }
    
    fclose(fp);
    
    printf("Everything has been added to Cannon_Angle_Guide.txt\n\n");
    
}
