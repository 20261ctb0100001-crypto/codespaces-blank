#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char apelido[50];
    char nome[100];
    int partidas;
} Jogador;

#define MAX_JOGADORES 100

extern Jogador jogadores[MAX_JOGADORES];
extern int quantidade_jogadores;

void carregar();
void cadastrar();
void listar();
Jogador* escolher_jogador();

void jogar_adivinhe(Jogador *jogador);
void jogar_ppt(Jogador *jogador);
void jogar_parimpar(Jogador *jogador);

void mostrar_placar();
void titulo(const char texto[]);

int main() {

    srand((unsigned int)time(NULL));

    carregar();

    while (1) {

        titulo("FLIPERAMA");

        printf("1 - Adivinhe\n");
        printf("2 - Pedra, Papel e Tesoura\n");
        printf("3 - Par ou Impar\n");
        printf("4 - Cadastrar jogador\n");
        printf("5 - Listar jogadores\n");
        printf("6 - Ver placar\n");
        printf("0 - Sair\n");

        int opcao;

        printf("\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Digite apenas numeros.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (opcao) {

            case 1: {
                Jogador *jogador = escolher_jogador();

                if (jogador != NULL) {
                    jogar_adivinhe(jogador);
                }

                break;
            }

            case 2: {
                Jogador *jogador = escolher_jogador();

                if (jogador != NULL) {
                    jogar_ppt(jogador);
                }

                break;
            }

            case 3: {
                Jogador *jogador = escolher_jogador();

                if (jogador != NULL) {
                    jogar_parimpar(jogador);
                }

                break;
            }

            case 4:
                cadastrar();
                break;

            case 5:
                listar();
                break;

            case 6:
                mostrar_placar();
                break;

            case 0:
                printf("\nSaindo do Fliperama...\n");
                return 0;

            default:
                printf("\nOpcao invalida.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }

    return 0;
}