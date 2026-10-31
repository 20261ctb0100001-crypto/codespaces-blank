# Documentação do repositório

Este repositório reúne exercícios de programação, o projeto Fliperama em C e materiais históricos do curso técnico de Tecnologia da Informação.

## Organização principal

- `beecrowd/C/`: exercícios resolvidos em C.
- `beecrowd/Python/`: exercícios resolvidos em Python.
- `fliperama.c/`: projeto atual do Fliperama, com código-fonte, dados, configurações e versões anteriores.
- `historico/`: materiais de aulas, estudos, dados antigos e documentação complementar.

## Fliperama em C

O **Fliperama em C** é um programa de terminal com cadastro de jogadores e jogos simples. O código principal está em `fliperama.c/fliperama.c` e os dados dos jogadores ficam em `fliperama.c/jogadores.csv`.

Para executar no GitHub Codespaces ou Linux:

```bash
cd /workspaces/codespaces-blank/fliperama.c
gcc -Wall -Wextra -std=c99 fliperama.c -o fliperama && ./fliperama
```

No Windows com MinGW:

```bash
gcc -Wall -Wextra -std=c99 fliperama.c -o fliperama.exe
fliperama.exe
```

Consulte `fliperama.c/README.md` para as instruções e funcionalidades detalhadas do projeto.

## Exercícios Beecrowd

Os exercícios estão separados por linguagem dentro da pasta `beecrowd/`. Cada arquivo pode ser compilado ou executado individualmente, conforme a linguagem utilizada.

## Histórico

A pasta `historico/` preserva materiais de estudo e versões antigas. Ela não substitui nem duplica as pastas atuais de exercícios e do Fliperama.

## Autor e ferramentas de apoio

Repositório desenvolvido no contexto das atividades do curso técnico de Tecnologia da Informação. O ChatGPT foi utilizado como apoio para revisão e documentação; o conteúdo deve ser compreendido e conferido pelo autor.