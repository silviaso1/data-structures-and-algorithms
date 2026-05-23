/*
Implementar uma função que, dada uma matriz
Mm×n, gere um vetor V de tamanho n, onde
cada elemento do vetor consiste na soma dos
elementos de uma coluna de M. Ou seja, o
elemento V[0] consiste na soma dos elementos
da primeira coluna de M, o elemento V[1]
consiste na soma dos elementos da segunda
coluna de M, e assim por diante.
*/

#include <stdio.h>

#define LIN 5
#define COL 3

void soma(int m[][COL]);

void main(){
     int matriz[LIN][COL] = {
         {3, 5, 9},
        {3, 8, 6},
        {0, 1, 2},
        {9, 3, 4},
        {8, 7, 5}

    };
    
    soma(matriz);
    
}

void soma(int m[][COL]){
    
    int i, j, vet[COL], soma = 0;
    
    for(i=0; i<COL; i++){
        for(j=0;j<LIN;j++){
            soma+= m[j][i];
        }
        
        vet[i] = soma;
        soma= 0;
    }
    
    for(i=0; i< COL; i++){
        printf("%d ", vet[i]);
    }
}