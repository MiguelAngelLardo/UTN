#include "Validaciones.h"
#include <iostream>
#include <regex>

#include "Disenio.h"
#include "rlutil.h"  // Incluir nuevamente para asegurar

using namespace std;


/*****************************FX utopicas**********************/
string validarTodoRl(const string &textoAMostrar, int &yActual, int tipoValidacion, int deltaY,  int minTamTextMailTel, int maxTamTextMailTel){
  dibujarMarcoPrincipal();
  string text_dni_mail_tel;
  regex dniTestigo("^[1-9][0-9]{6,7}$"); //la regex ya tiene su largo de 7 a 8
  regex mailTestigo("^[a-zA-Z0-9ñ._-]+@[a-zA-Z0-9]+\\.([a-zA-Z]{3,4})(\\.([a-zA-Z]{2,3}))?$");
  regex telefonoTestigo("^[+]*[(]?[0-9]{1,4}[)]?[0-9\\s-]+$");
  regex temperaturaTestigo("^(2[5-9]|3[0-9]|4[0-5])(\\.[0-9])?$");//25 a 29 || 30 a 39 || 40 a 45 -> ? es 0 o 1 vez

  string mensaje = string(1, char(175)) + " " + "Ingrese " + textoAMostrar + ":"; ///string(size_t n, char c) me pone el char en el lenght que tengo - ": " no uso por q me piinta el espacio de azul
  int x = calcularCentradoX(mensaje);
  bool valido = false;
  string mensajeError;

  do{
    coutPosicionadoRl(x, yActual, mensaje, rlutil::BLUE, rlutil::WHITE);// Subrayado en Y+1
    text_dni_mail_tel = cinPosicionadoRl(x + mensaje.length() + 1, yActual);//fondo negro letra verde - asi no me lo pinta en azul y me da un espacio mas

    switch(tipoValidacion){
      case 1:
        valido = (minTamTextMailTel != maxTamTextMailTel) ? (text_dni_mail_tel.length() >= minTamTextMailTel && text_dni_mail_tel.length() <= maxTamTextMailTel) : (text_dni_mail_tel.length() == minTamTextMailTel);
        mensajeError = valido  ? "" : "Error: " + textoAMostrar +  (minTamTextMailTel != maxTamTextMailTel ? " debe tener entre " + to_string(minTamTextMailTel) + " y " + to_string(maxTamTextMailTel) + " caracteres." : " debe tener estrictamente " + to_string(minTamTextMailTel) + " caracteres.");
      break;

      case 2:
        valido = regex_match(text_dni_mail_tel, dniTestigo);
        mensajeError = valido ? "" : "Error: " + textoAMostrar + " debe tener entre 7 y 8 caracteres y no empezar con 0.";
      break;

      case 3:
        valido = (regex_match(text_dni_mail_tel, mailTestigo)) && (text_dni_mail_tel.length() >= minTamTextMailTel && text_dni_mail_tel.length() <= maxTamTextMailTel);
        mensajeError = valido ? "" : "Error: " + textoAMostrar + " debe tener un formato valido (ejemplo@gmail.com o ejemplo@gmail.com.ar).";
      break;

      case 4:
        valido = (regex_match(text_dni_mail_tel, telefonoTestigo)) && (text_dni_mail_tel.length() >= minTamTextMailTel && text_dni_mail_tel.length() <= maxTamTextMailTel);
        mensajeError = valido ? "" : "Error: " + textoAMostrar + " debe tener un formato valido (+549 11 2345-6789 o 11 234 567).";
      break;

      case 5:
        valido = regex_match(text_dni_mail_tel, temperaturaTestigo);
        mensajeError = valido ? "" : "Error: " + textoAMostrar + " debe tener un formato valido entre 25 a 45 (Ej: 36.5 o 36).";
      break;
    }

    if (!valido) {// limpio cin y muestro error
      mostrarMensajeErrorTemporal(x + mensaje.length() + 1, yActual, text_dni_mail_tel, mensajeError);
    }

  }while(!valido);

  yActual += deltaY; // Actualizar Y para el próximo elemento
  return text_dni_mail_tel;
}

