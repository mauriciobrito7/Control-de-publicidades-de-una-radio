#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include "Radio.h"
#define ARCHIVO_LOCUTORES "Locutores/Locutores.bin"
#define MAX_NOMBRE 30
#define MAX_APELLIDO 50

void menu (Radio *estacion_de_radio);
void controlDeUsuarios(Radio *estacion_de_radio);

int main ()
{
    //INSTANCIAR RADIO QUE CONTIENE TODAS LAS ESTRUCTURAS
	Radio mi_estacion_de_radio;
	//CARGAR LA LISTA CON LOS REGISTROS DEL ARCHIVO
	//cargarListaLocutores(&mi_estacion_de_radio);
	iniciarListas(&mi_estacion_de_radio);
	menu(&mi_estacion_de_radio);
	pausar();
	return 0;
}

// MENU
void menu (Radio *estacion_de_radio){
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
        case 7: eliminarListaLocutor(estacion_de_radio);
				free(estacion_de_radio->lista_de_locutores);
        		exit(1);
        default :
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while(op!=7);
}

void controlDeUsuarios(Radio *estacion_de_radio)
{
    int op;
    do{
    system("cls");
    textcolor(WHITE);
    printf("[1] Registro de locutores \n");
    printf("[2] Registro de secretaria \n");
    printf("[3] Modificar registro de locutor \n");
    printf("[4] Modificar registro de secretaria \n");
    printf("[5] Mostrar listado de locutores \n");
    printf("[6] Mostrar listado de secretarias \n");
    printf("[7] Menu principal \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion:");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: registroLocutor(estacion_de_radio); break;
        case 2: //registroSecretaria(estacion_de_radio);break;
        case 3: //eliminarLocutor(estacion_de_radio);break;
        case 4: break;
        case 5: mostrarListaDeLocutores(estacion_de_radio); break;
        case 6: //mostrarListaDeSecretarias(estacion_de_radio);break;
        case 7: menu(estacion_de_radio); break;
        default : gotoxy(30,40);
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while(op!=7);

}
