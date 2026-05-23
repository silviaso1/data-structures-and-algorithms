/*Desenvolver uma função recursiva que exiba
todos os múltiplos do número N, inferiores ou
iguais ao valor V.*/

#include <stdio.h>

void func(int n, int v, int i);

int main() {
    int n = 5, v = 30;
    int i = 1;

    printf("Multiplos de %d inferiores ou iguais a %d:\n", n, v);
    func(n, v, i);

    return 0;
}

void func(int n, int v, int i) {
    int multiple = n * i;

    if (multiple <= v) {
        printf("%d x %d = %d\n", n, i, multiple);
        func(n, v, i + 1); 
    }
}
