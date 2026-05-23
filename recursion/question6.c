/*Dada uma string s, desenvolver uma função
recursiva que determine se s é ou não um
palíndromo.*/

#include <stdio.h>
#include <string.h>

#define TAM 5
int func(char s[], int i, int j);

int main()
{
    char s[TAM] = "ana";
    int i =0, j= strlen(s)- 1;
    
    int retorno = func(s, i, j);
    
    if(retorno == 1){
        printf("É palindromo\n");
    }
    else{
        printf("Não é\n");
    }
}
int func(char s[], int i, int j){
    
    if(i<strlen(s) && j>0){
         if(s[i] == s[j]){
            return 1;
        }
        else{
            return 0;
        }
        
        func(s, i+ 1, j- 1);
        
    }

}