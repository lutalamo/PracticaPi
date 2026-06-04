#include <stdio.h>
/* imprime la tabla Fahrenheit-Celcius 
            para fahr = 0, 20, ..., 300 */

int 
main(){
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;  /* limite inferior de la tabla de temperaturas */
    upper = 300; /* limite superior */
    step = 20; /* tamaño de incremento */ 

    fahr = lower;
    printf("Fahrenheit\tCelcius\n");
    while (fahr <= upper) {
        celcius = 5 * (fahr-32)/9;
        printf("%d\t\t%d\n", fahr, celcius);
        fahr += step;
    }
}