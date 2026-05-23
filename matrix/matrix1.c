/*
Faça uma função que, dada uma matriz Mm×n de
reais, gere a matriz Mt, sua transposta.
*/

#include <stdio.h>

#define LIN 3 
#define COL 2 

void transposta(int m[][COL]);

void main(){
     int matriz[LIN][COL] = {
        {3, 5},
        {3, 9},
        {7, 1},

    };
    
    transposta(matriz);
    
}

void transposta(int m[][COL]){
    
    int i, j;
    int mt[COL][LIN];
    
    for(i=0; i<LIN; i++){
        for(j=0;j<COL;j++){
            mt[j][i] = m[i][j];
        }
    }
    
    for(i=0; i<LIN; i++){
        for(j=0;j<COL;j++){
            printf("%d", mt[i][j]);}
        printf("\n");
    }
}
