# Fliperama em C

## 1. Sobre o projeto

O Fliperama em C é um programa de terminal desenvolvido como continuação do projeto de Fliperama feito em Python. Ele reúne jogos simples contra o computador e um cadastro de jogadores. O programa guarda os apelidos e a quantidade de partidas concluídas no arquivo `jogadores.csv`.

## 2. Funcionalidades

- Cadastrar, listar, editar e remover jogadores.
- Recusar apelidos vazios, duplicados, longos demais ou com vírgula.
- Impedir novos cadastros quando a capacidade máxima de 50 jogadores é atingida.
- Salvar e carregar os dados usando um arquivo CSV.
- Jogar Adivinhe o Número, Cara ou Coroa, UNO simplificado, Pedra-Papel-Tesoura e Par ou Ímpar.
- Voltar ao menu durante as partidas usando a opção indicada em cada jogo.

## 3. Como compilar e executar

No GitHub Codespaces, abra o terminal e execute:

```bash
cd /workspaces/codespaces-blank/fliperama-c
gcc -std=c99 -Wall -Wextra -pedantic -Werror fliperama.c -o fliperama
./fliperama
```

O arquivo executável `fliperama` é gerado localmente e não deve ser enviado ao GitHub. Para abrir o programa novamente, depois de compilado, use `./fliperama`.

## 4. Comparação entre Python e C

As linhas abaixo foram localizadas nos arquivos do projeto com `grep -n`. Os números correspondem às versões presentes neste repositório.

| Operação | Python: jogadores.py | C: fliperama.c |
|---|---:|---:|
| Verificar se o apelido já existe | linha 28: comparação com `==` | linha 42: `strcmp` |
| Adicionar um jogador ao cadastro | linha 35: `append` | linha 160: `strcpy` e incremento da quantidade |
| Gravar os dados no arquivo | linha 15: `open` para escrita | linha 127: `fopen` para escrita |
| Carregar os dados do arquivo | linha 8: `open` para leitura | linha 94: `fopen` para leitura |

No Python, a lista pode aumentar conforme novos elementos são adicionados. Em C, os apelidos ficam em um vetor com capacidade definida, e os dados são manipulados com funções próprias para strings e arquivos.

## 5. O que o C me obrigou a decidir

Uma decisão importante foi definir uma capacidade máxima para o cadastro. Como o vetor tem tamanho fixo, precisei verificar se ainda existe espaço antes de gravar um novo apelido. A condição `qtd >= CAPACIDADE` impede que o programa tente escrever fora dos limites do vetor.

Também precisei escolher como os dados seriam guardados no arquivo: cada linha do CSV contém o apelido e a quantidade de partidas, separados por vírgula.

## 6. Autoavaliação

Com este projeto, pratiquei funções, vetores, strings, estruturas de decisão, laços, números aleatórios e leitura e gravação de arquivos. A comparação com Python ajudou a perceber que, em C, preciso controlar explicitamente os limites dos vetores e cuidar da manipulação de memória. Ainda posso melhorar os testes de cada jogo e treinar mais o uso de ponteiros e arquivos.
