#include <stdio.h>

void valorMedio(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos);
void valorMaximoMinimo(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos);
void generacionMasMenosUsada(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos);
void sumaTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos);
void porcentajeGeneracionTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos);

int lecturaGeneracion(generacionElectrica* generacionDatos);
int calculoDatos(generacionElectrica* generacionDatos);

int sesionIncognito();
