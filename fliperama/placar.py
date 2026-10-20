import csv
import os


ARQUIVO = "placar.csv"
ARQUIVO_JOGADORES = "placar_jogadores.csv"

JOGOS = ["adivinhe", "ppt", "parimpar"]


def criar_placar():
    if not os.path.exists(ARQUIVO):
        with open(ARQUIVO, "w", newline="", encoding="utf-8") as arquivo:
            escritor = csv.writer(arquivo)

            for jogo in JOGOS:
                escritor.writerow([jogo, 0, 0, 0])


def ler_placar():
    criar_placar()

    placar = {}

    with open(ARQUIVO, "r", newline="", encoding="utf-8") as arquivo:
        leitor = csv.reader(arquivo)

        for linha in leitor:
            if len(linha) >= 4:
                placar[linha[0]] = {
                    "vitorias": int(linha[1]),
                    "derrotas": int(linha[2]),
                    "empates": int(linha[3])
                }

    return placar


def registrar_partida(jogo, resultado, jogador=None):
    placar = ler_placar()

    if jogo not in placar:
        return

    if resultado == "vitoria":
        placar[jogo]["vitorias"] += 1

    elif resultado == "derrota":
        placar[jogo]["derrotas"] += 1

    elif resultado == "empate":
        placar[jogo]["empates"] += 1

    with open(ARQUIVO, "w", newline="", encoding="utf-8") as arquivo:
        escritor = csv.writer(arquivo)

        for nome in JOGOS:
            escritor.writerow([
                nome,
                placar[nome]["vitorias"],
                placar[nome]["derrotas"],
                placar[nome]["empates"]
            ])

    if jogador is not None:
        registrar_partida_jogador(jogo, resultado, jogador)


def registrar_partida_jogador(jogo, resultado, jogador):
    placares = {}

    if os.path.exists(ARQUIVO_JOGADORES):
        with open(
            ARQUIVO_JOGADORES,
            "r",
            newline="",
            encoding="utf-8"
        ) as arquivo:
            leitor = csv.reader(arquivo)

            for linha in leitor:
                if len(linha) >= 11:
                    placares[linha[0]] = {
                        "nome": linha[1],
                        "adivinhe_v": int(linha[2]),
                        "adivinhe_d": int(linha[3]),
                        "adivinhe_e": int(linha[4]),
                        "ppt_v": int(linha[5]),
                        "ppt_d": int(linha[6]),
                        "ppt_e": int(linha[7]),
                        "parimpar_v": int(linha[8]),
                        "parimpar_d": int(linha[9]),
                        "parimpar_e": int(linha[10])
                    }

    apelido = jogador[0]
    nome = jogador[1]

    if apelido not in placares:
        placares[apelido] = {
            "nome": nome,
            "adivinhe_v": 0,
            "adivinhe_d": 0,
            "adivinhe_e": 0,
            "ppt_v": 0,
            "ppt_d": 0,
            "ppt_e": 0,
            "parimpar_v": 0,
            "parimpar_d": 0,
            "parimpar_e": 0
        }

    chave = {
        "adivinhe": {
            "vitoria": "adivinhe_v",
            "derrota": "adivinhe_d",
            "empate": "adivinhe_e"
        },
        "ppt": {
            "vitoria": "ppt_v",
            "derrota": "ppt_d",
            "empate": "ppt_e"
        },
        "parimpar": {
            "vitoria": "parimpar_v",
            "derrota": "parimpar_d",
            "empate": "parimpar_e"
        }
    }

    if jogo in chave and resultado in chave[jogo]:
        campo = chave[jogo][resultado]
        placares[apelido][campo] += 1

    with open(
        ARQUIVO_JOGADORES,
        "w",
        newline="",
        encoding="utf-8"
    ) as arquivo:
        escritor = csv.writer(arquivo)

        for apelido, dados in placares.items():
            escritor.writerow([
                apelido,
                dados["nome"],
                dados["adivinhe_v"],
                dados["adivinhe_d"],
                dados["adivinhe_e"],
                dados["ppt_v"],
                dados["ppt_d"],
                dados["ppt_e"],
                dados["parimpar_v"],
                dados["parimpar_d"],
                dados["parimpar_e"]
            ])


def mostrar_placar():
    placar = ler_placar()

    nomes = {
        "adivinhe": "ADIVINHE",
        "ppt": "PEDRA, PAPEL E TESOURA",
        "parimpar": "PAR OU IMPAR"
    }

    print()
    print("=" * 50)
    print("                 PLACAR GERAL")
    print("=" * 50)

    for jogo in JOGOS:
        print()
        print(nomes[jogo])
        print(f"Vitorias: {placar[jogo]['vitorias']}")
        print(f"Derrotas: {placar[jogo]['derrotas']}")
        print(f"Empates: {placar[jogo]['empates']}")

    print()
    print("=" * 50)
    print("             PLACAR DOS JOGADORES")
    print("=" * 50)

    if not os.path.exists(ARQUIVO_JOGADORES):
        print("Nenhum jogador possui partidas registradas.")
        print("=" * 50)
        return

    encontrou = False

    with open(
        ARQUIVO_JOGADORES,
        "r",
        newline="",
        encoding="utf-8"
    ) as arquivo:
        leitor = csv.reader(arquivo)

        for linha in leitor:
            if len(linha) < 11:
                continue

            encontrou = True

            apelido = linha[0]
            nome = linha[1]

            adivinhe_v = int(linha[2])
            adivinhe_d = int(linha[3])
            adivinhe_e = int(linha[4])

            ppt_v = int(linha[5])
            ppt_d = int(linha[6])
            ppt_e = int(linha[7])

            parimpar_v = int(linha[8])
            parimpar_d = int(linha[9])
            parimpar_e = int(linha[10])

            total_vitorias = (
                adivinhe_v +
                ppt_v +
                parimpar_v
            )

            total_derrotas = (
                adivinhe_d +
                ppt_d +
                parimpar_d
            )

            total_empates = (
                adivinhe_e +
                ppt_e +
                parimpar_e
            )

            total_partidas = (
                total_vitorias +
                total_derrotas +
                total_empates
            )

            if total_partidas > 0:
                aproveitamento = (
                    total_vitorias / total_partidas
                ) * 100
            else:
                aproveitamento = 0

            print()
            print(f"JOGADOR: {apelido} | {nome}")
            print("-" * 50)

            print(
                f"Adivinhe       | "
                f"V: {adivinhe_v} | "
                f"D: {adivinhe_d} | "
                f"E: {adivinhe_e}"
            )

            print(
                f"Pedra, Papel e Tesoura | "
                f"V: {ppt_v} | "
                f"D: {ppt_d} | "
                f"E: {ppt_e}"
            )

            print(
                f"Par ou Impar   | "
                f"V: {parimpar_v} | "
                f"D: {parimpar_d} | "
                f"E: {parimpar_e}"
            )

            print("-" * 50)
            print(f"Total de partidas: {total_partidas}")
            print(f"Total de vitorias: {total_vitorias}")
            print(f"Total de derrotas: {total_derrotas}")
            print(f"Total de empates: {total_empates}")
            print(f"Aproveitamento: {aproveitamento:.1f}%")

    if not encontrou:
        print("Nenhum jogador possui partidas registradas.")

    print()
    print("=" * 50)