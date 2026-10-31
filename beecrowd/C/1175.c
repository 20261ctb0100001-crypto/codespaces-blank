#include <stdio.h>

int main() {
    int N[20];
    int i, temp;

    // Lê os 20 valores
    for (i = 0; i < 20; i++) {
        scanf("%d", &N[i]);
    }

    // Troca os elementos
    for (i = 0; i < 10; i++) {
        temp = N[i];
        N[i] = N[19 - i];
        N[19 - i] = temp;
    }

    // Mostra o vetor modificado
    for (i = 0; i < 20; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}