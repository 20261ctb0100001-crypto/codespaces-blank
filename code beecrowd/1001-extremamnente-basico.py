'''
Problema beecrowd | 1001
Data: 2026.abril.16
Estudante: Rafael
'''
#Objetivo: Ler dois inteiros nas variaveis A e B, calcular a osoma em X e exibir o resultado
# 
# --ANALISE (LIAC)---
# Entrada: dois numeros inteiros, cada um em uma linhna separada
# Processamento: somar A + B e amarzenar em X
# Saída : exibir no formato exato "X = valor" espaços ao redor do =, sem mensagens extras)

# int ()   - converte o texto lido para número inteiro 
# input 90  - lê o valor fornecido (digitando ou pelo Beecrowd)
# int(input()) - lê e converte em uma única instrução
A = int(input())
B = int(input())

# O enunciado especifica explicitamente as variáveis A, B e X - seguir a risca
X = A + B

# f-string: insere o valor de X dentro do texto com ()
# Atenção: espaço antes e depois do = e obrigatorio conforme o anunciado
print(f"X = {X}")

