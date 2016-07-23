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

int buscarLocutor(Locutor *locutorAModificar){
    FILE * file;
    file=fopen(ARCHIVO_LOCUTORES, "rb");
    if(!file){
        printf("No hay registros en el archivo\n");
        pausar();
    }else{
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
                    while(fread(locutorAModificar,sizeof(Locutor),1,file)){
                        if(locutorAModificar->persona_locutor.cedula==cedula){
                            fclose(file);
                            return 1;
                        }
                    }
                    printf("No hay ningun Locutor registrado con esa Cedula\n");
                    break;
            case 3:     system("cls");
                        char nombre[30];
                        printf("Ingresar Nombre: \n");
                        fflush(stdin);
                        gets(nombre);
                        printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
                        int i=1, encontrado=0;
                        while(fread(locutorAModificar,sizeof(Locutor),1,file)){
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
                        }

                      if(encontrado){
                          do{
                          textcolor(YELLOW);
                          printf("Ingrese el locutor a elegir: "); textcolor(WHITE);scanf("%i", &op);
                          }while(op>=i || op<0);
                          rewind(file);
                          while(fread(locutorAModificar,sizeof(Locutor),1,file)){
                              if(strcmpi(locutorAModificar->persona_locutor.nombre,nombre)==0)
                                  --op;
                              if(op==0){
                                fclose(file);
                                return 1;
                              }
                          }
                      }
                      fclose(file);
                      pausar();
                      return 1;
                      printf("No hay ningun Locutor registrado con ese Nombre\n");
                      break;
            default : mensajePorDefecto(); break;
        }
        pausar();
        fclose(file);
        return NULL;
        }while(op!=3);

    }

}

void modificarRegistroLocutor(Radio * estacion_de_radio){
    Locutor locutorAModificar;
    FILE *file;
    if(buscarLocutor(&locutorAModificar)){
        int op=0;
        do{
            system("cls");
            textcolor(WHITE);
            printf("[1] Modificar sueldo base\n");
            printf("[2] Despedir Locutor\n");
            printf("[3] Cancelar\n");
            textcolor(YELLOW);
            printf("Ingrese la opcion: ");
            textcolor(WHITE);scanf("%i",&op);

            switch(op){
                case 1:
                        file=fopen(ARCHIVO_LOCUTORES,"r+b");
                        if(!file){
                         errorCritico();
                        }else{
                            system("cls");
                            printf("Ingrese el nuevo sueldo para el locutor %s:",locutorAModificar.persona_locutor.nombre);
                            scanf("%i",&locutorAModificar.empleado_locutor.sueldo);
                            fseek(file,(sizeof(Locutor)*(locutorAModificar.empleado_locutor.id))-sizeof(Locutor),0);
                                fwrite(&locutorAModificar,sizeof(Locutor),1,file);
                            printf("Locutor Modificado..\n");
                            fclose(file);
                            getch(); controlDeUsuarios(estacion_de_radio); break;
                        }
                case 3: menu(estacion_de_radio); break;
                default : mensajePorDefecto(); break;
            }
        }while(op!=3);
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
