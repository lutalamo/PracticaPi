#include <assert.h>
#include "random.h"
#include <stdio.h>
#include <ctype.h>
#include "getnum.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void eliminaBlancos (char * s){
  bool flag = false;
  int i = 0; // indice de lectura
  int j = 0; // indice de escritura
  
  while (s[i] != '\0'){
    if (s[i] == ' '){
      if (!flag){
        s[j++] = s[i]; // copio el primer espacio
        flag = true;
      }
    }
    else {
      s[j++] = s[i];
      flag = false;
    }
    i++;
  }
  s[j] = '\0';
}

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaBlancos(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaBlancos(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaBlancos(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaBlancos(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}