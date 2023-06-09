#ifndef ESTRUCTURAS_DE_DATOS_H
#define ESTRUCTURAS_DE_DATOS_H

enum eleccionModo
{
    salir = -1,
    volver = 0,
    quedar = 1,
    modoIncognito = 2,
    modoUsuario = 3
};

enum estadoSesionUsuario
{
    sesionCerrada = 0,
    sesionAbierta = 1
};

#define Npequeno 100
#define Ngrande 3000
#define numeroTiposDeGeneracion 17 // numero cuantos tipos de generacion hay empezando con 1
#define numeroColumnas 25          // numero de columnas en el archivo empezando con 1

typedef struct // struct para calculos guardados
{
    char nombre[Npequeno];
    char valor[Npequeno];
} calculoGuardado;

typedef struct
{
    char nombre[Npequeno];
    char contrasena[Npequeno];

    char preguntaSeguridad[Npequeno];
    char respuestaSeguridad[Npequeno];

    int sesionEstado; //si la sesion esta abierta o cerrada

    calculoGuardado calculosGuardados[Npequeno];
    int numeroCalculosGuardados;
} usuario;

typedef struct // struct para cada tipo de generacion
{
    char nombre[Npequeno];
    float valores[numeroColumnas - 1];
    float min, max, media;
} tipoGeneracion;

typedef struct // struct para cada tipo de generacion
{
    int mes;
    int ano;
} fecha;

typedef struct // struct para todos los tipos de generacion
{
    tipoGeneracion TiposGeneracion[numeroTiposDeGeneracion];

    char titulo[Npequeno];
    char sistemaElectrico[Npequeno];
    char magnitudes[Npequeno];
    fecha fechas[Npequeno];

} generacionElectrica;

typedef struct
{
    int mes1, anio1, mes2, anio2;
    float media;
    int total_Meses;
    float valor_maximo;
    float valor_minimo;
    float suma_total;
    float generacionMasUsada;
    float generacionMenosUsada;
} datosParaCalculos;

#endif