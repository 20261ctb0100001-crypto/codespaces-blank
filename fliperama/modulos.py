def ler_inteiro(mensagem):
    while True:
        try:
            return int(input(mensagem))
        except ValueError:
            print("Digite um número válido.")


def ler_opcao(mensagem, minimo, maximo):
    while True:
        opcao = ler_inteiro(mensagem)

        if minimo <= opcao <= maximo:
            return opcao

        print(f"Digite uma opção entre {minimo} e {maximo}.")
        