#include <stdio.h>
#include <math.h>

double desviacion(const unsigned char arr[], int n) {
    // Extraer los n números de los nibbles
    int nums[n];
    for (int i = 0; i < n; i++) {
        unsigned char byte = arr[i / 2];
        if (i % 2 == 0)
            nums[i] = (byte >> 4) & 0x0F;   // nibble alto
        else
            nums[i] = byte & 0x0F;           // nibble bajo
    }

    // Calcular media
    double suma = 0;
    for (int i = 0; i < n; i++)
        suma += nums[i];
    double media = suma / n;

    // Calcular varianza
    double varianza = 0;
    for (int i = 0; i < n; i++)
        varianza += (nums[i] - media) * (nums[i] - media);
    varianza /= n;

    return sqrt(varianza);
}
int main(){
    unsigned char arr[] = { 0x37, 0xF2, 0x03 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int dim = n * 2;
    int arr1[dim];

    separar (arr, n);
    
    printf("Vector separado: ");
    for ( int i = 0; i < dim; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");
}