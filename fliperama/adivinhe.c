#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void adivinhe() {
    int numero, tentativa;

    srand(time(NULL));
    numero = rand() % 100 + 1;

    printf("\n=== ADIVINHE O NUMERO ===\n");
    printf("Tente adivinhar um numero de 1 a 100: ");
    scanf("%d", &tentativa);

    while (tentativa != numero) {
        if (tentativa < numero) {
            printf("Muito baixo! Tente novamente: ");
        } else {
            printf("Muito alto! Tente novamente: ");
        }

        scanf("%d", &tentativa);
    }

    printf("Parabens! Voce acertou!\n");
}