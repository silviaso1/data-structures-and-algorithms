#include <stdio.h>

int removeDuplicatas(char *arquivo1, char *arquivo2) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2 = fopen(arquivo2, "w");

    if (!arq1 || !arq2) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return -1;
    }

    int numero, numeroTemp, duplicata;

    // Ler cada número do arquivo de entrada
    while (fscanf(arq1, "%d", &numero) != EOF) {
        // Reiniciar a verificação de duplicatas
        duplicata = 0;

        // Abrir arquivo de saída para leitura
        FILE *saidaTemp = fopen(arquivo2, "r");

        if (!saidaTemp) {
            fclose(arq1);
            fclose(arq2);
            return -1;
        }

        // Verificar se o número já está no arquivo de saída
        while (fscanf(saidaTemp, "%d", &numeroTemp) != EOF) {
            if (numeroTemp == numero) {
                duplicata = 1;
                break;
            }
        }

        fclose(saidaTemp);

        // Se não for duplicata, escreva no arquivo de saída
        if (!duplicata) {
            fprintf(arq2, "%d\n", numero);
        }
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}

int main() {
    if (removeDuplicatas("teste.txt", "B.txt") == 0) {
        printf("Arquivo processado com sucesso.\n");
    } else {
        printf("Erro ao processar o arquivo.\n");
    }
    return 0;
}

