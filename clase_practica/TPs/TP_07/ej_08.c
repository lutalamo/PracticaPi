#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../getnum.h"
#include "../random.h"

#define CANT_BOLILLAS 90
#define CANT_NUM_CARTON 15

void generarBolillero(int bolillero[], int cant){
    int bolillero[CANT_BOLILLAS];
    for (int i=0; i<cant; i++){
        bolillero[i] = i+1;
    }
    // mezclo el bolillero
    for (int i=CANT_BOLILLAS-1; i>0; i++){
            int j = randInt(0, i);
            int tmp = bolillero[i];
            bolillero[i] = bolillero[j];
            bolillero[j] = tmp;

    }
}

void generarCarton(int carton[]){
    int bolillero[CANT_BOLILLAS];
    generarBolillero(bolillero, CANT_BOLILLAS);
    for (int i = 0; i<CANT_NUM_CARTON; i++){
        carton[i] = bolillero[i];
    }
}

int sacarBolilla(int bolillero[], int * cantBolillas){
    if (*cantBolillas == 0)
        return -1;  // No hay mas
    
    int bolilla = bolillero[*cantBolillas - 1];
    (*cantBolillas)--;
    return bolilla;
}

int buscarBolilla(int carton[], int bolilla){
    for (int i=0; i < CANT_NUM_CARTON; i++){
        if (carton[i] == bolilla){
            carton[i] = -1; //tacho el numero como que ya salio
            return 1; 
        }
    }
    return 0;
}

int controlarCarton ( int carton[], int bolilla){
    int encontrada = buscarBolilla(carton, bolilla);

    if(!encontrada) return 0; // si no esta, no se cambia nada

    int cantLineas = 0; 
    for (int l=0; l<3; l++){
        int completa = 1;
        for (int f=0; f<5; f++){
            if(carton[l * 5 + f] != -1){
                completa = 0;
            }
        }
        if(completa){     // si hay una linea completa
            cantLineas++; // sumamos uno
        }
    }
    return cantLineas;
}

