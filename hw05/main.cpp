#include <cstdio>
#include <cmath>
//#include "formula.h"
//#include "range.h"


int main(int argc, const char * argv[]) {
    
    int row = 6;
    int cols = 6;
    char c [row][cols];
    
    for (int i = 0; i<6; i++){
        c[i][6]='\0';
        int j = 0;
        while (j<6){
            if (j%2 != 0){
                c[i][j] = '0';
            }
            else {
                c[i][j] ='1';
            }
            printf("%c", c[i][j]);
            j++;
        }
        printf("\n");
    }
    
}
