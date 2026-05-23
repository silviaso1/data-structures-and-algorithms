/*
Desenvolver uma função recursiva que, dado
um vetor V com quant números inteiros,
determine se seus elementos estão dispostos
de maneira a representar uma progressão
aritmética.
*/

#include <stdio.h>

int func(int vet[], int r, int i, int tam){
    
    if(i <= tam){
        if(vet[i+ 1] - vet[i] == r){
            return 1;
        }
        else{
            return 0;
        }
        func(vet, r, i + 1, tam);
    }
}


int main(){
    int vet[5] = { 8, 10, 12, 14, 16};
    int razao = 2,i = 0, retorno;
    
    retorno = func(vet, razao, i, 5);
    
    if(retorno == 1){
        printf("É progressao");
        
    }else{
        printf("Não é");
    }
}

