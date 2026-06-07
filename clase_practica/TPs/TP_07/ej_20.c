#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char * TAlumnos[];

char ** aprobados (TAlumnos nombres, const int notas[]){
    // cuento aprobados
    int count = 0;
    for (int i = 0; nombres[i][0] != '\0'; i++){
        if (notas[i] >= 4) count++;
    }

    char **ans = malloc ((count + 1) * sizeof(*ans));

    int j = 0;
    for (int i = 0; nombres[i][0] != '\0' ; i++){
        if (notas[i] >= 4){
            ans[j] = strdup(nombres[i]);
            j++;
        }
    }
    ans[j] = NULL;
    return ans;
}