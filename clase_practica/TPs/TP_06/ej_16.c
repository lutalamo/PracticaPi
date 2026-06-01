// Escribir una función que reciba una matriz de números enteros y cuya cantidad 
// de filas está dada por la constante simbólica FILS y la cantidad de columnas
// por la constante simbólica COLS.
// Se asegura que ambas constantes son mayores o iguales a 2 (no hace falta validarlo)
// La función debe retornar 1 si la matriz es "ascendente", -1 si es "descendente" y 0 
// si no es ascendente ni descendente. Se dice que una matriz es ascendente si recorriendola 
// en forma ordenada por filas cada elemento es mayor o igual al anterior, En forma análoga se define una matriz descendente.
// El recorrido comienza por el elemento [0][0], continúa con el [0][1] y luego de terminar la primera 
// fila hace lo mismo con la segunda fila, tercer fila, etc.
#include <stdio.h>
#define FILS 4
#define COLS 6

int verifica ( int matriz[FILS][COLS] ){
    int asc = 1;
    int desc = 1;
    

    for ( int i = 0; i < FILS; i++ ){
        for ( int j = 0; j < COLS - 1; j++ ){
            if ( matriz[i][j] > matriz[i][j+1]){
                asc = 0;
            }
            else if ( matriz[i][j] < matriz[i][j+1] ){
                desc = 0;
            }
            
        }
    }
    if ( asc == 1 ) return 1;
    else if ( desc == 1 ) return -1;
    else return 0;

}
void printArray(int m[FILS][COLS]){
    for ( int i = 0; i < FILS; i++ ){
        for ( int j = 0; j < COLS; j++ ){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int m[FILS][COLS] = {
        {1, 2, 3, 8, 9, 22},
        {1, 2, 5, 40, 50, 54},
        {2, 5, 10, 11, 44, 50},
        {7, 9, 10, 12, 42, 45}
    };
    printf("%d\n", verifica (m));
    

}