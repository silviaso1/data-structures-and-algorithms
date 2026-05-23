/* Dado um arquivo texto, contendo números inteiros, um por linha, criar um arquivo “novo.txt” 
apenas com os elementos originais que, na ordem em que foram lidos, fazem com que o novo arquivo
esteja ordenado crescentemente. Todos os demais valores que “atrapalharam” essa ordenação serão 
armazenados em outro arquivo chamado “descartados.txt*/

#include <stdio.h>

int arquivo(char *original, char *novo, char *descartar);

void main() {
    if (arquivo("teste.txt", "novo.txt", "descartados.txt") == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("Arquivos criados com sucesso.\n");
    }
    
}

int arquivo(char *original,char *novo, char *descartar) {
    FILE *arq1 = fopen(original, "r");
    FILE *arq2 = fopen(novo, "w");
    FILE *arq3 = fopen(descartar, "w");

    if (!arq1 || !arq2 || !arq3) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        if (arq3) fclose(arq3);
        return -1; 
        
        
    }

    int numero;
    int ultimo_numero = -999999; 

    while (fscanf(arq1, "%d", &numero) != EOF) {
        if (numero >= ultimo_numero) {
            fprintf(arq2, "%d\n", numero);
            ultimo_numero = numero;
        } else {
            fprintf(arq3, "%d\n", numero);
        }
    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    return 0;
}

