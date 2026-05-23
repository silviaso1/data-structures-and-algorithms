/*Dupla:
    Silvia Soares de Oliveira;
    Gabriel da Silva Pestana
*/

#include <stdio.h>
#include "TAD_Altura.h"

int main() {
    Altura *alt1, *alt2, *diferenca, *soma, *copia;
    int m, cm;

    alt1 = alt_cria(2, 30);  
    alt2 = alt_cria(1, 80);   

    printf("Altura 1: %s\n", alt_getAltura(alt1));
    printf("Altura 2: %s\n", alt_getAltura(alt2));

    printf("\nComparacao (alt1 - alt2): %d\n", alt_compara(alt1, alt2));

 
    diferenca = alt_diferenca(alt1, alt2);
    printf("Diferenca entre alt1 e alt2: %s\n", alt_getAltura(diferenca));

 
    copia = alt_copia(alt1);
    printf("Copia de alt1: %s\n", alt_getAltura(copia));

    soma = alt_soma(alt1, 50); 
    printf("Altura 1 + 50cm: %s\n", alt_getAltura(soma));

    alt_atribui(alt2, 3, 15);
    printf("Altura 2 apos atribui: %s\n", alt_getAltura(alt2));
    
    alt_acessa(alt1, &m, &cm);
    printf("\nAcesso junto alt1: %dm %dcm\n", m, cm);

    alt_acessaMetroSeparado(alt1, &m);
    printf("Apenas metros alt1: %dm\n", m);
    alt_acessaCentimetroSeparado(alt1, &cm);
    printf("Apenas centimetros alt1: %dcm\n", cm);

    alt_acessa(alt2, &m, &cm);
    printf("\nAcesso junto alt2: %dm %dcm\n", m, cm);


    alt_acessaMetroSeparado(alt2, &m);
    printf("Apenas metros alt2: %dm\n", m);
    alt_acessaCentimetroSeparado(alt2, &cm);
    printf("Apenas centimetros alt2: %dcm\n", cm);

    alt_libera(alt1);
    alt_libera(alt2);
    alt_libera(diferenca);
    alt_libera(copia);
    alt_libera(soma);

    return 0;
}
