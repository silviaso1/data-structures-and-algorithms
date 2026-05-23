/*Faça uma função que, dado um arquivo A
contendo números reais, um por linha, crie um
novo arquivo B contendo os mesmos
elementos de A, porém ordenados
decrescentemente e sem repetição.*/

#include <stdio.h>

int arquivo(char *nome1, char *nome2);

void main() {
    if (arquivo("teste.txt", "teste2.txt") == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("Arquivo criado com sucesso.\n");
    }
}

int arquivo(char *nome1, char *nome2) {
    FILE *arq1 = fopen(nome1, "r");
    FILE *arq2 = fopen(nome2, "w");

    if (!arq1 || !arq2) {
        return -1; // Erro ao abrir um dos arquivos
    }
	int count = 0, i, j;
    float numeros[count];
    float numero, temp;

    // Ler todos os números do arquivo A
    while (fscanf(arq1, "%f", &numero) != EOF) {
        numeros[count++] = numero;
    }
    fclose(arq1);
    
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (numeros[j] < numeros[j + 1]) {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < count; i++) {
        if (i == 0 || numeros[i] != numeros[i - 1]) {
            fprintf(arq2, "%.2f\n", numeros[i]);
        }
    }
    fclose(arq2);
    return 0;
}

