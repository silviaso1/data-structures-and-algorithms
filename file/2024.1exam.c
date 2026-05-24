/*Desenvolver uma função que, dados os nomes de dois
arquivos textos, contendo números inteiros, um por
linha, determine se o primeiro arquivo está contido no
segundo (ou seja, se todos os elementos do primeiro
também estão no segundo).*/
#include <stdio.h>

int verificarContido(char *arquivo1, char *arquivo2);

int main() {
    int contido = verificarContido("teste.txt", "teste2.txt");
    
    if (contido == -1) {
        printf("Erro ao abrir um dos arquivos.\n");
    } else if (contido == 1) {
        printf("O primeiro arquivo está contido no segundo arquivo.\n");
    } else {
        printf("O primeiro arquivo não está contido no segundo arquivo.\n");
    }
    
    return 0;
}

int verificarContido(char *arquivo1, char *arquivo2) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2;

    if (!arq1) {
        return -1; 
    }

    int num1, num2;
    int encontrado;

    while (fscanf(arq1, "%d", &num1) != EOF) {
        encontrado = 0;

        arq2 = fopen(arquivo2, "r");  // Reabre o segundo arquivo

        if (!arq2) {
            fclose(arq1);
            return -1; // Erro ao abrir arquivo2
        }

        while (fscanf(arq2, "%d", &num2) != EOF) {
            if (num1 == num2) {
                encontrado = 1;
                break;
            }
        }

        fclose(arq2);  // Fecha o segundo arquivo

        if (!encontrado) {
            fclose(arq1);
            return 0; // Um número de arq1 não está em arq2
        }
    }

    fclose(arq1);
    return 1; // Todos os números de arq1 estão em arq2
}

