#include <stdio.h>

#include "estructuras_de_datos.h"

int sesionIncognito()
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
        printf("2. Hacer calculos (es necesario haber leido los datos)\n");
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
    file = fopen("Codigo/generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
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
    float media =0;
	int total_Meses=0;


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
  	float valor_maximo = 0.0;
	float valor_minimo = generacionDatos->TiposGeneracion[0].valores[0];
	float suma_total = 0.0;
    switch (seleccion_calculo)
{
   case 1: //Valor Medio,  variables: media y total de meses para realizar operacion
             printf("Introduzca el tipo de generacion: ");
    		scanf("%s", tipoGeneracion);
    		printf("\nHa seleccionado: %s\n", tipoGeneracion);
			for (i = 0; i < numeroTiposDeGeneracion; i++)
            {
                if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracion) == 0)
                {
                    for (j = 0; j < numeroColumnas - 1; j++)
                    {
                        int mes = generacionDatos->fechas[j].mes;
                        int anio = generacionDatos->fechas[j].ano;
						
                        if ((anio > anio1 || (anio == anio1 && mes >= mes1)) && (anio < anio2 || (anio == anio2 && mes <= mes2)))
                        //Para rango de fechas: fecha antes o despues del año inical
						//fecha en el mismo año que el año de inicio y final y  mes menor, igual o posterior al mes inicial.
                        {
                            media += generacionDatos->TiposGeneracion[i].valores[j];
                            total_Meses++;
                        }
                    }
                    break;
                }
            }
            if (media > 0)
                media /= total_Meses;

        	printf("La media de los datos de %s entre las fechas %d/%d - %d/%d es: %f\n", tipoGeneracion, mes1, anio1, mes2, anio2, media);
	break;
	case 2:
    // Valor máximo y mínimo
		 printf("Introduzca el tipo de generacion: ");
    	scanf("%s", tipoGeneracion);
    	printf("\nHa seleccionado: %s\n", tipoGeneracion);
        for (i = 0; i < numeroTiposDeGeneracion; i++)
        {
            if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracion) == 0)
            {
                for (j = 0; j < numeroColumnas; j++)
                {
                    int mes = generacionDatos->fechas[j].mes;
                    int anio = generacionDatos->fechas[j].ano;
                    if ((anio > anio1 || (anio == anio1 && mes >= mes1)) && (anio < anio2 || (anio == anio2 && mes <= mes2)))
                    {
                       float valor_generacion = generacionDatos->TiposGeneracion[i].valores[j];

                        if (valor_generacion > valor_maximo)
                        {
                        	valor_maximo = valor_generacion;
						}

                        if (valor_generacion < valor_minimo){
                        	valor_minimo = valor_generacion;
						}
                            
                    }
                }
                break;
            }
        }

        printf("Los valores maximos y minimos de %s entre las fechas %d/%d - %d/%d son:\nValor maximo: %f\nValor minimo: %f\n", tipoGeneracion, mes1, anio1, mes2, anio2, valor_maximo, valor_minimo);
        break;
    
    case 3:
            printf("La generación más usada entre las fechas %d/%d - %d/%d es: -------\n", mes1, anio1, mes2, anio2);
            break;
    case 4:
            printf("El porcentaje en la generación total de %s entre las fechas %d/%d - %d/%d es: -------\n", tipoGeneracion, mes1, anio1, mes2, anio2);
            break;
    case 5:
    	printf("Introduzca el tipo de generacion: ");
    	scanf("%s", tipoGeneracion);
    	printf("\nHa seleccionado: %s\n", tipoGeneracion);
		for (i = 0; i < numeroTiposDeGeneracion; i++)
            {
                if (strcmp(generacionDatos->TiposGeneracion[i].nombre, tipoGeneracion) == 0)
                {
                    for (j = 0; j < numeroColumnas - 1; j++)
                    {
                        int mes = generacionDatos->fechas[j].mes;
                        int anio = generacionDatos->fechas[j].ano;
						
                        if ((anio > anio1 || (anio == anio1 && mes >= mes1)) && (anio < anio2 || (anio == anio2 && mes <= mes2)))
                        //Para rango de fechas: fecha antes o despues del año inical
						//fecha en el mismo año que el año de inicio y final y  mes menor, igual o posterior al mes inicial.
                        {
                            suma_total += generacionDatos->TiposGeneracion[i].valores[j];
                        }
                    }
                    break;
                }
            }
            printf("La suma total de la generación %s entre las fechas %d/%d - %d/%d es: %f\n", tipoGeneracion, mes1, anio1, mes2, anio2, suma_total);
            break;
    default:
            printf("El número elegido no es una opción válida, seleccione de nuevo.\n");
            break;
    
    return volver;
}
}


