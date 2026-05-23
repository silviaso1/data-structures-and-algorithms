//Nomes: Silvia Soares e Gekyume Serna

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Representação do TAD: TData
typedef struct data tData;

/* Funções exportadas */
tData* dta_cria(int dia, int mes, int ano);
void dta_libera(tData* p);
void dta_acessa(tData* p, int* dia, int* mes, int* ano);
void dta_atribui(tData* p, int dia, int mes, int ano);
tData* dta_intervalo(tData* p1, int X);
tData* dta_exibe(tData* p1);
char* dta_getData(tData* p);
int dta_diferenca(tData* dt1, tData* dt2);
char* dta_MesExtenso(tData* p);
