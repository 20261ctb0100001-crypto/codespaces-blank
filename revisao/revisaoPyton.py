# 1. Variáveis e tipos de dados
# Variáveis são espaços usados para guardar informações.
# Tipos de dados indicam o tipo de informação guardada.

nome = "Rafael"       # string (texto)
idade = 14            # inteiro (número sem decimal)
altura = 1.72         # float (número com decimal)
aprovado = True       # booleano (Verdadeiro ou Falso)


# 2. Operadores
# Operadores são símbolos usados para realizar operações matemáticas ou comparações.

soma = 10 + 5             # adição: resultado 15
subtracao = 10 - 5        # subtração: resultado 5
multiplicacao = 10 * 5    # multiplicação: resultado 50
divisao = 10 / 5          # divisão: resultado 2


# 3. Entrada de dados
# Entrada de dados permite que o usuário digite informações usando input().

nome = input("Digite seu nome: ")
idade = int(input("Digite sua idade: "))


# 4. Saída de dados
# Saída de dados mostra informações na tela usando print().

print("Nome:", nome)
print("Idade:", idade)


# 5. Estrutura de repetição
# Serve para repetir um comando várias vezes.
# O for repete o código enquanto existir uma sequência.

for i in range(5):
    print("Número:", i)


# 6. Estrutura de condição
# Permite que o programa tome decisões usando if e else.

if idade >= 18:
    print("Maior de idade")
else:
    print("Menor de idade")


# 7. Sub-rotinas (Funções)
# Funções são blocos de código criados para reutilizar comandos.

def saudacao(nome):
    print("Olá,", nome)

saudacao(nome)