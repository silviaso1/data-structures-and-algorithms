/*Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/

#include <stdio.h>
#include <string.h>

void removerCaractere(char *str, char caractere) {
    int i, j = 0;
    int tamanho = strlen(str);

    for (i = 0; i < tamanho; i++) {
        if (str[i] != caractere) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0'; 
}

void main() {
    char minhaString[50] = "Exemplo com muitas letras ";
    char caractereRemover = 'm';

    removerCaractere(minhaString, caractereRemover);
    
    printf("Nova string: %s\n", minhaString); 


}