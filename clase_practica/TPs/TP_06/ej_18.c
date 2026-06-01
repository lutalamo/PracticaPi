#include <assert.h>
#include "random.h"
#include <stdio.h>
#include <ctype.h>
#include "getnum.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define COLS 4

int  contiene (const int fila1[], const int fila2[], int dim){   // si f1 esta contenida en f2
    int i = 0, j = 0;

    while (i < dim){
        if (j == dim){  // f2 se quedo sin elementos
            return 0;
        }

        if (fila1[i] < fila2[j]){   // f1 no es amiga de f2
            return 0;
        }
        else if (fila1[i] > fila2[j]){
            j++;
        }
        else {      // cuando son iguales
            i++;
        }
    }
    return i == dim;
} 

int vecEnMatriz (int col, const int vec[], const int m[][col], int fils){
    for (int i = 0; i < fils; i++){
        if (contiene(vec, m[i], col)){
            return 1;
        }
    }
    return 0;
}

int matrizAmigas (int cols, const int m1[][cols], int f1, const int m2[][cols], int f2){
    for (int i = 0; i < f1; i++){
        if (!vecEnMatriz(cols, m1[i], m2, f2)){
            return 0;
        }
    }
    return 1;
}

int sonAmigas (int col, const int m1[][col], int fil1, const int m2[][col], int fil2){

    if (matrizAmigas(col, m1, fil1, m2, fil2)){
        return 1;
    }
    if (matrizAmigas(col, m2, fil2, m1, fil1)){
        return 2;
    }
    return 0;
}



int
main(void)
{
  int m1[][COLS] = {{0,1,2,3}, {4,4,5,6}, {7,8,8,9}};
  int m2[][COLS] = {{0,1,2,3}, {-3,7,8,9}, {-1,3,4,7}, {4,5,6,8}};
  int m3[][COLS] = {{2,3,3,7}};
  assert(sonAmigas(4, m1,3,m2,4)==1);
  assert(sonAmigas(4, m1,1,m2,4)==1);
  assert(sonAmigas(4, m1,2,m2,4)==1);
  assert(sonAmigas(4, m1,2,m2,2)==0);
  assert(sonAmigas(4, m2,4,m1,3)==2);
  assert(sonAmigas(4, m1,3,m3,1)==0);
  assert(sonAmigas(4, m3,1,m1,3)==0);
  int res = sonAmigas(4, m1,3,m1,3);
  assert(res==1 || res==2);

  // Agregamos tests "grandes"
  const unsigned int BIG_ROWS1 = 1000;
  const unsigned int BIG_ROWS2 = 1200;
  int big1[BIG_ROWS1][COLS];
  int big2[BIG_ROWS2][COLS];

  // big1: filas ordenadas, cada fila distinta
  for (unsigned int i = 0; i < BIG_ROWS1; i++) {
    for (unsigned int j = 0; j < COLS; j++) {
      big1[i][j] = (int)(i + j);
    }
  }

  // big2: contiene todas las filas de big1 más algunas filas extra al final
  for (unsigned int i = 0; i < BIG_ROWS2; i++) {
    for (unsigned int j = 0; j < COLS; j++) {
      if (i < BIG_ROWS1) {
        big2[i][j] = (int)(i + j);         // mismas filas que big1
      } else {
        big2[i][j] = (int)(10000 + i + j); // filas extra que no están en big1
      }
    }
  }

  // Todas las filas de big1 están en big2, pero no al revés
  assert(sonAmigas(COLS, big1, BIG_ROWS1, big2, BIG_ROWS2) == 1);
  assert(sonAmigas(COLS, big2, BIG_ROWS2, big1, BIG_ROWS1) == 2);

  const unsigned int MANY_ROWS  = 500;
  const unsigned int MANY_COLS  = 200;
  int bigA[MANY_ROWS][MANY_COLS];
  int bigB[MANY_ROWS][MANY_COLS];
  int bigC[MANY_ROWS + 100][MANY_COLS];

  // bigA y bigB idénticas, filas ordenadas
  for (unsigned int i = 0; i < MANY_ROWS; i++) {
    for (unsigned int j = 0; j < MANY_COLS; j++) {
      bigA[i][j] = (int)(i * 2 + j);
      bigB[i][j] = (int)(i * 2 + j);
    }
  }

  // bigC contiene todas las filas de bigA y algunas filas extra
  for (unsigned int i = 0; i < MANY_ROWS + 100; i++) {
    for (unsigned int j = 0; j < MANY_COLS; j++) {
      if (i < MANY_ROWS) {
        bigC[i][j] = (int)(i * 2 + j);        // mismas filas que bigA
      } else {
        bigC[i][j] = (int)(50000 + i + j);    // filas extra
      }
    }
  }

  // Matrices grandes idénticas: puede devolver 1 o 2
  int resBig = sonAmigas(MANY_COLS, bigA, MANY_ROWS, bigB, MANY_ROWS);
  assert(resBig == 1 || resBig == 2);

  // bigA es subconjunto de bigC (en filas), pero no al revés
  assert(sonAmigas(MANY_COLS, bigA, MANY_ROWS, bigC, MANY_ROWS + 100) == 1);
  assert(sonAmigas(MANY_COLS, bigC, MANY_ROWS + 100, bigA, MANY_ROWS) == 2);
  puts("OK!");

  return 0;
}