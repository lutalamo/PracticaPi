#include <assert.h>
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
    {-1, 0},  // arriba
    {1, 0},   // abajo
    {0, -1},  // izquierda
    {0, 1},   // derecha
    {-1, -1}, // diag sup-izq
    {-1, 1},  // diag sup-der
    {1, -1},  // diag inf-izq
    {1, 1}    // diag inf-der
};

int buscaEnDire(unsigned dim, char tablero[dim][dim], int pos_y, int pos_x) {
  char pieza = tablero[pos_y][pos_x];
  int count = 0;

  for (int k = 0; k < DIRECCIONES; k++) {

    int f = pos_y + direcciones[k][0];
    int c = pos_x + direcciones[k][1];

    while (f >= 0 && f < dim && c >= 0 && c < dim) {
      if (tablero[f][c] != ' ') {
        if ((isupper(pieza) && islower(tablero[f][c])) ||
            (islower(pieza) && isupper(tablero[f][c]))) {
          count++;
        }
        break;
      }

      f += direcciones[k][0];
      c += direcciones[k][1];
    }
  }
  return count;
}

int damas(unsigned dim, char tablero[dim][dim]) {

  int count = 0;

  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      if (tablero[i][j] == 'd' || tablero[i][j] == 'D') {
        count += buscaEnDire(dim, tablero, i, j);
      }
    }
  }
  return count;
}

// ejercicio 11 - tipo parcial
void ordenar(unsigned fils, unsigned cols, int matriz[fils][cols],
             unsigned col) {
  if (col > cols || col == 0)
    return;

  int idx = col - 1;

  for (int i = 0; i < fils - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < fils; j++) {
      if (matriz[j][idx] < matriz[minIdx][idx]) {
        minIdx = j;
      }
     
    // swap
      for (int k = 0; k < cols; k++) {
        int tmp = matriz[i][k];
        matriz[i][k] = matriz[minIdx][k];
        matriz[minIdx][k] = tmp;
      }
    }
  }
}

// ejercicio 12 - Matriz Traspuesta
void traspuesta(unsigned dim, int matriz[dim][dim]) {
  for (int i = 0; i < dim; i++) {
    for (int j = i + 1; j < dim;
         j++) { // arranca desde i+1 para solo ver la mitad de arriba
      int tmp = matriz[i][j];
      matriz[i][j] = matriz[j][i];
      matriz[j][i] = tmp;
    }
  }
}

// ejercicio 13 - producto de matrices cuadradas
int suma(unsigned dim, const int m1[dim][dim], const int m2[dim][dim], int fila,
         int col) {
  int ans = 0;
  for (int i = 0; i < dim; i++) {
    ans += m1[fila][i] * m2[i][col];
  }
  return ans;
}

void productoMat(unsigned dim, const int m1[dim][dim], const int m2[dim][dim], int ans[dim][dim]) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      ans[i][j] = suma(dim, m1, m2, i, j);
    }
  }
}

