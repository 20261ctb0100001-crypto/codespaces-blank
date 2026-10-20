import json

ARQUIVO = "jogadores.json"


def carregar():
    try:
        with open(ARQUIVO, "r", encoding="utf-8") as arquivo:
            return json.load(arquivo)
    except FileNotFoundError:
        return []


def salvar(jogadores):
    with open(ARQUIVO, "w", encoding="utf-8") as arquivo:
        json.dump(jogadores, arquivo, ensure_ascii=False, indent=4)


def cadastrar(jogadores):
    print("=" * 40)
    print("              NOVO JOGADOR")
    print("=" * 40)

    apelido = input("Apelido (sem espacos): ")

    # Verifica se o apelido já existe
    for jogador in jogadores:
        if jogador[0].lower() == apelido.lower():
            print("Esse apelido já está cadastrado!")
            return

    nome = input("Nome completo: ")

    novo = [apelido, nome, "0"]
    jogadores.append(novo)

    salvar(jogadores)

    print(f"Jogador {apelido} cadastrado.")


def listar(jogadores):
    print("=" * 40)
    print("         JOGADORES CADASTRADOS")
    print("=" * 40)

    if len(jogadores) == 0:
        print("Nenhum jogador cadastrado.")
        return

    for jogador in jogadores:
        print(f"{jogador[0]} | {jogador[1]} | {jogador[2]} partidas")

    print("=" * 40)