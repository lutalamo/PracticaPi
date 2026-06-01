#include <stdio.h>
#include "../getnum.h"

int main(void){
    for (int a = 20; a >= -10; a -= 6){
        if (a < 20){
            printf(",");
        }
            printf("%d", a);
    }
            printf("\n");
            return 0;
}