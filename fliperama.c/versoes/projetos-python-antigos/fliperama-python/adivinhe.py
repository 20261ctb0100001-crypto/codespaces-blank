import random

from telas import titulo
from placar import registrar_partida


def jogar(jogador):
    titulo("ADIVINHE O NUMERO")

    print(f"Jogador: {jogador[0]}")

    vitorias = 0
    derrotas = 0
    rodada = 1

    while vitorias < 2 and derrotas < 2:
        print(f"\n--- RODADA {rodada} ---")

        numero = random.randint(1, 10)

        try:
            palpite = int(input("Adivinhe um numero de 1 a 10: "))
        except ValueError:
            print("Digite apenas numeros.")
            continue

        if palpite == numero:
            print(f"Voce acertou! O numero era {numero}.")
            vitorias += 1
        else:
            print(f"Voce errou! O numero era {numero}.")
            derrotas += 1

        print(f"Placar: Voce {vitorias} x {derrotas} Computador")

        rodada += 1

    print("\n" + "=" * 40)

    if vitorias == 2:
        print(f"VOCE VENCEU, {jogador[0]}!")
        registrar_partida("adivinhe", "vitoria", jogador)
    else:
        print(f"COMPUTADOR VENCEU, {jogador[0]}!")
        registrar_partida("adivinhe", "derrota", jogador)

    print("=" * 40)


if __name__ == "__main__":
    print("Execute o jogo pelo main.py")