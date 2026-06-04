#include <stdio.h>
#include "../getnum.h"

#define DIM 50

int readArray(float ar[], int dim){
    int i = 0;
    float c;
    while (i < dim && (c = getfloat("")) > 0.0){
        ar[i++] = c;
    }
    return i;
}


void printArray(const float ar[], int dim);

int main(void){
    float ar[DIM];
}
