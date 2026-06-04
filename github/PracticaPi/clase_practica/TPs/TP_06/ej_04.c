// Escribir una función que reciba un vector desordenado de números enteros y su dimensión, 
// y construya otro vector eliminando los valores repetidos. La función deberá retornar en 
// su nombre la dimensión del nuevo vector (La función solicitada  no debe superar las 10 líneas).

#include <stdio.h>


int numRep(int dim, int v1[dim], int v2[]){
    int dim1 = 0;                 // contara la dimension del nuevo vector
    
    for ( int i = 0; i < dim - 1; i++){
        int repetido = 0;
        for ( int j = i + 1; j < dim; j++ ){
            if (v1[i] == v1[j]){
                repetido = 1;
                break;
            }
        }
        if (!repetido){
            v2[dim1] = v1[i];
            dim1 += 1;
        }
    }
    return dim1;
}

int main(){
    
    int vec1[5] = {1, 4, 3, 1, 0};
    int vec2[5]; 

    int dim2 = numRep(5, vec1, vec2);
    printf("La dimension sin repeticion: %d\n", numRep(5, vec1, vec2));
    printf("Vector sin repeticiones: ");
    for (int i = 0; i < dim2; i++){
        printf("%d ", vec2[i]);
    }
    printf("\n");
}