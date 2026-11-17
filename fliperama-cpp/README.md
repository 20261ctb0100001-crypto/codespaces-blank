# Fliperama em C++ (MeuApp v4.0)

## 1. O que e

Este programa e a versao em C++ do Fliperama desenvolvido anteriormente em C na disciplina 2026-PCAP.
Ele permite cadastrar jogadores, jogar contra o computador, consultar o ranking e guardar os dados em um arquivo CSV.

O programa possui os jogos Adivinhe o Numero, Cara ou Coroa, UNO simplificado, Pedra, Papel e Tesoura e Par ou Impar. Tambem permite listar, alterar e excluir jogadores.

O ChatGPT foi usado como apoio para adaptar o codigo para C++, revisar o funcionamento e organizar este README. O estudante deve compreender e revisar o codigo entregue.

## 2. Como compilar e rodar

Dentro da pasta `fliperama-cpp`, execute:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -Werror fliperama.cpp -o fliperama
./fliperama
```

A compilacao deve terminar sem avisos ou erros. O executavel `fliperama` e gerado localmente e nao deve ser enviado ao GitHub.

## 3. Arquivos

- `fliperama.cpp`: menu, cadastro, jogos, ranking e funcoes de leitura e gravacao.
- `jogadores.csv`: apelidos e quantidade de partidas de cada jogador, separados por virgula.
- `README.md`: instrucoes, comparacao entre C e C++ e autoavaliacao.

## 4. C x C++: o que mudou

Os numeros indicam as linhas dos arquivos atuais. Na versao em C, a funcao de cadastro recebe o total por ponteiro (`int *qtd`); na versao C++, os dois vectors sao recebidos por referencia.

| O que | No fliperama.c | No fliperama.cpp |
|---|---|---|
| Guardar um jogador | `strcpy(apelidos[*qtd], nome)` (linha 160) | `apelidos.push_back(novo)` (linha 144) |
| Comparar apelidos | `strcmp(apelidos[i], procurado) == 0` (linha 42) | `apelidos[i] == procurado` (linha 76) |
| Funcao de cadastro | `void cadastrar(..., int *qtd)` (linha 139) | `void cadastrar(vector<string> &apelidos, vector<int> &partidas)` (linha 131) |

## 5. O que o C++ decidiu por mim

Com `string`, o programa pode guardar e comparar apelidos sem usar diretamente arrays de caracteres, `strcpy` e `strcmp`.
Com `vector`, a lista pode aumentar com `push_back` e diminuir com `erase`, sem manter manualmente uma capacidade fixa e uma variavel de quantidade.

Mesmo usando vectors, eu preciso passar as listas por referencia (`&`) nas funcoes que alteram os dados. Tambem preciso manter apelidos e partidas na mesma posicao para que cada jogador continue associado ao seu numero de partidas.

## 6. Autoavaliacao

| Criterio | Conceito que espero | Onde se prova |
|---|---|---|
| 1. Estrutura, compilacao e Git | A | O codigo compila com o comando da secao 2; o executavel esta no `.gitignore`; ha historico de commits; excluir e alterar estao no menu (linhas 165 e 193). |
| 2. Cadastro: vectors e referencia | B | `cadastrar` recebe os dois vectors por referencia (linha 131); cadastro usa `push_back` (linha 144); os dados sao salvos depois das acoes. |
| 3. Jogo | A | Adivinhe incrementa as partidas do jogador correto; ha outros jogos, ranking e mensagem de abertura do ranking (funcao `ranking`, linha 462). |
| 4. Persistencia | C | `salvar` usa `ofstream` (linha 84), `carregar` usa `ifstream` (linha 99) e a leitura acontece no inicio do programa. |
| 5. Documentacao e comparacao | A | Este README tem as seis secoes solicitadas, a tabela C x C++ com tres comparacoes e os numeros das linhas dos dois arquivos. |

Os conceitos acima sao uma autoavaliacao esperada, nao uma nota atribuida pelo professor.
