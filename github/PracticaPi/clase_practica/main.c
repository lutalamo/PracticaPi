#include <assert.h>
#include "random.h"
#include <stdio.h>
#include <ctype.h>
#include "getnum.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ejercicio 1
int sumaVec (const int v[], unsigned int dim){
    if (dim == 0){
        return 0;
    }
    return v[dim-1] + sumaVec(v, dim-1);
}

// ejercicio 2
int suma (int num){
    if (num < 0) return suma(-num);

    if (num == 0) return 0;
    
    return num%10 + suma(num/10);
}

// ejercicio 3
double productoEsc (double *v1, double *v2, unsigned int dim){
    if (dim == 0) {
        return 0; 
    }
    return v1[dim-1] * v2[dim-1] + productoEsc(v1, v2, dim-1);
}

// ejercicio 6
int aux (char *s, int i, int j){
    if (i >= j) return 1;
    if (s[i]!= s[j]) return 0;
    return aux(s, i+1, j-1);
}

int palindromo (char *s){
    return aux(s, 0, strlen(s) - 1);
}

//ejercicio 7
int busquedaBinaria(int *arr, int dim, int target){
    if (dim <= 0) return 0;
    
    int medio = dim/2;
    if (target == arr[medio]) return 1;

    if (target < arr[medio]){
        // paso el subvector de la izq, hasta medio
        return busquedaBinaria(arr, medio, target); 
    }
    else {
        return busquedaBinaria(arr + medio + 1, dim - medio - 1, target);
    }
}

// ejercicio 11
void boolChange (int matriz, int dim, int fila, int col){
    
}