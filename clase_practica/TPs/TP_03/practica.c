#include <stdio.h>
#include "../../getnum.c"

int main(){
    for (int i=9; i>=0; i>>1){
        
        putchar(i+'0');
    }
    return 0;
}