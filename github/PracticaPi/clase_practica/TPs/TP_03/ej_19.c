#include <stdio.h>
#include <ctype.h>

int main(){
    int c;
    int count = 0;
    while ( (c = getchar()) != EOF && c > '0' && c < '9' ){

        if ( c == '5') {
            count++;
        }        
    }
    printf("%d\n", count);
}