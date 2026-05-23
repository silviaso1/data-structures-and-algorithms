/*Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
 Determinar a quantidade de pessoas que
fazem aniversário no mês M;
 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/


#include <stdio.h>
#include <string.h>

#define TAM 10 

typedef struct {
    int dia;
    int mes;
} TData;

typedef struct {
    char nome[50];
    TData aniversario;
} Pessoa;

int quantAniversariosNoMes(Pessoa pessoas[], int tamanho, int mes) {
    int count = 0;
    for (int i = 0; i < tamanho; i++) {
        if (pessoas[i].aniversario.mes == mes) {
            count++;
        }
    }
    return count;
}

void exibirAniversariantesEntreDatas(Pessoa pessoas[], int tamanho, TData d1, TData d2) {
    printf("Pessoas que fazem aniversário entre %d/%d e %d/%d:\n", d1.dia, d1.mes, d2.dia, d2.mes);
    for (int i = 0; i < tamanho; i++) {
        if ((compareDatas(pessoas[i].aniversario, d1) >= 0) && (compareDatas(pessoas[i].aniversario, d2) <= 0)) {
            printf("%s\n", pessoas[i].nome);
        }
    }
}

int compareDatas(TData d1, TData d2) {
    if (d1.mes < d2.mes) {
        return -1;
    } else if (d1.mes > d2.mes) {
        return 1;
    } else {
        if (d1.dia < d2.dia) {
            return -1;
        } else if (d1.dia > d2.dia) {
            return 1;
        } else {
            return 0;
        }
    }
}

void main() {

    Pessoa pessoas[TAM] = {
        {"Joao", {15, 3}},
        {"Maria", {5, 6}},
        {"Pedro", {12, 8}},
        {"Ana", {25, 3}},
        {"Carlos", {7, 6}},
        {"Julia", {18, 8}},
        {"Fernanda", {10, 1}},
        {"Marcos", {21, 9}},
        {"Laura", {3, 7}},
        {"Rodrigo", {30, 5}}
    };

    int mes = 3;
    printf("Quantidade de pessoas que fazem aniversário no mês %d: %d\n", mes, quantAniversariosNoMes(pessoas, TAM, mes));

    TData d1 = {1, 6};
    TData d2 = {30, 8};
    exibirAniversariantesEntreDatas(pessoas, TAM, d1, d2);


}
