#include <iostream>
#include <cstring>
#include "fecha.h"
#include "investigadores.h"
#include "funciones.h"


const char* Investigador::getNombre (){
  return _nombre;
}

std::string Investigador::getApellido(){
  return _apellido;
}

Fecha Investigador::getFechaNacimiento(){
  return _fechaNacimiento;
}

int Investigador::getUnidadAcademica(){
  return _unidadAcademica;
}

int Investigador::getCategoria(){
  return _categoria;
}

int Investigador::getEspecialidad(){
  return _especialidad;
}

int Investigador::getDNI(){
  return dni;
}

void Investigador::setNombre(const char n[]){
  strcpy(_nombre, n);
}

void Investigador::setApellido(std::string apellido){
  while (apellido.length() > 30){
    std::cout << "ERROR: Escriba menos de 30 letras: ";
    getline(std::cin, apellido);
  } 
  _apellido = apellido;
}

void Investigador::setFechaNacimiento (Fecha fechaNacimiento){
  _fechaNacimiento = fechaNacimiento;
}

void Investigador::setUnidadAcademica (int unidadAcademica){
  while(unidadAcademica < 1 || unidadAcademica > 30){
    std::cout << "VALOR INVALIDO -> Ingrese un valor de 1 al 30: ";
    std::cin >> unidadAcademica;
  }
  _unidadAcademica = unidadAcademica;  
}

void Investigador::setCategoria(int categoria){
  while (categoria < 1 || categoria > 5){
    std::cout << "VALOR INVALIDO -> Ingrese un valor entre 1 y 5: ";
    std::cin >> categoria;  
  }
  _categoria = categoria;
}

void Investigador::setEspecialidad(int especialidad){
  while (especialidad < 1 || especialidad > 10){
    std::cout << "VALOR INVALIDO -> Ingrese un valor entre 1 y 10: ";
    std::cin >> especialidad;
  }
  _especialidad = especialidad;
}

void Investigador::setDNI(int dni){
  this->dni = dni;
}

Investigador::Investigador(){

}

Investigador::Investigador (const char *nombre, std::string apellido, Fecha fechaNAcimiento,  int unidadAcademica, int categoria, int especialidad, int dni){
  setNombre(nombre);
  setApellido(apellido);
  setFechaNacimiento(fechaNAcimiento);
  setUnidadAcademica(unidadAcademica);
  setCategoria(categoria);
  setEspecialidad(especialidad);
  setDNI(dni);
}

std::string Investigador::toString() {
    std::string valorADevolver;
    valorADevolver = "Nombre: " + std::string(_nombre) +
                     "\nApellido: " + _apellido +
                     "\nFecha Nacimiento: " + _fechaNacimiento.toString() +
                     "\nUnidad Academica: " + std::to_string(_unidadAcademica) +
                     "\nCategoria: " + std::to_string(_categoria) +
                     "\nEspecialidad: " + std::to_string(_especialidad) +
                     "\nDNI: " + std::to_string(dni);

    return valorADevolver;
}
