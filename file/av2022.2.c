/*Implementar uma função que, dados dois arquivos texto (arquivoA e arquivoB), 
contendo números inteiros, um por linha e sem repetições, determine o número de
elementos comuns entre os dois arquivos.*/

#include <stdio.h>

int contarNumerosComuns(char *arqA, char *arqB);

void main() {
    int retorno = contarNumerosComuns("teste.txt", "teste2.txt");
    
    if (retorno == -1) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        printf("%d numeros comuns.\n", retorno);
    }
}

int contarNumerosComuns(char *arqA, char *arqB) {
		
   	FILE *arq1 = fopen(arqA, "r");
    FILE *arq2;

    if (!arq1 || !arq2) {
        if (arq1) fclose(arq1);
        if (arq2) fclose(arq2);
        return -1;
    }

    int numero1, numero2;
    int cont = 0;

    while (fscanf(arq1, "%d", &numero1) != EOF) {
        arq2 = fopen(arqB, "r"); 
        while (fscanf(arq2, "%d", &numero2) != EOF) {
            if (numero1 == numero2) {
            	cont++;
                break;
            }
        }
        
        fclose(arq2);
        
    }
    
    fclose(arq1);
    
    return cont;
}


