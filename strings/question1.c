/*Suponha que não existissem as funções strlen,
strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o
mesmo objetivo daquelas.*/


#include <stdio.h>

int meu_strlen(const char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}


char* meu_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  
    return dest;
}


char* meu_strcat(char *dest, const char *src) {
    int tamanho_dest = meu_strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[tamanho_dest + i] = src[i];
        i++;
    }
    dest[tamanho_dest + i] = '\0';  
    return dest;
}

int meu_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void main() {
    char str1[50] = "Olá";
    char str2[50] = "Mundo";
    char str3[50];

    printf("Tamanho de str1: %d\n", meu_strlen(str1));

    meu_strcpy(str3, str1);
    printf("Cópia de str1 para str3: %s\n", str3);

    meu_strcat(str1, str2);
    printf("Concatenação de str2 ao final de str1: %s\n", str1);

    printf("Comparação de str1 e str2: %d\n", meu_strcmp(str1, str2));
    printf("Comparação de str1 e str3: %d\n", meu_strcmp(str1, str3));

   
}
