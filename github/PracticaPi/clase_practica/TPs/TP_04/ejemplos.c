#include <stdio.h>
#define MAYOR(n1, n2, r)    r = (n1) > (n2) ? (n1) : (n2);

int
main(void){
    int r;
    MAYOR(2, 5, r);
    printf("%d\n", r);

}
