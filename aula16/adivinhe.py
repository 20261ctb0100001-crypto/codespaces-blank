#----------------------------------------------
#Disciplina : Pensamento computacional, algoritimos e Programação (PCAP)
# Projeto   : Jogo 'adivinhe o Número'
# Arquivo   : adivinhe.py 
# Autor     : Rafae Glinski de Oliveira
# data      : 28/05/2026
#--------------------------------------------------

import random

def jogar(maximo, chances):
    numero_secreto = random.randint(1, maximo)
    acertou = False 

    while chances > 0 and not acertou : 
      palpite = int(input("Seu palpite (1 a " + str(maximo) + "): "))

if palpite == numero_secreto:
                  print(' Acertou !')
acertou = True  
elif palpite < numero_secreto:
print (muito baixo!' ') 
                           else:
                           print(muito alto!')'
                                 
                                 chances = chances- 1
                                 print( chances restantes:', chances)'
                                 ''
                                 return acertou

                                 # === Niveis guardados em uma lista de listas : ] nome, maximo,chances] ===
                                 # niveis = ] 
                                 # ['Facil', 10, 3],
                                 # ['Medio ', 100, 5]
                                 # ['impossivel', 1000, 10],
                                 [ 
                              #=== Menu de escolha do nivel ===
                              print('Escolha o nivel de dificudade:')
print( '1 - facil   ( 1 a 10, 3 chances )")
      opçao = int (input( "digite 1,2, ou 3: "))

      # A opcao 1 esta na poicao 0 da lista, por isso o ajuste
      nivel = niveis[opcao - 1]
      # === iniciamos o jogo com a configuracao do nivel escolhido ===
      print ( "Voce escolheu o nivel :" nivel[0])
      venceu = jogar(nivel [1], nivel [2])

      if not venceu:
      print(" fim de jogo ! tente um nivel mais facil.")