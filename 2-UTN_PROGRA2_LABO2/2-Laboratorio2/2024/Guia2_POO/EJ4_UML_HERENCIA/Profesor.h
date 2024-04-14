#pragma once
#include "Empleado.h"

class Profesor:public Empleado{
private: 
  char _titulo[50];
public:
  void cargar();
  void mostrar();
};

void Profesor::cargar(){
  Empleado::cargar();
  cout << "Titulo: ";
  cin >> _titulo;
}

void Profesor::cargar(){
  Empleado::mostrar();
  cout << "Tiene el titulo de " << _titulo << ".";
}