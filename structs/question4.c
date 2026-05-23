/*Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre um grupo
de pessoas: nome (string), gênero (char) e
idade (int). Pede-se uma função que determine
se os elementos deste vetor estão ordenados e
retorne 1, caso estejam ordenados, e 0, caso
contrário.*/


#include <stdio.h>
#include <string.h>

#define TAM 4

typedef struct {
    char nome[20];
    char genero[2];
    int idade;
} TGrupo;

int ordenacao(TGrupo grupo[]);
void exibirGrupo(TGrupo grupo[]); 

void main() {
    int retorno;
    
    TGrupo grupo[TAM] = {
        {"simone", "f", 21},
        {"julia", "f", 20},
        {"pedro", "m", 20},
        {"clara", "f", 32}
    };
    
    exibirGrupo(grupo); 
    
    retorno = ordenacao(grupo);
    
    if (retorno == 0) {
        printf("O grupo nao esta ordenado.\n");
    } else {
        printf("O grupo esta ordenado.\n");
    }
    
    exibirGrupo(grupo); 
    
   
}

int ordenacao(TGrupo grupo[]) {
    for (int i = 0; i < TAM - 1; i++) {
        if (grupo[i].idade > grupo[i + 1].idade) {
            return 0; 
        } else if (grupo[i].idade == grupo[i + 1].idade) {
            if (strcmp(grupo[i].nome, grupo[i + 1].nome) > 0) {
                return 0;
            }
        }
    }
    
    return 1;
}

void exibirGrupo(TGrupo grupo[]) {
    printf("Grupo:\n");
    for (int i = 0; i < TAM; i++) {
        printf("Nome: %s, Genero: %s, Idade: %d\n", grupo[i].nome, grupo[i].genero, grupo[i].idade);
    }
    printf("\n");
}
