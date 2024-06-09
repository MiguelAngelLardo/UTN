#pragma once
#include "Persona.h"

class Alumno:public Persona{
private:
  int _legajo;
  float _promedio;

public:
  void cargar();
  void mostrar();
};

void Alumno::cargar(){
  Persona::cargar();
  cout << "Legajo: ";
  cin >> _legajo;
}

void Alumno::mostrar(){
  Persona::mostrar();
  cout << "Su legajo es " << _legajo << " y tiene un promedio de: " << _promedio << ".";
}