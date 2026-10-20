import random

from telas import titulo
from placar import registrar_partida, mostrar_placar


def jogar(jogador):
    titulo("PAR OU IMPAR - MELHOR DE 3")

    print(f"Jogador: {jogador[0]}")

    vitorias = 0
    derrotas = 0
    rodada = 1

    while vitorias < 2 and derrotas < 2:
        print()
        print(f"--- RODADA {rodada} ---")
        print("1 - Par")
        print("2 - Impar")

        try:
            escolha = int(input("Escolha: "))
            numero = int(input("Digite um numero de 0 a 10: "))
        except ValueError:
            print("Digite apenas numeros.")
            continue

        if escolha not in [1, 2]:
            print("Opcao invalida.")
            continue

        if numero < 0 or numero > 10:
            print("Digite um numero entre 0 e 10.")
            continue

        computador = random.randint(0, 10)
        total = numero + computador

        if total % 2 == 0:
            resultado = "par"
        else:
            resultado = "impar"

        print()
        print(f"Voce escolheu: {numero}")
        print(f"Computador escolheu: {computador}")
        print(f"Conta: {numero} + {computador} = {total}")
        print(f"Resultado: {resultado}")

        if (
            (escolha == 1 and resultado == "par")
            or
            (escolha == 2 and resultado == "impar")
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
        registrar_partida("parimpar", "vitoria", jogador)
    else:
        print(f"COMPUTADOR VENCEU, {jogador[0]}!")
        registrar_partida("parimpar", "derrota", jogador)

    print("=" * 40)

    mostrar_placar()

    input("\nPressione Enter para continuar...")


if __name__ == "__main__":
    print("Execute o jogo pelo main.py")