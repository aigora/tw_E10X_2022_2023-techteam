enum eleccionModo{salir = -1, volver = 0, quedar = 1, modoIncognito = 2, modoUsuario = 3};

#define Npequeno 100
#define Ngrande 3000
#define numeroTiposDeGeneracion 17 //numero cuantos tipos de generacion hay empezando con 1
#define numeroColumnas 25 // numero de columnas en el archivo empezando con 1

typedef struct
{
    char nombre[Npequeno];
    char contrasena[Npequeno];

    char preguntaSeguridad[Npequeno];
    char respuestaSeguridad[Npequeno];

    // mas cosas para guardar los datos
}usuario;

typedef struct //struct para cada tipo de generacion
{
    char nombre[Npequeno];
    float valores[numeroColumnas-1];
	float min,max,media;
}tipoGeneracion;

typedef struct //struct para cada tipo de generacion
{
    int mes;
    int ano;
}fecha;

typedef struct //struct para todos los tipos de generacion
{
    tipoGeneracion TiposGeneracion[numeroTiposDeGeneracion];

    char titulo[Npequeno];
    char sistemaElectrico[Npequeno];
    char magnitudes[Npequeno];
    fecha fechas[Npequeno];

}generacionElectrica;

