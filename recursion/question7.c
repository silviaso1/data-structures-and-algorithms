/*Desenvolver uma função recursiva que
determine o número de caracteres comuns
entre duas strings s1 e s2.*/

#include <stdio.h>

int caracteresComuns(char s1[], char s2[]) {
    // Caso base: uma das strings é vazia
    if (s1[0] == '\0' || s2[0] == '\0') {
        return 0;
    }
    
    if (s1[0] == s2[0]) {
        return 1 + caracteresComuns(s1 + 1, s2 + 1); 
    } else {
        int comS1SemS2 = caracteresComuns(s1 + 1, s2);

        int comS2SemS1 = caracteresComuns(s1, s2 + 1);
        
        // Retorna o máximo encontrado entre as duas opções
        return (comS1SemS2 > comS2SemS1) ? comS1SemS2 : comS2SemS1;
    }
}

int main() {
    char s1[] = "abcdef";
    char s2[] = "abghij";
    
    int comuns = caracteresComuns(s1, s2);
    
    printf("Número de caracteres comuns entre '%s' e '%s' é: %d\n", s1, s2, comuns);
    
    return 0;
}
