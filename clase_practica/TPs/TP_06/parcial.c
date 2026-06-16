#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define DIRECCIONES 8

// ejercicio 2 - parcial 1 - 20/04/2026
int firstRepeated(const unsigned char arr[], unsigned dim, int *pos) {
  char aparece[16] = {0};
  for (int i = 0; i < dim; i++) {

    unsigned char byte = arr[i / 2];
    char num = (i % 2 == 0) ? (byte >> 4) & 0x0F : byte & 0x0F;

    if (aparece[num] != 0) {
      *pos = i;
      return num;
    } else {
      aparece[num] = 1;
    }
  }
  *pos = -1;
  return -1;
}

// ejercicio 1 - parcial 1 - 20/04/2026
int esConsecutivo(char c1, char c2) {
  if (isalpha(c1) && isalpha(c2)) {
    c1 = tolower(c1);
    c2 = tolower(c2);
    return (c2 - c1 == 1) ? 1 : 0;
  }
  return 0;
}

void eliminaConsecutivosAlfabeticos(char *s) {
  int j = 1;
  for (int i = 1; s[i] != '\0'; i++) {
    if (!esConsecutivo(s[i - 1], s[i])) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
  return;
}

// ejercicio 3 - parcial - 20/04/2026

int direcciones[][2] = {
  {-1,  0},   // arriba
  {1,   0},   // abajo
  {0,  -1},   // izquierda
  {0,   1},   // derecha
  {-1, -1},   // diag sup-izq
  {-1,  1},   // diag sup-der
  {1,  -1},   // diag inf-izq
  {1,   1}    // diag inf-der
};

int buscaEnDire (unsigned dim, char tablero[dim][dim], int pos_y, int pos_x){
  char pieza = tablero[pos_y][pos_x]; 
  int count = 0;

  for (int k = 0; k < DIRECCIONES; k++){
    
    int f = pos_y + direcciones[k][0];
    int c = pos_x + direcciones[k][1];

    while (pos_y >= 0 && pos_y < dim && pos_x >= 0 && pos_x < dim){
      if (tablero[pos_y][pos_x] != ' '){
        if (isupper(pieza) && islower(tablero[pos_y][pos_x])){
          count++;
        }
        else if (islower(pieza) ){

        }
      }

      pos_y += direcciones[k][0];
      pos_x += direcciones[k][1];
    }
  }
  return count;
}

int damas (unsigned dim, char tablero[dim][dim]){

  int count = 0;

  for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if (tablero[i][j] == 'd' || tablero[i][j] == 'D'){
        count += buscaEnDire(dim, tablero, i, j);
      }
    }
  }
  return count;
}