#include <stdio.h>

#include "estructuras_de_datos.h"

void sesionUsuario()
{
    printf("Has elegido el modo usuario.\n");

    char eleccion;
    do
    {
        printf("Eliga una de las opciones (Escriba el numero de la opcion).\n");
        printf("------------------------\n");
        printf("1. Iniciar una sesion\n");
        printf("2. Crear una cuenta\n");
        printf("\"q\" Salir del programa\n");
        printf("------------------------\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            // iniciar una sesion
            if(iniciarSesion() == salir){
                return;
            }
            break;
        case '2':
            // crear una cuenta
            if(crearCuenta() == salir){
                return;
            }
            break;
        case 'q':
            // nada, salir del programa
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (eleccion != 'q');
}

int iniciarSesion()
{
    usuario usuarioActual;
    printf("Para iniciar la sesion escriba el nombre del usuario.\n");
    scanf(" %s", usuarioActual.nombre);

    // iniciando una sesion
    return salir;
}

int crearCuenta()
{
    // creando nueva cuenta
    return salir;
}

int ayudaContrasena()
{
    // ayuda con una constrasena olvidada
    return salir;
}
