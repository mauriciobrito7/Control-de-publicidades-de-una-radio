//AQUI ESTARAN LAS FUNCIONES DE LA LIBRERIA
#include "Radio.h"

void pausar(){
	printf("\n");
    printf("\t \t \t \t \t PRESIONA CUALQUIER TECLA PARA CONTINUAR...");
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
    printf("\n %cLa opcion que ingreso no es correcta!",173);
    Sleep(1000);
}

//INICIALIZAR LA LISTA
void iniciarListas(Radio *estacion_de_radio){
    //SE INICIAN TODAS LAS LISTAS DE LA ESTACIÓN DE RADIO
	estacion_de_radio->lista_de_locutores=NULL;
	estacion_de_radio->lista_de_secretarias=NULL;
	estacion_de_radio->lista_de_clientes=NULL;
	estacion_de_radio->lista_de_programas=NULL;
	//estacion_de_radio->lista_de_programas->lista_locutores=NULL;
}

void cargarListaClientes(Radio *estacion_de_radio){
	system("cls");
	//CREAR ARCHIVO O ABRIR PARA LA LECTURA
	FILE *file;
	file=fopen(ARCHIVO_CLIENTES,"r");
	//SI NO SE PUDO LEER ES PORQUE NO EXISTE
	 if(!file){
	 	system("cls");
		printf("El archivo de los clientes esta vacio\n");
		pausar();
	 }else{
	    //LOCUTOR GENERAL QUE SE USARA PARA LEER CADA LOCUTOR QUE HAY EN EL ARCHIVO
	 	Cliente *clienteALeer;
	 	//REBOBINAR ARCHIVO
	 	rewind(file);
	 	//RESERVAR MEMORIA PARA LA PRIMERA VEZ QUE USARÁ EL LOCUTOR GENERAL
        clienteALeer=(Cliente*)malloc(sizeof(Cliente));

	 //MIENTRAS VAYA LEYENDO EL LOCUTOR QUE LO VAYA INGRENSANDO EN LA LISTA
        while(fread(clienteALeer, sizeof(Cliente),1, file)){
            //SE INGRESA EL LOCUTOR A LA LISTA DE LOCUTORES DE LA RADIO
	        ingresarClienteALaLista(estacion_de_radio,clienteALeer);
            //SE ASIGNA OTRO ESPACIO DE MEMORIA PARA EL SIGUIENTE LOCUTOR
            //estacion_de_radio->dueno.ingresos=(estacion_de_radio->dueno.ingresos+ clienteALeer->cotizacion);
            clienteALeer=(Cliente*)malloc(sizeof(Cliente));
        }
        //QUE SE LIBERE EL ESPACIO CREADO POR EL LOCUTR
        free(clienteALeer);
	 }
	 //AL TERMINAR EL PROCESO QUE SE CIERRE EL ARCHIVO
	 fclose(file);
}

void cargarListaLocutores(Radio *estacion_de_radio){
	system("cls");
	//CREAR ARCHIVO O ABRIR PARA LA LECTURA
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"r");
	//SI NO SE PUDO LEER ES PORQUE NO EXISTE
	 if(!file){
	 	system("cls");
		printf("El archivo de los locutores esta vacio\n");
		pausar();
	 }else{
	    //LOCUTOR GENERAL QUE SE USARA PARA LEER CADA LOCUTOR QUE HAY EN EL ARCHIVO
	 	Locutor *locutorALeer;
	 	//REBOBINAR ARCHIVO
	 	rewind(file);
	 	//RESERVAR MEMORIA PARA LA PRIMERA VEZ QUE USARÁ EL LOCUTOR GENERAL
        locutorALeer=(Locutor*)malloc(sizeof(Locutor));

	 //MIENTRAS VAYA LEYENDO EL LOCUTOR QUE LO VAYA INGRENSANDO EN LA LISTA
        while(fread(locutorALeer, sizeof(Locutor),1, file)){
            //SE INGRESA EL LOCUTOR A LA LISTA DE LOCUTORES DE LA RADIO
	        ingresarLocutorALaLista(estacion_de_radio,locutorALeer);
	        estacion_de_radio->dueno.egresos=(estacion_de_radio->dueno.egresos+ locutorALeer->empleado_locutor.sueldo);
            //SE ASIGNA OTRO ESPACIO DE MEMORIA PARA EL SIGUIENTE LOCUTOR
            locutorALeer=(Locutor*)malloc(sizeof(Locutor));
        }
        //QUE SE LIBERE EL ESPACIO CREADO POR EL LOCUTR
        free(locutorALeer);
	 }
	 //AL TERMINAR EL PROCESO QUE SE CIERRE EL ARCHIVO
	 fclose(file);
}

void cargarListaSecretarias(Radio *estacion_de_radio){
	system("cls");
	//CREAR ARCHIVO O ABRIR PARA LA LECTURA
	FILE *file;
	file=fopen(ARCHIVO_SECRETARIAS,"r");
	//SI NO SE PUDO LEER ES PORQUE NO EXISTE
	 if(!file){
	 	system("cls");
		printf("El archivo de las secretarias esta vacio\n");
		pausar();
	 }else{
	    // GENERAL QUE SE USARA PARA LEER CADA SECRETARIA QUE HAY EN EL ARCHIVO
	 	Secretaria *secretariaALeer;
	 	//REBOBINAR ARCHIVO
	 	rewind(file);
	 	//RESERVAR MEMORIA PARA LA PRIMERA VEZ QUE USARÁ LA SECRETARIA GENERAL
        secretariaALeer=(Secretaria*)malloc(sizeof(Secretaria));

	 //MIENTRAS VAYA LEYENDO LA SECRETARIA QUE LO VAYA INGRENSANDO EN LA LISTA
        while(fread(secretariaALeer, sizeof(Secretaria),1, file)){
            //SE INGRESA EL SECRETARIA A LA LISTA DE SECRETARIAS DE LA RADIO
	        ingresarSecretariaALaLista(estacion_de_radio,secretariaALeer);
            //SE ASIGNA OTRO ESPACIO DE MEMORIA PARA EL SIGUIENTE SECRETARIA
            secretariaALeer=(Secretaria*)malloc(sizeof(Secretaria));
        }
        //QUE SE LIBERE EL ESPACIO CREADO POR LA SECRETARIA
        free(secretariaALeer);
	 }
	 //AL TERMINAR EL PROCESO QUE SE CIERRE EL ARCHIVO
	 fclose(file);
}

