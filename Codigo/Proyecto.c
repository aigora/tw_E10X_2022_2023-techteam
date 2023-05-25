// #include <stdio.h>
// #define N 3000
// typedef struct 
// {
// 	float min,max,media;
// 	float valores[N];
// } variableGeneracion;

// int main() {
// 	int i=0;
// 	variableGeneracion hidraulica, turbinacion, nuclear,carbon, motores_diesel, turbina_gas, turbina_vapor,ciclo_combinado,
// 	hidroeolica, eolica, solar_fotovoltaica, solar_termica, otras_renovables,cogeneracion, residuos_no_renovables, 
// 	residuos_renovables, generacion_total;
	
// 	hidraulica.media = 0;
// 	turbinacion.media = 0;
// 	nuclear.media = 0;
// 	carbon.media = 0;
// 	motores_diesel.media = 0;
// 	turbina_gas.media = 0;
// 	turbina_vapor.media = 0;
// 	ciclo_combinado.media = 0;
// 	hidroeolica.media = 0;
// 	eolica.media = 0;
// 	solar_fotovoltaica.media = 0;
// 	solar_termica.media = 0;
// 	otras_renovables.media = 0;
// 	cogeneracion.media = 0;
// 	residuos_no_renovables.media = 0;
// 	residuos_renovables.media = 0;
// 	generacion_total.media = 0;
	
// 	FILE *file;
// 	file = fopen("C:/Users/julia/OneDrive/Documentos/UPM/Informatica/generacion_por_tecnologias_21_22_puntos_simplificado.csv","r");
// 	if (file == NULL)
// 	{
// 		printf("ERROR AL ABRIR EL FICHERO\n");
// 		return -1;
// 	}
// 	else
// 	{
// 		printf("EL FICHERO SE ABRIO DE FORMA CORRECTA\n");
// 		while (fscanf(file, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",&hidraulica.valores[i], 
// 		&turbinacion.valores[i], &nuclear.valores[i], &carbon.valores[i],&motores_diesel.valores[i],
// 		&turbina_gas.valores[i],&turbina_vapor.valores[i],&ciclo_combinado.valores[i],&hidroeolica.valores[i],
// 		&eolica.valores[i],&solar_fotovoltaica.valores[i],&solar_termica.valores[i],&otras_renovables.valores[i],
// 		&cogeneracion.valores[i],&residuos_no_renovables.valores[i],&residuos_renovables.valores[i],&generacion_total.valores[i]) != EOF)
// 		{
// 			if (i == 0)
// 			{
// 				hidraulica.max = hidraulica.valores[i];
// 				hidraulica.min = hidraulica.valores[i];
// 				turbinacion.max = turbinacion.valores[i];
// 				turbinacion.min = turbinacion.valores[i];
// 				nuclear.max = nuclear.valores[i];
// 				nuclear.min = nuclear.valores[i];
// 				carbon.max = carbon.valores[i];
// 				carbon.min = carbon.valores[i];
// 				motores_diesel.max = motores_diesel.valores[i];
// 				motores_diesel.min = motores_diesel.valores[i];
// 				turbina_gas.max= turbina_gas.valores[i];
// 				turbina_gas.min = turbina_gas.valores[i];
// 				turbina_vapor.max = turbina_vapor.valores[i];
// 				turbina_vapor.min = turbina_vapor.valores[i];
// 				ciclo_combinado.max = ciclo_combinado.valores[i];
// 				ciclo_combinado.min = ciclo_combinado.valores[i];
// 				hidroeolica.max = hidroeolica.valores[i];
// 				hidroeolica.min = hidroeolica.valores[i];
// 				eolica.max = eolica.valores[i];
// 				eolica.min = eolica.valores[i];
// 				solar_fotovoltaica.max = solar_fotovoltaica.valores[i];
// 				solar_fotovoltaica.min = solar_fotovoltaica.valores[i];
// 				solar_termica.max = solar_termica.valores[i];
// 				solar_termica.min = solar_termica.valores[i];
// 				otras_renovables.max = otras_renovables.valores[i];
// 				otras_renovables.min = otras_renovables.valores[i];
// 				cogeneracion.max = cogeneracion.valores[i];
// 				cogeneracion.min = cogeneracion.valores[i];
// 				residuos_no_renovables.max = residuos_no_renovables.valores[i];
// 				residuos_no_renovables.min = residuos_no_renovables.valores[i];
// 				residuos_renovables.max = residuos_renovables.valores[i];
// 				residuos_renovables.min = residuos_renovables.valores[i];
// 				generacion_total.max = generacion_total.valores[i];
// 				generacion_total.min = generacion_total.valores[i];		
				
