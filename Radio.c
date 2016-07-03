//AQUI ESTARAN LAS FUNCIONES DE LA LIBRERIA
#include "Radio.h"


void diseno(){
    int i;

    //R
    textcolor(WHITE);
    for(i=3;i<10;i++){
        gotoxy(30,i);
        printf("%c",178);

    }

    for(i=30;i<40;i++){
        gotoxy(i,3);
        printf("%c",178);
    }

    for(i=3;i<7;i++){
        gotoxy(40,i);
        printf("%c",178);
    }
    for(i=3;i<6;i++){
        gotoxy(40,i);
        printf("%c",178);
    }
    for(i=30;i<40;i++){
        gotoxy(i,6);
        printf("%c",178);
    }
    int j=39;
    for(i=7;i<10;i++){
        gotoxy(j++,i);
        printf("%c",178);
    }

    //A
    for(i=3;i<10;i++){
        gotoxy(44,i);
        printf("%c",178);

    }
    for(i=44;i<54;i++){
        gotoxy(i,3);
        printf("%c",178);
    }
    for(i=3;i<10;i++){
        gotoxy(54,i);
        printf("%c",178);
    }
    for(i=45;i<53;i++){
        gotoxy(i,6);
        printf("%c",178);
    }

    //D
    for(i=3;i<10;i++){
        gotoxy(58,i);
        printf("%c",178);
    }

    for(i=58;i<66;i++){
        gotoxy(i,3);
        printf("%c",178);
    }
     for(i=58;i<66;i++){
        gotoxy(i,9);
        printf("%c",178);
    }
     j=66;
    for(i=4;i<6;i++){
        gotoxy(j++,i);
        printf("%c",178);
    }

    for(i=6;i<8;i++){
        gotoxy(67,i);
        printf("%c",178);
    }
        gotoxy(66,8);
        printf("%c",178);

    //I
      for(i=3;i<10;i++){
        gotoxy(72,i);
        printf("%c",178);
    }

    //O
     for(i=3;i<10;i++){
        gotoxy(76,i);
        printf("%c",178);
    }
    for(i=77;i<88;i++){
        gotoxy(i,3);
        printf("%c",178);
    }
     for(i=3;i<10;i++){
        gotoxy(88,i);
        printf("%c",178);
    }
    for(i=77;i<88;i++){
        gotoxy(i,9);
        printf("%c",178);
    }

    //U
    textcolor(LIGHTBLUE);
    for(i=12;i<19;i++){
        gotoxy(30,i);
        printf("%c",178);
    }
    for(i=30;i<40;i++){
        gotoxy(i,18);
        printf("%c",178);
    }
    for(i=12;i<19;i++){
        gotoxy(40,i);
        printf("%c",178);
    }
    //N
    for(i=12;i<19;i++){
        gotoxy(46,i);
        printf("%c",178);
    }
    j=47;
    for(i=12;i<19;i++){
        gotoxy(j++,i);
        printf("%c",178);
    }

    for(i=12;i<19;i++){
        gotoxy(54,i);
        printf("%c",178);
    }
    //E
    for(i=12;i<19;i++){
        gotoxy(60,i);
        printf("%c",178);
    }
    for(i=60;i<70;i++){
        gotoxy(i,12);
        printf("%c",178);
    }
    for(i=60;i<67;i++){
        gotoxy(i,15);
        printf("%c",178);
    }
    for(i=60;i<70;i++){
        gotoxy(i,18);
        printf("%c",178);
    }

    //G
    for(i=12;i<19;i++){
        gotoxy(76,i);
        printf("%c",178);
    }

    for(i=76;i<87;i++){
        gotoxy(i,12);
        printf("%c",178);
    }

    for(i=76;i<89;i++){
        gotoxy(i,18);
        printf("%c",178);
    }
    for(i=18;i>15;i--){
        gotoxy(88,i);
        printf("%c",178);
    }

    for(i=84;i<89;i++){
        gotoxy(i,15);
        printf("%c",178);
    }

    //Marco
    textcolor(LIGHTGRAY);
    //Esquinas
    gotoxy(1,1);
    printf("%c",201);
    gotoxy(118,1);
    printf("%c",187);
    gotoxy(1,47);
    printf("%c",200);
    gotoxy(118,47);
    printf("%c",188);

    for(i=2;i<118;i++){
        gotoxy(i,1);
        printf("%c",205);
    }

    for(i=2;i<118;i++){
        gotoxy(i,47);
        printf("%c",205);
    }
    for(i=2;i<23;i++){
        gotoxy(1,i);
        printf("%c",186);
    }
    for(i=23;i<47;i++){
        gotoxy(1,i);
        printf("%c",186);
    }

    for(i=2;i<23;i++){
        gotoxy(118,i);
        printf("%c",186);
    }
    for(i=23;i<47;i++){
        gotoxy(118,i);
        printf("%c",186);
    }
    for(i=2;i<23;i++){
        gotoxy(1,i);
        printf("%c",186);
    }

    for(i=2;i<118;i++){
        gotoxy(i,22);
        printf("%c",205);
    }

    gotoxy(1,22);
    printf("%c",204);
     gotoxy(118,22);
    printf("%c",185);



    gotoxy(37,21);
    textcolor(LIGHTRED);
    printf("SISTEMA DE GESTION DE PUBLICIDAD DE LA RADIO \n",224);

    gotoxy(35,48);
    textcolor(DARKGRAY);
    printf("Desarrollado por: Mauricio Brito y Luis Prado");

}

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
    system("cls");
    do{
    diseno();

    textcolor(WHITE);
    gotoxy(30,26);
    printf("[1] Registro de locutores");
    gotoxy(30,28);
    printf("[2] Registro de secretaria");
    gotoxy(30,30);
    printf("[3] Modificar registro de locutor");
    gotoxy(30,32);
    printf("[4] Modificar registro de secretaria");
    gotoxy(30,34);
    printf("[5] Mostrar listado de locutores");
    gotoxy(30,36);
    printf("[6] Mostrar listado de secretarias");
    gotoxy(30,38);
    printf("[7] Menu principal");
    gotoxy(30,40);
    textcolor(YELLOW);
    printf("Ingrese la opcion:");
    textcolor(WHITE);scanf("%i",&op);

    switch(op){
        case 1: registroLocutor(estacion_de_radio); break;
        case 2: registroSecretaria(estacion_de_radio);break;
        case 3: break;
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
    }while((int)op<1 || (int)op>7);

}

