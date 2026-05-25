#include <stdio.h>
#include "modulo1"

int opc;

void menu_principal(){  
    do{
        printf("\n\nQual o modulo que deseja acessar:\n1-arsenal da guilda\n2-fila da enfermaria\n3-Mural de Missões\n4- Fechamento da Taverna\n0-sair do sistema\nescolha: ");
        scanf(" %d", &opc);

        switch(opc){
            case 1:
                printf("\nAbrindo arsenal da guilda...\n");
                arsenal();
            break;

            case 2:

            break;

            case 0:
                opc == 0;
            break;

            default:
                printf("\nopção invalida...\n");
            break;
        }
    }while(opc !=0);
}

int main(void)
{
    menu_principal();

    return 0;
}