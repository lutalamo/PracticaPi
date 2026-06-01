#include <assert.h>
#include "random.h"
#include <stdio.h>
#include <ctype.h>
#include "getnum.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

    
int producto_punto (int dim, const int m1[][dim], const int m2[][dim], int i, int j){
    int suma = 0;
    for (int k = 0; k < dim; k++){
        suma += m1[i][k] * m2[k][j];
    }
    return suma;
}

void productoMat(unsigned int dim, const int m1[][dim], const int m2[][dim], int m3[][dim]){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++){
            m3[i][j] = producto_punto(dim, m1, m2, i, j);
        }
    }
}
