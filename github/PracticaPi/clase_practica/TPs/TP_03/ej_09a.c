#include <stdio.h>
#include "../getnum.h"

// write a program to count blank, tabs and newlines

int countBlank (){
    int count = 0;
    int c;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n'){
            count++;
        }
    }
    return count;
}

int main(){
    int x;
    printf("Ingrese su texto aqui abajo, para terminar de escribir use: Control + D\n");
    x = countBlank();

    printf ("Cantidad: %d\n", x);
    
    return 0;
}