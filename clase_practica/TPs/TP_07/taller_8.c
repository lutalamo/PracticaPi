#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CANT 4
#define BLOCK 20

// Lee en s hasta maxDim caracteres inclusive
// La funcion lee hasta el \n

char* getLine(void) {
    char * s = NULL;
    int c;
    int len = 0;
    int capacidad = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        // Si se llena el buffer, lo agrandamos
        if (len + 1 >= capacidad) {
            capacidad = (capacidad == 0) ? 16 : capacidad * 2;
            s = realloc(s, capacidad);
            if (s == NULL) {
                printf("Error al reservar memoria\n");
                exit(1);
            }
        }
        s[len++] = (char)c;
    }

    if (len == 0 && c == EOF) {
        free(s);
        return NULL;
    }

    // Terminar el string
    s = realloc(s, len + 1);
    s[len] = '\0';

    return s;
}

int main(void) {
    char *palos[CANT];

    for (int i = 0; i < CANT; i++) {
        printf("Ingrese texto %d: ", i + 1);
        palos[i] = getLine();
    }

    printf("\n--- Resultados ---\n");
    for (int i = 0; i < CANT; i++) {
        puts(palos[i]);
    }

    // Liberar memoria
    for (int i = 0; i < CANT; i++) {
        free(palos[i]);
    }

    return 0;
}

char * getLine(){
    char * ans = NULL;
    int c, i=0;

    while ((c = getchar()) != '\n'){
        if (i%BLOCK == 0){
            ans = realloc(ans, i + BLOCK);
        }
        ans[i++] = c;
    }
    ans = realloc(ans, i+1);
    ans[i]=0;
    return ans;
}