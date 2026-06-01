#include <stdio.h>
#include "../random.h"
#define ROWS    10
#define COLS    5

int main(void){
    int numbers[ROWS] [COLS];

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
        numbers[j][i] = rand();
        printf("%d\t", numbers[i][j]);
        }
        putchar('\n');
    }

}