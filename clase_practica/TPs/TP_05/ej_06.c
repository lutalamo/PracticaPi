#include <stdio.h>
#include <ctype.h>
#include "../getnum.h"
#define MAYUS(c)    ((c) - ('a' - 'A'))
#define MINUS(c)    ((c) + ('a' - 'A'))

int mayus(char a){
    if ((a >= 'a') && (a <= 'z')){
        a = MAYUS(a);
    }
    return a;
}

int minus(char a){
    if(a >= 'A' && a <= 'Z'){
        a = MINUS(a);
    }
    return a;
}

int nextChar(char a){
    if (a != EOF && isprint(a)){
        a += 1;
        }
        return a;
    
}

int nextLetter(char a){
    if(((a >= 'A') && (a <= 'Y')) || ((a >= 'a') && (a <= 'y'))){
    a += 1;
    }
    else if (a == 'z') a = 'a';
    else if (a == 'Z') a = 'A';
    return a;
}

int main(){
    printf("Elija una opcion:\n1_ Convertir de minuscula a matuscula\n2_ Convertir de mayuscula a minuscula\n3_ Imprimir siguiente caracter\n4_ Imprimir siguiente letra.\n");
    char o = getchar();
    getchar();
    if (o == '1'){
        char a = getchar();
        printf("%c\n", mayus(a));
    }
    else if (o == '2'){
        char a = getchar();
        printf("%c\n", minus(a));
    }
    else if (o == '3'){
        char a = getchar();
        printf("%c\n", nextChar(a));
    }
    else{
        char a = getchar();
        printf("%c\n", nextLetter(a));
    }
}
