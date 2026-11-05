/*
 * Projeto: Fliperama em C
 * Autor: Rafael Glinski de Oliveira
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DONO "Rafael Glinski de Oliveira"
#define CAPACIDADE 50
#define TAM_APELIDO 20
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

/* Le uma linha inteira e aceita somente um numero dentro do intervalo. */
int ler_numero(int minimo, int maximo, int *valor) {
    char entrada[128];
    char *fim;
    long numero;

    if (fgets(entrada, sizeof entrada, stdin) == NULL) return 0;
    numero = strtol(entrada, &fim, 10);
    if (fim == entrada) return 0;
    while (*fim == ' ' || *fim == '\t' || *fim == '\r') fim++;
    if (*fim != '\n' && *fim != '\0') return 0;
    if (numero < minimo || numero > maximo) return 0;
    *valor = (int)numero;
    return 1;
}

int ler_texto(char destino[], int tamanho) {
    size_t comprimento;

    if (fgets(destino, tamanho, stdin) == NULL) return 0;

    comprimento = strlen(destino);
    if (comprimento > 0 && destino[comprimento - 1] == '\n') {
        destino[comprimento - 1] = '\0';
    } else {
        int c = getchar();

        if (c != '\n' && c != EOF) {
            limpar_entrada();
            destino[0] = '\0';
            return 0;
        }
    }

    if (destino[0] == '\0' || strchr(destino, ',') != NULL) {
        return 0;
    }

    return 1;
}

void carregar(char apelidos[][TAM_APELIDO],
              int partidas[], int *qtd) {
    FILE *arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo anterior. Comecando com cadastro vazio.\n");
        return;
    }

    char linha_arquivo[128];
    char nome[TAM_APELIDO];
    int total;

    while (*qtd < CAPACIDADE &&
           fgets(linha_arquivo, sizeof linha_arquivo, arquivo) != NULL) {
        char extra;
        int campos = sscanf(linha_arquivo, " %19[^,],%d %c",
                            nome, &total, &extra);

        if (campos != 2 || nome[0] == '\0' || total < 0 ||
            strchr(nome, '\n') != NULL || strchr(nome, '\r') != NULL) {
            continue;
        }

        if (buscar(apelidos, *qtd, nome) == -1) {
            strcpy(apelidos[*qtd], nome);
            partidas[*qtd] = total;
            (*qtd)++;
        }
    }
    fclose(arquivo);
    printf("%d jogador(es) carregado(s).\n", *qtd);
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

    /* Fase 5: impede cadastrar quando o vetor ja esta cheio. */
    if (*qtd >= CAPACIDADE) {
        printf("Cadastro cheio: nao cabe mais ninguem.\n");
        return;
    }

    printf("Digite o apelido: ");
    if (!ler_texto(nome, TAM_APELIDO)) {
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
        printf("%d. %s - Partidas concluidas: %d\n",
               i + 1, apelidos[i], partidas[i]);
}

