#include <stdio.h>

#include "estructuras_de_datos.h"

int sesionIcognito()
{
    printf("\nHas elegido el modo incognito.\n");
    printf("Tienes un accesso solo al menu incognito y no puedes guaardar calculaciones.\n");
    char eleccion;
    generacionElectrica generacionDatos;

    do
    {
        printf("\nEliga una de las opciones (Escriba el numero de la opcion).\n");
        printf("------------------------\n");
        printf("1. Leer los datos\n");
        printf("2. Hacer calculos\n");
        printf("3. Añadir nuevos datos\n");
        // printf("2. ...\n");
        printf("\"v\" Volver a la ultima pantalla\n");
        printf("\"q\" Salir del programa\n");
        printf("------------------------\n");
        scanf(" %c", &eleccion);
        switch (eleccion)
        {
        case '1':
            // iniciar una sesion
            if (lecturaGeneracion(&generacionDatos) == salir)
            {
                return salir;
            }
            break;
        case '2': 
        if (calculoDatos(&generacionDatos) == salir)
            {
                return salir;
            }
            break;
        case '3': 
        
    
            // Añadir nuevos datos
            // FALTA CODIGO
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

int lecturaGeneracion(generacionElectrica *generacionDatos)
{
    FILE *file;
    file = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (file == NULL)
    {
        printf("ERROR AL ABRIR EL FICHERO\n");
        return -1;
    }
    else
    {
        printf("EL FICHERO SE ABRIO DE FORMA CORRECTA\n");
        char temporal[Npequeno];

        // lectura de los datos principales
        fscanf(file, "%[^,],%[^,]", temporal, generacionDatos->titulo); // lectura del titulo
        fscanf(file, "%[^\n]\n", temporal);                             // omitir comas innecesarias

        fscanf(file, "%[^,],%[^,]", temporal, generacionDatos->sistemaElectrico);
        fscanf(file, "%[^\n]\n", temporal); // omitir comas innecesarias

        fscanf(file, "%[^,],%[^,]", temporal, generacionDatos->magnitudes);
        fscanf(file, "%[^\n]\n", temporal); // omitir comas innecesarias

        printf("titulo: %s\n", generacionDatos->titulo);
        printf("sistemaElectrico: %s\n", generacionDatos->sistemaElectrico);
        printf("magnitudes: %s\n", generacionDatos->magnitudes);

        fscanf(file, "%[^\n]\n", temporal); // omitir fila innecesaria vacia
		int i,j;
        // lectura de las fechas
        fscanf(file, "%[^,]", temporal);
        for (i = 0; i < numeroColumnas - 1; i++)
        {
            fscanf(file, ",%i-%i", &generacionDatos->fechas[i].mes, &generacionDatos->fechas[i].ano);
        }

        // impresion de las fechas
        for (i = 0; i < numeroColumnas - 1; i++)
        {
            printf("%i-%i\n", generacionDatos->fechas[i].mes, generacionDatos->fechas[i].ano);
        }

        // lectura de cada tipo de generacion
        for (i = 0; i < numeroTiposDeGeneracion; i++)
        {
            fscanf(file, "\n%[^,]", generacionDatos->TiposGeneracion[i].nombre);
            generacionDatos->TiposGeneracion[i].media = 0;

            for (j = 0; j < numeroColumnas - 1; j++)
            {
                fscanf(file, ",%f", &generacionDatos->TiposGeneracion[i].valores[j]);
            }
        }

        // impresion de todos los valore leidos
        for (i = 0; i < numeroTiposDeGeneracion; i++)
        {
            printf("\n----Tipo: %s ----\n", generacionDatos->TiposGeneracion[i].nombre);
            for (j = 0; j < numeroColumnas - 1; j++)
            {
                printf("%f, ", generacionDatos->TiposGeneracion[i].valores[j]);
            }
            printf("\n");
        }
    }
    return volver;
}


int calculoDatos(generacionElectrica *generacionDatos)
{
    printf("Ha seleccionado hacer calculos\n");

    char tipoGeneracion[Npequeno];
    int mes1, anio1, mes2, anio2, seleccion_calculo;
    float media;

    printf("Introduzca el tipo de generacion: ");
    scanf("%s", tipoGeneracion);
    

    printf("Introduzca el rango de fechas (mes y año) para los calculos.\n");
    printf("Fecha 1:\n");
    printf("Mes: ");
    scanf("%d", &mes1);
    printf("Año: ");
    scanf("%d", &anio1);

    printf("Fecha 2:\n");
    printf("Mes: ");
    scanf("%d", &mes2);
    printf("Año: ");
    scanf("%d", &anio2);
   
	printf("\nHa seleccionado: %s\n", tipoGeneracion);
    printf("Ha seleccionado las fechas %d/%d - %d/%d\n", mes1, anio1, mes2, anio2);
 	printf("------------------------\n");
    printf("Seleccione que calculo desea hacer: \n");
    printf("1. Valor medio\n");
    printf("2. Valor maximo y minimo\n");
    printf("3. Generacion mas/menos usada\n");
    printf("4. Porcentaje en la generacion total\n");
    printf("5. Suma total\n");
    printf("\"v\" Volver a la ultima pantalla\n");
    printf("\"q\" Salir del programa\n");
	
    scanf("%d", &seleccion_calculo);
    
  int i, j; 

    switch (seleccion_calculo)
    {
    case 1:
       printf("Ha seleccionado calcular el valor medio\n");
    
    float sumaValores = 0.0;
    int numero_meses = (anio2 - anio1) * 12 + (mes2 - mes1) + 1;

    for (i = mes1 - 1; i < mes2; i++)
    {
        for (j = 0; j < numeroColumnas - 1; j++)
        {
            sumaValores += generacionDatos->TiposGeneracion[i].valores[j];
        }
    }

    //media
  
    float media = sumaValores / numero_meses;

    printf("La media de los datos de %s entre las fechas %d/%d - %d/%d es: %f\n", tipoGeneracion, mes1, anio1, mes2, anio2, media);
    break;
    
    break;
    
    
    case 2:
            printf("Los valores máximos y mínimos de %s entre las fechas %d/%d - %d/%d son: -------\n", tipoGeneracion, mes1, anio1, mes2, anio2);
            break;
    case 3:
            printf("La generación más usada entre las fechas %d/%d - %d/%d es: -------\n", mes1, anio1, mes2, anio2);
            break;
    case 4:
            printf("El porcentaje en la generación total de %s entre las fechas %d/%d - %d/%d es: -------\n", tipoGeneracion, mes1, anio1, mes2, anio2);
            break;
    case 5:
            printf("La suma total de la generación %s entre las fechas %d/%d - %d/%d es: -------\n", tipoGeneracion, mes1, anio1, mes2, anio2);
            break;
    default:
            printf("El número elegido no es una opción válida, seleccione de nuevo.\n");
            break;
    }
    
    return volver;
}


