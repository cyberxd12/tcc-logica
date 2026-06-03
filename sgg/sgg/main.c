#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arsenal.h"
#include "enfermaria.h"
#include "mural.h"

/* ============================================================
   Sistema de Gerenciamento da Guilda (S.G.G)
   main.c -> apenas o Menu Principal e a leitura de entrada.
   A logica de cada estrutura vive nos modulos .h/.c.
   ============================================================ */

/* ===================== Utilidades de entrada ===================== */

/* Limpa o buffer do teclado: resolve o '\n' que o scanf deixa pra tras
   e descarta lixo quando o usuario digita algo invalido (anti-goblin). */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Le um inteiro com seguranca. Se o usuario digitar algo que nao eh
   numero, retorna -1 (e o menu trata como "opcao invalida"). */
int lerInteiro(void) {
    int valor;
    int r = scanf("%d", &valor);
    limparBuffer();              /* sempre limpa o resto da linha */
    if (r != 1) return -1;       /* nao conseguiu ler um numero */
    return valor;
}

/* Le uma linha de texto (aceita espacos) e remove o '\n' do final. */
void lerTexto(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    } else {
        destino[0] = '\0';
    }
}

/* ===================== Submenus ===================== */

void menuArsenal(const Arma arsenal[], int total) {
    int op;
    do {
        printf("\n--- ARSENAL DA GUILDA ---\n");
        printf("1 - Ver catalogo completo\n");
        printf("2 - Ver ordenado por preco (Bubble Sort)\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        op = lerInteiro();
        switch (op) {
            case 1: visualizarCatalogo(arsenal, total); break;
            case 2: listarPorPreco(arsenal, total);     break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

void menuEnfermaria(Fila *f) {
    int op;
    char nome[50];
    do {
        printf("\n--- ENFERMARIA (Fila FIFO) ---\n");
        printf("1 - Adicionar ferido (entra no fim)\n");
        printf("2 - Curar proximo heroi (sai do inicio)\n");
        printf("3 - Ver fila de espera\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        op = lerInteiro();
        switch (op) {
            case 1:
                printf("Nome do heroi ferido: ");
                lerTexto(nome, sizeof(nome));
                if (strlen(nome) == 0) { printf("Nome invalido.\n"); break; }
                adicionarFerido(f, nome);
                break;
            case 2: curarHeroi(f);           break;
            case 3: visualizarEnfermaria(f); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

void menuMural(NoMissao **mural) {
    int op, dif;
    char nome[50];
    do {
        printf("\n--- MURAL DE MISSOES (Lista Encadeada) ---\n");
        printf("1 - Afixar missao (nome + dificuldade 1-5)\n");
        printf("2 - Concluir missao (por nome)\n");
        printf("3 - Buscar por dificuldade\n");
        printf("4 - Ver mural completo\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        op = lerInteiro();
        switch (op) {
            case 1:
                printf("Nome da missao: ");
                lerTexto(nome, sizeof(nome));
                if (strlen(nome) == 0) { printf("Nome invalido.\n"); break; }
                printf("Dificuldade (1 a 5): ");
                dif = lerInteiro();
                if (dif < 1 || dif > 5) { printf("Dificuldade invalida (use 1 a 5).\n"); break; }
                afixarMissao(mural, nome, dif);
                break;
            case 2:
                printf("Nome da missao a concluir: ");
                lerTexto(nome, sizeof(nome));
                if (strlen(nome) == 0) { printf("Nome invalido.\n"); break; }
                concluirMissao(mural, nome);
                break;
            case 3:
                printf("Nivel de dificuldade (1 a 5): ");
                dif = lerInteiro();
                if (dif < 1 || dif > 5) { printf("Nivel invalido.\n"); break; }
                buscarPorDificuldade(*mural, dif);
                break;
            case 4: visualizarMural(*mural); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

/* ===================== Programa principal ===================== */

int main(void) {
    /* Modulo 1: vetor estatico de structs */
    Arma arsenal[MAX_ARMAS];
    int  totalArmas;
    inicializarArsenal(arsenal, &totalArmas);

    /* Modulo 2: fila dinamica (enfermaria) */
    Fila enfermaria;
    inicializarFila(&enfermaria);

    /* Modulo 3: lista encadeada (mural) - comeca vazia */
    NoMissao *mural = NULL;

    int op;
    do {
        printf("\n========== TAVERNA DA GUILDA - MENU PRINCIPAL ==========\n");
        printf("1 - Arsenal da Guilda\n");
        printf("2 - Enfermaria\n");
        printf("3 - Mural de Missoes\n");
        printf("0 - Fechar Sistema (com faxina de memoria)\n");
        printf("Escolha: ");
        op = lerInteiro();
        switch (op) {
            case 1: menuArsenal(arsenal, totalArmas); break;
            case 2: menuEnfermaria(&enfermaria);      break;
            case 3: menuMural(&mural);                break;
            case 0:
                /* Modulo 4 - A Faxina: libera tudo que sobrou antes de sair */
                printf("\nFazendo a faxina da Taverna...\n");
                limparEnfermaria(&enfermaria);
                limparMural(&mural);
                printf("Memoria limpa. Ate a proxima, aventureiro!\n");
                break;
            default:
                printf("Opcao invalida! Tente de novo.\n");
        }
    } while (op != 0);

    return 0;
}
