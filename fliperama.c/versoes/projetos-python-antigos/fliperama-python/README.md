# Fliperama do Rafael

Um fliperama de terminal com três jogos, placar que não esquece e cadastro de jogadores. Projeto da disciplina PCAP, 1º ano do Técnico em Informática do IFPR.

## O que ele faz

* Três jogos pelo menu: Adivinhe o Número, Pedra-Papel-Tesoura e Par ou Ímpar
* Placar que conta quantas vezes cada jogo foi jogado e continua contando depois de fechar o programa
* Cadastro de jogadores: cadastrar, listar, alterar e excluir

## Como rodar

```bash
cd fliperama
python3 main.py
```

## Os arquivos

* `main.py` — controla o menu principal, o placar e as chamadas dos jogos.
* `telas.py` — ferramentas visuais do programa.
* `modulos.py` — ferramentas de lógica e validação de entradas.
* `placar.py` — ferramentas de dados do placar.
* `jogadores.py` — ferramentas de dados e cadastro dos jogadores.
* `adivinhe.py` — jogo Adivinhe o Número.
* `ppt.py` — jogo Pedra-Papel-Tesoura.
* `parimpar.py` — jogo Par ou Ímpar.
* `placar.csv` — arquivo que guarda os dados do placar.
* `jogadores.csv` — arquivo que guarda os dados dos jogadores.

## De onde ele veio

* Aula 20 — criação e organização das funções de lógica e validação.
* Aula 21 — desenvolvimento do cadastro de jogadores.
* Aula 22 — cadastro, busca e armazenamento dos jogadores.
* Aula 23 — documentação do projeto e preparação da entrega.

## O que ainda não funciona

* Nomes de jogadores com vírgula podem causar problema no arquivo CSV.
* Ainda precisamos identificar uma segunda limitação real do seu projeto.
