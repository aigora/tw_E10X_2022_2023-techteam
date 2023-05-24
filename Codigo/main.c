#include <stdio.h>

#include "menu_principal.h"
#include "estructuras_de_datos.h"
#include "sesion_usuario.h"
#include "sesion_incognito.h"

void buclePrincipal();

int main()
{
    buclePrincipal();
    return 0;
}

void buclePrincipal()
{
    int modo = volver;
    while (modo == volver)
    {
        switch (menuPrincipal())
        {
        case modoUsuario:
            modo = sesionUsuario();
            break;
        case modoIncognito:
            modo = sesionIcognito();
            break;
        case salir:
            // salir del programa
            modo = salir;
            break;
        default:
            break;
        }
    }
    printf("Saliendo del programa.\n");
}