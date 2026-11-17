/*
 * Projeto: Fliperama em C++
 * Autor: Rafael Glinski de Oliveira
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CAPACIDADE = 50;
const string ARQUIVO = "jogadores.csv";

struct Jogador {
    string apelido;
    int partidas;
};

void linha() {
    cout << "========================================\n";
}

void titulo(string texto) {
    linha();
    cout << texto << "\n";
    linha();
}

int buscar(Jogador jogadores[], int qtd, string nome) {
    for (int i = 0; i < qtd; i++) {
        if (jogadores[i].apelido == nome) {
            return i;
        }
    }
    return -1;
}

int lerNumero(int minimo, int maximo) {
    string entrada;
    int numero;
    char extra;
    stringstream fluxo;

    if (!getline(cin, entrada)) {
        return -2;
    }

    fluxo.str(entrada);

    if (!(fluxo >> numero) || (fluxo >> extra)) {
        return -2;
    }

    if (numero < minimo || numero > maximo) {
        return -2;
    }

    return numero;
}

void carregar(Jogador jogadores[], int &qtd) {
    ifstream arquivo(ARQUIVO.c_str());

    if (!arquivo.is_open()) {
        cout << "Nenhum arquivo anterior. Comecando com cadastro vazio.\n";
        return;
    }

    string nome;
    int total;
    qtd = 0;

    while (getline(arquivo, nome, ',') && arquivo >> total) {
        arquivo.ignore(1000, '\n');

        if (nome.empty() || total < 0 || qtd >= CAPACIDADE) {
            continue;
        }

        if (buscar(jogadores, qtd, nome) == -1) {
            jogadores[qtd].apelido = nome;
            jogadores[qtd].partidas = total;
            qtd++;
        }
    }

    arquivo.close();
    cout << qtd << " jogador(es) carregado(s).\n";
}

void salvar(Jogador jogadores[], int qtd) {
    ofstream arquivo(ARQUIVO.c_str());

    if (!arquivo.is_open()) {
        cout << "Erro ao salvar os jogadores.\n";
        return;
    }

    for (int i = 0; i < qtd; i++) {
        arquivo << jogadores[i].apelido << ","
                << jogadores[i].partidas << "\n";
    }

    arquivo.close();
}

void cadastrar(Jogador jogadores[], int &qtd) {
    string nome;

    if (qtd >= CAPACIDADE) {
        cout << "Cadastro cheio: nao cabe mais ninguem.\n";
        return;
    }

    cout << "Digite o apelido: ";
    getline(cin, nome);

    if (nome.empty() || nome.find(',') != string::npos ||
        nome.length() >= 20) {
        cout << "Entrada invalida.\n";
        return;
    }

    if (buscar(jogadores, qtd, nome) != -1) {
        cout << "Esse jogador ja esta cadastrado.\n";
        return;
    }

    jogadores[qtd].apelido = nome;
    jogadores[qtd].partidas = 0;
    qtd++;

    cout << "Jogador cadastrado com sucesso!\n";
}

void listar(Jogador jogadores[], int qtd) {
    titulo("JOGADORES CADASTRADOS");

    if (qtd == 0) {
        cout << "Nenhum jogador cadastrado.\n";
        return;
    }

    for (int i = 0; i < qtd; i++) {
        cout << i + 1 << ". " << jogadores[i].apelido
             << " - Partidas concluidas: " << jogadores[i].partidas << "\n";
    }
}

void excluir(Jogador jogadores[], int &qtd) {
    int numero;
    int confirmar;

    listar(jogadores, qtd);
    if (qtd == 0) return;

    cout << "Numero do jogador que deseja excluir: ";
    numero = lerNumero(1, qtd);

    if (numero == -2) {
        cout << "Numero invalido.\n";
        return;
    }

    cout << "Confirmar exclusao? (1 = sim / 0 = nao): ";
    confirmar = lerNumero(0, 1);

    if (confirmar != 1) {
        cout << "Exclusao cancelada.\n";
        return;
    }

    for (int i = numero - 1; i < qtd - 1; i++) {
        jogadores[i] = jogadores[i + 1];
    }

    qtd--;
    salvar(jogadores, qtd);
    cout << "Jogador excluido com sucesso!\n";
}

void editar(Jogador jogadores[], int qtd) {
    int numero;
    string novo;

    listar(jogadores, qtd);
    if (qtd == 0) return;

    cout << "Numero do jogador que deseja editar: ";
    numero = lerNumero(1, qtd);

    if (numero == -2) {
        cout << "Numero invalido.\n";
        return;
    }

    cout << "Novo apelido: ";
    getline(cin, novo);

    if (novo.empty() || novo.find(',') != string::npos ||
        novo.length() >= 20) {
        cout << "Entrada invalida.\n";
        return;
    }

    int pos = buscar(jogadores, qtd, novo);
    if (pos != -1 && pos != numero - 1) {
        cout << "Esse apelido ja pertence a outro jogador.\n";
        return;
    }

    jogadores[numero - 1].apelido = novo;
    salvar(jogadores, qtd);
    cout << "Apelido atualizado com sucesso!\n";
}

int escolherJogador(Jogador jogadores[], int qtd) {
    string nome;

    cout << "Digite seu apelido: ";
    getline(cin, nome);

    int pos = buscar(jogadores, qtd, nome);

    if (pos == -1) {
        cout << "Jogador nao cadastrado!\n";
    }

    return pos;
}

void adivinhe(Jogador jogadores[], int qtd) {
    int pos = escolherJogador(jogadores, qtd);
    if (pos == -1) return;

    int segredo = rand() % 100 + 1;
    int palpite;
    int tentativas = 0;

    titulo("ADIVINHE O NUMERO");
    cout << "Adivinhe um numero de 1 a 100!\n";
    cout << "Digite -1 a qualquer momento para voltar ao menu.\n";

    do {
        cout << "Seu palpite (-1 para sair): ";
        palpite = lerNumero(-1, 100);

        if (palpite == -1) {
            cout << "Voce saiu do Adivinhe o Numero. Voltando ao menu...\n";
            return;
        }

        if (palpite == -2) {
            cout << "Digite um numero valido de 1 a 100 ou -1 para sair.\n";
            continue;
        }

        if (palpite == 0) {
            cout << "Digite um numero de 1 a 100.\n";
        } else {
            tentativas++;

            if (palpite < segredo) {
                cout << "Maior!\n";
            } else if (palpite > segredo) {
                cout << "Menor!\n";
            } else {
                cout << "Parabens, " << jogadores[pos].apelido
                     << "! Voce venceu em " << tentativas
                     << " tentativa(s)!\n";
                jogadores[pos].partidas++;
            }
        }
    } while (palpite != segredo);
}

void caraOuCoroa(Jogador jogadores[], int qtd) {
    int pos = escolherJogador(jogadores, qtd);
    if (pos == -1) return;

    int escolha;
    int resultado = rand() % 2;

    titulo("CARA OU COROA");
    cout << "1 - Cara\n2 - Coroa\n0 - Voltar ao menu\n";
    cout << "Sua escolha: ";
    escolha = lerNumero(0, 2);

    if (escolha == -2) {
        cout << "Escolha invalida.\n";
        return;
    }
    if (escolha == 0) return;

    cout << "A moeda caiu em: " << (resultado == 0 ? "Cara" : "Coroa") << "!\n";

    if (escolha == resultado + 1) {
        cout << "Voce venceu, " << jogadores[pos].apelido << "!\n";
    } else {
        cout << "O computador venceu esta rodada!\n";
    }

    jogadores[pos].partidas++;
}

void pedraPapelTesoura(Jogador jogadores[], int qtd) {
    int pos = escolherJogador(jogadores, qtd);
    if (pos == -1) return;

    int escolha;
    int computador = rand() % 3 + 1;
    string opcoes[4] = {"", "Pedra", "Papel", "Tesoura"};

    titulo("PEDRA, PAPEL E TESOURA");
    cout << "1 - Pedra\n2 - Papel\n3 - Tesoura\n0 - Voltar ao menu\n";
    cout << "Sua escolha: ";
    escolha = lerNumero(0, 3);

    if (escolha == -1) {
        cout << "Escolha invalida.\n";
        return;
    }
    if (escolha == 0) return;

    cout << "Voce escolheu: " << opcoes[escolha] << "\n";
    cout << "Computador escolheu: " << opcoes[computador] << "\n";

    if (escolha == computador) {
        cout << "Empate!\n";
    } else if ((escolha == 1 && computador == 3) ||
               (escolha == 2 && computador == 1) ||
               (escolha == 3 && computador == 2)) {
        cout << "Parabens, " << jogadores[pos].apelido << "! Voce venceu!\n";
    } else {
        cout << "O computador venceu esta rodada!\n";
    }

    jogadores[pos].partidas++;
}

void parOuImpar(Jogador jogadores[], int qtd) {
    int pos = escolherJogador(jogadores, qtd);
    if (pos == -1) return;

    int escolha;
    int numero;
    int numeroPc = rand() % 11;
    int soma;

    titulo("PAR OU IMPAR");
    cout << "1 - Par\n2 - Impar\n0 - Voltar ao menu\n";
    cout << "Escolha: ";
    escolha = lerNumero(0, 2);

    if (escolha == -1) {
        cout << "Escolha invalida.\n";
        return;
    }
    if (escolha == 0) return;

    cout << "Escolha um numero de 0 a 10: ";
    numero = lerNumero(0, 10);

    if (numero == -2) {
        cout << "Numero invalido.\n";
        return;
    }

    soma = numero + numeroPc;

    cout << "Voce escolheu " << numero << " e o computador escolheu "
         << numeroPc << ".\n";
    cout << "Soma: " << soma << " - " << (soma % 2 == 0 ? "Par" : "Impar") << "\n";

    if ((soma % 2 == 0 && escolha == 1) ||
        (soma % 2 != 0 && escolha == 2)) {
        cout << "Parabens, " << jogadores[pos].apelido << "! Voce venceu!\n";
    } else {
        cout << "O computador venceu!\n";
    }

    jogadores[pos].partidas++;
}

struct Carta {
    int cor;
    int numero;
};

string cores[4] = {"Vermelho", "Azul", "Verde", "Amarelo"};

void mostrarCarta(Carta carta) {
    cout << cores[carta.cor] << " " << carta.numero;
}

bool podeJogar(Carta carta, Carta topo) {
    return carta.cor == topo.cor || carta.numero == topo.numero;
}

void removerCarta(Carta mao[], int &qtd, int indice) {
    for (int i = indice; i < qtd - 1; i++) {
        mao[i] = mao[i + 1];
    }
    qtd--;
}

void uno(Jogador jogadores[], int qtd) {
    int pos = escolherJogador(jogadores, qtd);
    if (pos == -1) return;

    const int TOTAL_CARTAS = 76;
    const int LIMITE_RODADAS = 13;
    Carta baralho[TOTAL_CARTAS];
    Carta mao[80];
    Carta computador[80];
    int proxima = 0;
    int qtdMao = 7;
    int qtdPc = 7;
    int rodadas = 0;

    for (int cor = 0; cor < 4; cor++) {
        baralho[proxima].cor = cor;
        baralho[proxima].numero = 0;
        proxima++;

        for (int numero = 1; numero <= 9; numero++) {
            for (int repeticao = 0; repeticao < 2; repeticao++) {
                baralho[proxima].cor = cor;
                baralho[proxima].numero = numero;
                proxima++;
            }
        }
    }

    for (int i = TOTAL_CARTAS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    proxima = 0;
    for (int i = 0; i < 7; i++) {
        mao[i] = baralho[proxima++];
        computador[i] = baralho[proxima++];
    }

    Carta topo = baralho[proxima++];

    titulo("UNO - VERSAO SIMPLIFICADA");
    cout << "Combine a cor ou o numero da carta do topo.\n";
    cout << "A partida tem limite de " << LIMITE_RODADAS << " rodadas.\n";

    while (qtdMao > 0 && qtdPc > 0 && rodadas < LIMITE_RODADAS) {
        int escolha;

        cout << "\n--- Rodada " << rodadas + 1 << " de " << LIMITE_RODADAS << " ---\n";
        cout << "Carta no topo: ";
        mostrarCarta(topo);
        cout << "\n\nSuas cartas:\n";

        for (int i = 0; i < qtdMao; i++) {
            cout << i + 1 << " - ";
            mostrarCarta(mao[i]);
            if (podeJogar(mao[i], topo)) cout << " [pode jogar]";
            cout << "\n";
        }

        cout << "Digite o numero da carta, 0 para comprar ou -1 para sair: ";
        escolha = lerNumero(-1, qtdMao);

        if (escolha == -1) {
            cout << "Voce saiu do UNO. A partida foi encerrada.\n";
            return;
        }

        if (escolha == -2) {
            cout << "Entrada invalida. Escolha uma carta, 0 para comprar ou -1 para sair.\n";
            continue;
        }

        if (escolha == 0) {
            if (proxima >= TOTAL_CARTAS) {
                cout << "O baralho acabou. A partida terminou empatada.\n";
                jogadores[pos].partidas++;
                return;
            }

            Carta comprada = baralho[proxima++];
            mao[qtdMao++] = comprada;
            cout << "Voce comprou: ";
            mostrarCarta(comprada);
            cout << "\n";

            if (podeJogar(comprada, topo)) {
                char resposta;
                cout << "Deseja jogar a carta comprada? (s/n): ";
                cin >> resposta;
                cin.ignore(1000, '\n');

                if (resposta == 's' || resposta == 'S') {
                    topo = comprada;
                    removerCarta(mao, qtdMao, qtdMao - 1);
                }
            }
        } else if (escolha >= 1 && escolha <= qtdMao &&
                   podeJogar(mao[escolha - 1], topo)) {
            topo = mao[escolha - 1];
            removerCarta(mao, qtdMao, escolha - 1);
        } else {
            cout << "Jogada invalida! Escolha uma carta permitida ou 0 para comprar.\n";
            continue;
        }

        if (qtdMao == 0) break;

        int indice = -1;
        for (int i = 0; i < qtdPc; i++) {
            if (podeJogar(computador[i], topo)) {
                indice = i;
                break;
            }
        }

        if (indice != -1) {
            topo = computador[indice];
            cout << "Computador jogou: ";
            mostrarCarta(topo);
            cout << "\n";
            removerCarta(computador, qtdPc, indice);
        } else if (proxima < TOTAL_CARTAS) {
            computador[qtdPc++] = baralho[proxima++];
            cout << "Computador comprou uma carta.\n";
        }

        rodadas++;
    }

    if (qtdMao == 0) {
        cout << "Parabens, " << jogadores[pos].apelido << "! Voce venceu o UNO!\n";
    } else if (qtdPc == 0) {
        cout << "O computador venceu o UNO!\n";
    } else {
        cout << "A partida terminou empatada.\n";
    }

    jogadores[pos].partidas++;
}

void mostrarMenu() {
    titulo("FLIPERAMA EM C++");
    cout << "Desenvolvido por: Rafael Glinski de Oliveira\n";
    cout << "[1] Adivinhe o Numero\n";
    cout << "[2] Cadastrar jogador\n";
    cout << "[3] Listar jogadores\n";
    cout << "[4] Remover jogador\n";
    cout << "[5] Cara ou Coroa\n";
    cout << "[6] UNO\n";
    cout << "[7] Pedra, Papel e Tesoura\n";
    cout << "[8] Editar apelido\n";
    cout << "[9] Par ou Impar\n";
    cout << "[0] Salvar e sair\n";
    linha();
    cout << "Sua escolha: ";
}

int main() {
    Jogador jogadores[CAPACIDADE];
    int qtd = 0;
    int opcao = -1;

    srand((unsigned int) time(0));
    carregar(jogadores, qtd);

    do {
        mostrarMenu();
        opcao = lerNumero(0, 9);

        if (opcao == -2) {
            cout << "Digite uma opcao valida de 0 a 9.\n\n";
            continue;
        }

        switch (opcao) {
            case 1:
                adivinhe(jogadores, qtd);
                break;
            case 2:
                cadastrar(jogadores, qtd);
                break;
            case 3:
                listar(jogadores, qtd);
                break;
            case 4:
                excluir(jogadores, qtd);
                break;
            case 5:
                caraOuCoroa(jogadores, qtd);
                break;
            case 6:
                uno(jogadores, qtd);
                break;
            case 7:
                pedraPapelTesoura(jogadores, qtd);
                break;
            case 8:
                editar(jogadores, qtd);
                break;
            case 9:
                parOuImpar(jogadores, qtd);
                break;
            case 0:
                salvar(jogadores, qtd);
                cout << "Dados salvos. Ate a proxima!\n";
                break;
        }

        if (opcao != 0) {
            salvar(jogadores, qtd);
        }

        cout << "\n";
    } while (opcao != 0);

    return 0;
}