void registroSecretaria(Radio estacion_de_radio)
{
    system("cls");
    diseno();
    char aux[50];
    char *nombre;
    char *apellido;
    int edad;
    int cedula;
    int sueldo;
    static int id=0;

    textcolor(WHITE);
    gotoxy(3,26);
    printf("Ingrese el nombre de la nueva secretaria:");
    fflush(stdin);
    gotoxy(3,27);
    gets(aux);
    nombre=(char*)malloc((strlen(aux)+1)*sizeof(char));
     if (nombre)
        strcpy(nombre,aux);
     else
        printf("Error no se ha podido crear espacio de memoria para el nombre");

    gotoxy(3,28);
    printf("Ingrese el apellido de la nueva secretaria:");
    fflush(stdin);
    gotoxy(3,29);
    gets(aux);
    apellido=(char*)malloc((strlen(aux)+1)*sizeof(char));
    if (nombre)
        strcpy(apellido,aux);
    else
        printf("Error no se ha podido crear espacio de memoria para el apellido");


    gotoxy(3,30);
    printf("Ingrese la cedula de la nueva secretaria");
    gotoxy(3,31);
    scanf("%i",&cedula);

    gotoxy(3,32);
    printf("Ingrese la edad de la nueva secretaria: ");
    gotoxy(3,33);
    scanf("%i",&edad);
    gotoxy(3,34);

    printf("Ingrese el sueldo de la nueva secretaria: ");
    gotoxy(3,35);
    scanf("%i",&sueldo);
    id++;

    estacion_de_radio.lista_de_secretarias = insertarEnListaSecretarias(nombre,apellido,edad,cedula,id,sueldo, estacion_de_radio);

    gotoxy(39,45);
    printf("SECRETARIA REGISTRADA PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);

}

void registroLocutor(Radio estacion_de_radio)
{
    system("cls");
    diseno();
    char aux[50];
    char *nombre;
    char *apellido;
    int edad;
    int cedula;
    int sueldo;
    static int id=0;

    textcolor(WHITE);
    gotoxy(3,26);
    printf("Ingrese el nombre del nuevo locutor:");
    fflush(stdin);
    gotoxy(3,27);
    gets(aux);
    nombre=(char*)malloc((strlen(aux)+1)*sizeof(char));
     if (nombre)
        strcpy(nombre,aux);
     else
        printf("Error no se ha podido crear espacio de memoria para el nombre");

    gotoxy(3,28);
    printf("Ingrese el apellido del nuevo locutor:");
    fflush(stdin);
    gotoxy(3,29);
    gets(aux);
    apellido=(char*)malloc((strlen(aux)+1)*sizeof(char));
    if (nombre)
        strcpy(apellido,aux);
    else
        printf("Error no se ha podido crear espacio de memoria para el apellido");


    gotoxy(3,30);
    printf("Ingrese la cedula del locutor");
    gotoxy(3,31);
    scanf("%i",&cedula);

    gotoxy(3,32);
    printf("Ingrese la edad del nuevo locutor: ");
    gotoxy(3,33);
    scanf("%i",&edad);
    gotoxy(3,34);

    printf("Ingrese el sueldo del nuevo locutor: ");
    gotoxy(3,35);
    scanf("%i",&sueldo);
    id++;

    estacion_de_radio.lista_de_locutores = insertarEnListaLocutores(nombre,apellido,edad,cedula,id,sueldo, estacion_de_radio);

    gotoxy(39,45);
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

    gotoxy(39,45);
    printf("PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);
}

void mostrarListaDeLocutores(Radio estacion_de_radio)
{
    system("cls");
    diseno();
    int i;
    Locutor *cabeza_de_listaAuxiliar;
    cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_locutores;

    textcolor(WHITE);
    gotoxy(8,26);
    printf("Id Locutor");
    gotoxy(26,26);
    printf("Nombre");
    gotoxy(40,26);
    printf("Apellido");
    gotoxy(54,26);
    printf("Cedula");
    gotoxy(68,26);
    printf("Edad");
    gotoxy(76,26);
    printf("Sueldo");
    gotoxy(84,26);
    printf("Nombre del programa");

    for(i=2;i<118;i++){
        gotoxy(i,27);
        printf("%c",196);
       }
    int  n=28;
    while(cabeza_de_listaAuxiliar)
    {
        gotoxy(8,n);
        printf("%i",cabeza_de_listaAuxiliar->empleado_locutor.id);
        gotoxy(26,n);
        printf("%s",cabeza_de_listaAuxiliar->persona_locutor.nombre);
        gotoxy(40,n);
        printf("%s",cabeza_de_listaAuxiliar->persona_locutor.apellido);
        gotoxy(68,n);
        printf("%i \n",cabeza_de_listaAuxiliar->persona_locutor.edad);
        gotoxy(54,n);
        printf("%i ",cabeza_de_listaAuxiliar->persona_locutor.cedula);
        gotoxy(76,n);
        printf("%i ",cabeza_de_listaAuxiliar->empleado_locutor.sueldo);
        cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;
        n++;
    }

    gotoxy(39,45);
    printf("PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);
}

void mostrarListaDeSecretarias(Radio estacion_de_radio)
{
    system("cls");
    diseno();
    int i;
    Secretaria *cabeza_de_listaAuxiliar;
    cabeza_de_listaAuxiliar=estacion_de_radio.lista_de_secretarias;

    textcolor(WHITE);
    gotoxy(8,26);
    printf("Id Secretaria");
    gotoxy(26,26);
    printf("Nombre");
    gotoxy(40,26);
    printf("Apellido");
    gotoxy(54,26);
    printf("Cedula");
    gotoxy(68,26);
    printf("Edad");
    gotoxy(76,26);
    printf("Sueldo");


    for(i=2;i<118;i++){
        gotoxy(i,27);
        printf("%c",196);
       }
    int  n=28;
    while(cabeza_de_listaAuxiliar)
    {
        gotoxy(8,n);
        printf("%i",cabeza_de_listaAuxiliar->empleado_secretaria.id);
        gotoxy(26,n);
        printf("%s",cabeza_de_listaAuxiliar->persona_secretaria.nombre);
        gotoxy(40,n);
        printf("%s",cabeza_de_listaAuxiliar->persona_secretaria.apellido);
        gotoxy(68,n);
        printf("%i \n",cabeza_de_listaAuxiliar->persona_secretaria.edad);
        gotoxy(54,n);
        printf("%i ",cabeza_de_listaAuxiliar->persona_secretaria.cedula);
        gotoxy(76,n);
        printf("%i ",cabeza_de_listaAuxiliar->empleado_secretaria.sueldo);
        cabeza_de_listaAuxiliar=cabeza_de_listaAuxiliar->sig;
        n++;
    }

    gotoxy(39,45);
    printf("PRESIONA CUALQUIER TECLA PARA VOLVER...",224);
    getch();
    controlDeUsuarios(estacion_de_radio);
}

