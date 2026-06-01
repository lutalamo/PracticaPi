#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//Escribir un programa que convierta enteros de una base a otra. Los números entre y después de los 
// símbolos '<' y '>' indican la base de entrada y de salida respectivamente. Dichos números serán decimales entre 2 y 10.

// Ejemplo: la cadena de entrada < 5 > 2  indica que leerá números enteros en base 5 y los imprimirá en 
// su equivalente binario. Luego, si se ingresa 41 se lo deberá pasar a 10101.

int pasar_a_decimal(int n, int b1){
    int i=1;
    int resto, num=0;
    
    while (n>0){
        resto = n%10;
        num += resto*i;
        n /= 10;
        i *= b1;
    }
    return num;
}
int * pasar_a_base(int n, int b2, int *cant_dig){
    *cant_dig = 0;
    int resto;
    int num = 0;
    int capacidad = 4;
    int * v = malloc(capacidad * sizeof(int));
    
    while(n>0){
        if ( *cant_dig >= capacidad){
            capacidad *= 2;
            int * tmp = (int*) realloc(v, capacidad * sizeof(int));
            if (tmp == NULL){
                free(v);
                return NULL; // fallo de memoria
            }
            v = tmp; // actualizo ahora
        }
        resto = n % b2;
        v[(*cant_dig)++] = resto;
        n /= b2;
    }
    return v;
}

int * convertir(unsigned int b1, unsigned int b2, int n, int * len){
    int decimal = pasar_a_decimal(n, b1);
    int * resultado = pasar_a_base(decimal, b2, len);
    
    // Invertir el vector
    for ( int i=0; i < *len/2; i++){
        int temp = resultado[i];
        resultado[i] = resultado[*len-1 - i];
        resultado[*len-1 - i] = temp;
    }
    return resultado;
}

int main(){
    int len;
    int * v = convertir(5, 2, 41, &len);
    for (int i = 0; i < len; i++){
        printf("%d ", v[i]);
    }
    free(v);
    char * p = "lapicera";
}