void cargarListaProgramas(Radio *estacion_de_radio){
	system("cls");
	//CREAR ARCHIVO O ABRIR PARA LA LECTURA
	FILE *file;
	file=fopen(ARCHIVO_PROGRAMAS,"r");
	//SI NO SE PUDO LEER ES PORQUE NO EXISTE
	 if(!file){
	 	system("cls");
		printf("El archivo de los programas esta vacio\n");
		pausar();
	 }else{
	    // GENERAL QUE SE USARA PARA LEER CADA SECRETARIA QUE HAY EN EL ARCHIVO
	 	Programa *programaALeer;
	 	//REBOBINAR ARCHIVO
	 	rewind(file);
	 	//RESERVAR MEMORIA PARA LA PRIMERA VEZ QUE USARÁ LA SECRETARIA GENERAL
        programaALeer=(Programa*)malloc(sizeof(Programa));

	 //MIENTRAS VAYA LEYENDO LA SECRETARIA QUE LO VAYA INGRENSANDO EN LA LISTA
        while(fread(programaALeer, sizeof(Programa),1, file)){
            //SE INGRESA EL SECRETARIA A LA LISTA DE SECRETARIAS DE LA RADIO
	        ingresarProgramaALaLista(estacion_de_radio,programaALeer);
            //SE ASIGNA OTRO ESPACIO DE MEMORIA PARA EL SIGUIENTE SECRETARIA
            programaALeer=(Programa*)malloc(sizeof(Programa));
        }
        //QUE SE LIBERE EL ESPACIO CREADO POR LA SECRETARIA
        free(programaALeer);
	 }
	 //AL TERMINAR EL PROCESO QUE SE CIERRE EL ARCHIVO
	 fclose(file);
}

void controlDeProgramas(Radio *estacion_de_radio){
    char op;
    do{
        system("cls");
        textcolor(LIGHTBLUE);
        printf("--CONTROL DE PROGRAMAS--\n");
        textcolor(WHITE);
        printf("[1] Registrar de programa\n");
        printf("[2] Modificar programa \n");
        printf("[3] Mostrar listado de programas\n");
        printf("[4] Menu principal \n");
        printf("[5] Salir del programa \n");
        textcolor(YELLOW);
        printf("Ingrese la opcion:");
        textcolor(WHITE);fflush(stdin); op=getche();

        switch(op){
            case 49: registroPrograma(estacion_de_radio); break;
            case 50: //modificarRegistroPrograma(estacion_de_radio);
                        break;
            case 51: mostrarListaDeProgramas(); break;
            case 52: menu(estacion_de_radio); break;
            case 53: salirDelPrograma(estacion_de_radio); exit(1);
            default : mensajePorDefecto();
        }
    }while(op!=53);
}

void controlDeUsuarios(Radio *estacion_de_radio)
{
    char op;
    do{
        system("cls");
        textcolor(LIGHTBLUE);
        printf("--CONTROL DE USUARIOS--\n");
        textcolor(WHITE);
        printf("[1] Registro de locutores \n");
        printf("[2] Registro de secretaria \n");
        printf("[3] Modificar registro de locutor \n");
        printf("[4] Modificar registro de secretaria \n");
        printf("[5] Mostrar listado de locutores \n");
        printf("[6] Mostrar listado de secretarias \n");
        printf("[7] Mostrar due%co \n",164);
        printf("[8] Menu principal \n");
        printf("[9] Salir del programa \n");
        textcolor(YELLOW);
        printf("Ingrese la opcion:");
        textcolor(WHITE);fflush(stdin); op=getche();

        switch(op){
            case 49: registroLocutor(estacion_de_radio); break;
            case 50: registroSecretaria(estacion_de_radio);break;
            case 51: modificarRegistroLocutor(estacion_de_radio); break;
            case 52: modificarRegistroSecretaria(estacion_de_radio); break;
            case 53: mostrarListaDeLocutores(); break;
            case 54: mostrarListaDeSecretarias();break;
            case 55: break;
            case 56: menu(estacion_de_radio); break;
            case 57: salirDelPrograma(estacion_de_radio); exit(1);
            default : mensajePorDefecto();
        }
    }while(op!=56);

}

void controlDeClientes(Radio *estacion_de_radio)
{
    char op;
    do{
        system("cls");
        textcolor(LIGHTBLUE);
        printf("--CONTROL DE CLIENTES--\n");
        textcolor(WHITE);
        printf("[1] Registro de cliente\n");
        printf("[2] Modificar cliente \n");
        printf("[3] Mostrar listado de clientes \n");
        printf("[4] Menu principal \n");
        printf("[5] Salir del programa \n");
        textcolor(YELLOW);
        printf("Ingrese la opcion:");
        textcolor(WHITE);fflush(stdin); op=getche();

        switch(op){
            case 49: registroCliente(estacion_de_radio); break;
            case 50: break;
            case 51: mostrarListaDeClientes(); break;
            case 52: menu(estacion_de_radio); break;
            case 53: salirDelPrograma(estacion_de_radio); exit(1);
            default : mensajePorDefecto();
        }
    }while(op!=53);

}

static void guardarCliente(Cliente *nuevoCliente){
	FILE *file;

	file=fopen(ARCHIVO_CLIENTES,"ab");
	if(!file){
		errorCritico();
	}else{
		fwrite(nuevoCliente, sizeof(Cliente), 1,file);
	}
	fclose(file);
}

