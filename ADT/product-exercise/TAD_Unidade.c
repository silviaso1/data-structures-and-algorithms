//Nomes: Silvia Soares e Gekyume Serna

#include "TAD_Unidade.h"

struct unidade {
    tData* fabricacao;
    int lote;
};

Unidade* unidade_cria(tData* fabricacao, int lote) {
    Unidade* u = (Unidade*) malloc(sizeof(Unidade));
    if (fabricacao != NULL) {
        int d, m, a;
        dta_acessa(fabricacao, &d, &m, &a);
        u->fabricacao = dta_cria(d, m, a);
    } else {
        u->fabricacao = dta_cria(1, 1, 2023);
    }
    u->lote = lote;
    return u;
}

void unidade_libera(Unidade* u) {
    if (u != NULL) {
        dta_libera(u->fabricacao);
        free(u);
    }
}

void unidade_exibe(Unidade* u) {
    printf("Data de Fabricacao: ");
    dta_exibe(u->fabricacao);
    printf(" | Lote: %d\n", u->lote);
}

tData* unidade_getFabricacao(Unidade* u) { return u->fabricacao; }
int unidade_getLote(Unidade* u) { return u->lote; }

void unidade_setFabricacao(Unidade* u, tData* fabricacao) {
    int d, m, a;
    dta_acessa(fabricacao, &d, &m, &a);
    dta_atribui(u->fabricacao, d, m, a);
}

void unidade_setLote(Unidade* u, int lote) { u->lote = lote; }

int unidade_getIdade(Unidade* u, tData* dataAlvo) {
    return dta_diferenca(dataAlvo, u->fabricacao);
}

int unidade_menorQue(Unidade* u1, Unidade* u2) {

    tData* base = dta_cria(1, 1, 2025);
    int idade1 = unidade_getIdade(u1, base);
    int idade2 = unidade_getIdade(u2, base);
    dta_libera(base);

    if (idade1 < idade2) return 1;
    if (idade1 == idade2) return u1->lote < u2->lote;
    return 0;
}

char* unidade_getUnidade(Unidade* u) {
    char* str = (char*) malloc(50);
    char* data = dta_getData(u->fabricacao);
    sprintf(str, "Data: %s | Lote: %d", data, u->lote);
    free(data);
    return str;
}
