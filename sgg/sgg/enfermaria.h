#ifndef ENFERMARIA_H
#define ENFERMARIA_H

/* ===== Modulo 2: A Fila da Enfermaria =====
   FILA DINAMICA com regra FIFO (entra no fim, sai no inicio).
   Guardamos ponteiros para o inicio e para o fim da fila. */

typedef struct NoFerido {
    char nome[50];
    struct NoFerido *prox;
} NoFerido;

typedef struct {
    NoFerido *inicio;
    NoFerido *fim;
} Fila;

void inicializarFila(Fila *f);
int  adicionarFerido(Fila *f, const char *nome); /* malloc + insere no FIM (1 ok / 0 falha) */
void curarHeroi(Fila *f);          /* remove do INICIO + free                 */
void visualizarEnfermaria(const Fila *f);
void limparEnfermaria(Fila *f);    /* faxina: free em todos os nos restantes  */

#endif
