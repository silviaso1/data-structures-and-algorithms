/*Considere a existência de um vetor de structs
com quant posições, onde cada uma destas
armazena os seguintes dados sobre os
funcionários de uma empresa: matricula (int),
nome (string), gênero (char) e salário (float).
Pede-se uma função que, dado um gênero,
desloque todos os funcionários deste gênero
para o início do vetor (e, consequentemente, os
funcionários do outro gênero ficarão ao final do
conjunto).*/


#include <stdio.h>
#include <string.h>

#define FUNCIONARIOS 10

typedef struct {
    int matricula;
    char nome[50];
    char genero; 
    float salario;
} Funcionario;

void reorganizarPorGenero(Funcionario funcionarios[], int numFuncionarios, char genero) {
    int i, j = 0;

    for (i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].genero == genero) {
            Funcionario temp = funcionarios[i];
            funcionarios[i] = funcionarios[j];
            funcionarios[j] = temp;
            j++;
        }
    }
}

void main() {
    Funcionario funcionarios[FUNCIONARIOS] = {
        {101, "Maria", 'F', 3500.0},
        {102, "Joao", 'M', 4000.0},
        {103, "Ana", 'F', 3200.0},
        {104, "Pedro", 'M', 3800.0},
        {105, "Julia", 'F', 3000.0},
        {106, "Carlos", 'M', 4100.0},
        {107, "Fernanda", 'F', 3300.0},
        {108, "Marcos", 'M', 3700.0},
        {109, "Laura", 'F', 3100.0},
        {110, "Rodrigo", 'M', 3900.0}
    };

    int numFuncionarios = 10;
    char genero = 'F'; 

    reorganizarPorGenero(funcionarios, numFuncionarios, genero);

    printf("Funcionarios apos reorganizacao por genero '%c':\n", genero);
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Matricula: %d, Nome: %s, Genero: %c, Salario: %.2f\n", funcionarios[i].matricula,
               funcionarios[i].nome, funcionarios[i].genero, funcionarios[i].salario);
    }

    
}
