# ---------------------------------------------------------
# Disciplina : Pensamento Computacional, Algoritmos e Programação (PCAP)
# Projeto : Jogo "Pedra-Papel-Tesoura"
# Arquivo : ppt.py
# Autor : [SEU NOME AQUI]
# Data : [DATA DE HOJE]
# ---------------------------------------------------------

import random

# === Sub-rotina: decide o resultado de UMA rodada ===
def resultado(jogador, maquina):
    if jogador == maquina:
        return "empate"

    if jogador == "pedra" and maquina == "tesoura":
        return "jogador"

    if jogador == "papel" and maquina == "pedra":
        return "jogador"

    if jogador == "tesoura" and maquina == "papel":
        return "jogador"

    return "maquina"


# === Loop principal do jogo ===
jogar_novamente = "s"

while jogar_novamente == "s":

    opcoes = ["pedra", "papel", "tesoura"]
    pontos_jogador = 0
    pontos_maquina = 0

    print("\n=== PEDRA, PAPEL E TESOURA ===")

    for rodada in range(1, 6):
        print(f"\n--- Rodada {rodada} ---")

        jogada_maquina = random.choice(opcoes)
        jogada_jogador = input("Sua jogada: ").lower().strip()

        print(f"🤖 Máquina jogou: {jogada_maquina}")

        if jogada_jogador not in opcoes:
            print("❌ Jogada inválida! Você perde a rodada.")
            pontos_maquina += 1
        else:
            quem = resultado(jogada_jogador, jogada_maquina)

            if quem == "empate":
                print("🤝 Empate!")
            elif quem == "jogador":
                print("🏆 Você ganhou a rodada!")
                pontos_jogador += 1
            else:
                print("🤖 A máquina ganhou a rodada!")
                pontos_maquina += 1

        print(f"Placar parcial -> Você: {pontos_jogador} | Máquina: {pontos_maquina}")

    print("\n=== FIM DO JOGO ===")
    print(f"Placar final -> Você: {pontos_jogador} | Máquina: {pontos_maquina}")

    if pontos_jogador > pontos_maquina:
        print("🎉 Parabéns! Você venceu o jogo!")
    elif pontos_maquina > pontos_jogador:
        print("😢 A máquina venceu o jogo!")
    else:
        print("🤝 O jogo terminou empatado!")

    jogar_novamente = input("\nDeseja jogar novamente? (s/n): ").lower().strip()

print("Obrigado por jogar! 👋")
