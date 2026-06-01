#include <stdio.h>
#include "../random.h"

int semilla(){
    srand((int) time(NULL));
}

void mezclar (int TAM, int array[TAM]){
    int num, indiceRand;
    for (int i = 0; i < TAM; i++){
        indiceRand = randInt(0, TAM - 1);
        num = array[i];
        array[i] = array[indiceRand];
        array[indiceRand] = num; 
    }
}


int main(){


}
