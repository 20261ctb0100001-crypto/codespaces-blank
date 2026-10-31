import random

from telas import titulo
from placar import registrar_partida, mostrar_placar


def jogar(jogador):
    titulo("PEDRA, PAPEL E TESOURA - MELHOR DE 3")

    print(f"Jogador: {jogador[0]}")

    opcoes = ["pedra", "papel", "tesoura"]

    vitorias = 0
    derrotas = 0
    rodada = 1

    while vitorias < 2 and derrotas < 2:
        print()
        print(f"--- RODADA {rodada} ---")
        print("1 - Pedra")
        print("2 - Papel")
        print("3 - Tesoura")

        try:
            escolha = int(input("Escolha: "))
        except ValueError:
            print("Digite apenas 1, 2 ou 3.")
            continue

        if escolha not in [1, 2, 3]:
            print("Opcao invalida.")
            continue

        jogador_escolha = opcoes[escolha - 1]
        computador = random.choice(opcoes)

        print()
        print(f"Voce escolheu: {jogador_escolha}")
        print(f"Computador escolheu: {computador}")

        if jogador_escolha == computador:
            print("Empate! A rodada nao conta.")
            continue

        if (
            (jogador_escolha == "pedra" and computador == "tesoura")
            or
            (jogador_escolha == "papel" and computador == "pedra")
            or
            (jogador_escolha == "tesoura" and computador == "papel")
        ):
            print("Voce venceu a rodada!")
            vitorias += 1
        else:
            print("Computador venceu a rodada!")
            derrotas += 1

        print()
        print(f"Placar da partida: Voce {vitorias} x {derrotas} Computador")

        rodada += 1

    print()
    print("=" * 40)

    if vitorias == 2:
        print(f"VOCE VENCEU, {jogador[0]}!")
        registrar_partida("ppt", "vitoria", jogador)
    else:
        print(f"COMPUTADOR VENCEU, {jogador[0]}!")
        registrar_partida("ppt", "derrota", jogador)

    print("=" * 40)

    mostrar_placar()

    input("\nPressione Enter para continuar...")


if __name__ == "__main__":
    print("Execute o jogo pelo main.py")