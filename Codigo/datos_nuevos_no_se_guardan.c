// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_LINEA 256
// #define MAX_GENERACIONES 50
// #define MAX_MESES 24

// typedef struct {
//     char nombre[MAX_LINEA];
//     float valores[MAX_MESES];
// } ModosGeneracion;

// typedef struct {
//     ModosGeneracion generaciones[MAX_GENERACIONES];
//     int numGeneraciones;
// } GeneracionElectrica;

// void mostrarMenu()
// {
//     printf("\nElige una de las opciones.\n");
//     printf("----------------------------\n");
//     printf("1. Agregar nuevos datos\n");
//     printf("2. Salir\n");
//     printf("----------------------------\n");
//     printf("Opcion: ");
// }

// void agregarDatos(GeneracionElectrica *generacionDatos)
// {
//     if (generacionDatos->numGeneraciones >= MAX_GENERACIONES) {
//         printf("Se ha alcanzado el maximo de generaciones. No se pueden agregar mas tipos.\n");
//         return;
//     }

//     char nombre[MAX_LINEA];
//     float valores[MAX_MESES];

//     printf("Ingrese el nombre de la generacion: ");
//     scanf(" %[^\n]s", nombre);

//     for (int i = 0; i < MAX_MESES; i++) {
//         printf("Ingrese el valor para el mes %d: ", i + 1);
//         scanf("%f", &valores[i]);
//     }

//     strcpy(generacionDatos->generaciones[generacionDatos->numGeneraciones].nombre, nombre);
//     memcpy(generacionDatos->generaciones[generacionDatos->numGeneraciones].valores, valores, sizeof(valores));
//     generacionDatos->numGeneraciones++;

//     printf("Los datos se han agregado correctamente.\n");
// }

// int main()
// {
//     GeneracionElectrica generacionDatos;
//     generacionDatos.numGeneraciones = 0;

//     FILE *file = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
//     if (file == NULL) {
//         printf("Error al abrir el archivo.\n");
//         return -1;
//     }

//     // Leer las lineas innecesarias
//     char temporal[MAX_LINEA];
//     for (int i = 0; i < 5; i++) {
//         fgets(temporal, sizeof(temporal), file);
//     }

//     // Leer los datos
//     while (generacionDatos.numGeneraciones < MAX_GENERACIONES && fgets(temporal, sizeof(temporal), file) != NULL) {
//         char nombre[MAX_LINEA];
//         float valores[MAX_MESES];

//         sscanf(temporal, "%[^,],", nombre);
//         for (int i = 0; i < MAX_MESES; i++) {
//             sscanf(temporal + strlen(nombre) + 1 + i * 6, "%f,", &valores[i]);
//         }

//         strcpy(generacionDatos.generaciones[generacionDatos.numGeneraciones].nombre, nombre);
//         memcpy(generacionDatos.generaciones[generacionDatos.numGeneraciones].valores, valores, sizeof(valores));
//         generacionDatos.numGeneraciones++;
//     }

//     fclose(file);

//     char opcion;

//     printf("Bienvenido al programa de generacion electrica.\n");

//     do {
//         mostrarMenu();
//         scanf(" %c", &opcion);

//         switch (opcion) {
//             case '1':
//                  agregarDatos(&generacionDatos);
//                 break;
//             case '2':
//                 printf("Saliendo del programa...\n");
//                 break;
//             default:
//                 printf("Has escrito una opcion invalida. Elige otra vez.\n");
//                 break;
//         }
//     } while (opcion != '2');

//     return 0;
// }
