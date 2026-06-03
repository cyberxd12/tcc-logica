#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mural.h"

/* Cria um no (nome + dificuldade) e insere no FIM da lista. */
int afixarMissao(NoMissao **cabeca, const char *nome, int dificuldade) {
    NoMissao *novo = (NoMissao *) malloc(sizeof(NoMissao));
    if (novo == NULL) {                 /* valida o malloc */
        printf("Erro: memoria insuficiente.\n");
        return 0;
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';
    novo->dificuldade = dificuldade;
    novo->prox = NULL;

    if (*cabeca == NULL) {              /* lista vazia: o novo vira a cabeca */
        *cabeca = novo;
    } else {                            /* percorre ate o ultimo no e liga no fim */
        NoMissao *atual = *cabeca;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf("Missao '%s' (Dif %d) afixada no mural.\n", novo->nome, novo->dificuldade);
    return 1;
}

/* Busca a missao pelo nome, remove o no (tratando o caso da cabeca),
   refaz a ligacao dos ponteiros e libera a memoria. */
void concluirMissao(NoMissao **cabeca, const char *nome) {
    NoMissao *atual    = *cabeca;
    NoMissao *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;               /* lembra o no anterior para religar depois */
        atual    = atual->prox;
    }

    if (atual == NULL) {                /* percorreu tudo e nao achou */
        printf("Missao '%s' nao encontrada no mural.\n", nome);
        return;
    }

    if (anterior == NULL) {             /* o no eh a CABECA da lista */
        *cabeca = atual->prox;          /* a cabeca passa a ser o segundo no */
    } else {                            /* no do meio ou do fim */
        anterior->prox = atual->prox;   /* o anterior "pula" o no que sera removido */
    }

    printf("Missao '%s' concluida! Recompensa liberada.\n", atual->nome);
    free(atual);                        /* limpa a memoria do no removido */
}

/* Percorre a lista imprimindo apenas as missoes do nivel pedido. */
void buscarPorDificuldade(const NoMissao *cabeca, int nivel) {
    printf("\n=== Missoes de dificuldade %d ===\n", nivel);
    int encontrou = 0;
    const NoMissao *atual = cabeca;
    while (atual != NULL) {
        if (atual->dificuldade == nivel) {
            printf(" - %s\n", atual->nome);
            encontrou = 1;
        }
        atual = atual->prox;
    }
    if (!encontrou) printf("Nenhuma missao nesse nivel.\n");
}

void visualizarMural(const NoMissao *cabeca) {
    printf("\n=== MURAL DE MISSOES ===\n");
    if (cabeca == NULL) { printf("Nenhuma missao afixada.\n"); return; }
    const NoMissao *atual = cabeca;
    int i = 1;
    while (atual != NULL) {
        printf(" %d. [Dif %d] %s\n", i++, atual->dificuldade, atual->nome);
        atual = atual->prox;
    }
}

/* Faxina: free em todos os nos restantes da lista. */
void limparMural(NoMissao **cabeca) {
    NoMissao *atual = *cabeca;
    while (atual != NULL) {
        NoMissao *prox = atual->prox;   /* guarda o proximo antes do free */
        free(atual);
        atual = prox;
    }
    *cabeca = NULL;
}