// 			} 
// 			hidraulica.media += hidraulica.valores[i];
// 			turbinacion.media += turbinacion.valores[i];
// 			nuclear.media += nuclear.valores[i];
// 			carbon.media += carbon.valores[i];
// 			motores_diesel.media+= motores_diesel.valores[i];
// 			turbina_gas.media += turbina_gas.valores[i];
// 			turbina_vapor.media += turbina_vapor.valores[i];
// 			ciclo_combinado.media += ciclo_combinado.valores[i];
// 			hidroeolica.media += hidroeolica.valores[i];
// 			eolica.media += eolica.valores[i];
// 			solar_fotovoltaica.media+= solar_fotovoltaica.valores[i];
// 			solar_termica.media += solar_termica.valores[i];
// 			otras_renovables.media+= otras_renovables.valores[i];
// 			cogeneracion.media += cogeneracion.valores[i];
// 			residuos_no_renovables.media += residuos_no_renovables.valores[i];
// 			residuos_renovables.media += residuos_renovables.valores[i];
// 			generacion_total.media += generacion_total.valores[i];
			
			
// 			if (hidraulica.valores[i] > hidraulica.max)
// 			{
//                 hidraulica.max = hidraulica.valores[i];
// 			}
//             if (hidraulica.valores[i] < hidraulica.min)
//             {
//                 hidraulica.min = hidraulica.valores[i];
//             }
//             if (turbinacion.valores[i] > turbinacion.max)
//             {
//                turbinacion.max = turbinacion.valores[i];
//             }
//             if (turbinacion.valores[i] < turbinacion.min)
//             {
//                 turbinacion.min = turbinacion.valores[i];
//             }
//             if (nuclear.valores[i] > nuclear.max)
//             {
//                nuclear.max = nuclear.valores[i];
//             }
//             if (nuclear.valores[i] < nuclear.min)
//             {
//                 nuclear.min = nuclear.valores[i];
//             }
//             if (carbon.valores[i] > carbon.max)
// 			{
//                 carbon.max = carbon.valores[i];
// 			}
//             if (carbon.valores[i] < carbon.min)
//             {
//                 carbon.min = carbon.valores[i];
//             }
//             if (motores_diesel.valores[i] > motores_diesel.max)
// 			{
//                 motores_diesel.max = motores_diesel.valores[i];
// 			}
//             if (motores_diesel.valores[i] < motores_diesel.min)
//             {
//                motores_diesel.min = motores_diesel.valores[i];
//             }
//             if (turbina_gas.valores[i] > turbina_gas.max)
// 			{
//                 turbina_gas.max = turbina_gas.valores[i];
// 			}
//             if (turbina_gas.valores[i] < turbina_gas.min)
//             {
//                 turbina_gas.min = turbina_gas.valores[i];
//             }
//             if (turbina_vapor.valores[i] > turbina_vapor.max)
// 			{
//                 turbina_vapor.max = turbina_vapor.valores[i];
// 			}
//             if (turbina_vapor.valores[i] <turbina_vapor.min)
//             {
//                 turbina_vapor.min = turbina_vapor.valores[i];
//             }
//             if (ciclo_combinado.valores[i] > ciclo_combinado.max)
//             {
//                ciclo_combinado.max = ciclo_combinado.valores[i];
//             }
//             if (ciclo_combinado.valores[i] <ciclo_combinado.min)
//             {
//                 ciclo_combinado.min = ciclo_combinado.valores[i];
//             }
//             if (hidroeolica.valores[i] > hidroeolica.max)
//             {
//                hidroeolica.max = hidroeolica.valores[i];
//             }
//             if (hidroeolica.valores[i] <hidroeolica.min)
//             {
//                 hidroeolica.min = hidroeolica.valores[i];
//             }
//             if (eolica.valores[i] > eolica.max)
// 			{
//                 eolica.max = eolica.valores[i];
// 			}
//             if (eolica.valores[i] < eolica.min)
//             {
//                 eolica.min = eolica.valores[i];
//             }
//             if (solar_fotovoltaica.valores[i] > solar_fotovoltaica.max)
// 			{
//                 solar_fotovoltaica.max = solar_fotovoltaica.valores[i];
// 			}
//             if (solar_fotovoltaica.valores[i] < solar_fotovoltaica.min)
//             {
//               solar_fotovoltaica.min = solar_fotovoltaica.valores[i];
//             }
//             if (solar_termica.valores[i] > solar_termica.max)
// 			{
//                 solar_termica.max = solar_termica.valores[i];
// 			}
//             if (solar_termica.valores[i] < solar_termica.min)
//             {
//                solar_termica.min = solar_termica.valores[i];
//             }
//             if (otras_renovables.valores[i] > otras_renovables.max)
// 			{
//                 otras_renovables.max = otras_renovables.valores[i];
// 			}
//             if (otras_renovables.valores[i] < otras_renovables.min)
//             {
//                 otras_renovables.min = otras_renovables.valores[i];    
//             }
//             if (cogeneracion.valores[i] > cogeneracion.max)
//             {
//               cogeneracion.max = cogeneracion.valores[i];
//             }
//             if (cogeneracion.valores[i] <cogeneracion.min)
//             {
//                 cogeneracion.min =cogeneracion.valores[i];
//             }
//             if (residuos_no_renovables.valores[i] >residuos_no_renovables.max)
//             {
//                residuos_no_renovables.max = residuos_no_renovables.valores[i];
//             }
//             if (residuos_no_renovables.valores[i] <residuos_no_renovables.min)
//             {
//                 residuos_no_renovables.min = residuos_no_renovables.valores[i];
//             }
//             if (residuos_renovables.valores[i] > residuos_renovables.max)
// 			{
//                 residuos_renovables.max = residuos_renovables.valores[i];
// 			}
//             if (residuos_renovables.valores[i] < residuos_renovables.min)
//             {
//                residuos_renovables.min = residuos_renovables.valores[i];
//             }
//             if (generacion_total.valores[i] > generacion_total.max)
// 			{
//                 generacion_total.max = generacion_total.valores[i];
// 			}
//             if (generacion_total.valores[i] < generacion_total.min)
//             {
//                generacion_total.min = generacion_total.valores[i];
//             }
            
