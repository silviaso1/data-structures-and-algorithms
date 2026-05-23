/*Implementar uma função que, dada uma lista dinâmica do tipo TLista, verifique se os elementos
da estrutura encontram-se ordenados de forma crescente ou não.*/

#include <stdio.h>
#include <stdlib.h>

// definição de tipos
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

// protótipos das funções
int crescente(TLista L);
int inserir(TLista *L, int numero);
void exibir(TLista L);

// main
int main() {
    // declaração de variáveis
    TLista L1 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 4);
    inserir(&L1, 3);
    inserir(&L1, 5);
    inserir(&L1, 1);


    int retorno = crescente(L1);

    if (retorno == 0) {
        printf("Nao é crescente\n");
    } else {
        printf("é cescente\n");
    }

    exibir(L1);

    return 0;
}

int crescente(TLista L) {
    if (L == NULL || L->prox == NULL) {
        return 1; // Lista vazia ou com um único elemento é considerada crescente
    }

    TLista atual = L;
    TLista proximo = L->prox;

    while (proximo != NULL) {
        if (atual->valor > proximo->valor) {
            return 0;
        }
        atual = proximo;
        proximo = proximo->prox;
    }

    return 1;
}

int inserir(TLista *L, int numero) {
    // declaração de variáveis
    TLista aux;
    
    // Passo 1: alocar memória para o novo elemento
    aux = (TLista) malloc(sizeof(TNo)); // malloc - memory allocation
    
    // verificando se houve erro na alocação
    if (!aux) {
        return 0;
    } else {
        // Passo 2: armazenando 'numero' na posição recém-alocada
        aux->valor = numero;
        
        // Passo 3: fazer o novo nó apontar para o "antigo primeiro nó"
        aux->prox = *L;
        
        // Passo 4: fazer com que *L aponte para o novo Nó
        *L = aux;
        
        return 1;
    }
}

void exibir(TLista L) {
    // declaração de variáveis
    TLista aux = L;
    
    // verificando se a lista está vazia
    if (!L) {
        printf("Lista vazia!\n");
    } else {
        printf("Lista: ");
    
        // while (aux != NULL)
        while (aux) {
            printf("%d ", aux->valor);
            // ou:    printf("%d ", (*aux).valor);
            
            aux = aux->prox;
        }
        
        printf("\n");
    }
}
