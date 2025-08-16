#pragma once 
#include <cstring>
#include "Funciones.h"

class Materia{
private:
  int _codigo;
  char _materia[50];
  char _carrera[50];

public:
  Materia(int cod = 1, const char *mat = "S/N", const char *car = "S/N");

  void setCodigo(int cod){_codigo = cod;}
  void setMateria(const char *mat){strcpy(_materia, mat);}
  void setCarrera(const char *car){strcpy(_carrera, car);}

  int getCodigo(){return _codigo;}
  const char *getMateria(){return _materia;}
  const char *getCarrera(){return _carrera;}

  void cargar();
  void mostrar();

};

Materia::Materia(int cod, const char *mat, const char *car){
  _codigo = cod;
  strcpy(_materia, mat);
  strcpy(_carrera, car);
}

void Materia::cargar(){
  cout << "CODIGO: ";
  cin >> _codigo;
  cout << "NOMBRE MATERIA: ";
  cin.ignore();
  cargarCadena(_materia, 49);
  cout << "NOMBRE CARRERA: ";
  cargarCadena(_carrera, 49);
}

void Materia::mostrar(){
  cout << "CODIGO: " << _codigo << endl;
  cout << "NOMBRE MATERIA: " << _materia << endl;
  cout << "NOMBRE CARRERA: " << _carrera << endl;
}

