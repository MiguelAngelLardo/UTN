#include <iostream>
#include "Postulante.h"

using namespace std;

std::string Postulante::getNombre(){
  return _nombre;
}

void Postulante::setNombre(std::string nombre){
  _nombre = nombre;  
}

int Postulante::getEdad(){
  return _edad;
}

void Postulante::setEdad(int edad){
  _edad = edad;
}

int Postulante::getExperiencia(){
  return _experiencia;
}

void Postulante::setExperiencia(int experiencia){
  _experiencia = experiencia;
}

std::string Postulante::getPuesto(){
  return _puesto;
}

void Postulante::setPuesto(std::string puesto){
  _puesto = puesto;
}

void Postulante::cargar(){
  cout << "Ingrese nombre: ";
  cin >> _nombre;
  cout << "Ingrese edad: ";
  cin >> _edad;
  cout << "Ingrese experiencia: ";
  cin >> _experiencia;
  cout << "Ingrese puesto:";
  cin >> _puesto;  
}
