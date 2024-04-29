#include "Persona.h"

int Persona::getDocumento(){
  return _documento;
}

void Persona::setDocumento(int documento){
  _documento = documento;
}

std::string Persona::getNombre(){
  return _nombre;
}

void Persona::setNombre(std::string nombre){
  _nombre = nombre;
}

std::string Persona::getApellido(){
  return _apellido;
}

void Persona::setApellido(std::string apellido){
  _apellido = apellido;
}

int Persona::getNacimiento(){
  return _nacimiento;
}

void Persona::setNacimiento(int nacimiento){
  _nacimiento = nacimiento; 
}

Persona::Persona(int documento, std::string nombre, std::string apellido, int nacimiento){
  _documento = documento;
  _nombre = nombre;
  _apellido = apellido;
  _nacimiento = nacimiento;
}

std::string Persona::nombreCompleto(){
  std::string nombreApellido;

  nombreApellido = _nombre + " " + _apellido;

  return nombreApellido;
}

int Persona::edad(){
  return 2024 - _nacimiento;
}

void Persona::tuNuevoNombre(std::string nuevoNombre){
  if(nuevoNombre != " ")//si esta vacio no lo carga
    _nombre = nuevoNombre;
}


std::string Persona::toString(){
  return "DNI " + std::to_string(_documento) + " " + nombreCompleto() + " nacio en " +  std::to_string (_nacimiento) + " -> tiene: " + std::to_string(edad()) + " años"; 
}


