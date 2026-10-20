#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ppt() {
    int jogador, computador;

    srand(time(NULL));

    printf("\n=== PEDRA, PAPEL E TESOURA ===\n");
    printf("🤖 VOCE ESTA JOGANDO CONTRA O ROBO!\n\n");

    printf("1 - Pedra\n");
    printf("2 - Papel\n");
    printf("3 - Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &jogador);

    if (jogador < 1 || jogador > 3) {
        printf("Escolha invalida!\n");
        return;
    }

    computador = rand() % 3 + 1;

    printf("\n🤖 Robo: estou pensando...\n");

    printf("🤖 Robo escolheu: ");

    if (computador == 1)
        printf("Pedra\n");
    else if (computador == 2)
        printf("Papel\n");
    else
        printf("Tesoura\n");

    if (jogador == computador) {
        printf("\nEMPATE! 🤖\n");
    }
    else if (
        (jogador == 1 && computador == 3) ||
        (jogador == 2 && computador == 1) ||
        (jogador == 3 && computador == 2)
    ) {
        printf("\nVOCE VENCEU O ROBO! 🔥\n");
    }
    else {
        printf("\nO ROBO VENCEU! 🤖\n");
    }
}
