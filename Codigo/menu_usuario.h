#ifndef MENU_USUARIO_H
#define MENU_USUARIO_H

int menuUsuarioAbierto(usuario *usuarioActual);
int menuUsuario(usuario *usuarioActual);

void mostrarDatosGuardados();
void cambiarContrasena();
int borrarCuenta(usuario *usuarioActual);
void borrarArchivoCuenta(usuario *usuarioActual);
int borrarDatosGuardados(usuario *usuarioActual);
void borrarTodosDatos(usuario *usuarioActual);
void borrarUnDatoGuardado(usuario *usuarioActual, int numeroFila);
void leerDatosGuardados(usuario *usuarioActual);

#endif
