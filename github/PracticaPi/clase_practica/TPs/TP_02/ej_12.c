#include <stdio.h>
#include "../getnum.h"
#define delta printf("Es una letra\n")
#define del printf("No es una letra\n")

int
main(void){

    int a = getchar();
    int c;

    while((c = getchar()) != '\n' && c != EOF);


    (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z'))) ? delta : del;

}