void excluir(char apelidos[][TAM_APELIDO],
             int partidas[], int *qtd) {
    int numero, confirmar;

    listar(apelidos, partidas, *qtd);
    if (*qtd == 0) return;

    printf("Numero do jogador que deseja excluir: ");
    if (!ler_numero(1, *qtd, &numero)) {
        printf("Numero invalido.\n");
        return;
    }

    if (numero < 1 || numero > *qtd) {
        printf("Jogador nao encontrado.\n");
        return;
    }

    printf("Confirmar exclusao? (1 = sim / 0 = nao): ");
    if (!ler_numero(0, 1, &confirmar) || confirmar != 1) {
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


void editar(char apelidos[][TAM_APELIDO], int partidas[], int qtd) {
    int numero;
    char novo[TAM_APELIDO];

    listar(apelidos, partidas, qtd);
    if (qtd == 0) return;

    printf("Numero do jogador que deseja editar: ");
    if (!ler_numero(1, qtd, &numero)) {
        printf("Numero invalido.\n");
        return;
    }

    printf("Novo apelido: ");
    if (!ler_texto(novo, TAM_APELIDO)) {
        printf("Entrada invalida.\n");
        return;
    }
    if (buscar(apelidos, qtd, novo) != -1 &&
        strcmp(apelidos[numero - 1], novo) != 0) {
        printf("Esse apelido ja pertence a outro jogador.\n");
        return;
    }

    strcpy(apelidos[numero - 1], novo);
    salvar(apelidos, partidas, qtd);
    printf("Apelido atualizado com sucesso!\n");
}

int escolher_jogador(char apelidos[][TAM_APELIDO], int qtd) {
    char nome[TAM_APELIDO];

    printf("Digite seu apelido: ");
    if (!ler_texto(nome, TAM_APELIDO)) {
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
    int tentativas = 0;

    titulo("ADIVINHE O NUMERO");
    printf("Adivinhe um numero de 1 a 100!\n");
    printf("Digite -1 a qualquer momento para voltar ao menu.\n");

    for (;;) {
        printf("Seu palpite (-1 para sair): ");
        if (!ler_numero(-1, 100, &palpite)) {
            if (feof(stdin)) {
                printf("\nEntrada encerrada. Voltando ao menu...\n");
                return;
            }
            printf("Digite um numero de 1 a 100 ou -1 para sair.\n");
            continue;
        }
        if (palpite == 0) {
            printf("Digite um numero de 1 a 100 ou -1 para sair.\n");
            continue;
        }
        if (palpite == -1) {
            printf("Voce saiu do Adivinhe o Numero. Voltando ao menu...\n");
            return;
        }
        tentativas++;
        if (palpite < segredo) {
            printf("Maior!\n");
        } else if (palpite > segredo) {
            printf("Menor!\n");
        } else {
            printf("Parabens, %s! Voce venceu em %d tentativa(s)!\n",
                   apelidos[pos], tentativas);
            partidas[pos]++;
            break;
        }
    }
}

void cara_ou_coroa(char apelidos[][TAM_APELIDO],
                   int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    if (pos == -1) return;

    int escolha;
    int resultado = rand() % 2;

    titulo("CARA OU COROA");
    printf("1 - Cara\n2 - Coroa\n0 - Voltar ao menu\n");
    printf("Sua escolha (0 para sair): ");

    if (!ler_numero(0, 2, &escolha)) {
        printf("Escolha invalida.\n");
        return;
    }

    if (escolha == 0) {
        printf("Voce cancelou Cara ou Coroa. Voltando ao menu...\n");
        return;
    }

    if (escolha != 1 && escolha != 2) {
        printf("Escolha 1, 2 ou 0 para sair.\n");
        return;
    }

    printf("A moeda caiu em: %s!\n",
           resultado == 0 ? "Cara" : "Coroa");

    if (escolha == resultado + 1) {
        printf("Voce venceu, %s!\n", apelidos[pos]);
    } else {
        printf("O computador venceu esta rodada!\n");
    }
    partidas[pos]++;
}

void pedra_papel_tesoura(char apelidos[][TAM_APELIDO],
                            int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    if (pos == -1) return;

    int escolha;
    int computador = rand() % 3 + 1;

    titulo("PEDRA, PAPEL E TESOURA");
    printf("1 - Pedra\n");
    printf("2 - Papel\n");
    printf("3 - Tesoura\n");
    printf("0 - Voltar ao menu\n");
    printf("Sua escolha: ");

    if (!ler_numero(0, 3, &escolha)) {
        printf("Escolha invalida.\n");
        return;
    }

    if (escolha == 0) {
        printf("Voce voltou ao menu principal.\n");
        return;
    }

    if (escolha < 1 || escolha > 3) {
        printf("Escolha invalida. Digite 1, 2, 3 ou 0.\n");
        return;
    }

    const char *opcoes[] = {"", "Pedra", "Papel", "Tesoura"};
    printf("Voce escolheu: %s\n", opcoes[escolha]);
    printf("Computador escolheu: %s\n", opcoes[computador]);

    if (escolha == computador) {
        printf("Empate!\n");
    } else if ((escolha == 1 && computador == 3) ||
               (escolha == 2 && computador == 1) ||
               (escolha == 3 && computador == 2)) {
        printf("Parabens, %s! Voce venceu!\n", apelidos[pos]);
    } else {
        printf("O computador venceu esta rodada!\n");
    }
    partidas[pos]++;
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
    int turnos = 0;
    const int LIMITE_TURNOS = 13;

    embaralhar(baralho);

    for (int i = 0; i < 7; i++) {
        mao[i] = baralho[proxima++];
        computador[i] = baralho[proxima++];
    }

    Carta topo = baralho[proxima++];

    titulo("UNO - VERSAO SIMPLIFICADA");
    printf("Combine a cor ou o numero da carta do topo.\n");
    printf("A partida tem limite de %d rodadas para ser mais rapida.\n",
           LIMITE_TURNOS);

    while (qtd_mao > 0 && qtd_pc > 0 && turnos < LIMITE_TURNOS) {
        int escolha;

        printf("\n--- Rodada %d de %d ---\n", turnos + 1, LIMITE_TURNOS);
        printf("Carta no topo: ");
        mostrar_carta(topo);
        printf("\n\nSuas cartas:\n");

        for (int i = 0; i < qtd_mao; i++) {
            printf("%d - ", i + 1);
            mostrar_carta(mao[i]);
            if (pode_jogar(mao[i], topo)) printf(" [pode jogar]");
            printf("\n");
        }

        printf("Digite o numero da carta, 0 para comprar ou -1 para sair: ");

        if (!ler_numero(-1, MAO_MAX, &escolha)) {
            printf("Entrada invalida. Rodada encerrada.\n");
            return;
        }

        if (escolha == -1) {
            printf("\nVoce saiu do UNO. A partida foi encerrada.\n");
            return;
        }

        if (escolha == 0) {
            if (proxima >= TOTAL_CARTAS) {
                printf("O baralho acabou. A partida terminou empatada.\n");
                partidas[pos]++;
                return;
            }

            Carta comprada = baralho[proxima++];
            mao[qtd_mao++] = comprada;
            printf("Voce comprou: ");
            mostrar_carta(comprada);
            printf("\n");

            if (pode_jogar(comprada, topo)) {
                char resposta;
                printf("A carta comprada pode ser jogada. Deseja joga-la? (s/n; x para sair): ");
                char resposta_linha[16];
                if (fgets(resposta_linha, sizeof resposta_linha, stdin) == NULL) {
                    printf("\nEntrada encerrada. Voltando ao menu...\n");
                    return;
                }
                resposta = resposta_linha[0];
                if (resposta_linha[strlen(resposta_linha) - 1] != '\n' &&
                    !feof(stdin)) {
                    limpar_entrada();
                    printf("Resposta muito longa. Digite apenas s, n ou x.\n");
                    return;
                }
                if (resposta != 's' && resposta != 'S' &&
                    resposta != 'n' && resposta != 'N' &&
                    resposta != 'x' && resposta != 'X') {
                    printf("Resposta invalida. Digite s, n ou x.\n");
                    return;
                }

                if (resposta == 'x' || resposta == 'X') {
                    printf("\nVoce saiu do UNO. A partida foi encerrada.\n");
                    return;
                }

                if (resposta == 's' || resposta == 'S') {
                    topo = comprada;
                    printf("Voce jogou: ");
                    mostrar_carta(topo);
                    printf("\n");
                    remover_carta(mao, &qtd_mao, qtd_mao - 1);
                }
            }
        } else if (escolha >= 1 && escolha <= qtd_mao &&
                   pode_jogar(mao[escolha - 1], topo)) {
            topo = mao[escolha - 1];
            printf("Voce jogou: ");
            mostrar_carta(topo);
            printf("\n");
            remover_carta(mao, &qtd_mao, escolha - 1);
        } else {
            printf("Jogada invalida! Escolha uma carta permitida ou 0 para comprar.\n");
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
        } else {
            printf("O computador nao tem jogada e o baralho acabou.\n");
        }

        if (qtd_pc == 0) break;
        turnos++;
    }

    if (qtd_mao == 0) {
        printf("Parabens, %s! Voce venceu o UNO!\n", apelidos[pos]);
    } else if (qtd_pc == 0) {
        printf("O computador venceu o UNO!\n");
    } else if (turnos >= LIMITE_TURNOS) {
        printf("A partida atingiu o limite de rodadas e terminou empatada.\n");
    } else {
        printf("A partida terminou sem vencedor.\n");
    }
    partidas[pos]++;
}


int eh_par(int numero) {
    return numero % 2 == 0 ? 1 : 0;
}

void par_ou_impar(char apelidos[][TAM_APELIDO],
                  int partidas[], int qtd) {
    int pos = escolher_jogador(apelidos, qtd);
    int escolha, numero, numero_pc, soma;

    if (pos == -1) return;

    titulo("PAR OU IMPAR");
    printf("1 - Par\n2 - Impar\n0 - Voltar ao menu\n");
    printf("Escolha (0 para sair): ");
    if (!ler_numero(0, 2, &escolha)) {
        printf("Escolha invalida.\n");
        return;
    }
    if (escolha == 0) {
        printf("Voce saiu de Par ou Impar. Voltando ao menu...\n");
        return;
    }

    printf("Escolha um numero de 0 a 10: ");
    if (!ler_numero(0, 10, &numero)) {
        printf("Numero invalido.\n");
        return;
    }

    numero_pc = rand() % 11;
    soma = numero + numero_pc;

    printf("Voce escolheu %d e o computador escolheu %d.\n",
           numero, numero_pc);
    printf("Soma: %d - %s\n", soma,
           eh_par(soma) ? "Par" : "Impar");

    if ((eh_par(soma) && escolha == 1) ||
        (!eh_par(soma) && escolha == 2)) {
        printf("Parabens, %s! Voce venceu!\n", apelidos[pos]);
    } else {
        printf("O computador venceu!\n");
    }

    partidas[pos]++;
}

void mostrar_menu(void) {
    titulo("FLIPERAMA EM C");
    printf("Desenvolvido por: %s\n", DONO);
    printf("[1] Adivinhe o Numero\n");
    printf("[2] Cadastrar jogador\n");
    printf("[3] Listar jogadores\n");
    printf("[4] Remover jogador\n");
    printf("[5] Cara ou Coroa\n");
    printf("[6] UNO\n");
    printf("[7] Pedra, Papel e Tesoura\n");
    printf("[8] Editar apelido\n");
    printf("[9] Par ou Impar\n");
    printf("[0] Salvar e sair\n");
    linha();
    printf("Sua escolha: ");
}

int main(void) {
    char apelidos[CAPACIDADE][TAM_APELIDO];
    int partidas[CAPACIDADE] = {0};
    int qtd = 0, opcao = -1;

    srand((unsigned int)time(NULL));
    carregar(apelidos, partidas, &qtd);

    do {
        mostrar_menu();

        if (!ler_numero(0, 9, &opcao)) {
            if (feof(stdin)) {
                opcao = 0;
                continue;
            }
            printf("Digite uma opcao valida de 0 a 9.\n\n");
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
            case 8:
                editar(apelidos, partidas, qtd);
                break;
            case 9:
                par_ou_impar(apelidos, partidas, qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 5:
                cara_ou_coroa(apelidos, partidas, qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 6:
                uno(apelidos, partidas, qtd);
                salvar(apelidos, partidas, qtd);
                break;
            case 7:
                pedra_papel_tesoura(apelidos, partidas, qtd);
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
