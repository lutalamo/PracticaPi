#include <stdio.h>

void ordenar(int cols, int mat[][cols], int filas, int c){

    for ( int i = 0; i < filas - 1; i++ ){
        int min = i;

        for ( int j = i + 1; j < filas; j++){
            if ( mat[j][c] < mat[min][c] ){
                min = j;
            }
        }
        int temp = mat[i][c];
        mat[i][c] = mat[min][c];
        mat[min][c] = temp;
    }
}
void printArray(int cols, int m[][cols], int filas){
    for ( int i = 0; i < filas; i++ ){
        for ( int j = 0; j < cols; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int m[3][8] = {
        {1, 2, 3, 8, 4, 22, 88, 34},
        {3, 1, 5, 54, 3, 54, 11, 9},
        {2, 0, 1, 11, 44, 0, 2, 1}
    };
    ordenar (8, m, 3, 7);

    printArray (8, m, 3);
}