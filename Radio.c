//AQUI ESTARAN LAS FUNCIONES DE LA LIBRERIA
#include "Radio.h"

void pausar(){
	printf("\n");
    printf("\t \t \t \t \t PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}

void errorCritico()
{
  printf("No se ha podido reservar memoria\n");
  getch();
  exit(1);
}

void mensajePorDefecto()
{
    textcolor(RED);
    printf("%cLa opcion que ingreso no es correcta!",173);
    Sleep(1000);
}

//INICIALIZAR LA LISTA
void iniciarListas(Radio *estacion_de_radio){
	estacion_de_radio->lista_de_locutores=NULL;
	estacion_de_radio->lista_de_secretarias=NULL;
}

void cargarListaLocutores(Radio *estacion_de_radio){
	//INICIO LA LISTA DE LOCUTORES EN NULL
	system("cls");
	//TRATO DE LEER EL ARCHIVO PARA CARGAR LAS LISTAS
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"rb+");
	//SI NO SE PUDO LEER ES PORQUE NO EXISTE
	 if(!file){
	 	system("cls");
		printf("El archivo esta vacio\n");
		pausar();
	 }else{
	 	Locutor *locutorALeer;
	 	rewind(file);
        locutorALeer=(Locutor*)malloc(sizeof(Locutor));

	 //DE OTRA MANERA MIENTRAS VAYA LEYENDO EL LOCUTOR QUE LO VAYA INGRENSANDO EN LA LISTA
        while(fread(locutorALeer, sizeof(Locutor),1, file)){
	        ingresarLocutorALaLista(estacion_de_radio,locutorALeer);
            locutorALeer=(Locutor*)malloc(sizeof(Locutor));
        }
	 }
	 fclose(file);
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
    printf("[7] Mostrar due%co \n",164);
    printf("[8] Menu principal \n");
    textcolor(YELLOW);
    printf("Ingrese la opcion:");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: registroLocutor(estacion_de_radio); break;
        case 2: registroSecretaria(estacion_de_radio);break;
        case 3: modificarRegistroLocutor(estacion_de_radio); break;
        case 4: mostrarListaDeLocutores2(estacion_de_radio); break;
        case 5: mostrarListaDeLocutores(); break;
        case 6: mostrarListaDeSecretarias();break;
        case 7: break;
        case 8: menu(estacion_de_radio); break;
        default : mensajePorDefecto();
    }
    }while(op!=8);

}

static void guardarLocutor(Locutor *nuevoLocutor){
	FILE *file;

	file=fopen(ARCHIVO_LOCUTORES,"ab");
	if(!file){
		errorCritico();
	}else{
		fwrite(nuevoLocutor, sizeof(Locutor), 1,file);
	}
	fclose(file);
}

static void guardarSecretaria(Secretaria *nuevaSecretaria){
	FILE *file;

	file=fopen(ARCHIVO_SECRETARIAS,"ab");
	if(!file){
		errorCritico();
	}else{
		fwrite(nuevaSecretaria, sizeof(Secretaria), 1,file);
	}
	fclose(file);
}

static void ingresarLocutorALaLista(Radio *estacion_de_radio, Locutor *nuevoLocutor){
	if(!estacion_de_radio->lista_de_locutores){
		estacion_de_radio->lista_de_locutores=nuevoLocutor;
	}
	else{
		Locutor *listaAuxiliar;
		listaAuxiliar=estacion_de_radio->lista_de_locutores;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		listaAuxiliar->sig=nuevoLocutor;

	}
}

static void ingresarSecretariaALaLista(Radio *estacion_de_radio, Secretaria *nuevaSecretaria){
	if(!estacion_de_radio->lista_de_secretarias){
		estacion_de_radio->lista_de_secretarias=nuevaSecretaria;
	}
	else{
		Locutor *listaAuxiliar;
		listaAuxiliar=estacion_de_radio->lista_de_secretarias;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		listaAuxiliar->sig=nuevaSecretaria;

	}
}

