/*Desenvolver uma função que, dada uma matriz
Mm×n, determine se um número X se encontra
na linha L da matriz.*/
#include <stdio.h>

int encontrar(int matriz[][3], int c, int num, int l);

int main() {
    int matriz[5][3] = {
        {3, 5, 9},
        {3, 8, 6},
        {0, 1, 2},
        {9, 3, 4},
        {8, 7, 5}
    };
    
    int x, l;
    
    printf("Digite o número:\n");
    scanf("%d", &x);
    
    printf("Em qual linha?\n");
    scanf("%d", &l);
    
    int retorno = encontrar(matriz, 3, x, l);
    
    if(retorno == 1){
         printf("O número %d está na linha %d\n", x, l);
    } else {
        printf("O número %d não está na linha %d\n", x, l);
    }
    
    return 0;
}

int encontrar(int matriz[][3], int c, int num, int l) {
    for(int i = 0; i < c; i++) {
        if(matriz[l][i] == num) {
            return 1;  
        }
    }
    return 0;  
}
