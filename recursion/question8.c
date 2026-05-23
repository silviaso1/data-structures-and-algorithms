/*Desenvolver uma função recursiva que, dada
uma string, exiba-a invertida.*/

#include <stdio.h>

void exibirInvertida(char s[]) {

    if (s[0] == '\0') {
        return;
    } else {
        exibirInvertida(s + 1);

        printf("%c", s[0]);
    }
}

void main() {
    char str[] = "hello world";
    
    printf("String original: %s\n", str);
    printf("String invertida: ");
    exibirInvertida(str);
    printf("\n");
    
}
