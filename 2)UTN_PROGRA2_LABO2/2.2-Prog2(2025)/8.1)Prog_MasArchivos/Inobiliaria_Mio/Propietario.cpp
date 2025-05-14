#include <cstring>
#include "Propietario.h"

using namespace std;

Propietario::Propietario(){
  _nombre[0] = '\0';
  _apellido[0] = '\0';
  _DNI[0] = '\0';
  _celular[0] = '\0';
  _estado = true;
}

Propietario::Propietario(std::string nombre, std::string apellido, std::string dni, std::string celular, bool estado){
  setNombre(nombre);
  setApellido(apellido);
  setDNI(dni);
  setCelular(celular);
  setEstado(estado);
}

void Propietario::setNombre(std::string nombre){
  strcpy(_nombre, nombre.c_str());
}

void Propietario::setApellido(std::string apellido){
  strcpy(_apellido, apellido.c_str());
}

void Propietario::setDNI(std::string dni){
  strcpy(_DNI, dni.c_str());
}

void Propietario::setCelular(std::string celular){
  strcpy(_celular, celular.c_str());
}

void Propietario::setEstado(bool estado){
  _estado = estado;
}

std::string Propietario::getNombre(){
  return _nombre;
}

std::string Propietario::getApellido(){
  return _apellido;
}

std::string Propietario::getDNI(){
  return _DNI;
}

std::string Propietario::getCelular(){
  return _celular;
}

bool Propietario::getEstado(){
  return _estado;
}

std::string Propietario::toCSV(){
  return string(_nombre) + "," + string(_apellido) + "," + string(_DNI) + "," + string(_celular) + "," + (_estado ? "True" : "False");
}