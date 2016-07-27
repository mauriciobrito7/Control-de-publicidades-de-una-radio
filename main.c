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
	cargarListaClientes(&mi_estacion_de_radio);
	cargarListaProgramas(&mi_estacion_de_radio);
	cargarListaLocutores(&mi_estacion_de_radio);
	cargarListaSecretarias(&mi_estacion_de_radio);

	mi_estacion_de_radio.lista_de_programas->lista_locutores=NULL;
	//MENU PRINCIPAL
	menu(&mi_estacion_de_radio);
	return 0;
}

// MENU
void menu (Radio *estacion_de_radio){
    char op;

    do{
    system("cls");
    textcolor(LIGHTBLUE);
    printf("--SYSTEMA DE GESTION DE LA RADIO--\n");
    textcolor(WHITE);
    printf("[1] Gestion de clientes para la publicidad \n");
    printf("[2] Gestion de usuarios de la radio\n");
    printf("[3] Gestion de planes de las publicidades \n");
    printf("[4] Listado de publicidades \n");
    printf("[5] Reportes \n");
    printf("[6] Salir \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion: ");
    textcolor(WHITE);fflush(stdin);op=getche();

    switch(op){
        case 49: controlDeClientes(estacion_de_radio); break;
        case 50: controlDeUsuarios(estacion_de_radio); break;
        case 51: controlDeProgramas(estacion_de_radio); break;
        case 52: mostrarListaDeProgramas(estacion_de_radio); break;
        case 53: mostrarReportes(estacion_de_radio); break;
        case 54:
                 eliminarListaClientes(estacion_de_radio);
                 eliminarListaLocutor(estacion_de_radio);
                 eliminarListaSecretarias(estacion_de_radio);
                 eliminarListaProgramas(estacion_de_radio);
				 free(estacion_de_radio->lista_de_locutores);
				 free(estacion_de_radio->lista_de_secretarias);
				 free(estacion_de_radio->lista_de_clientes);
				 free(estacion_de_radio->lista_de_programas);
        		 exit(1);
        default : mensajePorDefecto();
    }
    }while(op!=54);
}

