enum eleccionModo{salir = -1, volver = 0, quedar = 1, modoIncognito = 2, modoUsuario = 3};

#define N 100

typedef struct
{
    char nombre[N];
    char contrasena[N];

    char preguntaSeguridad[N];
    char respuestaSeguridad[N];

    // mas cosas para guardar los datos
}usuario;