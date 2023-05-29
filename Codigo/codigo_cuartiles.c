#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MESES 24
#define MAX_GENERACION 100

// Funcion de comparacion para qsort
int comparar(const void *a, const void *b) {
    float numero1 = *(const float *)a;
    float numero2 = *(const float *)b;

    if (numero1 < numero2)
        return -1;
    else if (numero1 > numero2)
        return 1;
    else
        return 0;
}

// Funcion para calcular el cuartil habiendo ordenado los datos.
float calcularCuartil(float datos[], int n, int cuartil) {
    int posicion = (cuartil * n) / 100;
    return datos[posicion - 1];
}

int main() {
    FILE *file;
    char linea[MAX_LINE_LENGTH];
    char *nombre_generacion;
    char generaciones[MAX_GENERACION][MAX_LINE_LENGTH];
    float datos[MAX_GENERACION][MESES];
    int numero_generaciones = 0;

    file = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");  // Nombre del documento a leer.

    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Saltar las primeras 5 lineas ya que la informacion importante comienza en la linea 6.
    for (int i = 0; i < 5; i++) {
        fgets(linea, sizeof(linea), file);
    }

    // Leer los datos de cada generacion.
    while (fgets(linea, sizeof(linea), file) != NULL) {
        nombre_generacion = strtok(linea, ",");  // Obtener el primer dato.
        strcpy(generaciones[numero_generaciones], nombre_generacion);  // Copiar el nombre de la generacion.

        nombre_generacion = strtok(NULL, ",");  // Obtener el siguiente dato.
        int mes = 0;
        while (nombre_generacion != NULL && mes < MESES) {
            datos[numero_generaciones][mes] = atof(nombre_generacion);  // Convertir el dato a punto flotante y guardarlo
            nombre_generacion = strtok(NULL, ",");  // Obtener el siguiente dato.
            mes++;
        }

        // Ordenar los datos del aparato de menor a mayor.
        qsort(datos[numero_generaciones], mes, sizeof(float), comparar);

        numero_generaciones++;  // Para ir cambiando el tipo de generacion.
    }

    fclose(file);

    // Calcular y mostrar los cuartiles para cada generacion.
    for (int i = 0; i < numero_generaciones; i++) {
        printf("Generacion: %s\n", generaciones[i]);
        printf("Cuartiles:\n");
        printf("Q1: %.2f GWh\n", calcularCuartil(datos[i], MESES, 25));
        printf("Q2: %.2f GWh\n", calcularCuartil(datos[i], MESES, 50));
        printf("Q3: %.2f GWh\n", calcularCuartil(datos[i], MESES, 75));
        printf("Q4: %.2f GWh\n", calcularCuartil(datos[i], MESES, 100));
        printf("\n");
    }

    return 0;
}




