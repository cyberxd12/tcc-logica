#include <stdio.h>
#include "arsenal.h"

/* Preenche o vetor com o estoque base fixo da Taverna. */
void inicializarArsenal(Arma arsenal[], int *total) {
    Arma base[] = {
        {"Cajado Arcano",     45, 320.00f},
        {"Adaga Enferrujada",  8,  15.00f},
        {"Lamina Lendaria",  120, 999.00f},
        {"Espada Curta",      20,  50.00f},
        {"Arco Longo Elfico", 35, 200.00f},
        {"Machado de Guerra", 50, 120.00f}
    };
    int n = (int)(sizeof(base) / sizeof(base[0]));
    for (int i = 0; i < n; i++) {
        arsenal[i] = base[i];   /* copia struct a struct para o vetor da Guilda */
    }
    *total = n;
}

/* Lista todas as armas na ordem em que estao no estoque. */
void visualizarCatalogo(const Arma arsenal[], int total) {
    printf("\n=== ARSENAL DA GUILDA (catalogo completo) ===\n");
    if (total == 0) { printf("Nenhuma arma cadastrada.\n"); return; }
    for (int i = 0; i < total; i++) {
        printf(" %d) %-20s | Dano: %3d | Preco: %8.2f\n",
               i + 1, arsenal[i].nome, arsenal[i].dano, arsenal[i].preco);
    }
}

/* Ordena uma COPIA do vetor por preco usando Bubble Sort.
   Trabalhamos na copia para nao baguncar a ordem original do estoque. */
void listarPorPreco(const Arma arsenal[], int total) {
    Arma copia[MAX_ARMAS];
    for (int i = 0; i < total; i++) {
        copia[i] = arsenal[i];
    }

    /* Bubble Sort: empurra o maior preco para o fim a cada passada. */
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (copia[j].preco > copia[j + 1].preco) {
                Arma tmp     = copia[j];
                copia[j]     = copia[j + 1];
                copia[j + 1] = tmp;
            }
        }
    }

    printf("\n=== ARSENAL ordenado por preco (Bubble Sort) ===\n");
    for (int i = 0; i < total; i++) {
        printf(" %d) %-20s | Dano: %3d | Preco: %8.2f\n",
               i + 1, copia[i].nome, copia[i].dano, copia[i].preco);
    }
}
