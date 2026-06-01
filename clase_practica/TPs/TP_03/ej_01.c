#include <stdio.h>

int main(){
    int c;
    if ((c=getchar()) != EOF){

        if ('0' <= c && c <= '9'){
            printf("El caracter es un numero\n");
            return 0;
        }
        else if ('a' <= c && c <= 'z'){
            printf("El caracter es una letra minuscula\n");
            return 0;
    }
        else if ('A' <= c && c <= 'Z'){
            printf("El caracter es una letra mayuscula\n");
            return 0;
    }
}
    printf("Caracter ingresado invalido\n");
    return 0;
}