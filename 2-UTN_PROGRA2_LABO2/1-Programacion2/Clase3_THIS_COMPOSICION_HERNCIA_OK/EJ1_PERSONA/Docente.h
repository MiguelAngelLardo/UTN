#pragma once

#include "Empleado.h"

class Docente:public Empleado{
private:
  int _legajo;
  char _cargo[15];
  Fecha _fechaVacaciones;

public:
  Docente (int dni = -2, const char *nom = "S/Nombre", const char *ape = "S/Apellido", Fecha fNac = Fecha(), const char *dir = "S/Direccion", int codPos = -2, int cat = -2, float sueldo = 0.0, Fecha fIng = Fecha(1, 1, 1), int leg = -2, const char *car = "N/N", Fecha fVac = Fecha(6, 6, 6));

  ///SET
  void setLegajo(int l);
  void setCargo(const char *cargo);
  void setFechaVacaciones(Fecha f);

  ///GET
  int getLegajo();
  const char *getCargo();
  Fecha getFechaVacaciones();


  ///CARGAR-LISTAR
  void cargar();
  void mostrar();
};

Docente::Docente (int dni, const char *nom, const char *ape, Fecha fNac, const char *dir, int codPos, int cat, float sueldo, Fecha fIng, int leg, const char *car, Fecha fVac):
  Empleado(dni, nom, ape, fNac, dir, codPos, cat, sueldo, fIng),
  _legajo(leg){
    strcpy(_cargo, car);
    _fechaVacaciones = fVac;
   }

///SET
void Docente::setLegajo(int l){_legajo = l;}
void Docente::setCargo(const char *cargo){strcpy(_cargo, cargo);}
void Docente::setFechaVacaciones(Fecha f){_fechaVacaciones = f;}

///GET
int Docente::getLegajo(){return _legajo;}
const char *Docente::getCargo(){return _cargo;}
Fecha Docente::getFechaVacaciones(){return _fechaVacaciones;}


///CARGAR-LISTAR
void Docente::cargar(){
  Empleado::cargar();
  cout << "LEGAJO: ";
  cin >> _legajo;
  cout << "CARGO: ";
  cargarCadena(_cargo, 14);
  cout << "FECHA VACACIONES: " << endl;
  _fechaVacaciones.cargar();
}

void Docente::mostrar(){
  Empleado::mostrar();
  cout << "LEGAJO: " << _legajo << endl;
  cout << "CARGO: " << _cargo << endl;
  cout << "FECHA VACACIONES: ";
  _fechaVacaciones.mostrar();
}
