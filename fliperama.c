#include <stdio.h>
#include <string.h>

#define DONO "SEU NOME"
#define CAPACIDADE 10
#define TAM_APELIDO 15

void linha() {
    printf("======================================\n");
}

void titulo(char texto[]) {
    linha();
    printf("   %s\n", texto);
    linha();
}

int ler_numero(char mensagem[], int minimo, int maximo) {
    int numero, lidos;
    
    printf("%s", mensagem);
    lidos = scanf("%d", &numero);
    
    while (lidos != 1 || numero < minimo || numero > maximo) {
        if (lidos != 1) {
            scanf("%*s"); // Limpa o buffer caso não seja um número
        }
        printf("Opcao Invalida! Tente de novo: ");
        lidos = scanf("%d", &numero);
    }
    return numero;
}

void ler_texto(char mensagem[], char destino[]) {
    printf("%s", mensagem);
    scanf("%14s", destino); // Lê uma palavra de no máximo 14 letras
}

int buscar(char apelidos[][TAM_APELIDO], int qtd, char procurado[]) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (strcmp(apelidos[i], procurado) == 0) {
            return i;
        }
    }
    return -1;
}

int cadastrar(char apelidos[][TAM_APELIDO], int partidas[], int qtd) {
    char novo[TAM_APELIDO];
    
    titulo("NOVO JOGADOR");
    ler_texto("Apelido (sem espacos): ", novo);
    
    if (buscar(apelidos, qtd, novo) != -1) {
        printf("Esse apelido ja esta cadastrado.\n");
        return qtd;
    }
    
    strcpy(apelidos[qtd], novo);
    partidas[qtd] = 0;
    printf("Jogador %s cadastrado.\n", novo);
    return qtd + 1;
}

void listar(char apelidos[][TAM_APELIDO], int partidas[], int qtd) {
    int i;
    
    titulo("JOGADORES CADASTRADOS");
    if (qtd == 0) {
        printf("Nenhum jogador cadastrado ainda.\n");
    } else {
        for (i = 0; i < qtd; i++) {
            printf("[%d] %s: %d partidas\n", i, apelidos[i], partidas[i]);
        }
    }
}

void mostrar_menu() {
    linha();
    printf("    FLIPERAMA DO %s\n", DONO);
    linha();
    printf(" Adicionar Jogador\n");
    printf(" Cadastrar Partida\n");
    printf(" Listar Jogadores\n");
    printf(" Sair\n");
    linha();
}

int main() {
    char apelidos[CAPACIDADE][TAM_APELIDO];
    int partidas[CAPACIDADE];
    int qtd, opcao;
    
    qtd = 0;
    
    mostrar_menu();
    opcao = ler_numero("Sua escolha: ", 0, 3);
    
    while (opcao != 0) {
        if (opcao == 1) {
            if (qtd >= CAPACIDADE) {
                printf("O jogo esta cheio!\n");
            } else {
                qtd = cadastrar(apelidos, partidas, qtd);
            }
        } else if (opcao == 3) {
            listar(apelidos, partidas, qtd);
        }
        
        mostrar_menu();
        opcao = ler_numero("Sua escolha: ", 0, 3);
    }
    
    titulo("Ate a proxima!");
    return 0;
}
