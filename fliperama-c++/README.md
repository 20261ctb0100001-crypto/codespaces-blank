# Fliperama em C++ (MeuApp v4.0)

## 1. O que e

Este programa e a versao em C++ do Fliperama desenvolvido anteriormente em C na disciplina 2026-PCAP. Ele permite cadastrar jogadores, jogar contra o computador, consultar o ranking e guardar os dados em um arquivo CSV.

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
- `.gitignore`: impede que o executavel compilado seja enviado ao repositorio.

## 4. C x C++: o que mudou

| O que | Na versao em C | Na versao em C++ |
|---|---|---|
| Guardar jogadores | Arrays de caracteres com tamanho definido por `CAPACIDADE` | `vector<string>` que pode crescer com `push_back` |
| Guardar partidas | Array de inteiros separado | `vector<int>` paralelo aos apelidos |
| Comparar apelidos | `strcmp(apelidos[i], procurado) == 0` | `apelidos[i] == procurado` |
| Copiar/guardar apelido | `strcpy(apelidos[*qtd], nome)` | `apelidos.push_back(novo)` |
| Passar quantidade/listas | Ponteiro como `int *qtd` | Referencias aos vectors com `&` |
| Ler e gravar CSV | `FILE*`, `fopen`, `fprintf` e `fscanf` | `ifstream` e `ofstream` |

Na versao C++, os dois vectors precisam manter a mesma posicao para que cada apelido continue associado ao numero correto de partidas.

## 5. O que continua comigo

Mesmo com os recursos do C++, algumas responsabilidades continuam comigo:

1. **Manter os dados relacionados:** `apelidos` e `partidas` sao vectors separados. Quando cadastro, altero ou excluo um jogador, preciso atualizar os dois na mesma posicao.
2. **Validar as entradas:** usar `string` e `vector` facilita o trabalho, mas ainda preciso conferir se o apelido e valido, se nao esta repetido e se a opcao digitada esta dentro do intervalo permitido.

Exemplo de execucao no terminal:

```text
3 jogador(es) carregado(s).
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
```

## 6. Autoavaliacao

| Criterio | Autoavaliacao | Onde se prova |
|---|---|---|
| 1. Estrutura, compilacao e Git | A | O codigo compila com o comando da secao 2; o executavel e ignorado pelo Git; o projeto possui historico de commits. |
| 2. Cadastro com vectors e referencias | A | `cadastrar` recebe os vectors por referencia (linha 131) e adiciona dados com `push_back` (linha 144). |
| 3. Jogos e operacoes | A | O menu oferece jogos, alem de `excluir` (linha 165), `alterar` (linha 193) e Par ou Impar. |
| 4. Persistencia e ranking | A | `salvar` usa `ofstream` (linha 84), `carregar` usa `ifstream` (linha 99) e `ranking` organiza indices sem mudar a ordem original dos vectors (linha 462). |
| 5. Documentacao e comparacao | A | Este README tem seis secoes, tabela comparativa C x C++, a secao “O que continua comigo” e exemplo de execucao. |

Os conceitos acima sao minha autoavaliacao do trabalho, nao uma nota atribuida pelo professor.