bool preguntarSiNoRl(const string& output, int &yActual, int deltaY) {
  // char respuesta = '\0';
  string input;

  string mensaje = output + " (S/N):";//no va ": " por si lo quiero pintar en azul
  int x = calcularCentradoX(mensaje);
  coutPosicionadoRl(x, yActual, mensaje, rlutil::BLACK, rlutil::YELLOW, false);
  do{
    input = cinPosicionadoRl(x + mensaje.length() + 1, yActual, rlutil::BLACK, rlutil::LIGHTGREEN); //leo desp del mensaje
    if(!input.empty()) input[0] = toupper(input[0]);//si no esta vacio solo me interesa convertirla primera en mayuscula

    if (input.length() != 1 || (input != "S" && input!= "N")){//me aseguro que no ponga "nk" o "sj"
      string mensajeError = "Respuesta invalida. Presione 'S' o 'N'.";
      mostrarMensajeErrorTemporal(x + mensaje.length() + 1, yActual, input, mensajeError);
    }
  }while(input.length() != 1 || (input != "S" && input!= "N"));

  yActual += deltaY;
  return (input == "S");
}


void mostrarMensajeErrorTemporal(int xInput, int yActual, const string &borrarCin, const string &mensajeError) {
  int errorX = calcularCentradoX(mensajeError);
  int errorY = yActual + 2;

  coutPosicionadoRl(xInput, yActual, string(borrarCin.length(), ' '), rlutil::BLACK, rlutil::BLACK, false);// Borro lo que se haya escrito en la línea de entrada

  // Muestro el mensaje de error centrado
  coutPosicionadoRl(errorX, errorY, mensajeError, rlutil::RED, rlutil::WHITE, false);
  rlutil::msleep(1800);
  coutPosicionadoRl(errorX, errorY, string(mensajeError.length(), ' '), rlutil::BLACK, rlutil::BLACK, false); // Borro el mensaje de error
}

Fecha validarFechaRl(const string &textoAMostrar, int &yActual, int deltaY) {
  dibujarMarcoPrincipal();
  regex fechaTestigo("^([0-2]?[0-9]|3[01])/([0]?[1-9]|1[0-2])/([0-9]{4})$");//00 a 31 / 01 a 12 / 0000 a 9999

  string fechaIngresada, mensajeError;
  bool valido = false;

  string mensaje = string(1, char(175)) + " Ingrese " + textoAMostrar + " (DD/MM/AAAA):";
  int x = calcularCentradoX(mensaje);

  int dia, mes, anio;
  do{
    coutPosicionadoRl(x, yActual, mensaje, rlutil::BLUE, rlutil::WHITE);
    fechaIngresada = cinPosicionadoRl(x + mensaje.length() + 1, yActual);

    smatch subExpresiones; // smatch me separa las expresiones que tienen ()  => match[0] = "DD/MM/AAAA", match[1] = "DD", match[2] = "MM", match[3] = "AAAA"
    if(regex_match(fechaIngresada, subExpresiones, fechaTestigo)){ //el tercer parametro (el del medio) es para guardar las subExpresiones del ()
      dia = stoi(subExpresiones[1].str()); //stoy castea de string a int
      mes = stoi(subExpresiones[2].str());
      anio = stoi(subExpresiones[3].str());

      Fecha fechaTemp;
      valido = fechaTemp.esFechaValida(dia, mes, anio); //se fija q esten bien los dias meses y si es bisiesto
      mensajeError = valido ? "" : "Error: Fecha invalida. Verifique dia, mes y anioo.";
    }else{
      mensajeError = "Error: Formato invalido. Use DD/MM/AAAA.";
    }

    if (!valido) {
      mostrarMensajeErrorTemporal(x + mensaje.length() + 1, yActual, fechaIngresada, mensajeError);
    }

  }while(!valido);

  yActual += deltaY;
  return Fecha(dia, mes, anio);
}


