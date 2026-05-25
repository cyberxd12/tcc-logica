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
}

void filaPadrao(fila *fl){
    //retirada das structs da fila para exibir
    equipamento *atual = fl->inicio;
    equipamento *prox;
    int caunt= 1;
    
    printf("\nexibindo catalogo...\n");
    //exibição
    while(atual !=NULL){
        printf("\nEquipamento %d\nnome: %s\ndano: %d\npreço: %.2f\n", caunt++, atual->nome, atual->dano, atual->preco);
        //variavel prox recebe o proximo do atual
        prox = atual->prox;
        //prox se torna o atual
        atual = prox;
    }
}

void filaOrdenada(fila *fl){
    //retirada das structs da fila para exibir
    equipamento *atual = fl->inicio;
    equipamento *prox;
    int caunt= 1;
    
    printf("\nexibindo catalogo...\n");
    //exibição
    while(atual !=NULL){

        //tomando todo tipo de gap desse catalogo ordenado, como caralhos faz essa miseria
        while(atual->prox !=NULL){
            if(atual->preço > atual->prox->preco){
                //prox se torna o atual
                atual = atual->prox;
            }else{
                atual->prox = atual
            }
        }

        printf("\nEquipamento %d\nnome: %s\ndano: %d\npreço: %.2f\n", caunt++, atual->nome, atual->dano, atual->preco);
        //variavel prox recebe o proximo do atual
        prox = atual->prox;
        //prox se torna o atual
        atual = prox;
    }
}

void arsenal(){
    //modulo 1: O Arsenal da Guilda (Vetores e Structs)
    //vetor com 10 amazenamentos para equipamentos
    struct fila catalogo[10];
    catalogo->inicio = NULL;
    catalogo->fim = NULL;

    //inserindo equipamentos pradrões
    inserir_equipamento(catalogo, "espada", 10, 11.5);
    inserir_equipamento(catalogo, "escudo", 2, 9.0);
    inserir_equipamento(catalogo, "capacete", 0, 3.0);

    //seleção do menu
    int opc;

    do{
        printf("\nselecione o menu:\n1 - ordem padrão\n2 - menor preço\n0 - sair\nescolha: ");
        scanf(" %d", &opc);
        switch(opc){
            case 1:
                filaPadrao(catalogo); 
            break;
                
            case 2:
                filaOrdenada(catalogo);
            break;

            case 0:
                opc == 0;
            break;

            default:
                printf("\nopção invalida...\n");
            break;
        }
    }while(opc != 0);
    //fim do modulo 1
}
