#include <stdio.h>
#include <stdlib.h>

// Definição de tipos
typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

// Protótipos das funções
int empilhar(TLista *P, int numero);
int desempilhar(TLista *P, int *numero);
int topo(TLista P, int *t);
int ocorrencias(TLista *P, int num);
int remover_todas_ocorrencias(TLista *P, int num);
int menu();

// Main
int main() {
    TLista P = NULL;  // Representando a pilha inicialmente vazia
    int num, op;

    do {
        system("CLS");  // Limpar tela (use "clear" no Linux/Mac)

        // Exibindo o menu ao usuário
        op = menu();

        // Verificando a opção escolhida
        switch (op) {
            // Empilhar
            case 1:
                printf("\nEntre com o valor a ser inserido na pilha: ");
                scanf("%d", &num);
                if (empilhar(&P, num) == 1) {
                    printf("\n\tInsercao realizada com sucesso!");
                } else {
                    printf("\n\tERRO: Insercao nao realizada!");
                }
                break;

            // Desempilhar
            case 2:
                if (desempilhar(&P, &num)) {
                    printf("\n\tO valor %d foi removido da pilha!", num);
                } else {
                    printf("\n\tERRO: Pilha vazia!");
                }
                break;

            // Topo
            case 3:
                if (topo(P, &num)) {
                    printf("\n\tTopo da pilha: %d", num);
                } else {
                    printf("\n\tERRO: Pilha vazia!");
                }
                break;

            // Contar Ocorrências
            case 4:
                printf("\nEntre com o valor a ser contado na pilha: ");
                scanf("%d", &num);
                int cont = ocorrencias(&P, num);
                printf("\n\tO valor %d ocorre %d vezes na pilha.", num, cont);
                break;

            // Remover Todas as Ocorrências
            case 5:
                printf("\nEntre com o valor a ser removido da pilha: ");
                scanf("%d", &num);
                if (remover_todas_ocorrencias(&P, num)) {
                    printf("\n\tTodas as ocorrencias do valor %d foram removidas com sucesso!", num);
                } else {
                    printf("\n\tERRO: Valor %d nao encontrado na pilha!", num);
                }
                break;

            // Saída
            case 6:
                printf("\n\nPrograma finalizado!");
                break;

            default:
                printf("\n\nOpcao invalida! Tente novamente.");
        }

        system("PAUSE");
    } while (op != 6);

    return 0;
}

// Implementação das funções
int empilhar(TLista *P, int numero) {
    TLista aux = (TLista) malloc(sizeof(TNo));
    if (!aux) {
        return 0;
    }
    aux->valor = numero;
    aux->prox = *P;
    *P = aux;
    return 1;
}

int desempilhar(TLista *P, int *numero) {
    if (*P == NULL) {
        return 0;
    }
    TLista aux = *P;
    *numero = aux->valor;
    *P = aux->prox;
    free(aux);
    return 1;
}

int topo(TLista P, int *t) {
    if (P) {
        *t = P->valor;
        return 1;
    } else {
        return 0;
    }
}

int ocorrencias(TLista *P, int num) {
    int cont = 0;
    TLista aux = NULL;
    int valor;

    // Percorrer a pilha e contar as ocorrências
    while (*P != NULL) {
        desempilhar(P, &valor);
        if (valor == num) {
            cont++;
        }
        // Empilhar os elementos na pilha auxiliar
        empilhar(&aux, valor);
    }

    // Reempilhar os elementos de volta na pilha original
    while (aux != NULL) {
        desempilhar(&aux, &valor);
        empilhar(P, valor);
    }

    return cont;
}

int remover_todas_ocorrencias(TLista *P, int num) {
    TLista aux = NULL;  // Pilha auxiliar
    int valor;
    int removido = 0;

    // Percorrer a pilha e empilhar na pilha auxiliar se valor diferente de 'num'
    while (*P != NULL) {
        desempilhar(P, &valor);
        if (valor != num) {
            empilhar(&aux, valor);
        } else {
            removido = 1;  // Indicar que pelo menos uma ocorrência foi removida
        }
    }

    // Reempilhar os elementos da pilha auxiliar de volta para a pilha original
    while (aux != NULL) {
        desempilhar(&aux, &valor);
        empilhar(P, valor);
    }

    return removido;  // Retorna 1 se removeu pelo menos uma ocorrência, 0 caso contrário
}

int menu() {
    int opcao;
    printf("Menu de Operacoes:\n\n");
    printf("(1) Empilhar\n");
    printf("(2) Desempilhar\n");
    printf("(3) Topo\n");
    printf("(4) Contar Ocorrencias\n");
    printf("(5) Remover Todas as Ocorrencias\n");
    printf("(6) Sair\n\n");
    printf("Entre com a sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}