void registroLocutor(Radio *estacion_de_radio){
	system("cls");

    Locutor *nuevoLocutor;
    nuevoLocutor=(Locutor*)calloc(1,sizeof(Locutor));

    if(!nuevoLocutor){
    	errorCritico();
    }
    else{
    	FILE * file=fopen(ARCHIVO_LOCUTORES,"rb");
	    int id=0;

	    fseek(file,(sizeof(Locutor)*(-1)),SEEK_END);
	    if(fread(nuevoLocutor,sizeof(Locutor),1,file))
	    	id=nuevoLocutor->empleado_locutor.id;

	    printf("Ingrese el nombre del nuevo locutor: \n");
	    fflush(stdin);
	    gets(nuevoLocutor->persona_locutor.nombre);

	    printf("Ingrese el apellido del nuevo locutor: \n");
	    fflush(stdin);
	    gets(nuevoLocutor->persona_locutor.apellido);

	    printf("Ingrese la cedula del locutor \n");
	    scanf("%i",&nuevoLocutor->persona_locutor.cedula);

	    printf("Ingrese la edad del nuevo locutor: \n");
	    scanf("%i",&nuevoLocutor->persona_locutor.edad);

	    printf("Ingrese el sueldo del nuevo locutor: \n");
	    scanf("%i",&nuevoLocutor->empleado_locutor.sueldo);
	    id++;
		nuevoLocutor->empleado_locutor.id=id;
		nuevoLocutor->empleado_locutor.activo=1;
		nuevoLocutor->sig=NULL;
		fclose(file);
	    ingresarLocutorALaLista(estacion_de_radio,nuevoLocutor);
	    guardarLocutor(nuevoLocutor);
    }
}

Locutor * buscarLocutor(Radio * estacion_de_radio,Locutor *locutorAModificar){

        int op=0;
        do{
        system("cls");
        textcolor(WHITE);
        printf("[1] Buscar por ID\n");
        printf("[2] Buscar por Cedula\n");
        printf("[3] Buscar por Nombre\n");
        textcolor(YELLOW);
        printf("Ingrese la opcion: ");
        textcolor(WHITE);scanf("%i",&op);

        switch(op){
            case 1: break;
            case 2: system("cls");
                    int cedula;
                    printf("Ingresar Cedula: \n");
                    scanf("%i",&cedula);
                    //Para recorrer la lista
                    locutorAModificar=estacion_de_radio->lista_de_locutores;
                    while(locutorAModificar){
                        if(locutorAModificar->persona_locutor.cedula==cedula){
                            return locutorAModificar;
                        }
                        locutorAModificar=locutorAModificar->sig;
                    }
                    printf("No hay ningun Locutor registrado con esa Cedula\n");
                    pausar();
                    return 0;
                    break;

            case 3: system("cls");
                    char nombre[30];
                    printf("Ingresar Nombre: \n");
                    fflush(stdin);
                    gets(nombre);
                    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
                    int i=1, encontrado=0;
                    locutorAModificar=estacion_de_radio->lista_de_locutores;
                    while(locutorAModificar){
                        if(strcmpi(locutorAModificar->persona_locutor.nombre,nombre)==0){
                            printf("[%i] %-6s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n",i," ",locutorAModificar->empleado_locutor.id,
                            locutorAModificar->persona_locutor.nombre,
                            locutorAModificar->persona_locutor.apellido,
                            locutorAModificar->persona_locutor.cedula,
                            locutorAModificar->persona_locutor.edad,
                            locutorAModificar->empleado_locutor.sueldo,
                            "Nombre del programa");
                            i++;
                            encontrado=1;
                            }
                            locutorAModificar=locutorAModificar->sig;
                        }

                    if(encontrado){
                        do{
                            textcolor(YELLOW);
                            printf("Ingrese el locutor a elegir: "); textcolor(WHITE);scanf("%i", &op);
                          }while(op>=i || op<0);
                        locutorAModificar=estacion_de_radio->lista_de_locutores;
                        while(locutorAModificar){
                            if(strcmpi(locutorAModificar->persona_locutor.nombre,nombre)==0)
                                --op;
                            if(op==0){
                                pausar();
                                return locutorAModificar;
                              }
                            locutorAModificar=locutorAModificar->sig;
                          }
                      }
                    printf("No hay ningun Locutor registrado con ese Nombre\n");
                    pausar();
                    return 0;
                    break;
            default : mensajePorDefecto(); break;
        }
        }while(op!=3);

}

