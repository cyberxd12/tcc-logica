# Sistema de Gerenciamento da Guilda (S.G.G)

Projeto em C com arquitetura modular (`.h`/`.c`). O `main.c` cuida apenas do
Menu Principal e da leitura de entrada; cada modulo implementa uma estrutura
de dados.

## Estrutura dos arquivos
| Arquivo | Conteudo |
| --- | --- |
| `arsenal.h` / `arsenal.c` | Modulo 1 - Vetor de structs + Bubble Sort por preco |
| `enfermaria.h` / `enfermaria.c` | Modulo 2 - Fila dinamica FIFO (`malloc`/`free`) |
| `mural.h` / `mural.c` | Modulo 3 - Lista encadeada (remover por nome + filtro) |
| `main.c` | Menu Principal + leitura segura + Modulo 4 (A Faxina) |
| `Makefile` | Compilacao automatizada |

## Como compilar e rodar

Com o Makefile:
```bash
make
./sgg
```

Ou direto com o gcc:
```bash
gcc -Wall -Wextra -std=c11 main.c arsenal.c enfermaria.c mural.c -o sgg
./sgg
```

Para limpar os arquivos gerados:
```bash
make limpar
```

## Mapa da rubrica (5,0 pts)
- **Estruturas nucleares (1,5):** vetor (Arsenal), fila FIFO (Enfermaria), lista (Mural).
- **Memoria sem leaks (1,0):** todo `malloc` validado; `free` ao curar/concluir e na faxina (opcao 0).
- **Logica aplicada (1,0):** Bubble Sort por preco + filtro por dificuldade.
- **Modularizacao (1,0):** pares `.h`/`.c` por modulo; `main.c` so com o menu.
- **Robustez / UX (0,5):** valida opcoes do menu e entradas nao-numericas; trata fila/lista vazias.
