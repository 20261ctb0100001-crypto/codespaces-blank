# Fliperama em C++

## 1. Sobre o projeto

Este projeto é a versão em C++ do Fliperama que foi desenvolvido anteriormente em C. Ele funciona pelo terminal e reúne um cadastro de jogadores, cinco jogos contra o computador e um placar simples. Os dados são guardados no arquivo `jogadores.csv`, para continuarem disponíveis quando o programa for aberto novamente.

## 2. Funcionalidades

### Cadastro de jogadores
- Cadastrar jogadores com apelido.
- Listar os jogadores cadastrados e a quantidade de partidas concluídas.
- Editar apelidos.
- Excluir jogadores com confirmação.
- Limite de 50 jogadores.
- Não permite apelidos vazios, repetidos, com vírgula ou com 20 caracteres ou mais.

### Jogos
- **Adivinhe o Número:** descobrir um número aleatório entre 1 e 100.
- **Cara ou Coroa:** escolher um lado da moeda.
- **UNO simplificado:** combinar a cor ou o número das cartas; é possível comprar cartas e sair da partida.
- **Pedra, Papel e Tesoura:** jogar contra o computador.
- **Par ou Ímpar:** escolher par ou ímpar e um número de 0 a 10.

Nos jogos que oferecem a opção, digite o número indicado para voltar ao menu. No Adivinhe o Número e no UNO, digite `-1` para sair da partida.

## 3. Organização dos arquivos

```text
fliperama-cpp/
├── fliperama.cpp   # Código-fonte do programa
├── jogadores.csv  # Dados iniciais dos jogadores
└── README.md      # Documentação
```

O programa principal fica em um único arquivo `.cpp` para manter a implementação simples e fácil de compilar.

## 4. Como compilar e executar

No terminal do GitHub Codespaces, execute:

```bash
cd /workspaces/codespaces-blank/fliperama-cpp
g++ -std=c++11 -Wall -Wextra -pedantic -Werror fliperama.cpp -o fliperama
./fliperama
```

O comando de compilação cria o executável local `fliperama`. Esse arquivo não deve ser enviado ao GitHub; o `.gitignore` já está configurado para ignorá-lo.

## 5. Arquivo de jogadores

Cada linha de `jogadores.csv` segue este formato:

```text
apelido,partidas
```

Exemplo:

```text
rafael,0
renan,0
pedro,0
```

Não coloque vírgulas nos apelidos, porque a vírgula separa os campos do CSV.

## 6. O que foi utilizado de C++

A versão utiliza:
- `struct` para agrupar os dados de cada jogador e de cada carta.
- `string` para trabalhar com apelidos.
- `cin` e `cout` para entrada e saída.
- `ifstream` e `ofstream` para carregar e salvar o arquivo.
- Funções, vetores, estruturas condicionais e laços de repetição.

A lógica dos jogos e do cadastro foi adaptada da versão anterior em C para utilizar recursos de C++.

## 7. Uso de ferramentas de IA

O ChatGPT foi utilizado como apoio na adaptação do projeto de C para C++, na revisão da leitura de dados e na organização deste README. O estudante deve revisar o código, executar o programa e compreender as funções antes da apresentação ou entrega.
