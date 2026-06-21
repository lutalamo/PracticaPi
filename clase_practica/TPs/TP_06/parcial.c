#include <assert.h>
#include <ctype.h>
#include "../../random.h"
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

// ejercicio 20 - sudoku - ejercicio tipo parcial
#define DIM 9
#define VALID_NUM(a) ((a >= 1 && a <= 9)? 1 : 0)
int validarFila (char v[]){
  int aparece[9] = {0};
  int i = 0;
  for (; i < DIM; i++){
    if (!VALID_NUM(v[i])) return 0;
    if (!aparece[v[i] - 1]){
      aparece[v[i] - 1] = 1;
    }
    else return 0;
  }
  return 1;
}

int validarColumna (char cuadrado[][DIM], int col){
  int aparece[9] = {0};
  int i = 0;
  for (; i < DIM; i++){
    if (!VALID_NUM(cuadrado[i][col])) return 0;
    if (!aparece[cuadrado[i][col] - 1]){
      aparece[cuadrado[i][col] - 1] = 1;
    }
    else return 0;
  }
  return 1;
}

int validarSubCuadrado (char cuadrado[][DIM], int i, int idx_j){
  int aparece[9] = {0};
  int dim_i = i + 3;
  int dim_j = idx_j + 3;
  for (; i < dim_i; i++){
    for (int j = idx_j; j < dim_j; j++){
      if (!VALID_NUM(cuadrado[i][j])) return 0;
      if (!aparece[cuadrado[i][j] - 1]){
        aparece[cuadrado[i][j] - 1] = 1;
      }
      else return 0;
    }
  }
  return 1;
}

int validarSudoku (char m[][DIM]){
  for (int i = 0; i < DIM; i++){
    if (!validarColumna(m, i) || !validarFila(m[i])) return 0;
    
    if (i % 3 == 0){
      for (int j = 0; j < DIM; j += 3){
        if (!validarSubCuadrado(m, i, j)) return 0;
      }
  }
  }
  return 1;
}

//ejercicio 24
void eliminaBlancos (char s[]){
  int j = 0;
  for (int i = 0; s[i] != '\0'; i++){
    if (s[i] != ' '){
      s[j++] = s[i];
    }
    else if (s[i] == ' ' && s[i+1] != ' '){
      s[j++] =s[i];
    }
  }
  s[j] = '\0';
}

// ejercicio 3 - parcial 2023 1C
#define COL 5
#define FIL 6
// retorna 0 si va gris, 1 verde, 2 amarillo
int pertenece (char c, const char * oculta, int pos){
  if (oculta[pos] == c) return 1;

  for (int i = 0; i < COL; i++){
    if (oculta[i] == c) return 2;
  }
  return 0;
}

int wordle (const char *oculta, const char m[FIL][COL], char ans[][COL], int cant_int){
  for (int i = 0; i < cant_int; i++){
    //contador de letras correctas
    int contador = 0;

    for (int j = 0; j < COL; j++){
      int color = pertenece(m[i][j], oculta, j);
      if (color == 0){
        ans[i][j] = 'G';
      }
      else if (color == 1){
        ans[i][j] = 'V';
        contador++;
      }
      else if (color == 2){
        ans[i][j] = 'A';
      }
    }
    // retorno i+1, que es en el intento que se logro 
    if (contador == COL) return ++i;
  }
  // si sale es porque ninguno fue correcto
  return -1;
}

// ejercicio 2 - parcial 2023 1C
#define K 6
#define VALID(a) ((a) >= 1 && (a) <= 3*K)

// retorna la suma, o -1 si se repite algun numero o es invalido
int subCuadrado (const int matriz[][K], int pos_i, int pos_j){
  int aparece[K*3] = {0};
  int suma = 0;
  for (int i = pos_i; i < pos_i+3; i++){
    for (int j = pos_j; j < pos_j+3; j++){
      if (VALID(matriz[i][j])){
        if (!aparece[matriz[i][j] - 1]){
          aparece[matriz[i][j] - 1] = 1;
          suma += matriz[i][j];
        }
        else return -1;
      }
      //si es un numero invalido
      else return -1;
    }
  }
  // si llega hasta aca, no se repite nada, y los valores son correctos
  return suma;
}

