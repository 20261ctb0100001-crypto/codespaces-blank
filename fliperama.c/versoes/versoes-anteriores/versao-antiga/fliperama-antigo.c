#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CAPACIDADE 50
#define TAM_APELIDO 50
#define ARQUIVO "jogadores.csv"
#define MAO_MAX 80
#define TOTAL_CARTAS 76

typedef struct {
    int cor;
    int numero;
} Carta;

const char *cores[] = {"Vermelho", "Azul", "Verde", "Amarelo"};

void linha(void) {
    printf("========================================\n");
}

void titulo(const char texto[]) {
    int tamanho = (int)strlen(texto);
    int espacos = (40 - tamanho) / 2;

    linha();
    for (int i = 0; i < espacos; i++) printf(" ");
    printf("%s\n", texto);
    linha();
}

int buscar(char apelidos[][TAM_APELIDO], int qtd,
           const char procurado[]) {
    for (int i = 0; i < qtd; i++)
        if (strcmp(apelidos[i], procurado) == 0) return i;
    return -1;
}

void limpar_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void carregar(char apelidos[][TAM_APELIDO],
              int partidas[], int *qtd) {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) return;

    char nome[TAM_APELIDO];
    int total;

    while (*qtd < CAPACIDADE &&
           fscanf(arquivo, " %49[^,],%d", nome, &total) == 2) {
        if (buscar(apelidos, *qtd, nome) == -1) {
            strcpy(apelidos[*qtd], nome);
            partidas[*qtd] = total;
            (*qtd)++;
        }
    }
    fclose(arquivo);
}

void salvar(char apelidos[][TAM_APELIDO],
            int partidas[], int qtd) {
    FILE *arquivo = fopen(ARQUIVO, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar os jogadores.\n");
        return;
    }

    for (int i = 0; i < qtd; i++)
        fprintf(arquivo, "%s,%d\n", apelidos[i], partidas[i]);

    fclose(arquivo);
}

void cadastrar(char apelidos[][TAM_APELIDO],
               int partidas[], int *qtd) {
    char nome[TAM_APELIDO];

    if (*qtd >= CAPACIDADE) {
        printf("Limite de jogadores atingido.\n");
        return;
    }

    printf("Digite o apelido: ");
    if (scanf("%49s", nome) != 1) {
        limpar_entrada();
        printf("Entrada invalida.\n");
        return;
    }

    if (buscar(apelidos, *qtd, nome) != -1) {
        printf("Esse jogador ja esta cadastrado.\n");
        return;
    }

    strcpy(apelidos[*qtd], nome);
    partidas[*qtd] = 0;
    (*qtd)++;

    printf("Jogador cadastrado com sucesso!\n");
}

void listar(char apelidos[][TAM_APELIDO],
            int partidas[], int qtd) {
    titulo("JOGADORES CADASTRADOS");

    if (qtd == 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++)
        printf("%d. %s - Partidas vencidas: %d\n",
               i + 1, apelidos[i], partidas[i]);
}

void excluir(char apelidos[][TAM_APELIDO],
             int partidas[], int *qtd) {
    int numero;
    char confirmar;

    listar(apelidos, partidas, *qtd);
    if (*qtd == 0) return;

    printf("Numero do jogador que deseja excluir: ");
    if (scanf("%d", &numero) != 1) {
        limpar_entrada();
        printf("Numero invalido.\n");
        return;
    }

    if (numero < 1 || numero > *qtd) {
        printf("Jogador nao encontrado.\n");
        return;
    }

    printf("Excluir %s? (s/n): ", apelidos[numero - 1]);
    if (scanf(" %c", &confirmar) != 1) return;

    if (confirmar != 's' && confirmar != 'S') {
        printf("Exclusao cancelada.\n");
        return;
    }

    for (int i = numero - 1; i < *qtd - 1; i++) {
        strcpy(apelidos[i], apelidos[i + 1]);
        partidas[i] = partidas[i + 1];
    }

    (*qtd)--;
    salvar(apelidos, partidas, *qtd);
    printf("Jogador excluido com sucesso!\n");
}

int escolher_jogador(char apelidos[][TAM_APELIDO], int qtd) {
    char nome[TAM_APELIDO];

    printf("Digite seu apelido: ");
    if (scanf("%49s", nome) != 1) {
        limpar_entrada();
        return -1;
    }

    int pos = buscar(apelidos, qtd, nome);
    if (pos == -1) printf("Jogador nao cadastrado!\n");
    return pos;
}

void adivinhe(char apelidos[][TAM_APELIDO],
              int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    if (pos == -1) return;

    int segredo = rand() % 100 + 1;
    int palpite;

    titulo("ADIVINHE O NUMERO");
    printf("Adivinhe um numero de 1 a 100!\n");

    do {
        printf("Seu palpite: ");
        if (scanf("%d", &palpite) != 1) {
            limpar_entrada();
            printf("Entrada invalida.\n");
            return;
        }

        if (palpite < segredo) printf("Maior!\n");
        else if (palpite > segredo) printf("Menor!\n");
        else {
            printf("Parabens, %s! Voce venceu!\n", apelidos[pos]);
            partidas[pos]++;
        }
    } while (palpite != segredo);
}

void cara_ou_coroa(char apelidos[][TAM_APELIDO],
                   int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    if (pos == -1) return;

    int escolha;
    int resultado = rand() % 2;

    titulo("CARA OU COROA");
    printf("1 - Cara\n2 - Coroa\n");
    printf("Sua escolha: ");

    if (scanf("%d", &escolha) != 1) {
        limpar_entrada();
        printf("Entrada invalida.\n");
        return;
    }

    if (escolha != 1 && escolha != 2) {
        printf("Escolha 1 ou 2.\n");
        return;
    }

    printf("A moeda caiu em: %s!\n",
           resultado == 0 ? "Cara" : "Coroa");

    if (escolha == resultado + 1) {
        printf("Voce venceu, %s!\n", apelidos[pos]);
        partidas[pos]++;
    } else {
        printf("O computador venceu esta rodada!\n");
    }
}

