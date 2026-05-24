#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulo1"

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