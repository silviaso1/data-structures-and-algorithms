/*
Desenvolver uma fun��o que gere a seguinte
matriz M5?5:
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9

*/

#include <stdio.h>

void gerar(int m[][5], int l, int c);

void main(){
    
    int matriz [5][5];
    gerar(matriz, 5, 5);
}
void gerar(int m[][5], int l, int c){
    int i,j;
    
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
              m[i][j] = i + j + 1;
        }
    }
    
    printf("Matriz gerada:\n");
    for (i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    
}
