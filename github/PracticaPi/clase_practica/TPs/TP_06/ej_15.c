#include <stdio.h>
#define ANCHO 6
#define ALTO 4

void suavizar ( int matriz[ALTO][ANCHO], int w ){
    if ( w < 3 || w % 2 == 0 ){
        return; // no hago nada, w invalido
    }
    int m_aux[ALTO][ANCHO];
    for ( int i = 0; i < ALTO; i++ ){
        for ( int j = 0; j < ANCHO; j++ ){
            
            int suma = 0;
            int cuenta = 0;

            // Defino los bordes de la ventana centrada
            int fila_inicio = i - w/2;
            int fila_fin = i + w/2;
            int col_inicio = j - w/2;
            int col_fin = j + w/2;

            for ( int x = fila_inicio; x <= fila_fin; x++ ){
                for ( int y = col_inicio; y <= col_fin; y++ ){
                    if ( x >= 0 && x < ALTO && y >= 0 && y < ANCHO ){
                        suma += matriz[x][y];
                        cuenta++;
                    }
                }
            }
            float promedio = (float)suma / cuenta;
            int valor = (int)(promedio + 0.5);

            // Asigno el promedio a la matriz aux
            m_aux[i][j] = valor; 
        }
    }
    for ( int i = 0; i < ALTO; i++ ){
        for ( int j = 0; j < ANCHO; j++ ){
            matriz[i][j] = m_aux[i][j];
        }
    }
}
void printArray(int m[ALTO][ANCHO]){
    for ( int i = 0; i < ALTO; i++ ){
        for ( int j = 0; j < ANCHO; j++ ){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int m[ALTO][ANCHO] = {
        {1, 2, 3, 8, 4, 22},
        {3, 1, 5, 54, 3, 54},
        {2, 0, 1, 11, 44, 0},
        {12, 5, 3, 12, 42, 45}
    };
    suavizar (m, 3);
    printArray(m);

}