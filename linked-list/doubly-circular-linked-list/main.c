#include <stdio.h>
#include "circular.h"

int main() {
    TLista* lista = lista_criar(1, 0);
    if (lista == NULL) {
        printf("Erro ao criar lista.\n");
        return 1;
    }
    lista_inserir(lista, 10);
    lista_inserir(lista, 5);
    lista_inserir(lista, 20);
    lista_inserir(lista, 15);
    lista_inserir(lista, 5);

    printf("Lista: ");
    lista_imprimir(lista);

    lista_remover(lista, 10);
    
    printf("Lista com valor removido: ");
    lista_imprimir(lista);

    lista_destruir(lista);
    printf("\nLista destruida.\n");

    return 0;
}
