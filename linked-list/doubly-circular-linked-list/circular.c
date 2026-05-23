#include "circular.h"
#include <stdlib.h>
#include <stdio.h>

struct no {
    int valor;
    TNo* prox;
    TNo* ant;
};

struct lista {
    TNo* cabeca;
    int ordenada;
    int permite_repetidos;
};

int lista_buscar_elemento(TLista* lista, int valor_busca, TNo** no_encontrado) {
    TNo* no_atual;
    lista->cabeca->valor = valor_busca;
    
    if (lista_eh_ordenada(lista))
        for (no_atual = lista->cabeca->prox; no_atual->valor < valor_busca; no_atual = no_atual->prox);
    else
        for (no_atual = lista->cabeca->prox; no_atual->valor != valor_busca; no_atual = no_atual->prox);
    
    *no_encontrado = no_atual;
    return (no_atual != lista->cabeca && no_atual->valor == valor_busca);
}

TNo* lista_criar_no(int valor) {
    TNo* novo_no = (TNo*)malloc(sizeof(TNo));
    if (novo_no == NULL) return NULL;
    
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
    return novo_no;
}

TLista* lista_criar(int eh_ordenada, int aceita_repetidos) {
    TLista* nova_lista = (TLista*)malloc(sizeof(TLista));
    if (nova_lista == NULL) return NULL;
    
    TNo* cabeca = lista_criar_no(0);
    if (cabeca == NULL) {
        free(nova_lista);
        return NULL;
    }
    
    cabeca->prox = cabeca;
    cabeca->ant = cabeca;
    
    nova_lista->cabeca = cabeca;
    nova_lista->ordenada = eh_ordenada;
    nova_lista->permite_repetidos = aceita_repetidos;
    
    return nova_lista;
}

int lista_eh_ordenada(TLista* lista) {
    return lista->ordenada;
}

int lista_aceita_repetidos(TLista* lista) {
    return lista->permite_repetidos;
}

int lista_esta_vazia(TLista* lista) {
    return lista->cabeca->prox == lista->cabeca;
}

int lista_inserir(TLista* lista, int valor) {
    TNo* novo_no, *no_proximo;
    int elemento_existe;

    elemento_existe = lista_buscar_elemento(lista, valor, &no_proximo);

    if (!lista_aceita_repetidos(lista) && elemento_existe)
        return -1; 

    novo_no = lista_criar_no(valor);
    if (novo_no == NULL)
        return 0;

    novo_no->prox = no_proximo;
    novo_no->ant = no_proximo->ant;
    novo_no->ant->prox = novo_no;
    novo_no->prox->ant = novo_no;
    
    return 1;
}

int lista_remover(TLista* lista, int valor) {
    TNo* no_alvo;
    
    if (lista_esta_vazia(lista))
        return 0;
    
    if (!lista_buscar_elemento(lista, valor, &no_alvo))
        return -1;
    
    no_alvo->ant->prox = no_alvo->prox;
    no_alvo->prox->ant = no_alvo->ant;
    free(no_alvo);
    
    return 1;
}

void lista_imprimir(TLista* lista) {
    TNo* no_atual = lista->cabeca->prox;
    
    while (no_atual != lista->cabeca) {
        printf("%d ", no_atual->valor);
        no_atual = no_atual->prox;
    }
    printf("\n");
}

void lista_destruir(TLista* lista) {
    if (lista == NULL) return;
    
    TNo* no_atual = lista->cabeca->prox;
    TNo* no_proximo;
    
    while (no_atual != lista->cabeca) {
        no_proximo = no_atual->prox;
        free(no_atual);
        no_atual = no_proximo;
    }
    
    free(lista->cabeca);
    free(lista);
}