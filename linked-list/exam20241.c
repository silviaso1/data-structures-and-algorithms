/*Considere a existência de uma lista encadeada L1, do
tipo TLista, que pode conter números repetidos.
Implementar uma função que, dada L1, crie a lista
encadeada L2, contendo, para cada elemento distinto
de L1, o seu valor e a quantidade de ocorrências na
primeira lista.*/

#include <stdio.h>
#include <stdlib.h>

// definição de tipos
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

// protótipos das funções
void Criar(TLista lista1);
void inserir(TLista *L, int numero);
TLista buscar(TLista L, int numero);
void exibir(TLista L);

// main
int main() {
    
    TLista L1 = NULL;

    inserir(&L1, 10);
    inserir(&L1, 4);
    inserir(&L1, 13);
    inserir(&L1, 7);
    inserir(&L1, 10);
    inserir(&L1, 13);
    inserir(&L1, 13);

    printf("Lista L1:\n");
    exibir(L1);
    printf("\nCriando lista L2:\n");
    Criar(L1);

    return 0;
}

void Criar(TLista lista) {
    TLista l1 = lista;
    TLista l2 = NULL;

    while (l1 != NULL) {
        int valor = l1->valor;
        int cont = 0;

        TLista temp = lista;
        while (temp != NULL) {
            if (temp->valor == valor) {
                cont++;
            }
            temp = temp->prox;
        }
        
        if (!buscar(l2, valor)) {
            TLista novo = (TLista)malloc(sizeof(TNo));
            novo->valor = valor;
            novo->prox = l2;
            l2 = novo;
        }

        l1 = l1->prox;
    }

    // exibir lista L2
    printf("Lista L2:\n");
    exibir(l2);
}

void inserir(TLista *L, int numero) {
    TLista aux = (TLista)malloc(sizeof(TNo));
    aux->valor = numero;
    aux->prox = *L;
    *L = aux;
}

TLista buscar(TLista L, int numero) {
    TLista aux = L;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void exibir(TLista L) {
    TLista aux = L;
    if (aux == NULL) {
        printf("Lista vazia!\n");
    } else {
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}
