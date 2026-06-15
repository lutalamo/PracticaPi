#include <stdio.h>
#include <ctype.h>
#include <string.h>

// ejercicio 2 - parcial 1 - 20/04/2026
int firstRepeated (const unsigned char arr[], unsigned dim, int * pos){
    char aparece[16] = {0};
    for (int i = 0; i < dim; i++){

        unsigned char byte = arr[i/2];
        char num = (i % 2 == 0) ? (byte >> 4) & 0x0F : byte & 0x0F;

        if (aparece[num] != 0){
            * pos = i;
            return num;
        }
        else {
            aparece[num] = 1;
        }
    }
    *pos = -1;
    return -1;
}

// ejercicio 1 - parcial 1 - 20/04/2026
int esConsecutivo (char c1, char c2){
    if (isalpha(c1) && isalpha(c2)){
        c1 = tolower(c1);
        c2 = tolower(c2);
        return (c2 - c1 == 1) ? 1 : 0;
    }
    return 0;
}

void eliminaConsecutivosAlfabeticos (char *s){
    int j = 1;
    for (int i = 1; s[i] != '\0'; i++){
        if (!esConsecutivo(s[i-1], s[i])){
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
    return;
}