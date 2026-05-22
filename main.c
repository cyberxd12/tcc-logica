#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura do equipamento
typedef struct equipamento {
    char nome[50];
    int dano;
    float preco;
    struct equipamento *prox;
} equipamento;

//estrutura da fila
typedef struct fila{
    equipamento *inicio;
    equipamento *fim;
}fila;

void inserir_equipamento(fila *f, char *nome, int dano, float preco){
    //criando novo equipamento
    equipamento *novo = (equipamento*) malloc(sizeof(equipamento));
    
    //atribuindo valores
    strcpy(novo->nome, nome);
    novo->dano = dano;
    novo->preco = preco;
    novo->prox = NULL;
    
    //debug
    printf("\ncadastrando produto");
    printf("\nnome: %s", novo->nome);
    printf("\ndano: %i", novo->dano);
    printf("\npreco: %.2f", novo->preco);
    
    //teste sequencia da fila
    if(f->inicio == NULL){
        //se estiver vazia ele assume as duas posiçoes
        f->inicio = novo;
        f->fim = novo;
    }else{
        //se já tem algo na fila o proximo do atual sera o novo e o novo sera o ultimo
        f->fim->prox = novo;
        f->fim= novo;
    }
    
    printf("\nconcluido com sucesso!\n");
}

int main(void)
{
    //vetor com 10 amazenamentos para equipamentos
    fila catalogo;

    //inserindo equipamentos
    inserir_equipamento(&catalogo, "espada", 10, 11.5);
    inserir_equipamento(&catalogo, "escudo", 2, 9.0);
    inserir_equipamento(&catalogo, "capacete", 0, 3.0);

   
    return 0;
}