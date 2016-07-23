#ifndef _RADIO_H_//isnotdefine
#define _RADIO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#define ARCHIVO_LOCUTORES "Registros/Locutores/Locutores.bin"
#define ARCHIVO_SECRETARIAS "Registros/Secretarias/Secretarias.bin"
#define MAX_NOMBRE 20
#define MAX_APELLIDO 20

typedef struct persona
{
    int edad;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int cedula;
}Persona;

typedef struct empleado{
    int sueldo;
    //int horario_de_entrada;
    //int horario_de_salida;
    int activo;
    int id;
}Empleado;

typedef struct locutor{
    Persona persona_locutor;
    Empleado empleado_locutor;
    struct locutor *sig;
}Locutor;

typedef struct secretaria{
    Persona persona_secretaria;
    Empleado empleado_secretaria;
    //char *password;
    struct secretaria *sig;
    //Agregar_registro_de_locutor;
    //Agregar_registro_de_cliente;
    //Eliminar_registro_de_locutor;
    //Eliminar_registro_de_cliente;
}Secretaria;

typedef struct programas{
    char *Nombre_de_programa;
    int horario_de_inicio;
    int horario_de_fin;
    int coste_de_pauta;
    struct programas *sig;
    Locutor lista_de_locutores_asignados;
}Programas;

typedef struct boss{
    Persona persona_boss;
}Boss;

typedef struct radio{
    Locutor *lista_de_locutores;
    Secretaria *lista_de_secretarias;
    int disponibilidad_de_pautas;
    struct radio *sig;
    Boss dueno;
}Radio;

//DECLARACIÓN DE LAS FUNCIONES
//MENSAJES DE CONTROL
void pausar();
void errorCritico();
//MENU DE CONTROL DE USUARIO
void controlDeUsuarios(Radio *estacion_de_radio);
//INICIAR LAS LISTAS DE LA RADIO
static void recorrerLista(void * nodo);
void iniciarListas(Radio *estacion_de_radio);
void cargarListaLocutores(Radio *estacion_de_radio);
//GUARDAR REGISTROS DE LOS ARCHIVOS
static void guardarLocutor(Locutor *nuevoLocutor);
static void guardarSecretaria(Secretaria *nuevaSecretaria);
//INGRESOS EN LA LISTA
static void ingresarLocutorALaLista(Radio *estacion_de_radio, Locutor *nuevoLocutor);
static void ingresarSecretariaALaLista(Radio *estacion_de_radio, Secretaria *nuevaSecretaria);
//VALIDACIONES DE LOS REGISTROS
static int validarNombre(char nombre[]);
static int validarCedula(Radio *estacion_de_radio, int cedula);
static int validarEdad(int edad);
//REGISTROS
void registroLocutor(Radio *estacion_de_radio);
void registroSecretaria(Radio *estacion_de_radio);
//MOSTRAR CONTENIDO
void mostrarListaDeLocutores();
//MUESTRA LA LISTA ENLAZADA
void mostrarListaDeLocutores2(Radio *estacion_de_radio);
void mostrarListaDeSecretarias();
//MODIFICACIONES DE REGISTRO
Locutor * buscarLocutor(Radio * estacion_de_radio,Locutor *locutorAModificar);
static void modificarRegistroLocutor(Radio * estacion_de_radio);
static Locutor * eliminarLocutor(Radio *estacion_de_radio , Locutor *locutorAModificar);

void eliminarListaLocutor(Radio * estacion_de_radio);
void eliminarListaSecretarias(Radio * estacion_de_radio);

#endif
