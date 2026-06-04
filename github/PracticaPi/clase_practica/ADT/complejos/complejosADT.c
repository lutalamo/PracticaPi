#include <stdio.h>
#include "./complejosADT.h"

struct complexCDT {
    double re;
    double im;
};

complexADT newComplex (double im, double re){
    complexADT z = (complexADT)calloc(1, sizeof(z));
    z -> re = re;
    z -> im = im; 
}

double realPart (complexADT z){
    return z -> re;
}
double imPart (complexADT z){
    return z -> im;
}

complexADT addComplex (const complexADT z1, const complexADT z2){
    complexADT res = (complexADT)calloc(1, sizeof(res));
    res -> re = (z1 -> re) + (z2 -> re);
    res -> im = (z1 -> im) + (z2 -> im);

    return res;
}

void freeComplex (complexADT z){
    free(z);
}