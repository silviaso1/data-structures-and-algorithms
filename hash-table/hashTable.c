/*Este trabalho consiste na implementação de uma
tabela hash simples, com as seguintes características:

a. A tabela hash será composta por 10 listas
encadeadas simples (na prática, um vetor de
TLista, com tamanho igual a 10);
b. Os elementos de cada uma das listas não estão
dispostos de forma ordenada (crescente ou
decrescente). Ou seja, não há critério algum
de ordenação de seus elementos;
c. Elementos repetidos são proibidos nesta
tabela hash.

Devem ser desenvolvidas as mesmas operações
(funções) trabalhadas nas aulas para a implementação
de lista encadeada, a saber:
 Inserção de um novo valor;
 Remoção de determinado elemento;
 Alteração de um número por outro;
 Busca de um elemento na tabela;
 Exibição dos elementos: esta operação poderá
ser executada de duas maneiras, por escolha
do usuário – exibir os elementos de uma das
listas (informando o seu número) ou de toda a
tabela.
Para se determinar a qual lista determinado número
pertencerá, será necessário dividir este valor por 10
(quantidade de listas da tabela) e recuperar o resto
dessa operação. Este valor representará a lista na
qual o elemento deverá ser inserido. Por exemplo, o
número 34 será inserido na lista 4, pois o resto de
34/10 é 4;
*/

//Dupla:
//Silvia Soares e Jonathan Bastos

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef TNo* TLista;

#define TAM 10

int inserir(TLista *L, int numero);
int remover(TLista *L, int numero);
int alterar(TLista *L, int velho, int novo);
TLista buscar(TLista *L, int numero, int *numtab, TLista *pre);
void exibir(TLista *L);
int menu();

int dividir(int numero);
void exibirLista(TLista L);


int main() { 
    TLista L[TAM] = {NULL}; 
    int num1, num2, op;
    TLista pos, pre;
    int encontrar;

    do {
        system("CLS");

        op = menu();

        switch (op) {
            case 1: 
                printf("\nEntre com o valor a ser inserido: ");
                scanf("%d", &num1);

                if (inserir(L, num1) == 1) {
                    printf("\n\tInsercao realizada com sucesso!\n");
                } else {
                    printf("\n\tERRO: insercao nao realizada!\n");
                }
                break;

            case 2: 
                printf("\nEntre com o valor a ser removido: ");
                scanf("%d", &num1);

                if (remover(L, num1)) {
                    printf("\n\tRemocao realizada!\n");
                } else {
                    printf("\n\tERRO: remocao nao realizada!\n");
                }
                break;

            case 3: 
                printf("\nEntre com o valor a ser alterado: ");
                scanf("%d", &num1);

                printf("\nEntre com o novo valor: ");
                scanf("%d", &num2);

                if (alterar(L, num1, num2)) {
                    printf("\n\tAlteracao realizada!\n");
                } else {
                    printf("\n\tERRO: alteracao nao realizada!\n");
                }
                break;

            case 4: 
                printf("\nEntre com o valor a ser buscado: ");
                scanf("%d", &num1);

                pos = buscar(L, num1, &encontrar, &pre);
                if (pos) {
                    printf("\n\tO valor %d foi encontrado na lista da tabela %d!\n", pos->valor, encontrar);
                } else {
                    printf("\n\tO valor NAO foi encontrado na lista!\n");
                }
                break;

            case 5: 
                exibir(L);
                break;
            case 6: 
                printf("\n\nPrograma finalizado!\n");
                break;

            default: 
                printf("\n\nOpcao invalida! Tente novamente.\n");
        }

        system("PAUSE");
    } while (op != 6);

    return 0;
}

int inserir(TLista *L, int numero) {
    int tab;
    TLista aux, pre;

    if (buscar(L, numero, &tab, &pre)) {
        return 0;
    }

    aux = (TLista) malloc(sizeof(TNo));
    if (!aux) {
        return 0;
    }

    aux->valor = numero;
    aux->prox = L[tab];
    L[tab] = aux;

    return 1;
}

int remover(TLista *L, int numero) {
    int tab;
    TLista pre, pos;

    pos=buscar(L, numero, &tab, &pre);
    if (pos){
        if (pre == NULL){
            L[tab] = pos->prox;
        }else{
            pre->prox= pos->prox;
        }
        free(pos);
        return 1;
    }
    return 0;
}


int alterar(TLista *L, int velho, int novo){ 
    if(inserir(L, novo)){
        if(remover(L, velho)){
            return 1;
        }else{
            remover(L, novo);    
        }
    }
    return 0;
}

TLista buscar(TLista *L, int numero, int *numtab, TLista *pre){
    TLista aux;
    int tabela=dividir(numero);
    if (numtab){
        *numtab= tabela;
    }

    aux = L[tabela];
    *pre =NULL;

    while (aux) {
        if (aux->valor == numero) {
            return aux;
        }
        *pre=aux;
        aux = aux->prox;
    }
    return NULL;
}

void exibir(TLista *L) 
{
    int opcao;
    printf("deseja exibir:\n");
    printf("(1) Uma lista especifica\n");
    printf("(2) toda a tabela\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) 
    {
        case 1: {
            int numLista;
            printf("Digite o numero da lista: ");
            scanf("%d", &numLista);

            if (numLista < 0 || numLista >= TAM) {
                printf("Lista invalida!\n");
                break;
            }

            exibirLista(L[numLista]);
            break;
        }
        case 2:
            for (int i = 0; i < TAM; i++) {
                printf("Lista %d: ", i);
                exibirLista(L[i]);
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void exibirLista(TLista L) 
{
    TLista aux = L;
    if (!aux) {
        printf("Lista vazia!\n");
    } else {
        while (aux) {
            printf("%d\t", aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int menu() {
    int opcao;

    printf("Menu de Operacoes:\n\n");
    printf("(1) Inserir\n");
    printf("(2) Remover\n");
    printf("(3) Alterar\n");
    printf("(4) Buscar\n");
    printf("(5) Exibir\n");
    printf("(6) Sair\n\n");

    printf("Entre com a sua opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

int dividir(int numero){
    return numero % 10;
}