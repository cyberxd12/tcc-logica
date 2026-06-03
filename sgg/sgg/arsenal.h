#ifndef ARSENAL_H
#define ARSENAL_H

/* ===== Modulo 1: Arsenal da Guilda =====
   Catalogo de armas guardado em um VETOR ESTATICO de structs.
   O estoque base eh fixo (capacidade reservada: MAX_ARMAS). */

#define MAX_ARMAS 10   /* capacidade do vetor (o estoque base usa 6) */

typedef struct {
    char  nome[50];
    int   dano;
    float preco;
} Arma;

void inicializarArsenal(Arma arsenal[], int *total); /* preenche o estoque base  */
void visualizarCatalogo(const Arma arsenal[], int total); /* lista na ordem original */
void listarPorPreco(const Arma arsenal[], int total); /* ordena copia por preco  */

#endif
