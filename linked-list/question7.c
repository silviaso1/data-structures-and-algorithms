/*Desenvolver uma função que insira um número inteiro N na i-ésima posição de uma lista
encadeada L.*/

#include <stdio.h>
#include <stdlib.h>

// definição de tipos
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

// protótipos das funções
int inserirNaPosicao(TLista *L, int numero, int posicao);
int inserir(TLista *L, int numero);
void exibir(TLista L);

// main
int main() {
    // declaração de variáveis
    TLista L1 = NULL;

    // inserindo elementos em L1
    inserir(&L1, 4);
    inserir(&L1, 3);
    inserir(&L1, 2);
    inserir(&L1, 1);

    // exibindo a lista original
    printf("Lista original: ");
    exibir(L1);

    // inserindo número na i-ésima posição
    int numero = 99;
    int posicao = 2;
    int retorno = inserirNaPosicao(&L1, numero, posicao);

    if (retorno == 0) {
        printf("Posicao invalida\n");
    } else {
        printf("Numero %d adicionado na posicao %d\n", numero, posicao);
    }

    // exibindo a lista após inserção
    printf("Lista após insercao: ");
    exibir(L1);

    return 0;
}

int inserirNaPosicao(TLista *L, int numero, int posicao) {
    // declaração de variáveis
    TLista novoNo, aux = *L;
    int i;

    // alocar memória para o novo elemento
    novoNo = (TLista)malloc(sizeof(TNo));
    if (!novoNo) {
        return 0; // erro na alocação de memória
    }
    novoNo->valor = numero;

    // caso especial: inserção na primeira posição
    if (posicao == 0) {
        novoNo->prox = *L;
        *L = novoNo;
        return 1;
    }

    // encontrar a posição desejada
    for (i = 0; i < posicao - 1 && aux != NULL; i++) {
        aux = aux->prox;
    }

    // se a posição for inválida (maior que o tamanho da lista)
    if (aux == NULL) {
        free(novoNo); // liberar memória alocada
        return 0;
    }

    // inserir o novo nó na posição correta
    novoNo->prox = aux->prox;
    aux->prox = novoNo;

    return 1;
}

int inserir(TLista *L, int numero) {
    // declaração de variáveis
    TLista aux;

    // Passo 1: alocar memória para o novo elemento
    aux = (TLista)malloc(sizeof(TNo)); // malloc - memory allocation
    
    // verificando se houve erro na alocação
    if (!aux) {
        return 0; // erro na alocação de memória
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


