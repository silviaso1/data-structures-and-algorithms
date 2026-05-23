
//Nomes: Silvia Soares e Gekyume Serna
#include "TAD_Produto.h"

struct produto {
    char* identificacao;
    char* codBarras;
    float preco;
    int qtde;
    Unidade** unidades;
};

Produto* pr_cria(const char* identificacao, const char* codBarras, float preco, int qtde) {
    Produto* p = (Produto*) malloc(sizeof(Produto));
    p->identificacao = strdup(identificacao ? identificacao : "Produto");
    p->codBarras = strdup(codBarras ? codBarras : "");
    p->preco = preco;
    p->qtde = qtde;
    p->unidades = (Unidade**) malloc(qtde * sizeof(Unidade*));
    return p;
}

void pr_libera(Produto* p) {
    if(p != NULL) {
        free(p->identificacao);
        free(p->codBarras);
        for(int i=0; i<p->qtde; i++) unidade_libera(p->unidades[i]);
        free(p->unidades);
        free(p);
    }
}

void pr_exibe(Produto* p) {
    printf("Produto: %s | Cod: %s | Preco: %.2f | Qtde: %d\n", 
            p->identificacao, p->codBarras, p->preco, p->qtde);
    for(int i=0; i<p->qtde; i++) unidade_exibe(p->unidades[i]);
}

const char* pr_getIdentificacao(Produto* p){ return p->identificacao; }
const char* pr_getCodBarras(Produto* p){ return p->codBarras; }
float pr_getPreco(Produto* p){ return p->preco; }
int pr_getQtde(Produto* p){ return p->qtde; }

void pr_setIdentificacao(Produto* p, const char* id){ strcpy(p->identificacao,id); }
void pr_setCodBarras(Produto* p, const char* cb){ strcpy(p->codBarras,cb); }
void pr_setPreco(Produto* p, float preco){ p->preco = preco; }
void pr_setQtde(Produto* p, int q){ p->qtde = q; }

int pr_ehSemelhante(Produto* p1, Produto* p2){
    return strcmp(p1->identificacao, p2->identificacao) == 0;
}

void pr_reajuste(Produto* p, float percentual){
    p->preco = p->preco * (1 + percentual/100.0);
}

char* pr_getProduto(Produto* p){
    char* str = (char*) malloc(100);
    sprintf(str,"Produto: %s | Cod: %s | Preco: %.2f | Qtde: %d",
            p->identificacao, p->codBarras, p->preco, p->qtde);
    return str;
}

int pr_iguais(Produto* p1, Produto* p2){
    return strcmp(p1->identificacao,p2->identificacao)==0 &&
           strcmp(p1->codBarras,p2->codBarras)==0 &&
           p1->preco==p2->preco &&
           p1->qtde==p2->qtde;
}

void pr_addUnidade(Produto* p, Unidade* u){
    p->unidades[p->qtde++] = u;
}

void pr_verificaVencimento(Produto* p, tData* alvo){
    int desconto = 0;
    printf("\nProduto %s:\n", p->identificacao);
    for(int i=0; i<p->qtde; i++){
        int idade = unidade_getIdade(p->unidades[i], alvo);
        if(idade <= 3){
            desconto = 1;
            printf("Unidade vencendo: ");
            unidade_exibe(p->unidades[i]);
        }
    }
    if(desconto){
        printf(">> Aplicando desconto de 25%%!\n");
        pr_reajuste(p,-25);
    }
}
