def listar(jogadores):
    print("=" * 40)
    print("         JOGADORES CADASTRADOS")
    print("=" * 40)

    if len(jogadores) == 0:
        print("Nenhum jogador cadastrado.")
        return

    for jogador in jogadores:
        print(f"{jogador[0]} | {jogador[1]} | {jogador[2]} partidas")

    print("=" * 40)cd fliperama