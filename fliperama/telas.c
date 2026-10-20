#include <stdio.h>
#include <string.h>

void titulo(const char texto[]) {
    int tamanho = strlen(texto);
    int espacos = (40 - tamanho) / 2;

    printf("========================================\n");

    for (int i = 0; i < espacos; i++) {
        printf(" ");
    }

    printf("%s\n", texto);

    printf("========================================\n");
}