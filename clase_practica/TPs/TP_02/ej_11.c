#include <stdio.h>
#include "../getnum.h"

int main(void){

    int a = getchar();
    int b = getchar();

    int c;
    while((c = getchar()) != '\n' && c != EOF ){}

        if(a == EOF || b == EOF){
            printf("Faltan caracteres\n");
        }
        int mayor = (a > b) ? a : b;
        
        printf("=========================================\n");
        printf("El caracter mas grande en ASCII es: %c\n", mayor);
        printf("=========================================\n");

}