#ifndef SESION_INCOGNITO_H
#define SESION_INCOGNITO_H

void valorMedio(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos,
                calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);
void valorMaximoMinimo(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos,
                       calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);
void generacionMasMenosUsada(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos,
                             calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);
void sumaTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos,
               calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);
void porcentajeGeneracionTotal(generacionElectrica *generacionDatos, datosParaCalculos *datosCalculos,
                               calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);

int lecturaGeneracion(generacionElectrica *generacionDatos);
int calculoDatos(generacionElectrica *generacionDatos, usuario *usuarioActual);
void guardarCalculos(usuario *usuarioActual, calculoGuardado *calculoNuevo1, calculoGuardado *calculoNuevo2);

int sesionIncognito(usuario *usuarioActual);

#endif