/*
 * Disciplina: 2026-PCAP
 * Projeto: MeuApp v4.0 - Fliperama em C++
 * Autor: Rafael Glinski de Oliveira
 * LIAC: Menu validado, cadastro em vectors paralelos, jogos que contam
 * partidas e dados guardados em arquivo CSV.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#define DONO "Rafael Glinski de Oliveira"
#define ARQUIVO "jogadores.csv"

using namespace std;

struct Carta {
    int cor;
    int numero;
};

string cores[4] = {"Vermelho", "Azul", "Verde", "Amarelo"};

void linha() {
    cout << "========================================\n";
}

void titulo(string texto) {
    linha();
    cout << texto << "\n";
    linha();
}

int ler_numero(string mensagem, int minimo, int maximo) {
    int numero;

    while (true) {
        cout << mensagem;
        cin >> numero;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Digite um numero valido.\n";
            continue;
        }

        cin.ignore(1000, '\n');

        if (numero < minimo || numero > maximo) {
            cout << "Escolha um numero entre " << minimo
                 << " e " << maximo << ".\n";
            continue;
        }

        return numero;
    }
}

string ler_texto(string mensagem) {
    string texto;

    cout << mensagem;
    cin >> texto;
    cin.ignore(1000, '\n');

    return texto;
}

int buscar(const vector<string> &apelidos, string procurado) {
    for (int i = 0; i < (int)apelidos.size(); i++) {
        if (apelidos[i] == procurado) {
            return i;
        }
    }

    return -1;
}

void salvar(vector<string> &apelidos, vector<int> &partidas) {
    ofstream arquivo(ARQUIVO);

    if (!arquivo.is_open()) {
        cout << "Erro ao salvar os jogadores.\n";
        return;
    }

    for (int i = 0; i < (int)apelidos.size(); i++) {
        arquivo << apelidos[i] << "," << partidas[i] << "\n";
    }

    arquivo.close();
}

int carregar(vector<string> &apelidos, vector<int> &partidas) {
    ifstream arquivo(ARQUIVO);
    string nome;
    int total;
    int carregados = 0;

    if (!arquivo.is_open()) {
        cout << "Nenhum arquivo anterior. Comecando com cadastro vazio.\n";
        return 0;
    }

    while (getline(arquivo, nome, ',')) {
        if (!(arquivo >> total)) {
            break;
        }

        arquivo.ignore(1000, '\n');

        if (nome.empty() || total < 0 || buscar(apelidos, nome) != -1) {
            continue;
        }

        apelidos.push_back(nome);
        partidas.push_back(total);
        carregados++;
    }

    arquivo.close();
    cout << carregados << " jogador(es) carregado(s).\n";
    return carregados;
}

void cadastrar(vector<string> &apelidos, vector<int> &partidas) {
    string novo = ler_texto("Digite o apelido: ");

    if (novo.empty() || novo.find(',') != string::npos) {
        cout << "Apelido invalido.\n";
        return;
    }

    if (buscar(apelidos, novo) != -1) {
        cout << "Esse apelido ja esta cadastrado.\n";
        return;
    }

    apelidos.push_back(novo);
    partidas.push_back(0);

    cout << "Jogador cadastrado com sucesso!\n";
    salvar(apelidos, partidas);
}

void listar(vector<string> &apelidos, vector<int> &partidas) {
    titulo("JOGADORES CADASTRADOS");

    if (apelidos.empty()) {
        cout << "Nenhum jogador cadastrado ainda.\n";
        return;
    }

    for (int i = 0; i < (int)apelidos.size(); i++) {
        cout << i + 1 << ". " << apelidos[i]
             << " - " << partidas[i] << " partida(s)\n";
    }
}

void excluir(vector<string> &apelidos, vector<int> &partidas) {
    if (apelidos.empty()) {
        cout << "Nenhum jogador para excluir.\n";
        return;
    }

    listar(apelidos, partidas);
    string nome = ler_texto("Digite o apelido que deseja excluir: ");
    int pos = buscar(apelidos, nome);

    if (pos == -1) {
        cout << "Jogador nao encontrado.\n";
        return;
    }

    int confirmar = ler_numero("Confirmar exclusao? (1 sim / 0 nao): ", 0, 1);

    if (confirmar == 0) {
        cout << "Exclusao cancelada.\n";
        return;
    }

    apelidos.erase(apelidos.begin() + pos);
    partidas.erase(partidas.begin() + pos);

    cout << "Jogador excluido com sucesso!\n";
    salvar(apelidos, partidas);
}
void alterar(vector<string> &apelidos, vector<int> &partidas) {
    if (apelidos.empty()) {
        cout << "Nenhum jogador para alterar.\n";
        return;
    }

    listar(apelidos, partidas);
    int numero = ler_numero("Numero do jogador que deseja alterar: ",
                            1, (int)apelidos.size());
    int pos = numero - 1;
    string novo = ler_texto("Novo apelido: ");

    int encontrado = buscar(apelidos, novo);

    if (novo.empty() || novo.find(',') != string::npos ||
        (encontrado != -1 && encontrado != pos)) {
        cout << "Apelido invalido ou ja cadastrado.\n";
        return;
    }

    apelidos[pos] = novo;
    cout << "Apelido alterado com sucesso!\n";
    salvar(apelidos, partidas);
}

int escolher_jogador(vector<string> &apelidos) {
    string nome = ler_texto("Digite seu apelido: ");
    int pos = buscar(apelidos, nome);

    if (pos == -1) {
        cout << "Cadastre esse apelido antes de jogar.\n";
    }

    return pos;
}

void adivinhe(vector<string> &apelidos, vector<int> &partidas) {
    int pos = escolher_jogador(apelidos);
    if (pos == -1) return;

    int segredo = rand() % 100 + 1;
    int tentativas = 0;
    int palpite;

    titulo("ADIVINHE O NUMERO");
    cout << "Tente descobrir o numero de 1 a 100.\n";

    do {
        palpite = ler_numero("Seu palpite: ", 1, 100);
        tentativas++;

        if (palpite < segredo) {
            cout << "Maior!\n";
        } else if (palpite > segredo) {
            cout << "Menor!\n";
        }
    } while (palpite != segredo);

    cout << "Acertou em " << tentativas << " tentativa(s), "
         << apelidos[pos] << "!\n";
    partidas[pos]++;
    salvar(apelidos, partidas);
}

void cara_ou_coroa(vector<string> &apelidos, vector<int> &partidas) {
    int pos = escolher_jogador(apelidos);
    if (pos == -1) return;

    titulo("CARA OU COROA");
    cout << "1 - Cara\n2 - Coroa\n";
    int escolha = ler_numero("Sua escolha: ", 1, 2);
    int resultado = rand() % 2 + 1;

    cout << "A moeda caiu em " << (resultado == 1 ? "Cara" : "Coroa")
         << ".\n";

    if (escolha == resultado) {
        cout << "Voce venceu, " << apelidos[pos] << "!\n";
    } else {
        cout << "O computador venceu esta rodada.\n";
    }

    partidas[pos]++;
    salvar(apelidos, partidas);
}

void pedra_papel_tesoura(vector<string> &apelidos, vector<int> &partidas) {
    int pos = escolher_jogador(apelidos);
    if (pos == -1) return;

    titulo("PEDRA, PAPEL E TESOURA");
    cout << "1 - Pedra\n2 - Papel\n3 - Tesoura\n";
    int escolha = ler_numero("Sua escolha: ", 1, 3);
    int computador = rand() % 3 + 1;
    string opcoes[4] = {"", "Pedra", "Papel", "Tesoura"};

    cout << "Voce: " << opcoes[escolha] << "\n";
    cout << "Computador: " << opcoes[computador] << "\n";

    if (escolha == computador) {
        cout << "Empate!\n";
    } else if ((escolha == 1 && computador == 3) ||
               (escolha == 2 && computador == 1) ||
               (escolha == 3 && computador == 2)) {
        cout << "Voce venceu, " << apelidos[pos] << "!\n";
    } else {
        cout << "O computador venceu.\n";
    }

    partidas[pos]++;
    salvar(apelidos, partidas);
}

bool eh_par(int numero) {
    return numero % 2 == 0;
}

void par_ou_impar(vector<string> &apelidos, vector<int> &partidas) {
    int pos = escolher_jogador(apelidos);
    if (pos == -1) return;

    titulo("PAR OU IMPAR");
    cout << "1 - Par\n2 - Impar\n";
    int escolha = ler_numero("Sua escolha: ", 1, 2);
    int numero = ler_numero("Escolha um numero de 0 a 10: ", 0, 10);
    int numero_pc = rand() % 11;
    int soma = numero + numero_pc;

    cout << "Voce escolheu " << numero << " e o computador escolheu "
         << numero_pc << ".\n";
    cout << "Soma: " << soma << " - "
         << (eh_par(soma) ? "Par" : "Impar") << "\n";

    if ((eh_par(soma) && escolha == 1) ||
        (!eh_par(soma) && escolha == 2)) {
        cout << "Voce venceu, " << apelidos[pos] << "!\n";
    } else {
        cout << "O computador venceu.\n";
    }

    partidas[pos]++;
    salvar(apelidos, partidas);
}

void mostrar_carta(Carta carta) {
    cout << cores[carta.cor] << " " << carta.numero;
}

bool pode_jogar(Carta carta, Carta topo) {
    return carta.cor == topo.cor || carta.numero == topo.numero;
}

void uno(vector<string> &apelidos, vector<int> &partidas) {
    int pos = escolher_jogador(apelidos);
    if (pos == -1) return;

    vector<Carta> baralho;
    vector<Carta> mao;
    vector<Carta> computador;

    for (int cor = 0; cor < 4; cor++) {
        for (int numero = 0; numero <= 9; numero++) {
            Carta carta;
            carta.cor = cor;
            carta.numero = numero;
            baralho.push_back(carta);
        }
    }

    for (int i = (int)baralho.size() - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    for (int i = 0; i < 5; i++) {
        mao.push_back(baralho.back());
        baralho.pop_back();
        computador.push_back(baralho.back());
        baralho.pop_back();
    }

    Carta topo = baralho.back();
    baralho.pop_back();

    titulo("UNO SIMPLIFICADO");
    cout << "Combine a cor ou o numero da carta do topo.\n";
    int rodadas = 0;

    while (!mao.empty() && !computador.empty() && rodadas < 20) {
        cout << "\nCarta no topo: ";
        mostrar_carta(topo);
        cout << "\nSuas cartas:\n";

        for (int i = 0; i < (int)mao.size(); i++) {
            cout << i + 1 << " - ";
            mostrar_carta(mao[i]);
            if (pode_jogar(mao[i], topo)) cout << " [pode jogar]";
            cout << "\n";
        }

        int escolha = ler_numero("Carta (0 compra, -1 sai): ",
                                 -1, (int)mao.size());

        if (escolha == -1) {
            cout << "Voce saiu do UNO.\n";
            return;
        }

        if (escolha == 0) {
            if (baralho.empty()) {
                cout << "O baralho acabou.\n";
                break;
            }
            mao.push_back(baralho.back());
            baralho.pop_back();
            cout << "Voce comprou uma carta.\n";
            if (pode_jogar(mao.back(), topo)) {
                cout << "A carta comprada pode ser jogada.\n";
                int jogar = ler_numero("1 jogar / 0 guardar: ", 0, 1);
                if (jogar == 1) {
                    topo = mao.back();
                    mao.pop_back();
                }
            }
        } else if (pode_jogar(mao[escolha - 1], topo)) {
            topo = mao[escolha - 1];
            mao.erase(mao.begin() + escolha - 1);
        } else {
            cout << "Essa carta nao pode ser jogada.\n";
            continue;
        }

        if (mao.empty()) break;

        int pos_pc = -1;
        for (int i = 0; i < (int)computador.size(); i++) {
            if (pode_jogar(computador[i], topo)) {
                pos_pc = i;
                break;
            }
        }

        if (pos_pc != -1) {
            topo = computador[pos_pc];
            computador.erase(computador.begin() + pos_pc);
            cout << "O computador jogou uma carta.\n";
        } else if (!baralho.empty()) {
            computador.push_back(baralho.back());
            baralho.pop_back();
            cout << "O computador comprou uma carta.\n";
        }

        rodadas++;
    }

    if (mao.empty()) {
        cout << "Voce venceu o UNO, " << apelidos[pos] << "!\n";
    } else if (computador.empty()) {
        cout << "O computador venceu o UNO.\n";
    } else {
        cout << "A partida terminou empatada.\n";
    }

    partidas[pos]++;
    salvar(apelidos, partidas);
}

void ranking(vector<string> &apelidos, vector<int> &partidas) {
    vector<int> ordem;

    for (int i = 0; i < (int)apelidos.size(); i++) {
        ordem.push_back(i);
    }

    for (int i = 0; i < (int)ordem.size(); i++) {
        for (int j = i + 1; j < (int)ordem.size(); j++) {
            if (partidas[ordem[j]] > partidas[ordem[i]]) {
                int temp = ordem[i];
                ordem[i] = ordem[j];
                ordem[j] = temp;
            }
        }
    }

    titulo("RANKING DE JOGADORES");

    if (ordem.empty()) {
        cout << "Nenhum jogador cadastrado.\n";
        return;
    }

    for (int i = 0; i < (int)ordem.size(); i++) {
        int pos = ordem[i];
        cout << i + 1 << ". " << apelidos[pos]
             << " - " << partidas[pos] << " partida(s)\n";
    }
}

void mostrar_menu() {
    titulo("FLIPERAMA EM C++");
    cout << "Desenvolvido por: " << DONO << "\n";
    cout << "[1] Adivinhe o Numero\n";
    cout << "[2] Cadastrar jogador\n";
    cout << "[3] Listar jogadores\n";
    cout << "[4] Excluir jogador\n";
    cout << "[5] Cara ou Coroa\n";
    cout << "[6] UNO simplificado\n";
    cout << "[7] Pedra, Papel e Tesoura\n";
    cout << "[8] Alterar apelido\n";
    cout << "[9] Par ou Impar\n";
    cout << "[10] Ranking\n";
    cout << "[0] Salvar e sair\n";
    linha();
}

int main() {
    vector<string> apelidos;
    vector<int> partidas;
    int opcao;
    srand((unsigned int)time(NULL));

    int carregados = carregar(apelidos, partidas);
    cout << "O programa iniciou com " << carregados
         << " jogador(es) carregado(s).\n";

    do {
        mostrar_menu();
        opcao = ler_numero("Sua escolha: ", 0, 10);

        switch (opcao) {
            case 1:
                adivinhe(apelidos, partidas);
                break;
            case 2:
                cadastrar(apelidos, partidas);
                break;
            case 3:
                listar(apelidos, partidas);
                break;
            case 4:
                excluir(apelidos, partidas);
                break;
            case 5:
                cara_ou_coroa(apelidos, partidas);
                break;
            case 6:
                uno(apelidos, partidas);
                break;
            case 7:
                pedra_papel_tesoura(apelidos, partidas);
                break;
            case 8:
                alterar(apelidos, partidas);
                break;
            case 9:
                par_ou_impar(apelidos, partidas);
                break;
            case 10:
                ranking(apelidos, partidas);
                break;
            case 0:
                salvar(apelidos, partidas);
                cout << "Dados salvos. Ate a proxima!\n";
                break;
        }

        if (opcao != 0) {
            salvar(apelidos, partidas);
        }

        cout << "\n";
    } while (opcao != 0);

    return 0;
}
