#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include "Radio.h"
#define ARCHIVO_LOCUTORES "Locutores/Locutores.bin"
#define MAX_NOMBRE 30
#define MAX_APELLIDO 50
// MENU
void menu (Radio estacion_de_radio){
    int op;

    do{
    system("cls");
    textcolor(WHITE);
    printf("[1] Registro de clientes para publicidad \n");
    printf("[2] Control de usuarios \n");
    printf("[3] Buscar cliente \n");
    printf("[4] Gestion de planes y pagos de publicidad \n");
    printf("[5] Modificar cliente \n");
    printf("[6] Listado de clientes \n");
    printf("[7] Salir \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion: ");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: break;
        case 2: controlDeUsuarios(estacion_de_radio); break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: exit(1);
        default :
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while(op!=7);
}

int main ()
{
    //Instaciamos nuestra estación de radio
    Radio mi_estacion;
    //Inicializamos todas las listas que tenga la radio
    mi_estacion=inicializarListas(mi_estacion);

    //Luego cargariamos los datos en las listas!!

    //Iniciamos el programa llamando al menu
    menu(mi_estacion);
    //Liberamos toda la memoria reservada para la estacion de radio
    free(mi_estacion.lista_de_locutores);
     return 0;
}
