/*Implementar uma função que, dado um arquivo texto contendo números inteiros, um por linha,
 e dois valores inteiros A e B, crie outros três arquivos, como descritos a seguir:

O primeiro deles conterá todos os valores do arquivo original inferiores a A.
O segundo será formado pelos valores do arquivo original pertencentes ao intervalo de A a B.
O último arquivo conterá os elementos maiores do que B.*/

#include <stdio.h>

int arquivo(char arquivOriginal[], char arquivo1[], char arquivo2[], char arquivo3[], int a, int b);

int main() {
	
	int a=3, b=5;
    int contido = arquivo("teste.txt", "arquivo1.txt", "arquivo2.txt", "arquivo3.txt", a, b);
    
    if (contido == -1) {
        printf("Erro ao abrir um dos arquivos.\n");
    } else{
    	printf("Realizado com sucesso\n");
	}
    
    return 0;
}

int arquivo(char arquivOriginal[], char arquivo1[], char arquivo2[], char arquivo3[], int a, int b) {
    FILE *arqOrig = fopen(arquivOriginal, "r");
    FILE *arq1 = fopen(arquivo1, "w");
    FILE *arq2 = fopen(arquivo2, "w");
    FILE *arq3 = fopen(arquivo3, "w");

    if (!arqOrig || !arq1 || !arq2 || !arq3) {
         fclose(arqOrig);
         fclose(arq1);
         fclose(arq2);
         fclose(arq3);
        return -1;
    }

    int numero;

    while (fscanf(arqOrig, "%d", &numero) != EOF) {
        if (numero < a) {
            fprintf(arq1, "%d\n", numero);
        } else if (numero >= a && numero <= b) {
            fprintf(arq2, "%d\n", numero); 
        } else {
            fprintf(arq3, "%d\n", numero); 
        }
    }

    fclose(arqOrig);
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);

    return 0;
}

