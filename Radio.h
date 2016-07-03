#ifndef _RADIO_H_//isnotdefine
#define _RADIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

typedef struct persona
{
    int edad;
    char *nombre;
    char *apellido;
    int cedula;
}Persona;

typedef struct empleado{
    int sueldo;
    int horario_de_entrada;
    int horario_de_salida;
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
    char *password;
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

void diseno();
Radio inicializarListas(Radio estacion_de_radio);
Locutor * crearLocutor( char *nombre, char *apellido,int edad, int cedula, int id,int sueldo);
Locutor *insertarEnListaLocutores(char *nombre, char *apellido,int edad, int cedula, int id, int sueldo,Radio estacion_de_radio );
Secretaria * crearSecretaria( char *nombre, char *apellido,int edad, int cedula, int id,int sueldo);
Secretaria *insertarEnListaSecretarias(char *nombre, char *apellido,int edad, int cedula, int id, int sueldo, Radio estacion_de_radio);
void controlDeUsuarios(Radio estacion_de_radio);
void registroLocutor(Radio estacion_de_radio);
void registroSecretaria(Radio estacion_de_radio);
void mostrarListaDeLocutores(Radio estacion_de_radio);
void mostrarListaDeSecretarias(Radio estacion_de_radio);
void eliminarLocutor(Radio estacion_de_radio);

#endif