int verifica (const int matriz[][K]){
  int suma = 0;
  for (int i = 0; i < K; i += 3){
    for (int j = 0; j < K; j += 3){
      int actual = subCuadrado(matriz, i, j);
      if (suma == 0){
        suma = actual;
      }
      if (actual == -1) return 0;
      if (suma != actual){
        return 0;
      }
    }
  }
  return 1;
}

// ejercicio 1 - parcial 2023 1C
void elimina (char *s1, const char *s2, const char *s3){
  int j = 0;
  int s2_fin = 0;
  int s3_fin = 0;
  for (int i = 0; s1[i] != '\0'; i++){
    if (!s2_fin && s2[i] == '\0') s2_fin = 1;
    if (!s3_fin && s3[i] == '\0') s3_fin = 1;
    
    int sacar = 0;
    if (!s2_fin && s1[i] == s2[i]) sacar = 1;
    if (!s3_fin && s1[i] == s3[i]) sacar = 1;
    if (!sacar) s1[j++] = s1[i];
  }
  s1[j] = '\0';
}

// ejercicio 1 - recu 2022 1C

char teclado[10][26] = { 
  {0}, {0},
  {'A', 'B', 'C'},       // 2
  {'D', 'E', 'F'},       // 3
  {'G', 'H', 'I'},       // 4
  {'J', 'K', 'L'},       // 5
  {'M', 'N', 'O'},       // 6
  {'P', 'Q', 'R', 'S'},  // 7
  {'T', 'U', 'V'},       // 8
  {'W', 'X', 'Y', 'Z'}   // 9
};

void convertirATexto (unsigned long num, char * texto){
  if (num == 0) {
    *texto = '0';
    texto[1] = '\0';
    return;
  }
  int len = 0;
  unsigned long n = num;
  while (n != 0){
    n /= 10;
    len++;
  }
  //reseto n
  n = num;

  for (int i = len-1; i >= 0; i--){
    int last = n % 10;
    n /= 10;
    if (last == 0 || last == 1){
      texto[i] = '0' + last;
    }
    else if (last == 7 || last == 9){
      // obtengo la letra random
      int random = randInt(0, 3);
      texto[i] = teclado[last][random];
    }
    else {
      int random = randInt(0, 2);
      texto[i] = teclado[last][random];
    }
  }
  texto[len] = '\0';
}

// ejercicio 3 - recu 2022 1C
#define D 4
#define VALIDAR(a) ((a) >= 1 && (a) <= N*N)
int sumaCol (int matriz[][N], int col){
  int suma = 0;
  for (int i = 0; i < N; i++){
    if (VALIDAR(matriz[i][col])){
      suma += matriz[i][col];
    }
    else return 0;
  }
  return suma;
}

int sumaFil (int matriz[][N], int fil){
  int suma = 0;
  for (int i = 0; i < N; i++){
    if (VALIDAR(matriz[fil][i])){
      suma += matriz[fil][i];
    }
    else return 0;
  }
  return suma;
}

int esMagico (int matriz[][N]){
  int aparece[N*N] = {0};
  int suma = 0;
  for (int i = 0; i < N; i++){
    int sumActual = sumaFil(matriz, i);
    if (sumActual == 0) return 0;
    if (suma == 0) suma = sumActual;
    if (suma != sumActual) return 0;
    for (int j = 0; j < N; j++){
      sumActual = sumaCol(matriz, j);
      if (suma != sumActual) return 0;
      if (!aparece[matriz[i][j] - 1]){
        aparece[matriz[i][j] - 1] = 1;
      }
      else return 0;
    }
  }
  return 1;
}