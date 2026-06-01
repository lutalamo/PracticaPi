#include <stdint.h>
#include "../random.h"
#include <ctype.h>
#include <math.h>

#define SIZE ('Z' - 'A'+1)
int cuenta(void)
{
    int c;
    int count[SIZE] = {0};

    while ( ((c = getchar()) != 'EOF') && (c != '\n')) {
        c = toupper(c);
        if (isalpha(c))
            count[c - 'A']++;
    }
    for (int i = 0; i<SIZE; i++)
         if (count[i])
           printf("Cant. de %c= %d\n", i + 'A', count[i]);

    return 0;
}

void semilla(void){
    srand((int) time(NULL));
    return 0;
}

int main(void){
        semilla();

}