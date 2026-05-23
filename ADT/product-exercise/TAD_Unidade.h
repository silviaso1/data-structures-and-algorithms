//Nomes: Silvia Soares e Gekyume Serna

#pragma once
#include "Data.h"

typedef struct unidade Unidade;

Unidade* unidade_cria(tData* fabricacao, int lote);
void unidade_libera(Unidade* u);
void unidade_exibe(Unidade* u);
tData* unidade_getFabricacao(Unidade* u);
int unidade_getLote(Unidade* u);
void unidade_setFabricacao(Unidade* u, tData* fabricacao);
void unidade_setLote(Unidade* u, int lote);
int unidade_getIdade(Unidade* u, tData* dataAlvo);
int unidade_menorQue(Unidade* u1, Unidade* u2);
char* unidade_getUnidade(Unidade* u);
