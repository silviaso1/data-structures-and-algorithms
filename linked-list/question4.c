/*Implementar uma função que, dadas duas listas dinâmicas do tipo TLista, verifique se estas são
iguais; isto é, contêm os mesmos elementos, na mesma ordem.*/

#include <stdio.h>
#include <stdlib.h>

// definição de tipos
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

// protótipos das funções
int compararListas(TLista lista1, TLista lista2);
int inserir(TLista *L, int numero);
void exibir(TLista L);

// main
int main() {
    // declaração de variáveis
    TLista L1 = NULL, L2 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 10);
    inserir(&L1, 4);
    inserir(&L1, 13);
    inserir(&L1, 7);

    // inserindo elementos em L2
    inserir(&L2, 10);
    inserir(&L2, 5);
    inserir(&L2, 13);
    inserir(&L2, 7);

    // comparando as listas
    int retorno = compararListas(L1, L2);

    if (retorno == 0) {
        printf("Nao sao iguais\n");
    } else {
        printf("Sao iguais\n");
    }

    exibir(L1);
    exibir(L2);

    return 0;
}

int compararListas(TLista lista1, TLista lista2) {
    TLista l1 = lista1;
    TLista l2 = lista2;

    while (l1 && l2) {
        if (l1->valor != l2->valor) {
            return 0;
        }
        l1 = l1->prox;
        l2 = l2->prox;
    }

    // Verifica se ambas listas chegaram ao fim ao mesmo tempo
    if (l1 == NULL && l2 == NULL) {
        return 1;
    } else {
        return 0;
    }
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
            
            aux = aux->prox;
        }
        
        printf("\n");
    }
}
