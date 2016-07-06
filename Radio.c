//AQUI ESTARAN LAS FUNCIONES DE LA LIBRERIA
#include "Radio.h"

//INICIALIZAR LA LISTA
Radio inicializarListas(Radio estacion_de_radio)
{
    estacion_de_radio.lista_de_locutores=NULL;
    estacion_de_radio.lista_de_secretarias=NULL;
    return estacion_de_radio;
}

Locutor * crearLocutor( char *nombre, char *apellido,int edad, int cedula, int id,int sueldo)
{
    //CREANDO EL Locutor
    Locutor *registroNuevo;
    registroNuevo=(Locutor*)malloc(sizeof(Locutor));

    //SINO SE PUDO RESERVAR MEMORIA PARA EL REGISTRO
    if(!registroNuevo)
    {
       printf("No se pudo crear memoria para el registro\n");
       return NULL;
    }
    else
    {
        //SI SE PUDO RESERVAR LA MEMORIA SE REGISTRAN LOS DATOS
        registroNuevo->persona_locutor.nombre=nombre;
        registroNuevo->persona_locutor.apellido=apellido;
        registroNuevo->persona_locutor.edad=edad;
        registroNuevo->persona_locutor.cedula=cedula;
        registroNuevo->empleado_locutor.id=id;
        registroNuevo->empleado_locutor.activo=1;
        registroNuevo->empleado_locutor.sueldo=sueldo;
        registroNuevo->sig=NULL;
    }
    return registroNuevo;
}


Locutor *insertarEnListaLocutores(char *nombre, char *apellido,int edad, int cedula, int id, int sueldo, Radio estacion_de_radio)
{
     Locutor *cabeza_de_listaAuxiliar ,*registroNuevo;
     registroNuevo=crearLocutor(nombre,apellido,edad,cedula,id,sueldo);

     //SI SE PUDO CREAR EL Locutor QUE SE INSERTE EN LA LISTA
     if(registroNuevo)
     {
          //SI LA LISTA ESTA VACIA
         if(!estacion_de_radio.lista_de_locutores)
               estacion_de_radio.lista_de_locutores=registroNuevo;
         else
         {
              //SE USA EL cabeza_de_lista AUXILIAR PARA MOVERSE ENTRE LOS LocutorS
              cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_locutores;
              while(cabeza_de_listaAuxiliar->sig)
                cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;
              cabeza_de_listaAuxiliar->sig=registroNuevo;
         }
    }
    return estacion_de_radio.lista_de_locutores;
}

Secretaria * crearSecretaria( char *nombre, char *apellido,int edad, int cedula, int id,int sueldo)
{
    //CREANDO LA SECRETARIA
    Secretaria *registroNuevo;
    registroNuevo=(Locutor*)malloc(sizeof(Locutor));

    //SINO SE PUDO RESERVAR MEMORIA PARA EL REGISTRO
    if(!registroNuevo)
    {
       printf("No se pudo crear memoria para el registro\n");
       return NULL;
    }
    else
    {
        //SI SE PUDO RESERVAR LA MEMORIA SE REGISTRAN LOS DATOS
        registroNuevo->persona_secretaria.nombre=nombre;
        registroNuevo->persona_secretaria.apellido=apellido;
        registroNuevo->persona_secretaria.edad=edad;
        registroNuevo->persona_secretaria.cedula=cedula;
        registroNuevo->empleado_secretaria.id=id;
        registroNuevo->empleado_secretaria.activo=1;
        registroNuevo->empleado_secretaria.sueldo=sueldo;
        registroNuevo->sig=NULL;
    }
    return registroNuevo;
}

Secretaria *insertarEnListaSecretarias(char *nombre, char *apellido,int edad, int cedula, int id, int sueldo, Radio estacion_de_radio)
{
     Secretaria *cabeza_de_listaAuxiliar ,*registroNuevo;
     registroNuevo=crearSecretaria(nombre,apellido,edad,cedula,id,sueldo);

     //SI SE PUDO CREAR LA SECRETARIA QUE SE INSERTE EN LA LISTA
     if(registroNuevo)
     {
          //SI LA LISTA ESTA VACIA
         if(!estacion_de_radio.lista_de_secretarias)
               estacion_de_radio.lista_de_secretarias=registroNuevo;
         else
         {
              //SE USA EL cabeza_de_lista AUXILIAR PARA MOVERSE ENTRE LOS LocutorS
              cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_secretarias;
              while(cabeza_de_listaAuxiliar->sig)
                cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;
              cabeza_de_listaAuxiliar->sig=registroNuevo;
         }
    }
    return estacion_de_radio.lista_de_secretarias;
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
        case 1: registroLocutor(estacion_de_radio); break;
        case 2: registroSecretaria(estacion_de_radio);break;
        case 3: eliminarLocutor(estacion_de_radio);break;
        case 4: break;
        case 5: mostrarListaDeLocutores(estacion_de_radio); break;
        case 6: mostrarListaDeSecretarias(estacion_de_radio);break;
        case 7: menu(); break;
        default : gotoxy(30,40);
                  textcolor(RED);
                  printf("%cLa opcion que ingreso no es correcta!",173);
                  Sleep(1000);
                  system("cls");
    }
    }while(op!=7);

}

