#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../getnum.h"

int main(void){
    int c;
    char min;
    int found = 0;

    while ( (c = getchar()) != EOF){
        
        if ( !(isalpha(c) || c == ' ') ) break; /* Chequeo que sea letra o espacio */

        if (isalpha(c)){
            if(!found){             /* Aca encuentro la primera letra, funciona como interruptor */
                min = c;
                found = 1;
            }
            else if ( c < min){
                min = c;
            }
        }
        }
    if (found){
        printf("La letra mas chica es: %c\n", min);
    }
    else printf("No se ingresaron letras validas\n");
        
}