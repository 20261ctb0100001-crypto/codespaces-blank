'''
Problema: beecrowd | 1002
Data: ???
Estudante: ???
'''

# Objetivo: Ler o raio de um círculo e calcular sua área

# --- ANÁLISE (LIAC) ---
# Entrada: um número decimal representando o raio
# Processamento: calcular a área usando a fórmula A = pi * R²
# Saída: exibir no formato "A=valor" com 4 casas decimais

# Leitura do raio como número decimal
R = float(input())

# Defina pi conforme o enunciado indica
pi = 3.14159

# Qual é a fórmula da área do círculo?
AREA = pi * R ** 2

# Saída — observe o formato exato e o número de casas decimais no enunciado
print(f"A={AREA:.4f}")