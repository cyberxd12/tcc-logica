#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo1_h"

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
    if (fl == NULL || fl->inicio == NULL) {
        printf("\nCatalogo vazio!\n");
        return;
    }

    equipamento *atual;
    equipamento *menor;
    equipamento *anterior;
    equipamento *anterior_do_menor;
    int caunt = 1;

    //clonagem da fila
    fila filaClone;
    filaClone.inicio = NULL;
    filaClone.fim = NULL;

    //clonar nó por nó
    equipamento *auxOriginal = fl->inicio;
    equipamento *ultimoClonado = NULL;
    
    //novo nó
    while (auxOriginal != NULL) {
        // Aloca memória para um novo nó na fila clone
        equipamento *novoNo = (equipamento*) malloc(sizeof(equipamento));
        
        // Copia todos os dados do nó original para o novo nó
        strcpy(novoNo->nome, auxOriginal->nome);
        novoNo->dano = auxOriginal->dano;
        novoNo->preco = auxOriginal->preco;
        novoNo->prox = NULL; // Por enquanto ele é o último da nova fila

        // Conecta o novo nó na fila clone
        if (filaClone.inicio == NULL) {
            filaClone.inicio = novoNo; // Primeiro nó da cópia
        } else {
            ultimoClonado->prox = novoNo; // Conecta ao anterior da cópia
        }
        
        ultimoClonado = novoNo;
        auxOriginal = auxOriginal->prox; // Avança na lista original
    }

    printf("\nexibindo catalogo ordenado...\n");
    
    //exibição usando a fila clone
    while(filaClone.inicio != NULL){
        atual = filaClone.inicio;
        menor = filaClone.inicio;
        anterior = NULL;
        anterior_do_menor = NULL;
        
        while (atual != NULL) {
            if (atual->preco < menor->preco) {
                menor = atual;
                anterior_do_menor = anterior; 
            }
            anterior = atual;
            atual = atual->prox;
        }
        
        printf("\nEquipamento %d\nnome: %s\ndano: %d\npreço: %.2f\n", caunt++, menor->nome, menor->dano, menor->preco);
        
        // Cirurgia de remoção na Fila Clone
        if (menor == filaClone.inicio) {
            filaClone.inicio = filaClone.inicio->prox;
        } else {
            anterior_do_menor->prox = menor->prox;
        }

        free(menor); // Libera o nó da cópia
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