void registroSecretaria(Radio estacion_de_radio)
{
    system("cls");
    char aux[50];
    char *nombre;
    char *apellido;
    int edad;
    int cedula;
    int sueldo;
    static int id=0;

    textcolor(WHITE);
    printf("Ingrese el nombre de la nueva secretaria:\n");
    fflush(stdin);
    gets(aux);
    nombre=(char*)malloc((strlen(aux)+1)*sizeof(char));
     if (nombre)
        strcpy(nombre,aux);
     else
        printf("Error no se ha podido crear espacio de memoria para el nombre \n");

    printf("Ingrese el apellido de la nueva secretaria:\n");
    fflush(stdin);
    gets(aux);
    apellido=(char*)malloc((strlen(aux)+1)*sizeof(char));
    if (apellido)
        strcpy(apellido,aux);
    else
        printf("Error no se ha podido crear espacio de memoria para el apellido\n");

    free(aux);
    printf("Ingrese la cedula de la nueva secretaria\n");
    scanf("%i",&cedula);

    printf("Ingrese la edad de la nueva secretaria: \n");
    scanf("%i",&edad);

    printf("Ingrese el sueldo de la nueva secretaria: \n");
    scanf("%i",&sueldo);
    id++;

    estacion_de_radio.lista_de_secretarias = insertarEnListaSecretarias(nombre,apellido,edad,cedula,id,sueldo, estacion_de_radio);

    printf("SECRETARIA REGISTRADA PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);

}

void registroLocutor(Radio estacion_de_radio)
{
    system("cls");
    char aux[50];
    char *nombre;
    char *apellido;
    int edad;
    int cedula;
    int sueldo;
    static int id=0;

    textcolor(WHITE);

    printf("Ingrese el nombre del nuevo locutor: \n");
    fflush(stdin);
    gets(aux);
    nombre=(char*)malloc((strlen(aux)+1)*sizeof(char));
     if (nombre)
        strcpy(nombre,aux);
     else
        printf("Error no se ha podido crear espacio de memoria para el nombre \n");

    printf("Ingrese el apellido del nuevo locutor: \n");
    fflush(stdin);
    gets(aux);
    apellido=(char*)malloc((strlen(aux)+1)*sizeof(char));
    if (apellido)
        strcpy(apellido,aux);
    else
        printf("Error no se ha podido crear espacio de memoria para el apellido \n");

    free(aux);
    printf("Ingrese la cedula del locutor \n");
    scanf("%i",&cedula);

    printf("Ingrese la edad del nuevo locutor: \n");
    scanf("%i",&edad);

    printf("Ingrese el sueldo del nuevo locutor: \n");
    scanf("%i",&sueldo);
    id++;

    estacion_de_radio.lista_de_locutores = insertarEnListaLocutores(nombre,apellido,edad,cedula,id,sueldo, estacion_de_radio);

    printf("LOCUTOR REGISTRADO PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);

}

void eliminarLocutor(Radio estacion_de_radio)
{
    int cedula;
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

void mostrarListaDeLocutores(Radio estacion_de_radio)
{
    system("cls");
    int i;
    Locutor *cabeza_de_listaAuxiliar;
    cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_locutores;

    textcolor(DARKGRAY);
    printf("\n");

    printf("%-8s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Locutor","Nombre","Apellido","Cedula","Edad","Sueldo","Nombre del programa");

    for(i=2;i<119;i++){
        printf("%c",196);
       }
    printf("\n");
    textcolor(WHITE);
    while(cabeza_de_listaAuxiliar)
    {

       printf("%-8s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",cabeza_de_listaAuxiliar->empleado_locutor.id,
       cabeza_de_listaAuxiliar->persona_locutor.nombre,
       cabeza_de_listaAuxiliar->persona_locutor.apellido,
       cabeza_de_listaAuxiliar->persona_locutor.cedula,
       cabeza_de_listaAuxiliar->persona_locutor.edad,
       cabeza_de_listaAuxiliar->empleado_locutor.sueldo,
       "Nombre del programa");

        cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;

    }
    printf("\n");
    printf("\t \t \t \t \t PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
    controlDeUsuarios(estacion_de_radio);
}

void mostrarListaDeSecretarias(Radio estacion_de_radio)
{
    system("cls");

    int i;
    Secretaria *cabeza_de_listaAuxiliar;
    cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_secretarias;

    textcolor(DARKGRAY);
    printf("\n");

    printf("%-8s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"," ","Id Secretaria","Nombre","Apellido","Cedula","Edad","Sueldo","Horario");

    for(i=2;i<119;i++){
        printf("%c",196);
       }
    printf("\n");
    textcolor(WHITE);
    while(cabeza_de_listaAuxiliar)
    {

       printf("%-8s %-20i %-10s %-10s %-10i %-10i %-10i %-10s \n"," ",cabeza_de_listaAuxiliar->empleado_secretaria.id,
       cabeza_de_listaAuxiliar->persona_secretaria.nombre,
       cabeza_de_listaAuxiliar->persona_secretaria.apellido,
       cabeza_de_listaAuxiliar->persona_secretaria.cedula,
       cabeza_de_listaAuxiliar->persona_secretaria.edad,
       cabeza_de_listaAuxiliar->empleado_secretaria.sueldo,
       "Horario");

        cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;

    }
    printf("\n");
    printf("\t \t \t \t \t PRESIONA CUALQUIER TECLA PARA VOLVER...");
    getch();
    controlDeUsuarios(estacion_de_radio);
}

