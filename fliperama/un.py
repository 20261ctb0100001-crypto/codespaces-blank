import random

# Cores
cores = ["Vermelho", "Azul", "Verde", "Amarelo"]

# Criando o baralho
baralho = []

for cor in cores:
    for numero in range(10):
        baralho.append(cor + " " + str(numero))

# Embaralhando
random.shuffle(baralho)

# Cartas dos jogadores
jogador = []
robo = []

# Cada um recebe 7 cartas
for i in range(7):
    jogador.append(baralho.pop())
    robo.append(baralho.pop())

# Carta da mesa
mesa = baralho.pop()

# Começo do jogo
while True:

    print("\n==============================")
    print("            UNO")
    print("==============================")

    print("\nCarta da mesa:")
    print("-------------")
    print("|           |")
    print("|", mesa)
    print("|           |")
    print("-------------")

    print("\nSuas cartas:")

    for i in range(len(jogador)):
        print(i + 1, "-", jogador[i])

    print("\nRobô possui", len(robo), "cartas")

    print("\n0 - Comprar carta")

    escolha = input("\nEscolha uma carta: ")

    # Comprar carta
    if escolha == "0":

        jogador.append(baralho.pop())

        print("\nVocê comprou uma carta!")

    else:

        numero = int(escolha) - 1

        # Verificando se o número existe
        if numero >= 0 and numero < len(jogador):

            carta = jogador[numero]

            # Verifica se pode jogar
            if carta.split()[0] == mesa.split()[0] or carta.split()[1] == mesa.split()[1]:

                jogador.pop(numero)

                mesa = carta

                print("\nVocê jogou:", carta)

            else:

                print("\nVocê não pode jogar essa carta!")

                continue

        else:

            print("\nCarta inválida!")

            continue

    # Verifica se o jogador ganhou
    if len(jogador) == 0:

        print("\n==============================")
        print("       VOCÊ GANHOU!")
        print("==============================")

        break

    # ==============================
    # VEZ DO ROBÔ
    # ==============================

    print("\n------------------------------")
    print("        VEZ DO ROBÔ")
    print("------------------------------")

    jogou = False

    for i in range(len(robo)):

        carta_robo = robo[i]

        if carta_robo.split()[0] == mesa.split()[0] or carta_robo.split()[1] == mesa.split()[1]:

            mesa = robo.pop(i)

            print("\nO robô jogou:", mesa)

            jogou = True

            break

    # Se não tiver carta, compra
    if jogou == False:

        robo.append(baralho.pop())

        print("\nO robô não tinha carta.")
        print("O robô comprou uma carta.")

    # Verifica vitória do robô
    if len(robo) == 0:

        print("\n==============================")
        print("       ROBÔ GANHOU!")
        print("==============================")

        break