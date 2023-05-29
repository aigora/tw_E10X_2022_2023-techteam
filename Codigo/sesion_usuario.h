#ifndef SESION_USUARIO_H
#define SESION_USUARIO_H

int iniciarSesion();
int crearCuenta();
int ayudaContrasena();
int contrasenaCorrecta(char contrasena[]); //bool
int eleccionPreguntaSeguridad(usuario *usuarioNuevo);
int sesionUsuario();

#endif