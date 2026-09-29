'''
Problema beecrowd | 1004
Data: 2026.abril.2
Estudante: Rafael
'''
#Objetivo: Ler dois inteiros nas variaveis A e B, calcular o produto em PROD e exibir o resultado
# 
# --ANALISE (LIAC)---
# Entrada: dois numeros inteiros, cada um em uma linhna separada
# Processamento: multiplicar A por B e amarzenar em PROD
# Saída : exibir no formato exato "PROD = valor" espaços ao redor do =, sem mensagens extras)

# int ()   - converte o texto lido para número inteiro 
# input 90  - lê o valor fornecido (digitando ou pelo Beecrowd)
# int(input()) - lê e converte em uma única instrução
A = int(input())
B = int(input())

# O enunciado especifica explicitamente as variáveis A, B e PROD - seguir a risca
PROD = A * B

# f-string: insere o valor de PROD dentro do texto com {}
# Atenção: espaço antes e depois do = e obrigatorio conforme o anunciado
print(f"PROD = {PROD}")

