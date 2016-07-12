#ifndef _RADIO_H_//isnotdefine
#define _RADIO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#define ARCHIVO_LOCUTORES "Registros/Locutores/Locutores.bin"
#define ARCHIVO_SECRETARIAS "Registros/Secretarias/Secretarias.bin"
#define MAX_NOMBRE 30
#define MAX_APELLIDO 50

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
//INICIAR LAS LISTAS DE LA RADIO
void iniciarListas(Radio *estacion_de_radio);
//GUARDAR REGISTROS DE LOS ARCHIVOS
void guardarLocutor(Locutor *nuevoLocutor);
void guardarSecretaria(Secretaria *nuevaSecretaria);
//INGRESOS EN LA LISTA
void ingresarLocutorALaLista(Radio *estacion_de_radio, Locutor *nuevoLocutor);
void ingresarSecretariaALaLista(Radio *estacion_de_radio, Secretaria *nuevaSecretaria);
//REGISTROS
void registroLocutor(Radio *estacion_de_radio);
void registroSecretaria(Radio *estacion_de_radio);
//MOSTRAR CONTENIDO
void mostrarListaDeLocutores();
void mostrarListaDeSecretarias();
void eliminarListaLocutor(Radio * estacion_de_radio);
//void eliminarLocutor(Radio estacion_de_radio);

#endif
