//Nomes: Silvia Soares e Gekyume Serna

#pragma once
#include "TAD_Unidade.h"

typedef struct produto Produto;

Produto* pr_cria(const char* identificacao, const char* codigoBarras, float preco, int qtde);
void pr_libera(Produto* p);
void pr_exibe(Produto* p);
int pr_ehSemelhante(Produto* p1, Produto* p2);
void pr_reajuste(Produto* p, float percentual);
char* pr_getProduto(Produto* p);
int pr_iguais(Produto* p1, Produto* p2);

void pr_addUnidade(Produto* p, Unidade* u);
void pr_verificaVencimento(Produto* p, tData* alvo);

const char* pr_getIdentificacao(Produto* p);
const char* pr_getCodBarras(Produto* p);
float pr_getPreco(Produto* p);
int pr_getQtde(Produto* p);
