#include <stdio.h>
#include "../getnum.h"

int main(void){
    for (int a = 3; a <= 23; a += 5){
        if ( a > 3){
            printf(",");
        }
        printf("%d", a);
    }
    printf("\n");
    return 0;
}