// ejercicio 14 - interseccion de vectores - contiene
int estaContenido(unsigned dim1, const int v1[dim1], unsigned dim2,
                  const int v2[dim2]) {
  for (int i = 0; i < dim1; i++) {
    int flag = 0;
    for (int j = 0; j < dim2; j++) {
      if (v1[i] == v2[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag)
      return 0;
  }
  return 1;
}

int contiene(const int v1[], unsigned dim1, const int v2[], unsigned dim2) {
  if (estaContenido(dim1, v1, dim2, v2))
    return 1;
  if (estaContenido(dim2, v2, dim1, v1))
    return 2;
  return 0;
}

// ejercicio 15 - suavizar
#define ALTO 6
#define ANCHO 5
#define MAX(a, b) ((a < b) ? b : a)
#define MIN(a, b) ((a < b) ? a : b)

int promedio(unsigned char imagen[ALTO][ANCHO], int f_in, int f_fin, int c_in, int c_fin) {
  int count = 0;
  int ans = 0;
  for (int i = f_in; i <= f_fin; i++) {
    for (int j = c_in; j <= c_fin; j++) {
      ans += imagen[i][j];
      count++;
    }
  }
  ans = ans / count;
  return ans;
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w) {
  if (w < 3 || w % 2 == 0)
    return;

  unsigned char ans[ALTO][ANCHO];

  //casteo w a int, y calculo cuanto hay que moverse
  int k = w/2;

  // guardo en la matriz los valores suavizados
  for (int i = 0; i < ALTO; i++) {
    int f_inicial = MAX(0, i - k);
    int f_final = MIN(ALTO - 1, i + k);

    for (int j = 0; j < ANCHO; j++) {
      int c_inicial = MAX(0, j - k);
      int c_final = MIN(ANCHO - 1, j + k);
      ans[i][j] = promedio(imagen, f_inicial, f_final, c_inicial, c_final);
    }
  }

  //copio en la imagen los valores suavizados
  for (int i = 0; i < ALTO; i++){
    for (int j = 0; j < ANCHO; j++){
      imagen[i][j] = ans[i][j];
    }
  }
}

// ejercicio 16 - tipo parcial - matriz ascendente o descendente
#define FILS 3
#define COLS 4

int ascendenteODescendente (const int m[][COLS]){
  int flag = 0; 

  int anterior = m[0][0]; //inicializo con el primer elemento
  
  for (int i = 0; i < FILS; i++){
    for (int j = 0; j < COLS; j++){
      if (anterior < m[i][j]){ 
        //aca, si el flag es -1, significa que paso a ser descendente
        //en algun momento, por lo que no es ninguna de las 2
        if (flag == -1){
          return 0;
        }
        
        flag = 1;
        anterior = m[i][j];
      }
      else if (anterior > m[i][j]){
        if (flag == 1){
          return 0;
        }
        flag = -1; // pongo el flag en descendente
        anterior = m[i][j];
      }
      // si son iguales, no toco el flag, pero actualizo anterior
      else anterior = m[i][j];
    }
  }
  return (flag != 0)? flag : 1;
}

// ejercicio 17 - armar filas - tipo parcial
#define N 4
#define M 5

int armaFilas (int m[][M], int vec[]){
  int dim = 0;

  for (int i = 0; i < N; i++){
    int flag = 1;
    vec[dim] = 0;
    for (int j = 0; j < M; j++){
      if (m[i][j] < 0 || m[i][j] > 9) {
        flag = 0;
        break;
      }
      vec[dim] = vec[dim] * 10 + m[i][j];
    }
    if (flag) {
      dim++;
    }
  }
  return dim;
}

// ejercicio 18 - matriz amigas
int filaAmiga (unsigned cols, const int v1[], const int v2[]){
  int i = 0, j = 0;
  while (i < cols && j < cols){
    if (v1[i] < v2[j]) break; // si es mas chicho, no esta
    else if (v1[i] > v2[j]) j++;
    else if (v1[i] == v2[j]) {
      i++;
    }
  }
  return (i == cols) ? 1 : 0;
}

int matrizAmiga (unsigned cols, const int m1[][cols], const int m2[][cols], unsigned fil1, unsigned fil2){
  for (int i = 0; i < fil1; i++){
    int flag;
    for (int j = 0; j < fil2; j++){
      flag = filaAmiga(cols, m1[i], m2[j]);
      if (flag) break;
    }
    // si se apaga el flag, una fila no es amiga, por ende la matriz no sera amiga
    if (!flag) return 0;
  }
  return 1;
}

int sonAmigas (unsigned cols, const int m1[][cols], unsigned fil1, const int m2[][cols], unsigned fil2){
  if (matrizAmiga(cols, m1, m2, fil1, fil2)) return 1;
  if (matrizAmiga(cols, m2, m1, fil2, fil1)) return 2;
  return 0;
}
