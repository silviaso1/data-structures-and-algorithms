//Nomes: Silvia Soares e Gekyume Serna


#include <stdio.h>
#include <stdlib.h>
#include "TAD_Produto.h"
#include "TAD_Unidade.h"
#include "Data.h"

int main() {
    int dia, mes, ano;

    
    Produto* produtos[2];

    produtos[0] = pr_cria("Leite", "123456", 10.0, 0);
    produtos[1] = pr_cria("Iogurte", "987654", 6.0, 0);

    
    tData* d1 = dta_cria(1, 9, 2025);
    tData* d2 = dta_cria(3, 9, 2025);
    tData* d3 = dta_cria(10, 9, 2025);

    
    Unidade* u1 = unidade_cria(d1, 1);
    Unidade* u2 = unidade_cria(d2, 2);
    Unidade* u3 = unidade_cria(d3, 3);

    
    pr_addUnidade(produtos[0], u1);
    pr_addUnidade(produtos[0], u2);
    pr_addUnidade(produtos[1], u3);

    
    printf("Digite a data alvo (dd mm aaaa): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    tData* alvo = dta_cria(dia, mes, ano);

    
    for(int i=0; i<2; i++) {
        pr_exibe(produtos[i]);
        pr_verificaVencimento(produtos[i], alvo);
        printf("Preco final: %.2f\n", pr_getPreco(produtos[i]));
        printf("=================================\n");
    }

    
    for(int i=0; i<2; i++) {
        pr_libera(produtos[i]);
    }
    dta_libera(alvo);

    return 0;
}
