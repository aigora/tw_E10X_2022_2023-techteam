enum eleccionModo{modoIncognito = 0, modoUsuario = 1};

enum volverOSalir{volver = 0, salir = -1};

#define N 50

typedef struct
{
    char nombre[N];
    char contrasena[N];
    // mas cosas para guardar los datos
}usuario;