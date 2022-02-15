#include <cstdio>
#include <cmath>
#include "formula.h"
#include "range.h"


int main(int argc, const char * argv[]) {
    
    int max_y = 10;
    int max_x = 20;
    
    double factor = 10;
    
    double angle = 45.0;
    
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
    
}