static void guardarPrograma(Programa *nuevoPrograma){
	FILE *file;

	file=fopen(ARCHIVO_PROGRAMAS,"ab");
	if(!file){
		errorCritico();
	}else{
		fwrite(nuevoPrograma, sizeof(Programa), 1,file);
	}
	fclose(file);
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

static void ingresarClienteALaLista(Radio *estacion_de_radio, Cliente *nuevoCliente){
    //EL NUEVO NODO LOCUTOR SU SIGUIENTE APUNTARA A NULL PARA LOS ENLACES
    nuevoCliente->sig=NULL;
    //SI LA LISTA ESTA VACIA EL NUEVO LOCUTOR SERA EL PRIMER NODO EN LA LISTA
	if(!estacion_de_radio->lista_de_clientes){
		estacion_de_radio->lista_de_clientes=nuevoCliente;
	} // SI LA LISTA YA TIENE ELEMENTOS SE CORRERA HASTA LLEGAR AL FINAL PARA HACER EL ENLACE
	else{
		Cliente *listaAuxiliar;
		listaAuxiliar=estacion_de_radio->lista_de_clientes;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		//SE HACE EL ENLACE CON EL ULTIMO NODO DE LA LISTA
		listaAuxiliar->sig=nuevoCliente;

	}
}

static void ingresarLocutorALaLista(Radio *estacion_de_radio, Locutor *nuevoLocutor){
    //EL NUEVO NODO LOCUTOR SU SIGUIENTE APUNTARA A NULL PARA LOS ENLACES
    nuevoLocutor->sig=NULL;
    //SI LA LISTA ESTA VACIA EL NUEVO LOCUTOR SERA EL PRIMER NODO EN LA LISTA
	if(!estacion_de_radio->lista_de_locutores){
		estacion_de_radio->lista_de_locutores=nuevoLocutor;
	} // SI LA LISTA YA TIENE ELEMENTOS SE CORRERA HASTA LLEGAR AL FINAL PARA HACER EL ENLACE
	else{
		Locutor *listaAuxiliar;
		listaAuxiliar=estacion_de_radio->lista_de_locutores;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		//SE HACE EL ENLACE CON EL ULTIMO NODO DE LA LISTA
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

static void ingresarProgramaALaLista(Radio *estacion_de_radio, Programa *nuevoPrograma){
	if(!estacion_de_radio->lista_de_programas){
		estacion_de_radio->lista_de_programas=nuevoPrograma;
	}
	else{
		Programa *listaAuxiliar;
		listaAuxiliar=estacion_de_radio->lista_de_programas;
		while(listaAuxiliar->sig)
			listaAuxiliar=listaAuxiliar->sig;
		listaAuxiliar->sig=nuevoPrograma;

	}
}

static int validarNombreDelPrograma(char nombre[]){
        //EL NOMBRE NO PUEDE TENER ESPACIOS NI NÚMEROS
    //NO PUEDE TENER MAS DE 20 LETRAS
    //NO PUEDE TENER MAS DE UNA MAYUSCULA Y POR DEFECTO QUE SEA LA PRIMERA
    int i=0;
    while(nombre[i]!='\0'){
        if((int)nombre[i]<65 || (int)nombre[i]>95 && (int)nombre[i]<97 || (int)nombre[i]>122 )
            return 0;
        i++;
    }
    if(strlen(nombre)>30 || strlen(nombre)<2)
        return 0;
    return 1;
}

static int validarNombre(char nombre[]){
    //EL NOMBRE NO PUEDE TENER ESPACIOS NI NÚMEROS
    //NO PUEDE TENER MAS DE 20 LETRAS
    //NO PUEDE TENER MAS DE UNA MAYUSCULA Y POR DEFECTO QUE SEA LA PRIMERA
    int i=0;
    while(nombre[i]!='\0'){
        if(nombre[i]==' '|| (int)nombre[i]<65 || (int)nombre[i]>95 && (int)nombre[i]<97 || (int)nombre[i]>122)
            return 0;
        i++;
    }
    if(strlen(nombre)>20 || strlen(nombre)<2)
        return 0;

    i=1;
    while(nombre[i]!='\0'){
        if(isupper(nombre[i]))
            return 0;
        i++;
    }
    return 1;

}

static int validarCedula(Radio *estacion_de_radio, int cedula){
    Locutor * listaAuxiliar=estacion_de_radio->lista_de_locutores;
    Secretaria *listaAuxiliarS=estacion_de_radio->lista_de_secretarias;
    while(listaAuxiliar){
        if(listaAuxiliar->persona_locutor.cedula==cedula)
            return 0;
        listaAuxiliar=listaAuxiliar->sig;
    }
    while(listaAuxiliarS){
        if(listaAuxiliarS->persona_secretaria.cedula==cedula)
            return 0;
        listaAuxiliarS=listaAuxiliarS->sig;
    }
    if(cedula<3000000 || cedula>40000000)
        return 0;
    return 1;
}

static int validarSueldo(int sueldo){
        if(sueldo>50000)
            return 0;
        else if(sueldo<0)
            return 0;
    return 1;
}

void registroCliente(Radio *estacion_de_radio){
	system("cls");

    Cliente *nuevoCliente;
    nuevoCliente=(Cliente*)malloc(sizeof(Cliente));

    if(!nuevoCliente){
    	errorCritico();
    }
    else{
    	FILE * file=fopen(ARCHIVO_CLIENTES,"rb");
	    int id=0, valido=1;
	    char cedula[8]="",sueldo[5]="", edad[2]="";
	    long aux;

	    fseek(file,(sizeof(Cliente)*(-1)),SEEK_END);
	    if(fread(nuevoCliente,sizeof(Cliente),1,file))
	    	id=nuevoCliente->id;
        textcolor(LIGHTBLUE);
        printf("--REGISTRO CLIENTE--\n");
	    do{
            textcolor(WHITE);
            printf("Ingrese el nombre de la empresa del nuevo Cliente:                    \n");
            fflush(stdin);
            gets(nuevoCliente->nombre_empresa);
            valido=validarNombreDelPrograma(nuevoCliente->nombre_empresa);
                if(!valido){
                    textcolor(RED);
                    printf("El nombre que ingreso no esta permitido\n");
                    Sleep(2000);
                    system("cls");
                }
        }while(!valido);

        do{
            textcolor(WHITE);
            printf("Ingrese el nombre del nuevo Cliente:                                  \n");
            fflush(stdin);
            gets(nuevoCliente->persona_cliente.nombre);
            valido=validarNombre(nuevoCliente->persona_cliente.nombre);
                if(!valido){
                    textcolor(RED);
                    printf("El nombre no puede tener espacios o ser mas largo de 20 letras\n");
                    Sleep(2000);
                    system("cls");
                }
        }while(!valido);

	     do{
            textcolor(WHITE);
            printf("Ingrese el Apellido del nuevo cliente:                                  \n");
            fflush(stdin);
            gets(nuevoCliente->persona_cliente.apellido);
            valido=validarNombre(nuevoCliente->persona_cliente.apellido);
                if(!valido){
                    textcolor(RED);
                    printf("El Apellido no puede tener espacios o ser mas largo de 20 letras\r");
                    Sleep(2000);
                }
        }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la cedula del cliente                                \n");
            fflush(stdin);
            gets(cedula); aux=atoi(&cedula);
            valido=validarCedula(estacion_de_radio,aux);
            if(!valido){
                textcolor(RED);
                printf("La cedula que ingreso es incorrecta o ya esta registrada \r");
                Sleep(2000);
            }else
                nuevoCliente->persona_cliente.cedula=aux;
	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la edad del cliente                                \n");
            scanf("%i",&nuevoCliente->persona_cliente.edad);
            if(nuevoCliente->persona_cliente.edad<18 || nuevoCliente->persona_cliente.edad>80)
                valido=0;

            if(!valido){
                textcolor(RED);
                printf("La edad valida tiene que estar entre 18 y 80 a%cos \r",164);
                Sleep(2000);
            }
	    }while(!valido);
            id++;
            nuevoCliente->id=id;
            nuevoCliente->sig=NULL;
            fclose(file);
            ingresarClienteALaLista(estacion_de_radio,nuevoCliente);
            guardarCliente(nuevoCliente);
    }
}

void registroPrograma(Radio *estacion_de_radio){
    system("cls");

    Programa *nuevoPrograma;
    nuevoPrograma=(Programa*)malloc(sizeof(Programa));

    if(!nuevoPrograma){
    	errorCritico();
    }
    else{
    	FILE * file=fopen(ARCHIVO_PROGRAMAS,"rb");
	    int id=0, valido=1;
	    char inicio[1]="";
	    long aux;

	    fseek(file,(sizeof(Programa)*(-1)),SEEK_END);
	    if(fread(nuevoPrograma,sizeof(Programa),1,file))
	    	id=nuevoPrograma->id;
        do{
            textcolor(LIGHTBLUE);
            printf("--REGISTRO PROGRAMA--\n");
            textcolor(WHITE);
            printf("Ingrese el nombre del nuevo programa:                                  \n");
            fflush(stdin);
            gets(nuevoPrograma->nombre_de_programa);
            valido=validarNombreDelPrograma(nuevoPrograma->nombre_de_programa);
                if(!valido){
                    textcolor(RED);
                    printf("El nombre no puede tener espacios o ser mas largo de 20 letras\n");
                    Sleep(2000);
                    system("cls");
                }
        }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese el horario de inicio                                \n");
            scanf("%i",&nuevoPrograma->horario_de_inicio);
            if(nuevoPrograma->horario_de_inicio<1 || nuevoPrograma->horario_de_inicio>10)
                valido=0;
            if(!valido){
                textcolor(RED);
                printf("La hora que ingreso es incorrecta  \r");
                Sleep(2000);
            }
	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la hora de fin del programa                          \n");
            scanf("%i",&nuevoPrograma->horario_de_fin);
            if(nuevoPrograma->horario_de_fin<1 || nuevoPrograma->horario_de_fin>12)
                valido=0;
            if(!valido){
                textcolor(RED);
                printf("La hora que ingreso es incorrecta\r");
                Sleep(2000);
            }
	    }while(!valido);

	     do{
            textcolor(WHITE);
            printf("Ingrese el costo de pauta del programa                        \n");
            scanf("%i",&nuevoPrograma->coste_de_pauta);
            if(nuevoPrograma->coste_de_pauta>40000)
                valido=0;
            if(!valido){
                textcolor(RED);
                printf("El costo tiene que ser menor a 50000\r");
                Sleep(2000);
            }

	    }while(!valido);
            id++;
            nuevoPrograma->id=id;
            nuevoPrograma->sig=NULL;
            fclose(file);
            ingresarProgramaALaLista(estacion_de_radio,nuevoPrograma);
            guardarPrograma(nuevoPrograma);
    }
}

void registroLocutor(Radio *estacion_de_radio){
	system("cls");

    Locutor *nuevoLocutor;
    nuevoLocutor=(Locutor*)malloc(sizeof(Locutor));

    if(!nuevoLocutor){
    	errorCritico();
    }
    else{
    	FILE * file=fopen(ARCHIVO_LOCUTORES,"rb");
	    int id=0, valido=1;
	    char cedula[8]="",sueldo[5]="", edad[2]="";
	    long aux;

	    fseek(file,(sizeof(Locutor)*(-1)),SEEK_END);
	    if(fread(nuevoLocutor,sizeof(Locutor),1,file))
	    	id=nuevoLocutor->empleado_locutor.id;
        do{
            textcolor(LIGHTBLUE);
            printf("--REGISTRO LOCUTOR--\n");
            textcolor(WHITE);
            printf("Ingrese el nombre del nuevo locutor:                                  \n");
            fflush(stdin);
            gets(nuevoLocutor->persona_locutor.nombre);
            valido=validarNombre(nuevoLocutor->persona_locutor.nombre);
                if(!valido){
                    textcolor(RED);
                    printf("El nombre no puede tener espacios o ser mas largo de 20 letras\n");
                    Sleep(2000);
                    system("cls");
                }
        }while(!valido);

	     do{
            textcolor(WHITE);
            printf("Ingrese el Apellido del nuevo locutor:                                  \n");
            fflush(stdin);
            gets(nuevoLocutor->persona_locutor.apellido);
            valido=validarNombre(nuevoLocutor->persona_locutor.apellido);
                if(!valido){
                    textcolor(RED);
                    printf("El Apellido no puede tener espacios o ser mas largo de 20 letras\r");
                    Sleep(2000);
                }
        }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la cedula del locutor                                \n");
            fflush(stdin);
            gets(cedula); aux=atoi(&cedula);
            valido=validarCedula(estacion_de_radio,aux);
            if(!valido){
                textcolor(RED);
                printf("La cedula que ingreso es incorrecta o ya esta registrada \r");
                Sleep(2000);
            }else
                nuevoLocutor->persona_locutor.cedula=aux;
	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la edad del locutor                                \n");
            scanf("%i",&nuevoLocutor->persona_locutor.edad);
            if(nuevoLocutor->persona_locutor.edad<18 || nuevoLocutor->persona_locutor.edad>80)
                valido=0;
            if(!valido){
                textcolor(RED);
                printf("La edad valida tiene que estar entre 18 y 80 a%cos \r",164);
                Sleep(2000);
            }
	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese el sueldo del locutor                                \n");
            fflush(stdin);
            scanf("%i",&nuevoLocutor->empleado_locutor.sueldo);
            /*for(aux=0;aux<strlen(sueldo);aux++)
                    if(!isdigit(sueldo[aux]))
                        valido=0;
            aux=atoi(&sueldo);*/
                valido=validarSueldo(nuevoLocutor->empleado_locutor.sueldo);
            if(!valido){
                textcolor(RED);
                printf("El sueldo tiene que estar entre el presupuesto \r");
                Sleep(2000);
            }
                //nuevoLocutor->empleado_locutor.sueldo=aux;

	    }while(!valido);

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

        char op="";
        char nombre[30];
        char cedula[30];
        long aux;
        do{
            system("cls");
            textcolor(LIGHTBLUE);
            printf("--BUSCAR LOCUTOR--\n");
            textcolor(WHITE);
            printf("[1] Buscar por ID\n");
            printf("[2] Buscar por Cedula\n");
            printf("[3] Buscar por Nombre\n");
            printf("[4] Cancelar\n");
            textcolor(YELLOW);
            printf("Ingrese la opcion: ");
            fflush(stdin);
            textcolor(WHITE);op=getche();

            switch(op){
                case 49:
                        do{
                            system("cls");
                            printf("Ingresar ID: \n");
                            gets(cedula);
                            aux=atoi(&cedula);
                            printf("%ld  \n",aux);
                        }while(aux>500 || aux<0);
                        //Para recorrer la lista
                        locutorAModificar=estacion_de_radio->lista_de_locutores;
                        while(locutorAModificar){
                            if(locutorAModificar->empleado_locutor.id==aux){
                                return locutorAModificar;
                            }
                            locutorAModificar=locutorAModificar->sig;
                        }
                        printf("No hay ningun Locutor registrado con ese ID\n");
                        pausar();
                        break;
                case 50:
                        do{
                            system("cls");
                            printf("Ingresar Cedula: \n");
                            gets(cedula);
                            aux=atoi(&cedula);
                            printf("%ld  \n",aux);
                        }while(aux>40000000 || aux<0);
                        //Para recorrer la lista
                        locutorAModificar=estacion_de_radio->lista_de_locutores;
                        while(locutorAModificar){
                            if(locutorAModificar->persona_locutor.cedula==aux){
                                return locutorAModificar;
                            }
                            locutorAModificar=locutorAModificar->sig;
                        }
                        printf("No hay ningun Locutor registrado con esa Cedula\n");
                        pausar();
                        return 0;
                        break;

                case 51:
                        do{
                            system("cls");
                            printf("Ingresar Nombre: \n");
                            fflush(stdin);
                            gets(nombre);
                        }while(!validarNombre(nombre));
                        textcolor(LIGHTBLUE);
                        printf("%-52s LOCUTORES\n"," ");
                        textcolor(WHITE);
                        printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
                        textcolor(DARKGRAY);
                        printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
                        textcolor(WHITE);
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
                                printf("Ingrese el locutor a elegir: ");fflush(stdin); textcolor(WHITE);op=getche();
                                aux=atoi(&op);
                                printf("\n");
                              }while(aux<1 || aux>i);
                            locutorAModificar=estacion_de_radio->lista_de_locutores;
                            while(locutorAModificar){
                                if(strcmpi(locutorAModificar->persona_locutor.nombre,nombre)==0)
                                    --aux;
                                if(aux==0){
                                    pausar();
                                    return locutorAModificar;
                                  }
                                locutorAModificar=locutorAModificar->sig;
                              }
                          }
                        printf("\t\t\t\t No hay ningun Locutor registrado con ese Nombre\n");
                        pausar();
                        return 0;
                        break;
                case 52:  controlDeUsuarios(estacion_de_radio);
                default : mensajePorDefecto(); break;
            }
        }while(op!=52);

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
/*
static void modificarRegistroPrograma(Radio * estacion_de_radio){
     system("cls");
    if(estacion_de_radio->lista_de_locutores){
            Programa *programaAModificar;
            programaAModificar=(Programa*)malloc(sizeof(Programa));
            programaAModificar->sig=NULL;

            Locutor *locutorAModificar;
            locutorAModificar=(Locutor*)malloc(sizeof(Locutor));
            locutorAModificar->sig=NULL;
        //FUNCION DE  BUSQUEDA DEL LOCUTOR A PROCESAR
        if(programaAModificar=seleccionarPrograma(estacion_de_radio,programaAModificar)){
            char op="";
            system("cls");
            do{
                //OPCIONES DE MODIFICACIÓN DEL LOCUTOR
                textcolor(LIGHTBLUE);
                printf("--OPCIONES--\n");
                textcolor(WHITE);
                printf("[1] Modificar coste\n");
                printf("[2] Asignar Locutor\n");
                printf("[3] Remover Locutor\n");
                printf("[4] Cancelar\n");
                textcolor(YELLOW);
                printf("Ingrese la opcion: ");
                textcolor(WHITE);op=getche();
                FILE *file;
                switch(op){

                    case 49:
                            file=fopen(ARCHIVO_PROGRAMAS,"r+b");
                            if(!file){
                             errorCritico();
                            }else{
                                do{
                                    system("cls");
                                    printf("Ingrese el nuevo coste para el programa %s:",programaAModificar->nombre_de_programa);
                                    scanf("%i",&programaAModificar->coste_de_pauta);
                                }while(programaAModificar->coste_de_pauta>40000 || programaAModificar->coste_de_pauta<0);
                                fseek(file,(sizeof(Programa)*(programaAModificar->id))-sizeof(Programa),0);
                                    fwrite(programaAModificar,sizeof(Programa),1,file);
                                printf("Programa modificado..\n");
                                fclose(file);
                                getch(); controlDeProgramas(estacion_de_radio); break;
                            }

                    case 50:

                             buscarLocutor(estacion_de_radio,locutorAModificar);

                             //SI LA LISTA ESTA VACIA EL NUEVO LOCUTOR SERA EL PRIMER NODO EN LA LISTA
                            if(!programaAModificar->lista_locutores){
                                programaAModificar->lista_locutores=locutorAModificar;
                            } // SI LA LISTA YA TIENE ELEMENTOS SE CORRERA HASTA LLEGAR AL FINAL PARA HACER EL ENLACE
                            else{
                                Locutor *listaAuxiliar;
                                listaAuxiliar=programaAModificar->lista_locutores;
                                while(listaAuxiliar->sig)
                                    listaAuxiliar=listaAuxiliar->sig;
                                //SE HACE EL ENLACE CON EL ULTIMO NODO DE LA LISTA
                                listaAuxiliar->sig=locutorAModificar;
                            }

                             file=fopen(ARCHIVO_PROGRAMAS,"r+b");
                            if(!file){
                             errorCritico();
                            }else{

                                fseek(file,(sizeof(Programa)*(programaAModificar->id))-sizeof(Programa),0);
                                    fwrite(programaAModificar,sizeof(Programa),1,file);
                                printf("Programa modificado..\n");
                                fclose(file);
                                getch(); controlDeProgramas(estacion_de_radio); break;
                            }
                             break;

                    case 51: break;

                    case 52: menu(estacion_de_radio); break;
                    default : mensajePorDefecto(); break;
                }
            }while(op!=51);
        }
    }else{
        printf("No hay registros en el archivo");
        pausar();
    }
}
*/
Programa * seleccionarPrograma(Radio * estacion_de_radio,Programa *programaAModificar){

        char op="";
        long aux;
            textcolor(LIGHTBLUE);
            printf("%-52s PROGRAMAS\n"," ");
            textcolor(WHITE);
            printf("%-10s %-10s %-22s %-20s %-10s %-10s %-20s \n"," ","Id","Nombre","Inicio","Fin","Locutores","Precio");
            textcolor(DARKGRAY);
            printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
            textcolor(WHITE);
            int i=1, encontrado=0;
            programaAModificar=estacion_de_radio->lista_de_programas;
            while(programaAModificar){
                    printf("[%i] %-10s %-10i %-22s %-20i %-10i %-10s %-20i \n",i," ",programaAModificar->id,
                    programaAModificar->nombre_de_programa,
                    programaAModificar->horario_de_inicio,
                    programaAModificar->horario_de_fin,
                    "Locutores",
                    programaAModificar->coste_de_pauta);
                    programaAModificar=programaAModificar->sig;
                    i++;
                }

            do{
                textcolor(YELLOW);
                printf("Ingrese el programa a elegir: ");fflush(stdin); textcolor(WHITE);op=getche();
                aux=atoi(&op);
                printf("\n");
            }while(aux<1 || aux>i);

            programaAModificar=estacion_de_radio->lista_de_programas;
            while(programaAModificar){
                    if(programaAModificar->id==aux)
                            return programaAModificar;
                        programaAModificar=programaAModificar->sig;
                    }
}

