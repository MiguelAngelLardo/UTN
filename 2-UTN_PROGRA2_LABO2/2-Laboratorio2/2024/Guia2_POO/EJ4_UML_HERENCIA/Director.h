#pragma once 
#include "Empleado.h"

class Director:public Empleado{
private:
  char _carrera[50];
public:
  void cargar();
  void mostrar();
};

void Director::cargar(){
  Empleado::cargar();
  cout << "Carrera: ";
  cin >> _carrera;
}

void Director::mostrar(){
  Empleado::mostrar();
  cout << "Es el director/a de la carrera " << _carrera << "."; 
}