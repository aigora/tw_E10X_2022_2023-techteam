#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "estructuras_de_datos.h"

int sesionUsuario()
{
    printf("\nHas elegido el modo usuario.\n");

    char eleccion;
    do
    {
        printf("\nEliga una de las opciones (Escriba el numero de la opcion).\n");
        printf("------------------------\n");
        printf("1. Iniciar una sesion\n");
        printf("2. Crear una cuenta\n");
        printf("\"v\" Volver a la ultima pantalla\n");
        printf("\"q\" Salir del programa\n");
        printf("------------------------\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            // iniciar una sesion
            if (iniciarSesion() == salir)
            {
                return salir;
            }
            break;
        case '2':
            // crear una cuenta
            if (crearCuenta() == salir)
            {
                return salir;
            }
            break;
        case 'v':
            // volver a la ultima pantalla
            return volver;
            break;
        case 'q':
            // nada, salir del programa
            return salir;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (eleccion != 'q');

    return salir;
}

int iniciarSesion()
{
    usuario usuarioActual;
    printf("Para iniciar la sesion escriba el nombre del usuario.\n");
    scanf(" %s", usuarioActual.nombre);
    printf("Ahora escriba la contrasena.\n");
    scanf(" %s", usuarioActual.contrasena);

    // ver si existe este usuario y si la contrasena es correcta

    // iniciando una sesion
    return salir;
}

int crearCuenta()
{
    // creando nueva cuenta
    usuario usuarioNuevo;
    // preguntando el nombre y la contrasena
    printf("Para crear la cuenta escriba un nombre del usuario.\n");
    scanf(" %s", usuarioNuevo.nombre);
    printf("Ahora escriba su constrasena.\n");
    do
    {
        printf("La contrasena debe tener el minimo 5 caracteres con una letra minuscula, una letra mayuscula, y una cifra.\n");
        scanf(" %s", usuarioNuevo.contrasena);
        if (usuarioNuevo.contrasena[1] == '\0')
        {
            if (usuarioNuevo.contrasena[0] == 'q')
            {
                return salir;
            }
            else if (usuarioNuevo.contrasena[0] == 'v')
            {
                return volver;
            }
        }

    } while (!contrasenaCorrecta(usuarioNuevo.contrasena));
    
    // preguntando la pregunta de seguridad
    int eleccion;
    eleccion = eleccionPreguntaSeguridad(&usuarioNuevo);
    switch (eleccion)
    {
    case salir:
        return salir;
        break;
    case volver:
        return volver;
        break;
    default:
        break;
    }

    //el programa crea un usuario y una contrasena y la almacena en un nombredelusuario.txt
    FILE *pf = fopen(usuarioNuevo.nombre, "w");
    if (pf == NULL)
	 {
        printf("No se pudo crear el archivo.\n");
        return 1;
    }
    // Guardar nombre y contrasena en el archivo
    fprintf(pf, "nombre: %s\ncontrasena: %s\n", usuarioNuevo.nombre, usuarioNuevo.contrasena);
    fprintf(pf, "preguntaSeguridad: %s\nrespuestaSeguridad: %s\n", usuarioNuevo.preguntaSeguridad, usuarioNuevo.respuestaSeguridad);
    // Cerrar el archivo
    fclose(pf);
    printf("----------Usuario guardado!----------\n");

    // abrir funciones del menu del incognito y usuario
    return salir;
}

int contrasenaCorrecta(char contrasena[])
{
    bool letraMinuscula = false;
    bool letraMayuscula = false;
    bool cifra = false;
    int i;
    for (i = 0; i < Npequeno; i++)
    {
        if (contrasena[i] == '\0')
        {
            break;
        }
        else if (contrasena[i] >= 'A' && contrasena[i] <= 'Z')
        {
            letraMayuscula = true;
        }
        else if (contrasena[i] >= 'a' && contrasena[i] <= 'z')
        {
            letraMinuscula = true;
        }
        else if (contrasena[i] >= '0' && contrasena[i] <= '9')
        {
            cifra = true;
        }
    }
    if (letraMayuscula && letraMinuscula && cifra && i >= 5)
    {
        return true;
    }
    printf("Tu contrasena no cumple las condiciones necesarias.\n");
    printf("Eliga otra o escriba \"q\" para salir del programa o \"v\" para volver a la ultima pantalla.\n");
    return false;
}

int eleccionPreguntaSeguridad(usuario *usuarioNuevo)
{
    char eleccion;
    printf("Para que no pierde al acceso a su cuenta ahora eliga una pregunta de seguridad.\n");
    char pregunta1[] = "Cual era su comida favorita?";
    char pregunta2[] = "Cual era el nombre de su primera mascota?";
    char pregunta3[] = "Cual era el nombre y apellido de su primera pareja?";
    do
    {
        printf("Escriba el numero para elegir la pregunta de seguridad. Puedes elegiru na de las tres.\n");
        printf("-----------------------\n");
        printf("[1] %s\n", pregunta1);
        printf("[2] %s\n", pregunta2);
        printf("[3] %s\n", pregunta3);

        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            strcpy(usuarioNuevo->preguntaSeguridad,pregunta1);
            break;
        case '2':
            strcpy(usuarioNuevo->preguntaSeguridad,pregunta2);
            break;
        case '3':
            strcpy(usuarioNuevo->preguntaSeguridad,pregunta3);
            break;
        case 'q':
            return salir;
            break;
        case 'v':
            return volver;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez, escriba \"q\" para salir del programa o \"v\" para volver a la ultima pantalla.\n");
            break;
        }
    } while (eleccion != '1' && eleccion != '2' && eleccion != '3');
    printf("Has elegido la pregunta: %s\n", usuarioNuevo->preguntaSeguridad);
    printf("Ahora escriba la respuesta a la pregunta de seguridad.\n");
    scanf(" %99[^\n]", usuarioNuevo->respuestaSeguridad);
    printf("-----La pregunta de la seguridad guardada!-----\n");
    return quedar;
}

int ayudaContrasena()
{
    // ayuda con una constrasena olvidada
    // pregunta de seguridad?
    return salir;
}
