#include <iostream>
#include <cstring>
#include "Estudios.h"
#include "Disenio.h"
#include "rlutil.h"

using namespace std;

Estudios::Estudios(){
  _codigoEstudio[0] = '\0';
  _descripcion[0] = '\0';
}

Estudios::Estudios(std::string codigoEstudio, std::string descripcion){
  setCodigoEstudio(codigoEstudio);
  setDescripcion(descripcion);
}

void Estudios::setCodigoEstudio(const std::string &codigoEstudio){
  if(codigoEstudio.length() <= 4){
    strcpy(_codigoEstudio, codigoEstudio.c_str());
  } else {
    _codigoEstudio[0] = '\0';
  }
}

void Estudios::setDescripcion(const std::string &descripcion){
  if(descripcion.length() <= 36){
    strcpy(_descripcion, descripcion.c_str());
  } else {
    _descripcion[0] = '\0';
  }
}

std::string Estudios::getCodigoEstudio() const{
  return _codigoEstudio;
}

std::string Estudios::getDescripcion() const{
  return _descripcion;
}

  void Estudios::mostrar() const{
    cout << "Codigo de Estudio: " << _codigoEstudio << endl;
    cout << "Descripcion: " << _descripcion << endl;
  }
