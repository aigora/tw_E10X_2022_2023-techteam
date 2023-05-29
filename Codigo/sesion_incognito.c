#include <stdio.h>
#include <string.h>

#include "estructuras_de_datos.h"
#include "sesion_incognito.h"

int sesionIncognito(int sesionUsuario)
{
    if (sesionUsuario == sesionCerrada)
    {
        printf("\nHas elegido el modo incognito.\n");
        printf("Tienes un accesso solo al menu incognito y no puedes guaardar calculaciones.\n");
    }
    else if (sesionUsuario == sesionAbierta)
    {
        printf("\nEstas en el menu incognito. Para acceder el menu Usuario vuelva a la ultima pantalla.\n");
        printf("\nDespues de hacer calculos puedes guardarlos, porque tienes la sesion abierta\n");
    }

    char eleccion;
    generacionElectrica generacionDatos;

    do
    {
        printf("-----MENU INCOGNITO----\n");
        printf("\nEliga una de las opciones (Escriba el numero de la opcion).\n");
        printf("------------------------\n");
        printf("1. Leer los datos\n");
        printf("2. Hacer calculos (es necesario haber leido los datos)\n");
        printf("3. Anadir nuevos datos\n");
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

            // Anadir nuevos datos
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
        int i, j;
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

    int seleccion_calculo;
    datosParaCalculos datosCalculos;
    datosCalculos.media = 0;
    datosCalculos.total_Meses = 0;
    datosCalculos.valor_maximo = 0.0;
    datosCalculos.valor_minimo = generacionDatos->TiposGeneracion[0].valores[0];
    datosCalculos.suma_total = 0.0;
    datosCalculos.generacionMasUsada = 0.0;
    datosCalculos.generacionMenosUsada = 0.0;

    printf("Introduzca el rango de fechas (mes y ano) para los calculos.\n");
    printf("Fecha 1:\n");
    printf("Mes: ");
    scanf("%d", &datosCalculos.mes1);
    printf("Ano: ");
    scanf("%d", &datosCalculos.anio1);

    printf("Fecha 2:\n");
    printf("Mes: ");
    scanf("%d", &datosCalculos.mes2);
    printf("Ano: ");
    scanf("%d", &datosCalculos.anio2);

    printf("Ha seleccionado las fechas %d/%d - %d/%d\n", datosCalculos.mes1, datosCalculos.anio1, datosCalculos.mes2, datosCalculos.anio2);
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

    switch (seleccion_calculo)

    {
    case 1: // Valor Medio,  variables: media y total de meses para realizar operacion
        valorMedio(generacionDatos, &datosCalculos);
        break;
    case 2:
        // Valor m�ximo y m�nimo
        valorMaximoMinimo(generacionDatos, &datosCalculos);
        break;
    case 3:
        // generacios Mas y Menos usada
        generacionMasMenosUsada(generacionDatos, &datosCalculos);
        break;
    case 4:
        porcentajeGeneracionTotal(generacionDatos, &datosCalculos);
        break;
    case 5:
        sumaTotal(generacionDatos, &datosCalculos);
        break;
    default:
        printf("El numero elegido no es una opcion valida, seleccione de nuevo.\n");
        break;
        return volver;
    }

    return volver;
}

void valorMedio(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos)
{
    int i, j;
    char tipoGeneracionNombre[Npequeno];
    printf("Introduzca el tipo de generacion: ");
    scanf("%s", tipoGeneracionNombre);
    printf("\nHa seleccionado: %s\n", tipoGeneracionNombre);
    for (i = 0; i < numeroTiposDeGeneracion; i++)
    {
        if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracionNombre) == 0)
        {
            for (j = 0; j < numeroColumnas - 1; j++)
            {
                int mes = generacionDatos->fechas[j].mes;
                int anio = generacionDatos->fechas[j].ano;

                if ((anio > datosCalculos->anio1 || (anio == datosCalculos->anio1 && mes >= datosCalculos->mes1)) && (anio < datosCalculos->anio2 || (anio == datosCalculos->anio2 && mes <= datosCalculos->mes2)))
                // Para rango de fechas: fecha antes o despues del a�o inical
                // fecha en el mismo a�o que el a�o de inicio y final y  mes menor, igual o posterior al mes inicial.
                {
                    datosCalculos->media += generacionDatos->TiposGeneracion[i].valores[j];
                    datosCalculos->total_Meses++;
                }
            }
            break;
        }
    }
    if (datosCalculos->media > 0)
    {
        datosCalculos->media /= (float)datosCalculos->total_Meses;
    }

    printf("La media de los datos de %s entre las fechas %d/%d - %d/%d es: %f\n", tipoGeneracionNombre, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2, datosCalculos->media);
}

void valorMaximoMinimo(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos)
{
    printf("Introduzca el tipo de generacion: ");
    int i, j;
    char tipoGeneracionNombre[Npequeno];

    scanf("%s", tipoGeneracionNombre);
    printf("\nHa seleccionado: %s\n", tipoGeneracionNombre);

    for (i = 0; i < numeroTiposDeGeneracion; i++)
    {
        if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracionNombre) == 0)
        {
            for (j = 0; j < numeroColumnas; j++)
            {
                int mes = generacionDatos->fechas[j].mes;
                int anio = generacionDatos->fechas[j].ano;
                if ((anio > datosCalculos->anio1 || (anio == datosCalculos->anio1 && mes >= datosCalculos->mes1)) && (anio < datosCalculos->anio2 || (anio == datosCalculos->anio2 && mes <= datosCalculos->mes2)))
                {
                    float valor_generacion = generacionDatos->TiposGeneracion[i].valores[j];

                    if (valor_generacion > datosCalculos->valor_maximo)
                    {
                        datosCalculos->valor_maximo = valor_generacion;
                    }

                    if (valor_generacion < datosCalculos->valor_minimo)
                    {
                        datosCalculos->valor_minimo = valor_generacion;
                    }
                }
            }
            break;
        }
    }

    printf("Los valores maximos y minimos de %s entre las fechas %d/%d - %d/%d son:\nValor maximo: %f\nValor minimo: %f\n", tipoGeneracionNombre, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2, datosCalculos->valor_maximo, datosCalculos->valor_minimo);
}

