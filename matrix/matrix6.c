#include <stdio.h>

#define MESES 12
#define FUNCIONARIOS 10

void totalVendidoAno(int matriz[][FUNCIONARIOS], int l, int c);
void totalMes(int matriz[][FUNCIONARIOS], int c, int mes);
void totalFuncionario(int matriz[][FUNCIONARIOS], int l, int funcionario);
void maiorMes(int matriz[][FUNCIONARIOS], int l, int c);
void menorFuncionario(int matriz[][FUNCIONARIOS], int l, int c);

int main() {
    int matriz[MESES][FUNCIONARIOS] = {
        {3, 5, 9, 2, 4, 6, 8, 1, 3, 5},
        {3, 8, 6, 1, 7, 3, 2, 6, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {9, 3, 4, 8, 6, 5, 4, 3, 2, 1},
        {8, 7, 5, 6, 4, 3, 2, 1, 0, 9},
        {1, 3, 5, 7, 9, 2, 4, 6, 8, 0},
        {2, 4, 6, 8, 0, 1, 3, 5, 7, 9},
        {5, 6, 7, 8, 9, 0, 1, 2, 3, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
        {0, 2, 4, 6, 8, 1, 3, 5, 7, 9},
        {1, 3, 5, 7, 9, 0, 2, 4, 6, 8},
        {8, 6, 4, 2, 0, 9, 7, 5, 3, 1}
    };

    int mes, funcionario;

    printf("Insira o mês que você quer calcular (0-11):\n");
    scanf("%d", &mes);
    totalMes(matriz, FUNCIONARIOS, mes);

    printf("Insira o funcionário que você quer calcular (0-9):\n");
    scanf("%d", &funcionario);
    totalFuncionario(matriz, MESES, funcionario);

    totalVendidoAno(matriz, MESES, FUNCIONARIOS);
    maiorMes(matriz, MESES, FUNCIONARIOS);
    menorFuncionario(matriz, MESES, FUNCIONARIOS);

    return 0;
}

void totalVendidoAno(int matriz[][FUNCIONARIOS], int l, int c) {
    int total = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            total += matriz[i][j];
        }
    }
    printf("Total vendido durante o ano: %d\n", total);
}

void totalMes(int matriz[][FUNCIONARIOS], int c, int mes) {
    int soma = 0;
    for (int i = 0; i < c; i++) {
        soma += matriz[mes][i];
    }
    printf("Total vendido no mês %d: %d\n", mes, soma);
}

void totalFuncionario(int matriz[][FUNCIONARIOS], int l, int funcionario) {
    int soma = 0;
    for (int i = 0; i < l; i++) {
        soma += matriz[i][funcionario];
    }
    printf("Total vendido pelo funcionário %d durante o ano: %d\n", funcionario, soma);
}

void maiorMes(int matriz[][FUNCIONARIOS], int l, int c) {
    int maior = 0, mes = 0;
    for (int i = 0; i < l; i++) {
        int soma = 0;
        for (int j = 0; j < c; j++) {
            soma += matriz[i][j];
        }
        if (soma > maior) {
            maior = soma;
            mes = i;
        }
    }
    printf("O mês com maior índice de vendas é %d com %d vendas.\n", mes, maior);
}

void menorFuncionario(int matriz[][FUNCIONARIOS], int l, int c) {
    int menor = 999999, funcionario = 0;
    for (int j = 0; j < c; j++) {
        int soma = 0;
        for (int i = 0; i < l; i++) {
            soma += matriz[i][j];
        }
        if (soma < menor) {
            menor = soma;
            funcionario = j;
        }
    }
    printf("O funcionário que menos vendeu durante o ano é %d com %d vendas.\n", funcionario, menor);
}
