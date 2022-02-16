#include <cstdio>
#include <cmath>
#include "formula.h"
#include "range.h"


int main(int argc, const char * argv[]) {
    
    int max_y = 101;
    int max_x = 201;
    
    double factor = 20;
    
    double angle = 40.0;
    
    char **c;
    c = new char *[max_y];
    for (int i = 0; i<max_y; i++){
        c[i] = new char [max_x];
    }
    
    for (int i = 0; i<max_y; i++){
        int j = 0;
        while (j!= max_x){
            c[i][j] = ' ';
            j++;
        }
    }
    
    coordinate(angle, c, factor);
    
    for (int i = max_y-1; i>0; i--){
        int j = 0;
        while(j!=max_x-1){
            printf("%c",c[i][j]);
            j++;
        }
        printf("\n");
    }
    
}
