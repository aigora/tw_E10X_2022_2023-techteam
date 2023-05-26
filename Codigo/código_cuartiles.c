#include <stdio.h>
#include <stdlib.h>

#define N 2000

//función comparar
int comparar(const void *p1, const void *p2)
    {
        float numero1 = *(float *)p1;
        float numero2 = *(float *)p2;

            if (numero1 < numero2)
            {
                return -1;
            }
            else if (numero1 > numero2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }


// funcion para calcular el cuartil de un conjunto de datos de cada modo de generacion
float calcularCuartil(float datos[], int n, int cuartil)
    {
        float posicion = (cuartil / 4.0) * (n - 1);
        int indice = (int)posicion;
        float fraccion = posicion - indice;

            if (indice < 0)
            {
                return datos[0];
            }
            else if (indice >= n - 1)
            {
                return datos[n - 1];
            }
            else
            {
                return datos[indice] + fraccion * (datos[indice + 1] - datos[indice]);
            }

    }



int main()
{
    FILE * file;
    char linea[200];
    float datos[N];
    int numero_linea = 0;

    file = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
        if (file == NULL)
        {
            printf("ERROR AL ABRIR EL FICHERO\n");
            return -1;
        }
        while (fgets(linea, siezof(linea), file) != NULL)
        {
            datos[numero_linea] = atof(linea); //Convierte la línea a números en punto flotante.
            numero_linea++;
        }

        fclose(file);

        if (numero_linea == 0)
        {
            printf("El archivo esta vacio.\n");
            return 1;
        }

        qsort(datos, numero_linea,sizeof(float), comparar); //Ordenamos los números en orden ascendente.

        //Calculamos los cuartiles y los mostramos por pantalla.
        printf("Los cuartiles de /*cada tipo de modo de generacion)*/ son: \t q1: %.5f\t q2: %.5f\t q3: %.5f\t q4: %.5f\n", /*modo de generacion de energia*/ calcularCuartil(datos, numero_linea, 1), calcularCuartil(datos, numero_linea, 2), calcularCuartil(datos, numero_linea, 3));

        return 0;
}