// 			i++;		
// 		}
// 		fclose(file);
// 	}
	
// 	hidraulica.media /= i;
// 	turbinacion.media /= i;
// 	nuclear.media /= i;
// 	carbon.media /= i;
// 	motores_diesel.media /= i;
// 	turbina_gas.media /= i;
// 	turbina_vapor.media /= i;
// 	ciclo_combinado.media /= i;
// 	hidroeolica.media /= i;
// 	eolica.media /= i;
// 	solar_fotovoltaica.media /= i;
// 	solar_termica.media /= i;
// 	otras_renovables.media /= i;
// 	cogeneracion.media /= i;
// 	residuos_no_renovables.media /= i;
// 	residuos_renovables.media /= i;
// 	generacion_total.media /= i;
	
// 	printf("ha leido %i filas.\n\n", i);
	
// 	printf("Variable\tMin\t\tMax\t\tMedia\n");
//     printf("hidraulica\t\t%f\t%f\t%f\n", hidraulica.min, hidraulica.max, hidraulica.media);
//     printf("turbinacion\t\t%f\t%f\t%f\n", turbinacion.min,turbinacion.max, turbinacion.media);
//     printf("nuclear\t\t%f\t%f\t%f\n", nuclear.min, nuclear.max, nuclear.media);
//     printf("carbon\t\t%f\t%f\t%f\n", carbon.min, carbon.max, carbon.media);
//     printf("motores_diesel\t\t%f\t%f\t%f\n", motores_diesel.min, motores_diesel.max, motores_diesel.media);
//     printf("turbina_gas\t\t%f\t%f\t%f\n", turbina_gas.min,turbina_gas.max, turbina_gas.media);
//     printf("turbina_vapor\t\t%f\t%f\t%f\n", turbina_vapor.min, turbina_vapor.max, turbina_vapor.media);
//     printf("ciclo_combinado\t\t%f\t%f\t%f\n", ciclo_combinado.min, ciclo_combinado.max, ciclo_combinado.media);
//     printf("hidroeolica\t\t%f\t%f\t%f\n", hidroeolica.min, hidroeolica.max, hidroeolica.media);
//     printf("eolica\t\t%f\t%f\t%f\n", eolica.min,eolica.max, eolica.media);
//     printf("solar_fotovoltaica\t\t%f\t%f\t%f\n", solar_fotovoltaica.min, solar_fotovoltaica.max, solar_fotovoltaica.media);
//     printf("solar_termica\t\t%f\t%f\t%f\n", solar_termica.min, solar_termica.max, solar_termica.media);
//     printf("otras_renovables\t\t%f\t%f\t%f\n", otras_renovables.min, otras_renovables.max, otras_renovables.media);
//     printf("cogeneracion\t\t%f\t%f\t%f\n", cogeneracion.min, cogeneracion.max, cogeneracion.media);
//     printf("residuos_no_renovables\t\t%f\t%f\t%f\n", residuos_no_renovables.min, residuos_no_renovables.max, residuos_no_renovables.media);
//     printf("residuos_renovables\t\t%f\t%f\t%f\n", residuos_renovables.min, residuos_renovables.max, residuos_renovables.media);
//     printf("generacion_total\t\t%f\t%f\t%f\n", generacion_total.min, generacion_total.max, generacion_total.media);
  
    
// }
