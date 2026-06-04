#include <stdio.h>

int 
main(void)
{
    float a = 0.1;

    if (a == 0.1)
        printf("SON iguales\n");
    else
        printf("NO SON iguales: a vale %g que no es igual a 0.1\n",a);

    return 0;
}
// imprime que no son iguales, esto es porque 0.1 no se puede representar 
// exactamente en binario, entonces lo que se guarda, es un decimal muy
// parecido a 0.1, entonces cuando vaya a comparar no sera igual.
