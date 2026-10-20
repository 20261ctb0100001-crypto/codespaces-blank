#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_JOGADORES 100

typedef struct {
    char apelido[50];
    char nome[100];
    int partidas;
} Jogador;

Jogador jogadores[MAX_JOGADORES];
int quantidade_jogadores = 0;

#define ARQUIVO "jogadores.txt"

int comparar_apelidos(const char a[], const char b[]) {
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (tolower((unsigned char)a[i]) !=
            tolower((unsigned char)b[i])) {
            return 0;
        }

        i++;
    }

    return a[i] == '\0' && b[i] == '\0';
}

void carregar() {
    FILE *arquivo = fopen(ARQUIVO, "r");

    quantidade_jogadores = 0;

    if (arquivo == NULL) {
        return;
    }

    while (
        quantidade_jogadores < MAX_JOGADORES &&
        fscanf(
            arquivo,
            "%49[^|]|%99[^|]|%d\n",
            jogadores[quantidade_jogadores].apelido,
            jogadores[quantidade_jogadores].nome,
            &jogadores[quantidade_jogadores].partidas
        ) == 3
    ) {
        quantidade_jogadores++;
    }

    fclose(arquivo);
}

void salvar() {
    FILE *arquivo = fopen(ARQUIVO, "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar jogadores.\n");
        return;
    }

    for (int i = 0; i < quantidade_jogadores; i++) {
        fprintf(
            arquivo,
            "%s|%s|%d\n",
            jogadores[i].apelido,
            jogadores[i].nome,
            jogadores[i].partidas
        );
    }

    fclose(arquivo);
}

void cadastrar() {
    if (quantidade_jogadores >= MAX_JOGADORES) {
        printf("Limite de jogadores atingido.\n");
        return;
    }

    printf("========================================\n");
    printf("              NOVO JOGADOR\n");
    printf("========================================\n");

    char apelido[50];

    printf("Apelido (sem espacos): ");
    scanf("%49s", apelido);

    for (int i = 0; i < quantidade_jogadores; i++) {
        if (comparar_apelidos(
                jogadores[i].apelido,
                apelido)) {

            printf("Esse apelido ja esta cadastrado!\n");
            return;
        }
    }

    strcpy(
        jogadores[quantidade_jogadores].apelido,
        apelido
    );

    getchar();

    printf("Nome completo: ");

    fgets(
        jogadores[quantidade_jogadores].nome,
        sizeof(jogadores[quantidade_jogadores].nome),
        stdin
    );

    jogadores[quantidade_jogadores].nome[
        strcspn(
            jogadores[quantidade_jogadores].nome,
            "\n"
        )
    ] = '\0';

    jogadores[quantidade_jogadores].partidas = 0;

    quantidade_jogadores++;

    salvar();

    printf("Jogador %s cadastrado.\n", apelido);
}

void listar() {
    printf("========================================\n");
    printf("         JOGADORES CADASTRADOS\n");
    printf("========================================\n");

    if (quantidade_jogadores == 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade_jogadores; i++) {
        printf(
            "%s | %s | %d partidas\n",
            jogadores[i].apelido,
            jogadores[i].nome,
            jogadores[i].partidas
        );
    }

    printf("========================================\n");
}

Jogador* escolher_jogador() {
    if (quantidade_jogadores == 0) {
        printf("Nenhum jogador cadastrado.\n");
        printf("Cadastre um jogador primeiro.\n");
        return NULL;
    }

    printf("========================================\n");
    printf("           ESCOLHER JOGADOR\n");
    printf("========================================\n");

    for (int i = 0; i < quantidade_jogadores; i++) {
        printf(
            "%d - %s | %s\n",
            i + 1,
            jogadores[i].apelido,
            jogadores[i].nome
        );
    }

    int escolha;

    printf("Escolha o jogador: ");

    if (scanf("%d", &escolha) != 1) {
        printf("Digite apenas numeros.\n");

        while (getchar() != '\n');

        return NULL;
    }

    if (escolha < 1 || escolha > quantidade_jogadores) {
        printf("Jogador invalido.\n");
        return NULL;
    }

    return &jogadores[escolha - 1];
}