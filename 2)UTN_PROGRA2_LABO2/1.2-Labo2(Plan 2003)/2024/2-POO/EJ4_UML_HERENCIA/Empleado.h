#pragma once
#include <iostream>
using namespace std;
#include "Persona.h"

class Empleado:public Persona{
protected:
  int _antiguedad;
  float _sueldo;

public:
  void cargar();
  void mostrar ();
};

void Empleado::cargar(){
  Persona::cargar();
  cout << "Antiguedad: ";
  cin >> _antiguedad;
  cout << "Sueldo: ";
  cin >> _sueldo;
}
  
  
void Empleado::mostrar (){
  Persona::mostrar();
  cout << "Tiene una antiguedad de " << _antiguedad << " y un sueldo";
  cout << " de $" << _sueldo << ". ";
}