static Locutor * eliminarLocutor(Radio *estacion_de_radio, Locutor *locutorAModificar)
{
    Locutor *nodoAnterior, *cabezaAuxiliar=estacion_de_radio->lista_de_locutores;
    while(cabezaAuxiliar){
            //SI ALGUN LOCUTOR TIENE REGISTRADA ESA CEDULA QUE SALGA DEL BUCLE
        if(cabezaAuxiliar->persona_locutor.cedula==locutorAModificar->persona_locutor.cedula)
            break;
        //LOCUTOR ANTERIOR
        nodoAnterior=cabezaAuxiliar;
        //PARA RECORRER LA LISTA SE DIRECCIONA LA CABEZA AUXILIAR AL PROXIMO LOCUTOR DE LA LISTA
        cabezaAuxiliar=cabezaAuxiliar->sig;
    }
    //SI EXISTE EL LOCUTOR CON LA CEDULA
    if(cabezaAuxiliar){
        //SI ES EL PRIMER LOCUTOR
        if(cabezaAuxiliar==estacion_de_radio->lista_de_locutores)
           estacion_de_radio->lista_de_locutores=cabezaAuxiliar->sig;

        else{
            nodoAnterior->sig=cabezaAuxiliar->sig;
            free(cabezaAuxiliar);
        }
        printf("Locutor despedido\n");
    }
    return estacion_de_radio->lista_de_locutores;
}

