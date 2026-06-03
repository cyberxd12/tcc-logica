#ifndef MURAL_H
#define MURAL_H

/* ===== Modulo 3: O Mural de Missoes =====
   LISTA SIMPLESMENTE ENCADEADA dinamica.
   Cada no guarda o nome da missao e o nivel de dificuldade (1 a 5). */

typedef struct NoMissao {
    char nome[50];
    int  dificuldade;        /* 1 a 5 */
    struct NoMissao *prox;
} NoMissao;

int  afixarMissao(NoMissao **cabeca, const char *nome, int dificuldade); /* insere no fim */
void concluirMissao(NoMissao **cabeca, const char *nome); /* busca por nome, religa e free */
void buscarPorDificuldade(const NoMissao *cabeca, int nivel); /* filtro por nivel          */
void visualizarMural(const NoMissao *cabeca);
void limparMural(NoMissao **cabeca);  /* faxina: free em todos os nos restantes */

#endif