void embaralhar(Carta baralho[]) {
    int n = 0;

    for (int cor = 0; cor < 4; cor++) {
        baralho[n++] = (Carta){cor, 0};

        for (int numero = 1; numero <= 9; numero++) {
            baralho[n++] = (Carta){cor, numero};
            baralho[n++] = (Carta){cor, numero};
        }
    }

    for (int i = TOTAL_CARTAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void mostrar_carta(Carta c) {
    printf("%s %d", cores[c.cor], c.numero);
}

int pode_jogar(Carta c, Carta topo) {
    return c.cor == topo.cor || c.numero == topo.numero;
}

void remover_carta(Carta mao[], int *qtd, int indice) {
    for (int i = indice; i < *qtd - 1; i++)
        mao[i] = mao[i + 1];
    (*qtd)--;
}

void uno(char apelidos[][TAM_APELIDO],
         int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    if (pos == -1) return;

    Carta baralho[TOTAL_CARTAS];
    Carta mao[MAO_MAX], computador[MAO_MAX];
    int qtd_mao = 7, qtd_pc = 7, proxima = 0;

    embaralhar(baralho);

    for (int i = 0; i < 7; i++) {
        mao[i] = baralho[proxima++];
        computador[i] = baralho[proxima++];
    }

    Carta topo = baralho[proxima++];

    titulo("UNO - VERSAO SIMPLIFICADA");
    printf("Combine a cor ou o numero da carta do topo.\n");

    while (qtd_mao > 0 && qtd_pc > 0) {
        int jogou = 0;

        printf("\nCarta no topo: ");
        mostrar_carta(topo);
        printf("\n\nSuas cartas:\n");

        for (int i = 0; i < qtd_mao; i++) {
            printf("%d - ", i + 1);
            mostrar_carta(mao[i]);
            if (pode_jogar(mao[i], topo)) printf(" [pode jogar]");
            printf("\n");
        }

        int escolha;
        printf("Digite o numero da carta ou 0 para comprar: ");

        if (scanf("%d", &escolha) != 1) {
            limpar_entrada();
            printf("Entrada invalida. Rodada encerrada.\n");
            return;
        }

        if (escolha == 0) {
            if (proxima >= TOTAL_CARTAS) {
                printf("As cartas acabaram. Rodada empatada!\n");
                return;
            }

            mao[qtd_mao++] = baralho[proxima++];
            printf("Voce comprou: ");
            mostrar_carta(mao[qtd_mao - 1]);
            printf("\n");
        } else if (escolha >= 1 && escolha <= qtd_mao &&
                   pode_jogar(mao[escolha - 1], topo)) {
            topo = mao[escolha - 1];
            printf("Voce jogou: ");
            mostrar_carta(topo);
            printf("\n");
            remover_carta(mao, &qtd_mao, escolha - 1);
            jogou = 1;
        } else {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }

        if (qtd_mao == 0) break;

        int indice = -1;
        for (int i = 0; i < qtd_pc; i++) {
            if (pode_jogar(computador[i], topo)) {
                indice = i;
                break;
            }
        }

        if (indice != -1) {
            topo = computador[indice];
            printf("Computador jogou: ");
            mostrar_carta(topo);
            printf("\n");
            remover_carta(computador, &qtd_pc, indice);
        } else if (proxima < TOTAL_CARTAS) {
            computador[qtd_pc++] = baralho[proxima++];
            printf("Computador comprou uma carta.\n");
        } else if (!jogou) {
            printf("Nao ha mais cartas para comprar.\n");
            return;
        }

        if (qtd_pc == 0) break;
    }

    if (qtd_mao == 0) {
        printf("Parabens, %s! Voce venceu o UNO!\n", apelidos[pos]);
        partidas[pos]++;
    } else {
        printf("O computador venceu o UNO!\n");
    }
}

void mostrar_menu(void) {
    titulo("FLIPERAMA EM C");
    printf("[1] Adivinhe o Numero\n");
    printf("[2] Cadastrar jogador\n");
    printf("[3] Listar jogadores\n");
    printf("[4] Excluir jogador\n");
    printf("[5] Cara ou Coroa\n");
    printf("[6] UNO\n");
    printf("[0] Salvar e sair\n");
    linha();
    printf("Sua escolha: ");
}

int main(void) {
    char apelidos[CAPACIDADE][TAM_APELIDO];
    int partidas[CAPACIDADE] = {0};
    int qtd = 0, opcao;

    srand((unsigned int)time(NULL));
    carregar(apelidos, partidas, &qtd);

    do {
        mostrar_menu();

        if (scanf("%d", &opcao) != 1) {
            limpar_entrada();
            printf("Digite uma opcao valida.\n\n");
            continue;
        }

        switch (opcao) {
            case 1:
                adivinhe(apelidos, partidas, qtd);
                break;
            case 2:
                cadastrar(apelidos, partidas, &qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 3:
                listar(apelidos, partidas, qtd);
                break;
            case 4:
                excluir(apelidos, partidas, &qtd);
                break;
            case 5:
                cara_ou_coroa(apelidos, partidas, qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 6:
                uno(apelidos, partidas, qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 0:
                salvar(apelidos, partidas, qtd);
                printf("Dados salvos. Ate a proxima!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        if (opcao != 0) salvar(apelidos, partidas, qtd);
        printf("\n");

    } while (opcao != 0);

    return 0;
}
