#ifndef _RADIO_H_//isnotdefine
#define _RADIO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#define ARCHIVO_LOCUTORES "Registros/Locutores/Locutores.bin"
#define ARCHIVO_SECRETARIAS "Registros/Secretarias/Secretarias.bin"
#define ARCHIVO_CLIENTES "Registros/Clientes/Clientes.bin"
#define ARCHIVO_PROGRAMAS "Registros/Programas/Programas.bin"
#define ARCHIVO_LOCUTORES_EN_PROGRAMAS "Registros/Programas/Locutores_Asignados.bin"
#define MAX_NOMBRE 20

typedef struct persona
{
    int edad;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
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
    char password[12];
    struct secretaria *sig;
}Secretaria;

typedef struct cliente{
    Persona persona_cliente;
    char nombre_empresa[MAX_NOMBRE];
    int id;
    int cotizacion;
    struct cliente *sig;
}Cliente;

typedef struct programas{
    char nombre_de_programa[MAX_NOMBRE];
    int id;
    Locutor *lista_locutores;
    Cliente *lista_clientes;
    int horario_de_inicio;
    int horario_de_fin;
    int coste_de_pauta;
    struct programas *sig;
}Programa;

typedef struct boss{
    //Persona persona_boss;
    int ingresos;
    int egresos;
}Boss;

typedef struct radio{
    Locutor *lista_de_locutores;
    Secretaria *lista_de_secretarias;
    Cliente *lista_de_clientes;
    Programa *lista_de_programas;
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
//MENU DE CONTROL DE CLIENTES
void controlDeClientes(Radio *estacion_de_radio);
//MENU DE CONTROL DE PROGRAMAS
void controlDeProgramas(Radio *estacion_de_radio);
//INICIAR LAS LISTAS DE LA RADIO
static void recorrerLista(void * nodo);
void iniciarListas(Radio *estacion_de_radio);
void cargarListaLocutores(Radio *estacion_de_radio);
void cargarListaClientes(Radio *estacion_de_radio);
void cargarListaSecretarias(Radio *estacion_de_radio);
//GUARDAR REGISTROS DE LOS ARCHIVOS
static void guardarCliente(Cliente *nuevoCliente);
static void guardarLocutor(Locutor *nuevoLocutor);
static void guardarSecretaria(Secretaria *nuevaSecretaria);
static void guardarPrograma(Programa *nuevoPrograma);
//INGRESOS EN LA LISTA
static void ingresarClienteALaLista(Radio *estacion_de_radio, Cliente *nuevoCliente);
static void ingresarLocutorALaLista(Radio *estacion_de_radio, Locutor *nuevoLocutor);
static void ingresarSecretariaALaLista(Radio *estacion_de_radio, Secretaria *nuevaSecretaria);
static void ingresarProgramaALaLista(Radio *estacion_de_radio, Programa *nuevoPrograma);
//VALIDACIONES DE LOS REGISTROS
static int validarNombre(char nombre[]);
static int validarCedula(Radio *estacion_de_radio, int cedula);
static int validarNombreDelPrograma(char nombre[]);
//REGISTROS
void registroLocutor(Radio *estacion_de_radio);
void registroSecretaria(Radio *estacion_de_radio);
void registroCliente(Radio *estacion_de_radio);
void registroPrograma(Radio *estacion_de_radio);
//MOSTRAR CONTENIDO
void mostrarListaDeProgramas(Radio * estacion_de_radio);
void mostrarOpcionesDeProgramas(Radio * estacion_de_radio);
void mostrarListaDeLocutores();
void mostrarListaDeSecretarias();
void mostrarListaDeClientes();
void mostrarReportes(Radio * estacion_de_radio);
//MUESTRA LA LISTA ENLAZADA
void mostrarListaDeLocutores2(Radio *estacion_de_radio);
//MODIFICACIONES DE REGISTRO
Locutor * buscarLocutor(Radio * estacion_de_radio,Locutor *locutorAModificar);
Secretaria * buscarSecretaria(Radio * estacion_de_radio,Secretaria *secretariaAModificar);
Programa * seleccionarPrograma(Radio * estacion_de_radio,Programa *programaAModificar);
static void modificarRegistroLocutor(Radio * estacion_de_radio);
static void modificarRegistroSecretaria(Radio * estacion_de_radio);
static void modificarRegistroPrograma(Radio * estacion_de_radio);
static Locutor * eliminarLocutor(Radio *estacion_de_radio , Locutor *locutorAModificar);
static Secretaria * eliminarSecretaria(Radio *estacion_de_radio, Secretaria *secretariaAModificar);

void eliminarListaClientes(Radio *estacion_de_radio);
void eliminarListaLocutor(Radio * estacion_de_radio);
void eliminarListaSecretarias(Radio * estacion_de_radio);
void eliminarListaProgramas(Radio *estacion_de_radio);
static void salirDelPrograma(Radio *estacion_de_radio);

#endif
