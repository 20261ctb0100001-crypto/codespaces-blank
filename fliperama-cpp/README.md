# Fliperama em C++

## Sobre o projeto

Esta é a versão em C++ do Fliperama desenvolvido anteriormente em C. O programa funciona no terminal, permite cadastrar jogadores e oferece jogos contra o computador. Os apelidos e a quantidade de partidas concluídas são guardados no arquivo `jogadores.csv`.

## Funcionalidades

- Cadastrar, listar, editar e remover jogadores.
- Limite de 50 jogadores.
- Impedir apelidos vazios, repetidos ou com vírgula.
- Salvar e carregar os dados em arquivo CSV.
- Adivinhe o Número.
- Cara ou Coroa.
- UNO simplificado.
- Pedra, Papel e Tesoura.
- Par ou Ímpar.

## Como compilar e executar

No terminal do GitHub Codespaces, entre na pasta do projeto e execute:

```bash
cd fliperama-cpp
g++ -std=c++11 -Wall -Wextra -pedantic -Werror fliperama.cpp -o fliperama
./fliperama
```

O executável é criado localmente e não precisa ser enviado ao GitHub.

## O que mudou de C para C++

A lógica principal foi mantida, mas a versão C++ usa recursos próprios da linguagem, como `cout` e `cin` para entrada e saída, `string` para apelidos, `ifstream` e `ofstream` para ler e gravar o CSV, além de uma estrutura `struct Jogador` para reunir os dados de cada participante.

## Uso de ferramentas de IA

O ChatGPT foi utilizado como apoio para converter a versão anterior em C++ e revisar a organização do código. O código deve ser compilado e testado pelo estudante, que deve revisar as funções e compreender as alterações antes da entrega.
