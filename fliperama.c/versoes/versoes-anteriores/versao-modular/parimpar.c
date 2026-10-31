#include <stdio.h>

void parimpar() {
    int numero;

    printf("\n=== PAR OU IMPAR ===\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O numero %d e PAR.\n", numero);
    } else {
        printf("O numero %d e IMPAR.\n", numero);
    }
}