void generacionMasMenosUsada(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos)
{
    char tipoGeneracionNombre[Npequeno];
    int i, j;

    printf("Introduzca el tipo de generacion: ");
    scanf("%s", tipoGeneracionNombre);
    printf("\nHa seleccionado: %s\n", tipoGeneracionNombre);

    for (i = 0; i < numeroTiposDeGeneracion; i++)
    {
        if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracionNombre) == 0)
        {
            datosCalculos->generacionMasUsada = generacionDatos->TiposGeneracion[i].valores[0];
            datosCalculos->generacionMenosUsada = generacionDatos->TiposGeneracion[i].valores[0];

            for (j = 1; j < numeroColumnas - 1; j++)
            {
                int mes = generacionDatos->fechas[j].mes;
                int anio = generacionDatos->fechas[j].ano;

                if ((anio > datosCalculos->anio1 || (anio == datosCalculos->anio1 && mes >= datosCalculos->mes1)) && (anio < datosCalculos->anio2 || (anio == datosCalculos->anio2 && mes <= datosCalculos->mes2)))
                {
                    float valorGeneracion = generacionDatos->TiposGeneracion[i].valores[j];

                    if (valorGeneracion > datosCalculos->generacionMasUsada)
                        datosCalculos->generacionMasUsada = valorGeneracion;

                    if (valorGeneracion < datosCalculos->generacionMenosUsada)
                        datosCalculos->generacionMenosUsada = valorGeneracion;
                }
            }
            break;
        }
    }

    printf("La generacion mas usada de %s entre las fechas %d/%d - %d/%d es: %.2f\n", tipoGeneracionNombre, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2, datosCalculos->generacionMasUsada);
    printf("La generacion menos usada de %s entre las fechas %d/%d - %d/%d es: %.2f\n", tipoGeneracionNombre, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2, datosCalculos->generacionMenosUsada);
}

void sumaTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos)
{
    char tipoGeneracionNombre[Npequeno];
    int i, j;
    printf("Introduzca el tipo de generacion:\n ");
    scanf("%s", tipoGeneracionNombre);
    printf("Ha seleccionado: %s\n", tipoGeneracionNombre);
    for (i = 0; i < numeroTiposDeGeneracion; i++)
    {
        if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracionNombre) == 0)
        {
            for (j = 0; j < numeroColumnas - 1; j++)
            {
                int mes = generacionDatos->fechas[j].mes;
                int anio = generacionDatos->fechas[j].ano;

                if ((anio > datosCalculos->anio1 || (anio == datosCalculos->anio1 && mes >= datosCalculos->mes1)) && (anio < datosCalculos->anio2 || (anio == datosCalculos->anio2 && mes <= datosCalculos->mes2)))
                // Para rango de fechas: fecha antes o despues del a�o inical
                // fecha en el mismo a�o que el a�o de inicio y final y  mes menor, igual o posterior al mes inicial.
                {
                    datosCalculos->suma_total += generacionDatos->TiposGeneracion[i].valores[j];
                }
            }
            break;
        }
    }
    printf("La suma total de la generacion %s entre las fechas %d/%d - %d/%d es: %f\n", tipoGeneracionNombre, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2, datosCalculos->suma_total);
}

void porcentajeGeneracionTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos)
{
    char tipoGeneracionNombre[Npequeno];
    int i, j;
    printf("Introduzca el tipo de generacion: ");
    scanf("%s", tipoGeneracionNombre);
    printf("\nHa seleccionado: %s\n", tipoGeneracionNombre);

    float generacionTotal = 0.0;
    float generacionTipo = 0.0;

    for (i = 0; i < numeroTiposDeGeneracion; i++)
    {
        if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracionNombre) == 0)
        {
            for (j = 0; j < numeroColumnas - 1; j++)
            {
                int mes = generacionDatos->fechas[j].mes;
                int anio = generacionDatos->fechas[j].ano;

                if ((anio > datosCalculos->anio1 || (anio == datosCalculos->anio1 && mes >= datosCalculos->mes1)) &&
                    (anio < datosCalculos->anio2 || (anio == datosCalculos->anio2 && mes <= datosCalculos->mes2)))
                {
                    generacionTipo += generacionDatos->TiposGeneracion[i].valores[j];
                }
                generacionTotal += generacionDatos->TiposGeneracion[i].valores[j];
            }
            break;
        }
    }

    if (generacionTotal > 0.0)
    {
        float porcentaje = (generacionTipo / generacionTotal) * 100;
        printf("La generacion de %s representa el %.2f%% de la generacion total entre las fechas %d/%d - %d/%d\n", tipoGeneracionNombre, porcentaje, datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2);
    }
    else
    {
        printf("No se han encontrado datos de generacion para el tipo seleccionado entre las fechas %d/%d - %d/%d\n", datosCalculos->mes1, datosCalculos->anio1, datosCalculos->mes2, datosCalculos->anio2);
    }
}
