#include <stdio.h>
#define COLS 5
#define FILS 5
void interseccion ( int m1[FILS][COLS], int m2[FILS][COLS], int m3[FILS][COLS] ){
    for ( int i = 0; i < FILS; i++ ){
        int q = 0;
             for ( int j = 0; j < COLS; j++ ){
               int a = m1[i][j];
            
                for ( int l = 0; l < COLS; l++){
                    int b = m2[i][l];
                    if ( a == b ){
                        m3[i][q] = a;
                        q++;
                    }
                }
                while (q < COLS){
                    m3[i][q] = 0;
                    q++; 
                    }
             }
    }
    
}