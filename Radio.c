//AQUI ESTARAN LAS FUNCIONES DE LA LIBRERIA
#include "Radio.h"

void pausar(){
	printf("\n");
    printf("\t \t \t \t \t PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}

//INICIALIZAR LA LISTA
Radio inicializarListas(Radio estacion_de_radio)
{
    estacion_de_radio.lista_de_locutores=NULL;
    estacion_de_radio.lista_de_secretarias=NULL;
    return estacion_de_radio;
}

void guardarLocutor(Locutor *nuevoLocutor){
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"ab");
	if(!file){
		printf("No se ha podido abrir el archivo para guardar Locutor\n");
			pausar();
			exit(1);
	}else{
		fwrite(nuevoLocutor, sizeof(Locutor), 1,file);
	}
	fclose(file);
}

Locutor * ingresarLocutorALaLista(Radio estacion_de_radio, Locutor *nuevoLocutor){
	Locutor *listaAuxiliar;
	nuevoLocutor->sig=NULL;
	if(!estacion_de_radio.lista_de_locutores){
		estacion_de_radio.lista_de_locutores=nuevoLocutor;
			guardarLocutor(nuevoLocutor);
	}
	else{
		listaAuxiliar=estacion_de_radio.lista_de_locutores;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		listaAuxiliar->sig=nuevoLocutor;
			guardarLocutor(nuevoLocutor);
	}
	return estacion_de_radio.lista_de_locutores;
}


Locutor * registroLocutor(Radio estacion_de_radio){
	system("cls");
	char nombre[MAX_NOMBRE],apellido[MAX_APELLIDO];
    int edad, cedula, sueldo;
    Locutor *nuevoLocutor;
    nuevoLocutor=(Locutor*)malloc(sizeof(Locutor));
    FILE * file=fopen(ARCHIVO_LOCUTORES,"rb");
    if(!nuevoLocutor){
    	printf("No se ha podido reservar memoria para el nuevo locutor\n");
    	pausar();
    	exit(1);
    }
    else{

    static int id=0;
    while(fread(nuevoLocutor, sizeof(Locutor),1, file))
    	id=nuevoLocutor->empleado_locutor.id;
    printf("Ingrese el nombre del nuevo locutor: \n");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese el apellido del nuevo locutor: \n");
    fflush(stdin);
    gets(apellido);

    printf("Ingrese la cedula del locutor \n");
    scanf("%i",&cedula);

    printf("Ingrese la edad del nuevo locutor: \n");
    scanf("%i",&edad);

    printf("Ingrese el sueldo del nuevo locutor: \n");
    scanf("%i",&sueldo);
    id++;
    strcpy(nuevoLocutor->persona_locutor.nombre,nombre);
	strcpy(nuevoLocutor->persona_locutor.apellido,apellido);
	nuevoLocutor->persona_locutor.edad=edad;
	nuevoLocutor->persona_locutor.cedula=cedula;
	nuevoLocutor->empleado_locutor.sueldo=sueldo;
	nuevoLocutor->empleado_locutor.id=id;
	nuevoLocutor->empleado_locutor.activo=1;
	nuevoLocutor->sig=NULL;
    estacion_de_radio.lista_de_locutores = ingresarLocutorALaLista( estacion_de_radio,nuevoLocutor);
    }
    printf("\t \t \t LOCUTOR REGISTRADO PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
    return estacion_de_radio.lista_de_locutores;
}

void mostrarListaDeLocutores(Radio estacion_de_radio)
{
    system("cls");
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"rb");
	Locutor *locutorALeer;

	locutorALeer=(Locutor*)malloc(sizeof(Locutor));
	 if(!file){
	 	system("cls");
		printf("La lista esta vacia\n");
	 }else{
	 	 printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
	 	 while(fread(locutorALeer, sizeof(Locutor),1, file)){
	 	   printf("%-10s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",locutorALeer->empleado_locutor.id,
	       locutorALeer->persona_locutor.nombre,
	       locutorALeer->persona_locutor.apellido,
	       locutorALeer->persona_locutor.cedula,
	       locutorALeer->persona_locutor.edad,
	       locutorALeer->empleado_locutor.sueldo,
	       "Nombre del programa");
	    }
	}
	printf("\n");
	printf("\t \t \t \t  PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}



void controlDeUsuarios(Radio estacion_de_radio)
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
        case 1: estacion_de_radio.lista_de_locutores= registroLocutor(estacion_de_radio); break;
        case 2: //registroSecretaria(estacion_de_radio);break;
        case 3: //eliminarLocutor(estacion_de_radio);break;
        case 4: break;
        case 5: mostrarListaDeLocutores(estacion_de_radio); break;
        case 6: //mostrarListaDeSecretarias(estacion_de_radio);break;
        case 7: menu(); break;
        default : gotoxy(30,40);
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while(op!=7);

}


/*void eliminarLocutor(Radio estacion_de_radio)
{
    int cedula;
    system("cls");
    Locutor *cabezaAuxiliar, *nodoAnterior;
    //SE SOLICITA LA CEDULA DEL LOCUTOR A ELIMINAR
    printf("Introduzca la cedula del locutor a eliminar \n");
    scanf("%i",&cedula);
    //SE USA UNA CABEZA DE LISTA AUXILIAR PARA RECORRER LA LISTA Y SE INICIALIZA EN LA LISTA A RECORRER
    cabezaAuxiliar=estacion_de_radio.lista_de_locutores;
    while(cabezaAuxiliar){
            //SI ALGUN LOCUTOR TIENE REGISTRADA ESA CEDULA QUE SALGA DEL BUCLE
        if(cabezaAuxiliar->persona_locutor.cedula==cedula)
            break;
        //LOCUTOR ANTERIOR
        nodoAnterior=cabezaAuxiliar;
        //PARA RECORRER LA LISTA SE DIRECCIONA LA CABEZA AUXILIAR AL PROXIMO LOCUTOR DE LA LISTA
        cabezaAuxiliar=cabezaAuxiliar->sig;
    }
    //SI EXISTE EL LOCUTOR CON LA CEDULA
    if(cabezaAuxiliar){
        //SI ES EL PRIMER LOCUTOR
        if(cabezaAuxiliar==estacion_de_radio.lista_de_locutores)
           estacion_de_radio.lista_de_locutores=cabezaAuxiliar->sig;

        else{
            nodoAnterior->sig=cabezaAuxiliar->sig;
            free(cabezaAuxiliar);
        }
        printf("Locutor despedido\n");
    }
    else{
        printf("Lo siento no se ha encontrado un locutor registrado con esa cedula\n");
    }

    printf("PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);
}
*/
