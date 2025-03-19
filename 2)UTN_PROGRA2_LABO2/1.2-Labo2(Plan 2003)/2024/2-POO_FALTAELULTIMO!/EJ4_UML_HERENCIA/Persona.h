#pragma once
#include <iostream>
using namespace std;

class Persona{
protected:
  char _apellido[50];
  char _nombre[50];
  int _edad;
  int _dni;

public:
  void cargar();
  void mostrar();
};

void Persona::cargar(){
  cout << "APELLIDO: ";
  cin >> _apellido;
  cout << "NOMBRE: ";
  cin >> _nombre;
  cout << "EDAD: ";
  cin >> _edad;
  cout << "DNI: ";
  cin >> _dni;
}

void Persona::mostrar(){
  cout << _apellido << " " << _nombre << ", DNI nro "<< _dni << ". Tiene " << _edad << " anios.";
}
