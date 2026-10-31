#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void caraoucoroa() {
    int jogador, resultado;

    srand(time(NULL));

    printf("\n=== CARA OU COROA ===\n");
    printf("🤖 Voce esta jogando contra o robo!\n\n");

    printf("1 - Cara\n");
    printf("2 - Coroa\n");
    printf("Escolha: ");
    scanf("%d", &jogador);

    if (jogador < 1 || jogador > 2) {
        printf("Escolha invalida!\n");
        return;
    }

    resultado = rand() % 2 + 1;

    printf("\n🤖 O robo jogou a moeda...\n");

    if (resultado == 1)
        printf("Resultado: CARA!\n");
    else
        printf("Resultado: COROA!\n");

    if (jogador == resultado)
        printf("🎉 Voce acertou!\n");
    else
        printf("🤖 O robo venceu!\n");
}