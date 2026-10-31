#
#Arquivo:   telas.py
#DISCIPLINA:    2026-pcap
#aula:  20
#Autor:  rafael glinski de oliveira
#Data: 2026.08.04
#Conceitos:
#=============

#Definição da Moldura Caracteres e Tamanho
CAR = '#'
TAM = 40

# Desenho uma linha na tela
def linha():
    print(CAR* TAM)

#Desenha um texto entre linhas
def titulo(texto):
        print(texto).center(TAM)
linha()
titulo('ola')
