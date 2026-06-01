#include <stdio.h>

int repOrdenados(int dim, const int v1[], int v2[]){
    int dim1 = 0;

    for (int i = 0; i < dim; i++){
        v2[dim1] = v1[i];               // Guardo elemento actual

        while (i+1 < dim && v1[i] == v1[i+1]){  // Salteo repetidos
            i++;
        }

        dim1 += 1;
    }
    return dim1;
}

int main(){
    
    int vec1[5] = {1, 2, 2, 2, 5};
    int vec2[5]; 

    int dim2 = repOrdenados(5, vec1, vec2);
    printf("La dimension sin repeticion: %d\n", repOrdenados(5, vec1, vec2));
    printf("Vector sin repeticiones: ");
    for (int i = 0; i < dim2; i++){
        printf("%d ", vec2[i]);
    }
    printf("\n");
}