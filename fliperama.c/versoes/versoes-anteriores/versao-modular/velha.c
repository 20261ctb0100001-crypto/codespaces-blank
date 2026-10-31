#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostrarTabuleiro(char tabuleiro[]) {
    printf("\n");
    printf(" %c | %c | %c\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
    printf("\n");
}

int verificarVencedor(char t[]) {
    int linhas[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (t[linhas[i][0]] == t[linhas[i][1]] &&
            t[linhas[i][1]] == t[linhas[i][2]]) {

            if (t[linhas[i][0]] == 'X')
                return 1;

            if (t[linhas[i][0]] == 'O')
                return 2;
        }
    }

    return 0;
}

void velha() {
    char tabuleiro[9] = {'1','2','3','4','5','6','7','8','9'};
    int jogador, robo;
    int vencedor = 0;
    int jogadas = 0;

    srand(time(NULL));

    printf("\n=== JOGO DA VELHA ===\n");
    printf("Voce = X\n");
    printf("Robo = O\n");

    while (jogadas < 9 && vencedor == 0) {

        mostrarTabuleiro(tabuleiro);

        printf("Escolha uma posicao (1-9): ");
        scanf("%d", &jogador);

        if (jogador < 1 || jogador > 9 ||
            tabuleiro[jogador - 1] == 'X' ||
            tabuleiro[jogador - 1] == 'O') {

            printf("Posicao invalida!\n");
            continue;
        }

        tabuleiro[jogador - 1] = 'X';
        jogadas++;

        vencedor = verificarVencedor(tabuleiro);

        if (vencedor != 0)
            break;

        if (jogadas == 9)
            break;

        do {
            robo = rand() % 9;
        } while (tabuleiro[robo] == 'X' || tabuleiro[robo] == 'O');

        printf("Robo esta pensando...\n");

        tabuleiro[robo] = 'O';
        jogadas++;

        vencedor = verificarVencedor(tabuleiro);
    }

    mostrarTabuleiro(tabuleiro);

    if (vencedor == 1)
        printf("VOCE VENCEU O ROBO!\n");
    else if (vencedor == 2)
        printf("O ROBO VENCEU!\n");
    else
        printf("EMPATE!\n");
}