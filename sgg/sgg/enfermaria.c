#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enfermaria.h"

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim    = NULL;
}

/* Cria um no com malloc e insere no FIM da fila. */
int adicionarFerido(Fila *f, const char *nome) {
    NoFerido *novo = (NoFerido *) malloc(sizeof(NoFerido));
    if (novo == NULL) {                 /* SEMPRE validar o malloc */
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->prox = NULL;                  /* entra no fim, entao nao aponta pra ninguem */

    if (f->fim == NULL) {               /* fila vazia: novo eh inicio E fim */
        f->inicio = novo;
        f->fim    = novo;
    } else {                            /* liga o antigo fim no novo e move o 'fim' */
        f->fim->prox = novo;
        f->fim       = novo;
    }
    printf("%s entrou na fila da enfermaria.\n", novo->nome);
    return 1;
}

/* Atende quem esta no INICIO (FIFO), exibe a cura e libera a memoria. */
void curarHeroi(Fila *f) {
    if (f->inicio == NULL) {            /* fila vazia: nada a fazer */
        printf("A enfermaria esta vazia. Ninguem para curar.\n");
        return;
    }
    NoFerido *atendido = f->inicio;     /* o no da frente sera removido */
    f->inicio = f->inicio->prox;        /* o segundo da fila vira o novo inicio */
    if (f->inicio == NULL) {            /* se esvaziou, zera o 'fim' tambem... */
        f->fim = NULL;                  /* ...senao ele apontaria pra memoria liberada */
    }
    printf("O Clerigo curou %s!\n", atendido->nome);
    free(atendido);                     /* libera o no curado */
}

void visualizarEnfermaria(const Fila *f) {
    printf("\n=== FILA DA ENFERMARIA ===\n");
    if (f->inicio == NULL) { printf("Ninguem aguardando atendimento.\n"); return; }
    const NoFerido *atual = f->inicio;
    int i = 1;
    while (atual != NULL) {
        printf(" %d. %s\n", i++, atual->nome);
        atual = atual->prox;
    }
}

/* Faxina: percorre a fila inteira dando free em cada no. */
void limparEnfermaria(Fila *f) {
    NoFerido *atual = f->inicio;
    while (atual != NULL) {
        NoFerido *prox = atual->prox;   /* guarda o proximo ANTES de liberar o atual */
        free(atual);
        atual = prox;
    }
    f->inicio = NULL;
    f->fim    = NULL;
}