static void modificarRegistroLocutor(Radio * estacion_de_radio){
    system("cls");
    if(estacion_de_radio->lista_de_locutores){
            Locutor *locutorAModificar;
            locutorAModificar=(Locutor*)malloc(sizeof(Locutor));
            locutorAModificar->sig=NULL;
        //FUNCION DE  BUSQUEDA DEL LOCUTOR A PROCESAR
        if(locutorAModificar=buscarLocutor(estacion_de_radio,locutorAModificar)){
            int op=0;
            system("cls");
            do{
                //OPCIONES DE MODIFICACIÓN DEL LOCUTOR
                textcolor(WHITE);
                printf("[1] Modificar sueldo base\n");
                printf("[2] Despedir Locutor\n");
                printf("[3] Cancelar\n");
                textcolor(YELLOW);
                printf("Ingrese la opcion: ");
                textcolor(WHITE);scanf("%i",&op);
                FILE *file;
                switch(op){
                   //MODIFICAR EL SUELDO BASE DEL LOCUTOR
                    case 1:
                            file=fopen(ARCHIVO_LOCUTORES,"r+b");
                            if(!file){
                             errorCritico();
                            }else{
                                system("cls");
                                printf("Ingrese el nuevo sueldo para el locutor %s:",locutorAModificar->persona_locutor.nombre);
                                scanf("%i",&locutorAModificar->empleado_locutor.sueldo);
                                fseek(file,(sizeof(Locutor)*(locutorAModificar->empleado_locutor.id))-sizeof(Locutor),0);
                                    fwrite(locutorAModificar,sizeof(Locutor),1,file);
                                printf("Locutor Modificado..\n");
                                fclose(file);
                                getch(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //DESPEDIR LOCUTOR
                    case 2: //SE ABRE EN MODO W PARA QUE SOBREESCRIBA
                            file=fopen(ARCHIVO_LOCUTORES,"w");
                            if(!file){
                             errorCritico();
                            }else{
                                system("cls");
                                estacion_de_radio->lista_de_locutores=eliminarLocutor(estacion_de_radio,locutorAModificar);
                                Locutor *aux=estacion_de_radio->lista_de_locutores;
                                int id=1;
                                rewind(file);
                                while(aux){
                                    aux->empleado_locutor.id=id;
                                    fwrite(aux,sizeof(Locutor),1,file);
                                    id++;
                                    aux=aux->sig;
                                }
                                printf("Locutor Modificado..\n");
                                fclose(file);
                                pausar(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //REGRESAR AL MENU PRINCIPAL
                    case 3: menu(estacion_de_radio); break;
                    default : mensajePorDefecto(); break;
                }
            }while(op!=3);
        }
    }else{
        printf("No hay registros en el archivo");
        pausar();
    }

}

void registroSecretaria(Radio *estacion_de_radio){
	system("cls");

    Secretaria *nuevaSecretaria;
    nuevaSecretaria=(Secretaria*)calloc(1,sizeof(Secretaria));

    if(!nuevaSecretaria){
    	errorCritico();
    }
    else{
    	FILE * file=fopen(ARCHIVO_SECRETARIAS,"rb");
	    int id=0;

	    fseek(file,(sizeof(Secretaria)*(-1)),SEEK_END);
	    if(fread(nuevaSecretaria,sizeof(Secretaria),1,file))
	    	id=nuevaSecretaria->empleado_secretaria.id;

	    printf("Ingrese el nombre del nueva Secretaria: \n");
	    fflush(stdin);
	    gets(nuevaSecretaria->persona_secretaria.nombre);

	    printf("Ingrese el apellido del nueva Secretaria: \n");
	    fflush(stdin);
	    gets(nuevaSecretaria->persona_secretaria.apellido);

	    printf("Ingrese la cedula del Secretaria \n");
	    scanf("%i",&nuevaSecretaria->persona_secretaria.cedula);

	    printf("Ingrese la edad del nueva Secretaria: \n");
	    scanf("%i",&nuevaSecretaria->persona_secretaria.edad);

	    printf("Ingrese el sueldo del nueva Secretaria: \n");
	    scanf("%i",&nuevaSecretaria->empleado_secretaria.sueldo);
	    id++;
		nuevaSecretaria->empleado_secretaria.id=id;
		nuevaSecretaria->empleado_secretaria.activo=1;
		nuevaSecretaria->sig=NULL;
		fclose(file);
	    ingresarSecretariaALaLista(estacion_de_radio,nuevaSecretaria);
	    guardarSecretaria(nuevaSecretaria);
    }
}

void mostrarListaDeLocutores(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"rb");
	Locutor locutorALeer;

	printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
	while(fread(&locutorALeer, sizeof(Locutor),1, file)){
	 	printf("%-10s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",locutorALeer.empleado_locutor.id,
	    locutorALeer.persona_locutor.nombre,
	    locutorALeer.persona_locutor.apellido,
	    locutorALeer.persona_locutor.cedula,
	    locutorALeer.persona_locutor.edad,
	    locutorALeer.empleado_locutor.sueldo,
	    "Nombre del programa");
	}
	printf("\n");
	printf("\t \t \t \t  PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}

//MOSTRAR LISTA ENLAZADA
void mostrarListaDeLocutores2(Radio *estacion_de_radio){
	Locutor *listaAuxiliar;

	listaAuxiliar=estacion_de_radio->lista_de_locutores;
	system("cls");
	printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
	while(listaAuxiliar){
		printf("%-10s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",listaAuxiliar->empleado_locutor.id,
	    listaAuxiliar->persona_locutor.nombre,
	    listaAuxiliar->persona_locutor.apellido,
	    listaAuxiliar->persona_locutor.cedula,
	    listaAuxiliar->persona_locutor.edad,
	    listaAuxiliar->empleado_locutor.sueldo,
	    "Nombre del programa");
		listaAuxiliar=listaAuxiliar->sig;
	}
	printf("\n");
	printf("\t \t \t \t  PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}

void mostrarListaDeSecretarias(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_SECRETARIAS,"rb");
	Secretaria secretariaALeer;

	printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
	while(fread(&secretariaALeer, sizeof(Locutor),1, file)){
	 	printf("%-10s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",secretariaALeer.empleado_secretaria.id,
	    secretariaALeer.persona_secretaria.nombre,
	    secretariaALeer.persona_secretaria.apellido,
	    secretariaALeer.persona_secretaria.cedula,
	    secretariaALeer.persona_secretaria.edad,
	    secretariaALeer.empleado_secretaria.sueldo,
	    "Nombre del programa");
	}
	printf("\n");
	printf("\t \t \t \t  PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
}

void eliminarListaLocutor(Radio * estacion_de_radio){
	Locutor *listaAuxiliar;
	while(estacion_de_radio->lista_de_locutores){
		listaAuxiliar=estacion_de_radio->lista_de_locutores;
		estacion_de_radio->lista_de_locutores=estacion_de_radio->lista_de_locutores->sig;
		free(listaAuxiliar);
	}
}

