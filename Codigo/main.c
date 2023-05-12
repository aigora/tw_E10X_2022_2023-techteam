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
    switch (menuPrincipal())
    {
    case modoUsuario:
        sesionUsuario();
        break;
    case modoIncognito:
        sesionIcognito();
        break;
    default:
        break;
    }
    printf("Saliendo del programa.\n");
}