#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "estructuras_de_datos.h"
#include "sesion_incognito.h"
#include "menu_usuario.h"
#include "sesion_usuario.h"

int menuUsuario(usuario *usuarioActual)
{
    printf("Se ha iniciado sesion como %s\n", usuarioActual->nombre);
    printf("Ahora tiene el acceso al menu del usuario y menu incognito\n");

    char eleccion;
    do
    {
        printf("-----SESION ABIERTA----\n");
        printf("------------------------\n");
        printf("1. Menu Incognito\n");
        printf("2. Menu Usuario\n");
        printf("\"v\" Volver a la ultima pantalla\n");
        printf("\"q\" Salir del programa\n");
        printf("------------------------\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            if (sesionIncognito(sesionAbierta) == salir)
            {
                return salir;
            }
            break;
        case '2':
            if (menuUsuarioAbierto(usuarioActual) == salir)
            {
                return salir;
            }
            break;
        case 'q':
            return salir;
            break;
        case 'v':
            return volver;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (1);

    return salir;
}

int menuUsuarioAbierto(usuario *usuarioActual)
{
    char eleccion;
    do
    {
        printf("-----MENU USUARIO-----\n");
        printf("Eliga una de las opciones\n");
        printf("------------------------\n");
        printf("1. Leer datos guardados\n");
        printf("2. Borrar datos guardados (primero hay que leer los datos guardados)\n");
        printf("3. Cambiar contrasena\n");
        printf("4. Borrar cuenta\n");
        printf("\"v\" Volver a la ultima pantalla\n");
        printf("\"q\" Salir del programa\n");
        printf("------------------------\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            // mostrar datos
            mostrarDatosGuardados(usuarioActual);
            break;
        case '2':
            // borrar datos
            borrarDatosGuardados(usuarioActual);
            break;
        case '3':
            // cambiar contrasena
            cambiarContrasena(usuarioActual);
            break;
        case '4':
            // borrar cuenta
            if (borrarCuenta(usuarioActual) == salir)
            {
                return salir;
            }
            break;
        case 'q':
            return salir;
            break;
        case 'v':
            return volver;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (1);

    return volver;
}

void mostrarDatosGuardados(usuario *usuarioActual)
{
    printf("Ahora puedes ver todos datos guardados en tu perfil.\n");

    leerDatosGuardados(usuarioActual);
    if (usuarioActual->numeroCalculosGuardados > 0)
    {
        printf("-----CALCULOS GUARDADOS-----\n");
        int i;
        for (i = 0; i < usuarioActual->numeroCalculosGuardados; i++)
        {
            printf("%s\t\t", usuarioActual->calculosGuardados[i].nombre);
            printf("%s\n", usuarioActual->calculosGuardados[i].valor);
        }
        printf("------------------------\n\n");
    }
    else
    {
        printf("-----No hay calculos guardados :c-----\n");
    }
}

void leerDatosGuardados(usuario *usuarioActual)
{
    char nombreArchivo[Ngrande] = "";
    strcat(nombreArchivo, "usuarios/");
    strcat(nombreArchivo, usuarioActual->nombre);
    strcat(nombreArchivo, ".txt");

    FILE *file = fopen(nombreArchivo, "r");
    if (file == NULL)
    {
        printf("ERROR al abrir el fichero");
        return;
    }
    else
    {
        // iniciamos una sesion en caso de SI existir el usuario
        // printf("EL FICHERO SE ABRIO DE FORMA CORRECTA\n");
        char temporal[Npequeno];
        usuarioActual->numeroCalculosGuardados = 0;
        int i;
        // omitiendo datos
        for (i = 0; i < 5; i++)
        {
            fscanf(file, "%[^\n]\n", temporal);
        }

        // lectura de calculos guardados
        while (fscanf(file, "%[^,],%[^\n]\n", usuarioActual->calculosGuardados[usuarioActual->numeroCalculosGuardados].nombre, usuarioActual->calculosGuardados[usuarioActual->numeroCalculosGuardados].valor) != EOF)
        {
            usuarioActual->numeroCalculosGuardados++;
        }
    }
}

int borrarDatosGuardados(usuario *usuarioActual)
{
    if (usuarioActual->numeroCalculosGuardados == 0)
    {
        printf("No hay datos leidos.\n");
        return volver;
    }
    else
    {
        char eleccion;
        do
        {
            int i = 0;
            printf("-----CALCULOS GUARDADOS-----\n");
            for (i = 0; i < usuarioActual->numeroCalculosGuardados; i++)
            {
                printf("[%i]: %s\t", i + 1, usuarioActual->calculosGuardados[i].nombre);
                printf("%s\n", usuarioActual->calculosGuardados[i].valor);
            }
            printf("------------------------\n\n");

            printf("Escriba el numero de fila cual calculo quieres borrar o escriba \"0\" para borrar todos.\n");
            printf("Tambien puede escribir \"q\" para salir o \"v\" para volver\n");
            printf("Esta accion es irreversible!!!\n");
            scanf(" %c", &eleccion);
            switch (eleccion)
            {
            case 'q':
                return salir;
                break;
            case 'v':
                return volver;
                break;
            case '0':
                borrarTodosDatos(usuarioActual);
                return volver;
            default:
                if (eleccion >= '1' && eleccion <= usuarioActual->numeroCalculosGuardados + '0')
                {
                    int numeroFilaBorrar = eleccion - '0';
                    borrarUnDatoGuardado(usuarioActual, numeroFilaBorrar);
                }
                else
                {
                    printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
                }
                break;
            }
        } while (1);
    }
}

void borrarTodosDatos(usuario *usuarioActual)
{
    char nombreArchivo[Ngrande] = "";
    strcat(nombreArchivo, "usuarios/");
    strcat(nombreArchivo, usuarioActual->nombre);
    strcat(nombreArchivo, ".txt");
    FILE *pf = fopen(nombreArchivo, "w");
    if (pf == NULL)
    {
        printf("No se pudo acceder el archivo.\n");
        return;
    }
    // Guardar nombre y contrasena en el archivo
    fprintf(pf, "nombre:%s\ncontrasena:%s\n", usuarioActual->nombre, usuarioActual->contrasena);
    fprintf(pf, "preguntaSeguridad:%s\nrespuestaSeguridad:%s\n", usuarioActual->preguntaSeguridad, usuarioActual->respuestaSeguridad);
    fprintf(pf, "-----DATOS-----\n");
    // Cerrar el archivo
    fclose(pf);

    printf("Se han borrado los datos\n");
    usuarioActual->numeroCalculosGuardados = 0;
}

void borrarUnDatoGuardado(usuario *usuarioActual, int numeroFila)
{
    char nombreArchivo[Ngrande] = "";
    strcat(nombreArchivo, "usuarios/");
    strcat(nombreArchivo, usuarioActual->nombre);
    strcat(nombreArchivo, ".txt");
    FILE *pf = fopen(nombreArchivo, "w");

    if (pf == NULL)
    {
        printf("No se pudo acceder el archivo FILE SOURCE.\n");
        return;
    }

    // Guardar nombre y contrasena en el archivo
    fprintf(pf, "nombre:%s\ncontrasena:%s\n", usuarioActual->nombre, usuarioActual->contrasena);
    fprintf(pf, "preguntaSeguridad:%s\nrespuestaSeguridad:%s\n", usuarioActual->preguntaSeguridad, usuarioActual->respuestaSeguridad);
    fprintf(pf, "-----DATOS-----\n");
    int i;
    for (i = 0; i < usuarioActual->numeroCalculosGuardados; i++)
    {
        if (i != numeroFila-1)
        {
            fprintf(pf, "%s,%s\n", usuarioActual->calculosGuardados[i].nombre, usuarioActual->calculosGuardados[i].valor);
        }
    }

    fclose(pf);
    printf("La fila %i ha sido borrada.\n", numeroFila);
    leerDatosGuardados(usuarioActual);
}

void cambiarContrasena()
{
    printf("Ahora puedes cambiar la contrasena.\n");
    ayudaContrasena();
}

int borrarCuenta(usuario *usuarioActual)
{
    char eleccion;
    do
    {
        printf("!!!!!!!!!!!!!!!!\n");
        printf("Estas seguro si quieres borrar la cuenta?\n");
        printf("Esta accion es irreversible!!!\n");
        printf("!!!!!!!!!!!!!!!!\n");

        printf("Eliga una de las opciones\n");

        printf("\"1\" BORRAR la cuenta.\n");
        printf("\"v\" Volver a la ultima pantalla\n");
        printf("\"q\" Salir del programa\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            // borrar cuenta
            borrarArchivoCuenta(usuarioActual);
            return salir;
            break;
        case 'q':
            return salir;
            break;
        case 'v':
            return volver;
            break;
        default:
            printf("Has escrito una letra mala.\n Eliga otra vez o escriba \"q\" para salir del programa.\n");
            break;
        }
    } while (1);

    return volver;
}

void borrarArchivoCuenta(usuario *usuarioActual)
{
    char nombreArchivo[Ngrande] = "";
    strcat(nombreArchivo, "usuarios/");
    strcat(nombreArchivo, usuarioActual->nombre);
    strcat(nombreArchivo, ".txt");

    int ret = remove(nombreArchivo);

    if (ret == 0)
    {
        printf("Cuenta borrada con exito.\n");
    }
    else
    {
        printf("ERROR no se podría borrar la cuenta.\n");
    }
}
