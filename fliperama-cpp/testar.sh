#!/bin/bash
set -euo pipefail

PASTA="$(cd "$(dirname "$0")" && pwd)"
TEMPORARIO="$(mktemp -d)"
trap 'rm -rf "$TEMPORARIO"' EXIT

cp "$PASTA/fliperama.cpp" "$TEMPORARIO/"
cp "$PASTA/jogadores.csv" "$TEMPORARIO/"
cd "$TEMPORARIO"

echo "Compilando o Fliperama..."
g++ -std=c++11 -Wall -Wextra -pedantic -Werror fliperama.cpp -o fliperama

echo "Testando cadastro, jogos, edicao, exclusao e salvamento..."
printf '1\nrafael\n-1\n5\nrafael\n1\n6\nrafael\n-1\n7\nrafael\n1\n9\nrafael\n1\n5\n2\nJogadorTeste\n3\n8\n4\nJogadorEditado\n4\n4\n1\n0\n' | ./fliperama > resultado.txt

grep -q "ADIVINHE O NUMERO" resultado.txt
grep -q "CARA OU COROA" resultado.txt
grep -q "UNO - VERSAO SIMPLIFICADA" resultado.txt
grep -q "PEDRA, PAPEL E TESOURA" resultado.txt
grep -q "PAR OU IMPAR" resultado.txt
grep -q "Jogador cadastrado com sucesso" resultado.txt
grep -q "Apelido atualizado com sucesso" resultado.txt
grep -q "Jogador excluido com sucesso" resultado.txt
grep -q "Dados salvos" resultado.txt
grep -q "^rafael,0$" jogadores.csv

echo "Todos os testes automatizados passaram."
