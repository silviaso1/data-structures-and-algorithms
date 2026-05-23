/*Dada uma string s, desenvolver uma função
que determine se s é ou não um palíndromo.
Observação: uma string s será um palíndromo
quando seus caracteres formarem a mesma
sequência, independente se s é percorrida da
esquerda para direita ou vice-versa.*/

#include <stdio.h>

#define TAM 5

int func(char s[]);

void main()
{
    char s[TAM] = "ana";

    
    int retorno = func(s);
    
    if(retorno == 1){
        printf("É palindromo\n");
    }
    else{
        printf("Não é \n");
    }
}

int func(char s[]){
    int i, j;
    
    for(i=0, j=strlen(s) - 1; i<strlen(s), j>0; i++, j--){
        if(s[i] == s[j]){
            return 1;
        }
        else{
            return 0;
        }
    }
}