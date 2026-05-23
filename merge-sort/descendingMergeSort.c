#include <stdio.h>
#define TAM 5

void mergeSort(int vetor[], int esquerda, int direita);
void merge(int vetor[], int esquerda, int meio, int direita);


int main() {
    int vetor[TAM] = {38, 27, 43, 10, 3};

    printf("Antes da Ordenacao:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }

    mergeSort(vetor, 0, TAM - 1);

    printf("\nDepois da Ordenacao:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}

void mergeSort(int vetor[], int esquerda, int direita){
    
    int meio;
    
    if(esquerda < direita){
        meio = (esquerda + direita) / 2;
        
        mergeSort(vetor, esquerda, meio);
        mergeSort(vetor, meio + 1, direita);
        
        merge(vetor, esquerda, meio, direita);
    }
}

void merge(int vetor[], int esquerda, int meio, int direita){
    
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int esq[n1], dir[n2];

    for (i = 0; i < n1; i++)
        esq[i] = vetor[esquerda + i];
    for (j = 0; j < n2; j++)
        dir[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;

    while (i < n1 && j < n2) {
        if (esq[i] >= dir[j]) { 
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }
}
