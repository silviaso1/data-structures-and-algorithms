#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef struct no TNo;
typedef struct lista TLista;

TLista* lista_criar(int ordenada, int permite_repetidos);
int lista_eh_ordenada(TLista* lista);
int lista_aceita_repetidos(TLista* lista);
int lista_esta_vazia(TLista* lista);
int lista_inserir(TLista* lista, int valor);
int lista_remover(TLista* lista, int valor);
void lista_imprimir(TLista* lista);
void lista_destruir(TLista* lista);

#endif