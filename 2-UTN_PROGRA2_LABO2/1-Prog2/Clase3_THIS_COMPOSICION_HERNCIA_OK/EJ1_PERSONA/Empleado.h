#pragma once
#include "Persona.h"

class Empleado:public Persona{
protected:
  int _categoria;//1 a 5
  float _sueldo;
  Fecha _fechaIngreso;

public:
  Empleado(int dni = -1, const char *nom = "S/Nom", const char *ape = "S/Ape", Fecha fe = Fecha(), const char *dir = "S/Dir", int codPos = -1, int cat = 0, float sueldo = 0.0, Fecha f = Fecha(1, 1, 1));

  ///SET
  void setCategoria(int cat);
  void setSueldo(float sueldo);
  void setFechaIngreso(Fecha f);

  ///GET
  int getCategoria();
  float getSueldo();
  Fecha getFechaIngreso();

  ///CARGAR-LISTAR
  void cargar();
  void mostrar();
};

Empleado::Empleado(int dni, const char *nom, const char *ape, Fecha fe, const char *dir, int codPos, int cat, float sueldo, Fecha f) : Persona(dni, nom, ape, fe, dir, codPos), _categoria(cat), _sueldo(sueldo),  _fechaIngreso(f){}

///SET
void Empleado::setCategoria(int cat){_categoria = (cat >= 1 && cat <= 5) ? cat : -1;}
void Empleado::setSueldo(float sueldo){_sueldo = sueldo;}
void Empleado::setFechaIngreso(Fecha f){_fechaIngreso = f;}

///GET
int Empleado::getCategoria(){return _categoria;}
float Empleado::getSueldo(){return _sueldo;}
Fecha Empleado::getFechaIngreso(){return _fechaIngreso;}

///CARGAR-LISTAR
void Empleado::cargar(){
  Persona::cargar();
  int cat;
  cout << "CATEGORIA(1 al 5): ";
  cin >> cat;
  setCategoria(cat);
  cout << "FECHA INGRESO: " << endl;
  _fechaIngreso.cargar();
  cout << "SUELDO: ";
  cin >> _sueldo;
}

void Empleado::mostrar(){
  Persona::mostrar();
  cout << "CATEGORIA: " << _categoria << endl;
  cout << "FECHA INGRESO: ";
  _fechaIngreso.mostrar();
  cout << "SUELDO: " << _sueldo << endl;
}
