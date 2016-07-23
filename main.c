#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include "Radio.h"


void menu (Radio *estacion_de_radio);

int main ()
{
    //INSTANCIAR RADIO QUE CONTIENE TODAS LAS ESTRUCTURAS
	Radio mi_estacion_de_radio;
	//CARGAR LA LISTA CON LOS REGISTROS DEL ARCHIVO DE LOCUTOR
	iniciarListas(&mi_estacion_de_radio);
	cargarListaLocutores(&mi_estacion_de_radio);
	//MENU PRINCIPAL
	menu(&mi_estacion_de_radio);
	return 0;
}

// MENU
void menu (Radio *estacion_de_radio){
    char op;

    do{
    system("cls");
    textcolor(WHITE);
    printf("[1] Gestion de clientes para la publicidad \n");
    printf("[2] Gestion de usuarios de la radio\n");
    printf("[3] Gestion de planes de las publicidades \n");
    printf("[4] Listado de clientes \n");
    printf("[5] Salir \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion: ");
    textcolor(WHITE);fflush(stdin);op=getchar();

    switch(op){
        case 49: break;
        case 50: controlDeUsuarios(estacion_de_radio); break;
        case 51: break;
        case 52: break;
        case 53: eliminarListaLocutor(estacion_de_radio);
				free(estacion_de_radio->lista_de_locutores);
        		exit(1);
        default : mensajePorDefecto();
    }
    }while(op!=53);
}

