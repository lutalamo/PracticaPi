#include <stdio.h>

char c = 't';
int
main(void){
    printf("Esto imprime con %%c: %c\n", c);
    printf("esto imprime con %%d: %d\n", c);
    printf("Esto imprime con %%f: %f\n", c);
}