static void modificarRegistroLocutor(Radio * estacion_de_radio){
    system("cls");
    if(estacion_de_radio->lista_de_locutores){
            Locutor *locutorAModificar;
            locutorAModificar=(Locutor*)malloc(sizeof(Locutor));
            locutorAModificar->sig=NULL;
        //FUNCION DE  BUSQUEDA DEL LOCUTOR A PROCESAR
        if(locutorAModificar=buscarLocutor(estacion_de_radio,locutorAModificar)){
            char op="";
            system("cls");
            do{
                //OPCIONES DE MODIFICACIÓN DEL LOCUTOR
                textcolor(LIGHTBLUE);
                printf("--OPCIONES--\n");
                textcolor(WHITE);
                printf("[1] Modificar sueldo base\n");
                printf("[2] Despedir Locutor\n");
                printf("[3] Cancelar\n");
                textcolor(YELLOW);
                printf("Ingrese la opcion: ");
                textcolor(WHITE);op=getche();
                FILE *file;
                switch(op){
                   //MODIFICAR EL SUELDO BASE DEL LOCUTOR
                    case 49:
                            file=fopen(ARCHIVO_LOCUTORES,"r+b");
                            if(!file){
                             errorCritico();
                            }else{
                                do{
                                    system("cls");
                                    printf("Ingrese el nuevo sueldo para el locutor %s:",locutorAModificar->persona_locutor.nombre);
                                    scanf("%i",&locutorAModificar->empleado_locutor.sueldo);
                                }while(!validarSueldo(locutorAModificar->empleado_locutor.sueldo));
                                fseek(file,(sizeof(Locutor)*(locutorAModificar->empleado_locutor.id))-sizeof(Locutor),0);
                                    fwrite(locutorAModificar,sizeof(Locutor),1,file);
                                printf("Locutor Modificado..\n");
                                fclose(file);
                                getch(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //DESPEDIR LOCUTOR
                    case 50: //SE ABRE EN MODO W PARA QUE SOBREESCRIBA
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
                                fclose(file);
                                pausar(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //REGRESAR AL MENU PRINCIPAL
                    case 51: menu(estacion_de_radio); break;
                    default : mensajePorDefecto(); break;
                }
            }while(op!=51);
        }
    }else{
        printf("No hay registros en el archivo");
        pausar();
    }

}

Secretaria * buscarSecretaria(Radio * estacion_de_radio,Secretaria *secretariaAModificar){

        char op="";
        char nombre[30];
        long aux;
        do{
            system("cls");
            textcolor(LIGHTBLUE);
            printf("--BUSCAR SECRETARIA--\n");
            textcolor(WHITE);
            printf("[1] Buscar por ID\n");
            printf("[2] Buscar por Cedula\n");
            printf("[3] Buscar por Nombre\n");
            printf("[4] Cancelar\n");
            textcolor(YELLOW);
            printf("Ingrese la opcion: ");
            textcolor(WHITE);op=getche();

            switch(op){
                case 49:
                        do{
                            system("cls");
                            printf("Ingresar ID: \n");
                            gets(nombre);
                            aux=atoi(&nombre);
                            printf("%ld  \n",aux);
                        }while(aux>500 || aux<0);
                        //Para recorrer la lista
                        secretariaAModificar=estacion_de_radio->lista_de_secretarias;
                        while(secretariaAModificar){
                            if(secretariaAModificar->empleado_secretaria.id==aux){
                                return secretariaAModificar;
                            }
                            secretariaAModificar=secretariaAModificar->sig;
                        }
                        printf("No hay ningun Locutor registrado con ese ID\n");
                        pausar();
                        break;
                case 50: system("cls");
                        int cedula;
                        printf("Ingresar Cedula: \n");
                        scanf("%i",&cedula);
                        //Para recorrer la lista
                        secretariaAModificar=estacion_de_radio->lista_de_secretarias;
                        while(secretariaAModificar){
                            if(secretariaAModificar->persona_secretaria.cedula==cedula){
                                return secretariaAModificar;
                            }
                            secretariaAModificar=secretariaAModificar->sig;
                        }
                        printf("No hay ningun Locutor registrado con esa Cedula\n");
                        pausar();
                        return 0;
                        break;

                case 51: system("cls");

                        printf("Ingresar Nombre: \n");
                        fflush(stdin);
                        gets(nombre);
                        printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s \n"," ","Id Secretaria","Nombre","Apellido","Cedula","Edad","Sueldo");
                        int i=1, encontrado=0;
                        secretariaAModificar=estacion_de_radio->lista_de_secretarias;
                        while(secretariaAModificar){
                            if(strcmpi(secretariaAModificar->persona_secretaria.nombre,nombre)==0){
                                printf("[%i] %-6s %-20i %-10s %-10s %-10i %-10i %-10i \n",i," ",secretariaAModificar->empleado_secretaria.id,
                                secretariaAModificar->persona_secretaria.nombre,
                                secretariaAModificar->persona_secretaria.apellido,
                                secretariaAModificar->persona_secretaria.cedula,
                                secretariaAModificar->persona_secretaria.edad,
                                secretariaAModificar->empleado_secretaria.sueldo);
                                i++;
                                encontrado=1;
                                }
                                secretariaAModificar=secretariaAModificar->sig;
                            }

                        if(encontrado){
                            do{
                                textcolor(YELLOW);
                                printf("Ingrese la secretaria a elegir: "); fflush(stdin); textcolor(WHITE);op=getche();
                                aux=atoi(&op);
                              }while(aux>=i || aux<0);
                            secretariaAModificar=estacion_de_radio->lista_de_secretarias;
                            while(secretariaAModificar){
                                if(strcmpi(secretariaAModificar->persona_secretaria.nombre,nombre)==0)
                                    --aux;
                                if(aux==0){
                                    pausar();
                                    return secretariaAModificar;
                                  }
                                secretariaAModificar=secretariaAModificar->sig;
                              }
                          }
                        printf("No hay ninguna Secretaria registrada con ese nombre\n");
                        pausar();
                        return 0;
                        break;
                default : mensajePorDefecto(); break;
            }
        }while(op!=3);

}

static Secretaria * eliminarSecretaria(Radio *estacion_de_radio, Secretaria *secretariaAModificar)
{
    Secretaria *nodoAnterior, *cabezaAuxiliar=estacion_de_radio->lista_de_secretarias;
    while(cabezaAuxiliar){
            //SI ALGUN LOCUTOR TIENE REGISTRADA ESA CEDULA QUE SALGA DEL BUCLE
        if(cabezaAuxiliar->persona_secretaria.cedula==secretariaAModificar->persona_secretaria.cedula)
            break;
        //LOCUTOR ANTERIOR
        nodoAnterior=cabezaAuxiliar;
        //PARA RECORRER LA LISTA SE DIRECCIONA LA CABEZA AUXILIAR AL PROXIMO LOCUTOR DE LA LISTA
        cabezaAuxiliar=cabezaAuxiliar->sig;
    }
    //SI EXISTE EL LOCUTOR CON LA CEDULA
    if(cabezaAuxiliar){
        //SI ES EL PRIMER LOCUTOR
        if(cabezaAuxiliar==estacion_de_radio->lista_de_secretarias)
           estacion_de_radio->lista_de_secretarias=cabezaAuxiliar->sig;

        else{
            nodoAnterior->sig=cabezaAuxiliar->sig;
            free(cabezaAuxiliar);
        }
        printf("Secretaria despedida\n");
    }
    return estacion_de_radio->lista_de_secretarias;
}

static void modificarRegistroSecretaria(Radio * estacion_de_radio){
    system("cls");
    if(estacion_de_radio->lista_de_secretarias){
            Secretaria *secretariaAModificar;
            secretariaAModificar=(Secretaria*)malloc(sizeof(Secretaria));
            secretariaAModificar->sig=NULL;
        //FUNCION DE  BUSQUEDA DEL LOCUTOR A PROCESAR
        if(secretariaAModificar=buscarSecretaria(estacion_de_radio,secretariaAModificar)){
            char op="";
            system("cls");
            do{
                //OPCIONES DE MODIFICACIÓN DEL LOCUTOR
                textcolor(LIGHTBLUE);
                printf("--OPCIONES--\n");
                textcolor(WHITE);
                printf("[1] Modificar sueldo base\n");
                printf("[2] Despedir Secretaria\n");
                printf("[3] Cancelar\n");
                textcolor(YELLOW);
                printf("Ingrese la opcion: ");
                textcolor(WHITE);op=getche();
                FILE *file;
                switch(op){
                   //MODIFICAR EL SUELDO BASE DEL LOCUTOR
                    case 49:
                            file=fopen(ARCHIVO_SECRETARIAS,"r+b");
                            if(!file){
                             errorCritico();
                            }else{
                                do{
                                    system("cls");
                                    printf("Ingrese el nuevo sueldo para la secretaria %s:",secretariaAModificar->persona_secretaria.nombre);
                                    scanf("%i",&secretariaAModificar->empleado_secretaria.sueldo);
                                }while(!validarSueldo(secretariaAModificar->empleado_secretaria.sueldo));
                                fseek(file,(sizeof(Secretaria)*(secretariaAModificar->empleado_secretaria.id))-sizeof(Secretaria),0);
                                    fwrite(secretariaAModificar,sizeof(Secretaria),1,file);
                                printf("Secretaria modificada..\n");
                                fclose(file);
                                getch(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //DESPEDIR LOCUTOR
                    case 50: //SE ABRE EN MODO W PARA QUE SOBREESCRIBA
                            file=fopen(ARCHIVO_SECRETARIAS,"w");
                            if(!file){
                             errorCritico();
                            }else{
                                system("cls");
                                estacion_de_radio->lista_de_secretarias=eliminarSecretaria(estacion_de_radio,secretariaAModificar);
                                Secretaria *aux=estacion_de_radio->lista_de_secretarias;
                                int id=1;
                                rewind(file);
                                while(aux){
                                    aux->empleado_secretaria.id=id;
                                    fwrite(aux,sizeof(Secretaria),1,file);
                                    id++;
                                    aux=aux->sig;
                                }
                                fclose(file);
                                pausar(); controlDeUsuarios(estacion_de_radio); break;
                            }
                    //REGRESAR AL MENU PRINCIPAL
                    case 51: menu(estacion_de_radio); break;
                    default : mensajePorDefecto(); break;
                }
            }while(op!=51);
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
	    int id=0,valido=0;
	    char cedula[8]="",sueldo[5]="", edad[2]="";
	    long aux;

	    fseek(file,(sizeof(Secretaria)*(-1)),SEEK_END);
	    if(fread(nuevaSecretaria,sizeof(Secretaria),1,file))
	    	id=nuevaSecretaria->empleado_secretaria.id;
	    do{
            textcolor(LIGHTBLUE);
            printf("--REGISTRO SECRETARIA--\n");
            textcolor(WHITE);
            printf("Ingrese el nombre de la nueva secretaria:                                  \n");
            fflush(stdin);
            gets(nuevaSecretaria->persona_secretaria.nombre);
            valido=validarNombre(nuevaSecretaria->persona_secretaria.nombre);
                if(!valido){
                    textcolor(RED);
                    printf("El nombre no puede tener espacios o ser mas largo de 20 letras\n");
                    Sleep(2000);
                    system("cls");
                }
        }while(!valido);

	     do{
            textcolor(WHITE);
            printf("Ingrese el apellido del nueva secretaria:                                  \n");
            fflush(stdin);
            gets(nuevaSecretaria->persona_secretaria.apellido);
            valido=validarNombre(nuevaSecretaria->persona_secretaria.apellido);
                if(!valido){
                    textcolor(RED);
                    printf("El apellido no puede tener espacios o ser mas largo de 20 letras\r");
                    Sleep(2000);
                }
        }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la cedula de la secretaria                                \n");
            fflush(stdin);
            gets(cedula); aux=atoi(&cedula);
            valido=validarCedula(estacion_de_radio,aux);
            if(!valido){
                textcolor(RED);
                printf("La cedula que ingreso es incorrecta o ya esta registrada \r");
                Sleep(2000);
            }
            nuevaSecretaria->persona_secretaria.cedula=aux;
	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese la edad de la secretaria                                \n");
            scanf("%i",&nuevaSecretaria->persona_secretaria.edad);
            if(nuevaSecretaria->persona_secretaria.edad<18 || nuevaSecretaria->persona_secretaria.edad>80)
                valido=0;
            if(!valido){
                textcolor(RED);
                printf("La edad valida tiene que estar entre 18 y 80 a%cos \r",164);
                Sleep(2000);
            }

	    }while(!valido);

	    do{
            textcolor(WHITE);
            printf("Ingrese el sueldo de la secretaria                                \n");
            /*fflush(stdin);
            gets(sueldo); aux=atoi(&sueldo);
            valido=validarSueldo(aux);*/
            scanf("%i",&nuevaSecretaria->empleado_secretaria.sueldo);
            valido=validarSueldo(nuevaSecretaria->empleado_secretaria.sueldo);
            if(!valido){
                textcolor(RED);
                printf("El sueldo tiene que estar entre el presupuesto \r");
                Sleep(2000);
            }
            //nuevaSecretaria->empleado_secretaria.sueldo=aux;
	    }while(!valido);

            id++;
            nuevaSecretaria->empleado_secretaria.id=id;
            nuevaSecretaria->empleado_secretaria.activo=1;
            nuevaSecretaria->sig=NULL;
            fclose(file);
            ingresarSecretariaALaLista(estacion_de_radio,nuevaSecretaria);
            guardarSecretaria(nuevaSecretaria);
    }
}

void mostrarListaDeClientes(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_CLIENTES,"rb");
	Cliente clienteALeer;
    textcolor(LIGHTBLUE);
    printf("%-52s CLIENTES\n"," ");
    textcolor(WHITE);
	printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s \n"," ","Id Cliente","Nombre","Apellido","Cedula","Edad","Cotizacion");
	textcolor(DARKGRAY);
	printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
	textcolor(WHITE);
	while(fread(&clienteALeer, sizeof(Cliente),1, file)){
	 	printf("%-10s %-20i %-10s %-10s %-10i %-10i \n"," ",clienteALeer.id,
	    clienteALeer.persona_cliente.nombre,
	    clienteALeer.persona_cliente.apellido,
	    clienteALeer.persona_cliente.cedula,
	    clienteALeer.persona_cliente.edad);
	}
	pausar();
}

void mostrarListaDeLocutores(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_LOCUTORES,"rb");
	Locutor locutorALeer;
	textcolor(LIGHTBLUE);
    printf("%-52s LOCUTORES\n"," ");
    textcolor(WHITE);
	printf("%-10s %-15s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");
	textcolor(DARKGRAY);
	printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
	textcolor(WHITE);
	while(fread(&locutorALeer, sizeof(Locutor),1, file)){
	 	printf("%-10s %-15i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",locutorALeer.empleado_locutor.id,
	    locutorALeer.persona_locutor.nombre,
	    locutorALeer.persona_locutor.apellido,
	    locutorALeer.persona_locutor.cedula,
	    locutorALeer.persona_locutor.edad,
	    locutorALeer.empleado_locutor.sueldo,
	    "Nombre del programa");
	}
	pausar();
}
/*//MOSTRAR LISTA ENLAZADA

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
*/
//MOSTRAR LOS REGISTROS EN LOS ARCHIVOS
void mostrarListaDeSecretarias(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_SECRETARIAS,"rb");
	Secretaria secretariaALeer;
    textcolor(LIGHTBLUE);
    printf("%-52s SECRETARIAS\n"," ");
    textcolor(WHITE);
	printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s \n"," ","Id Secretaria","Nombre","Apellido","Cedula","Edad","Sueldo");
	textcolor(DARKGRAY);
	printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
	textcolor(WHITE);
	while(fread(&secretariaALeer, sizeof(Locutor),1, file)){
	 	printf("%-10s %-20i %-10s %-10s %-10i %-10i %-10i\n"," ",secretariaALeer.empleado_secretaria.id,
	    secretariaALeer.persona_secretaria.nombre,
	    secretariaALeer.persona_secretaria.apellido,
	    secretariaALeer.persona_secretaria.cedula,
	    secretariaALeer.persona_secretaria.edad,
	    secretariaALeer.empleado_secretaria.sueldo);
	}
	pausar();
}
//ELIMINAR CADA NODO DE LA LISTA

void mostrarReportes(Radio * estacion_de_radio){
    system("cls");
    textcolor(LIGHTBLUE);
    printf("%-52s PROGRAMAS\n"," ");
    textcolor(WHITE);
	printf("%-10s %-10s %-22s %-20s %-10s %-10s %-20s \n"," ","Egresos por sueldo","Ingresos por pautas");
	textcolor(DARKGRAY);
	printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
	textcolor(WHITE);
	printf("%-10s %-10i %-22i \n"," ",estacion_de_radio->dueno.egresos, estacion_de_radio->dueno.ingresos);
	pausar();
}

void mostrarListaDeProgramas(){
	system("cls");
	FILE *file;
	file=fopen(ARCHIVO_PROGRAMAS,"rb");
	Programa *programaALeer;
	char hora[2]="AM";
	int i;
    textcolor(LIGHTBLUE);
    printf("%-52s PROGRAMAS\n"," ");
    textcolor(WHITE);
	printf("%-10s %-10s %-22s %-20s %-10s %-10s %-20s \n"," ","Id","Nombre","Inicio","Fin","Locutores","Precio");
	textcolor(DARKGRAY);
	printf("%-10s-------------------------------------------------------------------------------------------------\n"," ");
	textcolor(WHITE);
	while(fread(programaALeer, sizeof(Programa),1, file)){
	 	printf("%-10s %-10i %-22s %-20i %-10i %-10s %-20i \n"," ",programaALeer->id,
	    programaALeer->nombre_de_programa,
	    programaALeer->horario_de_inicio,
	    programaALeer->horario_de_fin,
	    "Locutores",
	    programaALeer->coste_de_pauta);
	}
	pausar();
}

void eliminarListaClientes(Radio *estacion_de_radio){
    Cliente *listaAuxiliar;
	while(estacion_de_radio->lista_de_clientes){
		listaAuxiliar=estacion_de_radio->lista_de_clientes;
		estacion_de_radio->lista_de_clientes=estacion_de_radio->lista_de_clientes->sig;
		free(listaAuxiliar);
	}
}

void eliminarListaProgramas(Radio *estacion_de_radio){
    Programa *listaAuxiliar;
	while(estacion_de_radio->lista_de_programas){
		listaAuxiliar=estacion_de_radio->lista_de_programas;
		estacion_de_radio->lista_de_programas=estacion_de_radio->lista_de_programas->sig;
		free(listaAuxiliar);
	}
}

void eliminarListaLocutor(Radio * estacion_de_radio){
	Locutor *listaAuxiliar;
	while(estacion_de_radio->lista_de_locutores){
		listaAuxiliar=estacion_de_radio->lista_de_locutores;
		estacion_de_radio->lista_de_locutores=estacion_de_radio->lista_de_locutores->sig;
		free(listaAuxiliar);
	}
}

void eliminarListaSecretarias(Radio * estacion_de_radio){
	Secretaria *listaAuxiliar;
	while(estacion_de_radio->lista_de_secretarias){
		listaAuxiliar=estacion_de_radio->lista_de_secretarias;
		estacion_de_radio->lista_de_secretarias=estacion_de_radio->lista_de_secretarias->sig;
		free(listaAuxiliar);
	}
}

static void salirDelPrograma(Radio *estacion_de_radio){
    eliminarListaClientes(estacion_de_radio);
    eliminarListaLocutor(estacion_de_radio);
    eliminarListaSecretarias(estacion_de_radio);
    eliminarListaProgramas(estacion_de_radio);
	free(estacion_de_radio->lista_de_locutores);
	free(estacion_de_radio->lista_de_secretarias);
	free(estacion_de_radio->lista_de_clientes);
	free(estacion_de_radio->lista_de_programas);
}
