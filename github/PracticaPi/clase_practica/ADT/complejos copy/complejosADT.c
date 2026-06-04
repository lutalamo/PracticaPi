#include <stdio.h>
#include "./complejosADT.h"
#include <math.h>

struct complejoCDT{
    double re;
    double im;
};

complejoADT newCompl (double re, double im){
    complejoADT new = malloc(sizeof(*new));
    new->re = re;
    new->im = im;
    return new;
}

double getReal (complejoADT num){
    return num->re;
}

double getIm (complejoADT num){
    return num->im;
}

complejoADT suma(complejoADT num1, complejoADT num2){
    complejoADT ans = malloc(sizeof(*ans));
    ans->re = num1->re + num2->re;
    ans->im = num1->im + num2->im;
    return ans;
}

double modulo(complejoADT num){
    double ans = sqrt((num->re * num->re) + (num->im * num->im));
    return ans;
}

void freeComplejo (complejoADT num){
    free(num);
}