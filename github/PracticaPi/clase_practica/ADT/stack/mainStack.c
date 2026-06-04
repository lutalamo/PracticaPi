#include <stdio.h>
#include "./stackADT.h"
#include <string.h>

int miStrcmp (char *s1, char *s2){
    return strcmp(s1, s2) == 0; //strcmp devuelve 0 si son iguales. por eso la comparacion
}

int main(){
    stackADT stack = newStack(strcmp);
    push(stack, "hola");
    push(stack, "como");
    push(stack, "estas");
    assert(pop(stack) == 5);
}