#include <stdio.h>

int main(){
    printf ("Esto ocupa un char: %zu\n", sizeof(char));
    printf ("Esto ocupa un short: %zu\n", sizeof(short));
    printf ("Esto ocupa un int: %zu\n", sizeof(int));
    printf ("Esto ocupa un long: %zu\n", sizeof(long));
    printf ("Esto ocupa un long long: %zu\n", sizeof(long long));
    printf ("Esto ocupa un float: %zu\n", sizeof(float));
    printf ("Esto ocupa un double: %zu\n", sizeof(double));
    printf ("Esto ocupa un long double: %zu\n", sizeof(long double));
    printf ("Esto ocupa un pointer: %zu\n", sizeof(void*));
}
