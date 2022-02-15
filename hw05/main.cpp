#include <cstdio>
#include <cmath>
//#include "formula.h"
//#include "range.h"


int main(int argc, const char * argv[]) {
    
    int max_y = 6;
    int max_x = 6;
    char c [max_y][max_x];
    
    for (int y = max_y; y>0; y--){
        
        int x = 0;
        while (x != (max_x)){
            
            if (x == (y-1)){
                c[y][x] = '*';
            }
            else {
                c[y][x] = '-';
            }
            printf("%c", c[y][x]);
            x++;
        }
        printf("\n");
     
    }
    
}
