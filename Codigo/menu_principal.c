#include <stdio.h>
#include <stdbool.h>

#include "estructuras_de_datos.h"
#include "menu_principal.h"

int menuPrincipal()
{

    printf("Bienvenidos al programa!\n");
    printf("Puedes usar el programa en el modo Incognito o iniciar la sesion.\n");
    char eleccion;

    do
    {
        printf("Escriba \"0\" para elegir el modo Incognito o \"1\" para iniciar la sesion.\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '0':
            return modoIncognito;
            break;
        case '1':
            return modoUsuario;
            break;
        case 'q':
            return salir;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (true);
}
