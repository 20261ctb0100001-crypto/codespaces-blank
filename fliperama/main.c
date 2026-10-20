#include <stdio.h>

void telas();
void jogadores();
void placar();
void adivinhe();
void ppt();
void parimpar();
void caraoucoroa();
void velha();

int main() {
    int opcao;

    do {
        printf("\n=== FLIPERAMA ===\n");
        printf("1 - Adivinhe o numero\n");
        printf("2 - Pedra, Papel e Tesoura\n");
        printf("3 - Par ou Impar\n");
        printf("4 - Cara ou Coroa\n");
        printf("5 - Jogo da Velha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adivinhe();
                break;

            case 2:
                ppt();
                break;

            case 3:
                parimpar();
                break;

            case 4:
                caraoucoroa();
                break;

            case 5:
                velha();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}