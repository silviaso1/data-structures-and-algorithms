#include <stdio.h>

int ehSimetrica(int matriz[][3], int n);

int main() {
    int matriz[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    
    if (ehSimetrica(matriz, 3)) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }
    
    return 0;
}

int ehSimetrica(int matriz[][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return 0;  
            }
        }
    }
    return 1;  
}
