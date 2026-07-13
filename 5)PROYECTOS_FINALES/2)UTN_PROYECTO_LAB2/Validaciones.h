#pragma once
#include <string>
#include "Disenio.h"
#include "fecha.h"


/**
 * @brief Valida una cadena ingresada por el usuario usando expresiones regulares segun sea DNI, email o telefono y ademas un texto descriptivo.
 *
 * Dependiendo del valor de `tipoValidacion`, se aplica una validación distinta:
 * 1- Texto: Valida que la cadena ingresada contenga solo letras y espacios.
 * 2- DNI: Valida que la cadena ingresada contenga solo numeros.
 * 3- Email: Valida que la cadena ingresada tenga un formato de email valido.
 * 4- Telefono: Valida que la cadena ingresada tenga un formato de telefono valido.
 * 5- Temperatura: Valida que la cadena ingresada tenga un formato de temperatura valido (ej. 35.6).Ademas numeros entre 25 y 45.
 * 
 * Para el caso de la opcion 1, 3, 4 y 5se valida que el texto ingresado tenga un largo entre `minTamTextMailTel` y `maxTamTextMailTel` caracteres.
 * 
 * @param textoAMostrar Texto descriptivo que se muestra al usuario (ej. "Nombre", "Domicilio", el DNI", "el mail", "el telefono").
 * @param yActual Posicion vertical en la pantalla donde se muestra el texto descriptivo.
 * @param tipoValidacion Tipo de validacion a realizar (1- Texto, 2- DNI, 3- Email, 4- Telefono, 5- Temperatura).
 * @param deltaY valor que suma a la posicion vertical actual para mostrar el texto.
 * @param minTamTextMailTel Largo minimo para el texto
 * @param maxTamTextMailTel Largo maximo para el texto * 

 * @return std::string Cadena validada que cumple con el formato requerido ya sea Texto, DNI, Email o Telefono.
 */
std::string validarTodoRl(const std::string &textoAMostrar, int &yActual, int tipoValidacion = 1, int deltaY = 2, int minTamTextMailTel = 4, int maxTamTextMailTel = 25);
Fecha validarFechaRl(const std::string &textoAMostrar, int &yActual, int deltaY = 2);

bool preguntarSiNoRl(const std::string &output, int &yActual, int deltaY = 2);
void mostrarMensajeErrorTemporal(int xInput, int yActual, const std::string &borrarCin, const std::string &mensajeError);// lo uso en preguntarSiNo y validarTodoRl

// --- NUEVA FUNCIÓN GENÉRICA ---
template <typename ArchivoGenerico>//con template la declaracion y definicion va en .H
void validarExistenciaDat_CeroReg_ErrorMem(ArchivoGenerico &tipoArchivo, int &cantidadRegistros, bool& exito, int yActual, int deltaY = 0){

  cantidadRegistros = tipoArchivo.getCantidadRegistros(tipoArchivo.getNombreArchivo());  // Obtenemos la cantidad de registros. 

  if(tipoArchivo.existeArchivo(tipoArchivo.getNombreArchivo()) == false){
    std::string mensaje = "No existe el archivo: " + tipoArchivo.getNombreArchivo();
    coutCentrado(mensaje, yActual, deltaY);
    exito = false; // Indicamos que no se puede continuar (no hay nada que listar).
    return;
  }

  if (cantidadRegistros == -1) {  // Se comprueba el error más grave primero (-1)
    std::string mensaje = "No se pudo acceder al archivo(error memoria): " + tipoArchivo.getNombreArchivo();
    coutCentrado(mensaje, yActual, deltaY);
    exito = false;
    return;
  }

  
  if (cantidadRegistros == 0) {// Luego, comprobamos si está vacío (0)
    std::string mensaje = "No hay registros cargados en: " + tipoArchivo.getNombreArchivo();
    coutCentrado(mensaje, yActual, deltaY);
    exito = false;
    return;
  }
}
