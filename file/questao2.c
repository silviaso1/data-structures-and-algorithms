/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>

int arquivo(char nome[], char caractere);

void main() {
    char nome[20];
    char caractere;

    printf("Digite o nome do arquivo:\n");
    fflush(stdin);
    gets(nome);

    printf("Digite o caractere a ser contado:\n");
    fflush(stdin);
    scanf("%c", &caractere);

    int retorno = arquivo(nome, caractere);

    if (retorno == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("O caractere '%c' aparece %d vezes no arquivo.\n", caractere, retorno);
    }
}

int arquivo(char nome[], char caractere) {
    FILE* arq = fopen(nome, "r");
    if (!arq) {
        return -1;
    }

    char ch;
    int quant = 0;

    while (fscanf(arq, "%c", &ch) != EOF) {
        if (ch == caractere) {
            quant++;
        }
    }

    fclose(arq);
    return quant;
}

