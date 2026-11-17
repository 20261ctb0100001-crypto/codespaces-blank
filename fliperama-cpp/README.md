# Fliperama em C++ (MeuApp v4.0)

## O que e

Este programa de terminal continua o Fliperama que foi feito antes em C. Ele tem cadastro de jogadores, jogos contra o computador, ranking e salvamento das partidas em um arquivo CSV.

O ChatGPT foi usado como apoio para adaptar o codigo para C++, revisar o funcionamento e organizar este README. O codigo e as decisoes do projeto precisam ser revisados e compreendidos pelo estudante.

## Como compilar e rodar

Dentro da pasta `fliperama-cpp`, execute:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic -Werror fliperama.cpp -o fliperama
./fliperama
```

O executavel `fliperama` e criado somente no ambiente local e nao deve ser enviado ao GitHub.

## Arquivos

- `fliperama.cpp`: menu, cadastro, jogos, ranking e funcoes para salvar e carregar os dados.
- `jogadores.csv`: apelido e quantidade de partidas de cada jogador, separados por virgula.
- `README.md`: explicacao do projeto, comparacao entre C e C++ e autoavaliacao.

## C x C++: o que mudou

| O que | No fliperama.c (linha) | No fliperama.cpp (linha) |
|---|---|---|
| Guardar um jogador | `strcpy(apelidos[*qtd], nome)` (160) | `apelidos.push_back(novo)` (144) |
| Comparar apelidos | `strcmp(apelidos[i], procurado) == 0` (42) | `apelidos[i] == procurado` (76) |
| Funcao que cadastra | `void cadastrar(char apelidos[][TAM_APELIDO], ...)` (139) | `void cadastrar(vector<string> &apelidos, ...)` (131) |
| Ler uma opcao | `fgets` e `strtol` (57) | `cin >> numero` (43) |
| Salvar e carregar | `fopen` (127) | `ofstream` (85) e `ifstream` (100) |
| Vetor de apelidos | `char apelidos[CAPACIDADE][TAM_APELIDO]` (638) | `vector<string> apelidos` (511) |

## O que o C++ decidiu por mim

Com `string`, nao preciso copiar apelidos com `strcpy` nem comparar texto com `strcmp`: posso usar atribuicao e `==`.

Com `vector`, a lista pode crescer com `push_back` e diminuir com `erase`, sem definir uma capacidade fixa para o cadastro.

A funcao `cadastrar` passou a ser `void` porque recebe os dois vectors por referencia e altera os dados originais. Assim, ela nao precisa devolver a quantidade de jogadores.

### O que continua comigo

Eu ainda preciso passar os vectors por referencia (`&`) nas funcoes que trabalham com o cadastro, para que as mudancas aparecam no `main`.

Tambem preciso manter `apelidos` e `partidas` na mesma posicao: quando cadastro ou excluo alguem, as duas listas devem mudar juntas. O ranking usa indices para nao separar esses dados nem mudar a ordem original do cadastro.

### Exemplo de execucao

Trecho de uma abertura com tres registros no arquivo:

```text
3 jogador(es) carregado(s).
O programa iniciou com 3 jogador(es) carregado(s).
========================================
FLIPERAMA EM C++
========================================
Desenvolvido por: Rafael Glinski de Oliveira
[1] Adivinhe o Numero
[2] Cadastrar jogador
[3] Listar jogadores
...
[10] Ranking
[0] Salvar e sair
========================================
Sua escolha:
```

## Autoavaliacao

| Criterio | Conceito que espero | Onde se prova (arquivo e linha) |
|---|---|---|
| 1. Estrutura, compilacao e Git | B | Compilacao: comando acima; `.gitignore` com seis linhas; historico de commits do repositorio. |
| 2. Cadastro: vectors e referencia | A | `cadastrar` linha 131; recusa de repetido e `push_back` linha 144; `excluir` linha 165; `alterar` linha 193; ranking linha 462. |
| 3. Jogo e partidas | A | Adivinhe e soma de partidas; segundo jogo com `eh_par()` que devolve `bool`, linha 306. |
| 4. Persistencia | A | `salvar` linha 84; `carregar` linha 100; mensagem de jogadores carregados no inicio, perto da linha 516. |
| 5. Documentacao e comparacao | A | Esta tabela tem seis linhas de comparacao; inclui as duas secoes de decisoes e o exemplo de execucao. |
