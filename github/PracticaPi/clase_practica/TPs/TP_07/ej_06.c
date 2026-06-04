#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../getnum.h"
#include "../random.h"
#define X 3

void generarAleatorio(int vec[], int n){
    int digitos[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 9; i > 0; i--){
        int j = randInt(0, i);
        int tmp = digitos[i];
        digitos[i] = digitos[j];
        digitos[j] = tmp;
    }
    // me aseguro que no empiece con 0
    if (digitos[0] == 0){
            int tmp = digitos[0];
            digitos[0] = digitos[1];
            digitos[1] = tmp;
        
    }

    for(int j = 0; j<n; j++){
        vec[j] = digitos[j];
    }
}

int elegirNivel(void){
    int n = getint("Ingrese un numero entre 1 y 10: ");
    if (n>=1 && n<=10) return n;
}

void leerNumero(int vec[], int n){
    int valor = getint("Ingrese un numero de %d digitos no repetidos: ", n);
    
    // descompongo el numero y cargo al vector
    for (int i=n-1; i>=0; i--){
        vec[i] = valor % 10;
        valor /= 10;
    }
    if (valor != 0){
        printf("Cantidad de digitos incorrecta.\n");
        leerNumero(vec, n);
        return;
    }
}

int cantidadBien(int vIncognita[], int vNumero[], int n){
    int contador = 0;
    for (int i=0; i<n; i++){
        if (vIncognita[i] == vNumero[i]){
            contador++;
        }
    }
    return contador;
}

int cantidadRegular(int vIncognita[], int vNumero[], int n){
    int contador = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i != j && vIncognita[i] == vNumero[j]){
                contador++;
            }
        }
    }
    return contador;
}

int coincideNumero(int vr[], int vi[], int n){
    int bien = cantidadBien(vr, vi, n);
    int regular = cantidadRegular(vr, vi, n);

    printf("Cantidad BIEN: %d\tCantidad REGULAR: %d\n", bien, regular);

    if (bien == n){ //El usuario gano
        return 1;
    }
    else return 0;
}

int main(void){
    int incognita[X];
    int numero[X];
    int nivel;

    
    nivel = getint("Ingrese cantidad de intentos: ");

    // genero el aleatorio
    randomize();
    generarAleatorio(incognita, X);


    // bucle del juego
    int intento = 0;
    int acerto = 0; // 1 si acerto 0 si no

    while (intento < nivel && !acerto){
        printf("\nIntento %d/%d\n", intento+1, nivel);

        leerNumero(numero, X);
        acerto = coincideNumero(incognita, numero, X); 
        intento++;
    }

    if(acerto){
        printf("Ganaste en %d intentos\n", intento);
    }
    else {
        printf("Perdiste. Se agotaron los intentos.\n");
        printf("El numero era: ");
        for (int i=0; i<X; i++){
            printf("%d ", incognita[i]);
        }
        printf("\n");
    }
}