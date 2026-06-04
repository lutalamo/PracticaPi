// Hacer una función que reciba dos parámetros de entrada representando arreglos de números
// enteros positivos, ordenados en forma ascendente y sin elementos repetidos. El último elemento 
// de cada arreglo es -1. La función debe devolver en un tercer parámetro de salida un arreglo 
// ordenado con la unión de los dos primeros, también terminado en -1.
#include <stdio.h>

int unionOrdenada(const int v1[],int dim1, const int v2[], int dim2, int v3[]){
    int i = 0, j = 0, dim3 = 0;     

    while (v1[i] != -1 && v2[j] != -1){

        if (v1[i] < v2[j]){
            v3[dim3] = v1[i];
            i++;
        }
        else if (v1[i] > v2[j]){
            v3[dim3] = v2[j];
            j++;
        }
        else {
            v3[dim3] = v1[i];
            i++;
            j++;
        }
        dim3 += 1;
    }
    while (v1[i] != -1){            // Pongo lo que sobra
        v3[dim3++] = v1[i++];
    }
    while (v2[j] != -1){
        v3[dim3++] = v2[j++];
    }
    v3[dim3] = -1;  // Asigno -1 al final 

    return dim3;
}

int main(){
    
    int vec1[5] = {1, 2, 3, 4, -1};
    int vec2[7] = {1, 2, 3, 4, 6, 7, -1}; 
    int dim1 = 5, dim2 = 7;

    int vec3[dim1 + dim2];

    int dim3 = unionOrdenada(vec1, dim1, vec2, dim2, vec3);
    printf("La dimension sin repeticion: %d\n", dim3);
    printf("Vector sin repeticiones: ");
    for (int i = 0; i < dim3; i++){
        printf("%d ", vec3[i]);
    }
    printf("\n");
}