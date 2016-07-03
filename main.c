#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include "Radio.h"

// MENU
void menu (Radio estacion_de_radio){
    int op;
    system("cls");
    do{

    diseno();
    textcolor(WHITE);
    gotoxy(30,26);
    printf("[1] Registro de clientes para publicidad");
    gotoxy(30,28);
    printf("[2] Control de usuarios");
    gotoxy(30,30);
    printf("[3] Buscar cliente");
    gotoxy(30,32);
    printf("[4] Gestion de planes y pagos de publicidad");
    gotoxy(30,34);
    printf("[5] Modificar cliente");
    gotoxy(30,36);
    printf("[6] Listado de clientes");
    gotoxy(30,38);
    printf("[7] Salir");
    gotoxy(30,40);
    textcolor(YELLOW);
    printf("Ingrese la opcion:");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: break;
        case 2: controlDeUsuarios(estacion_de_radio); break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: exit(0);
        default : gotoxy(50,40);
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while((int)op<1 || (int)op>7);
}

int main ()
{
    Radio mi_estacion;
    mi_estacion=inicializarListas(mi_estacion);

    //AQUI FALTAN DOS PASOS
    diseno();
    menu(mi_estacion);
    free(mi_estacion.lista_de_locutores);
     return 0;
}
