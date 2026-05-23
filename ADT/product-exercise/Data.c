//Nomes: Silvia Soares e Gekyume Serna


#include "Data.h"

struct data {
    int dia, mes, ano;
};

// Funções auxiliares
int convDataDiaJuliano(int dia, int mes, int ano) {
    int A, B, C, D, E, F;
    if (mes < 3) {
        ano = ano - 1;
        mes = mes + 12;
    }
    A = (int)(ano / 100);
    B = (int)(A / 4);
    C = 2 - A + B;
    D = (int)(365.25 * (ano + 4716));
    E = (int)(30.6001 * (mes + 1));
    F = D + E + dia + 0.5 + C - 1524.5;
    return (int)(F);
}

tData* convDiaJulianoData(int juliano) {
    int A, B, C, D, E, F, G, H, I, J, K;
    A = juliano;    
    if (A > 2299160) {
        B = (int)((A - 1867216.25) / 36524.25);
        C = A + 1 + B - (int)(B / 4);
    } else {
        C = A;
    }
    D = C + 1524;
    E = (int)((D - 122.1) / 365.25);
    F = (int)(E * 365.25);
    G = (int)((D - F) / 30.6001);
    H = D - F - (int)(G * 30.6001);
    if (G < 14) I = G - 1;
    else I = G - 13;
    if (I > 2) J = E - 4716;
    else J = E - 4715;
    if (J > 0) K = J;
    else K = abs(J + 1);
    return dta_cria(H, I, K);
}

// Funções do TAD Data
tData* dta_cria(int dia, int mes, int ano) {
    tData* dt = (tData*)malloc(sizeof(struct data));
    dt->dia = dia;
    dt->mes = mes;
    dt->ano = ano;
    return dt;
}

void dta_libera(tData* p) { free(p); }

void dta_acessa(tData* p, int* dia, int* mes, int* ano) {
    *dia = p->dia;
    *mes = p->mes;
    *ano = p->ano;
}

void dta_atribui(tData* p, int dia, int mes, int ano) {
    p->dia = dia;
    p->mes = mes;
    p->ano = ano;
}

tData* dta_intervalo(tData* p, int X) {
    int juliano = convDataDiaJuliano(p->dia, p->mes, p->ano);
    juliano += X;
    return convDiaJulianoData(juliano);
}

int dta_diferenca(tData* dt1, tData* dt2){
    int juliano1 = convDataDiaJuliano(dt1->dia, dt1->mes, dt1->ano);
    int juliano2 = convDataDiaJuliano(dt2->dia, dt2->mes, dt2->ano);
    return abs(juliano1 - juliano2);
}

tData* dta_exibe(tData* p) {
    printf("%02d/%02d/%04d", p->dia, p->mes, p->ano);
    return p;
}

char* dta_getData(tData* p){
    char* dt = (char*)malloc(11);
    sprintf(dt, "%02d/%02d/%04d", p->dia, p->mes, p->ano);
    return dt;
}

char* dta_MesExtenso(tData* p) {
    switch (p->mes) {
        case 1: return "janeiro";
        case 2: return "fevereiro";
        case 3: return "março";
        case 4: return "abril";
        case 5: return "maio";
        case 6: return "junho";
        case 7: return "julho";
        case 8: return "agosto";
        case 9: return "setembro";
        case 10: return "outubro";
        case 11: return "novembro";
        case 12: return "dezembro";
        default: return "*invalido*";
    }
}
