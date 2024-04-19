#pragma once
#include <cstring>
#include "Fecha.h"
#include "Funciones.h"

class Inmueble{ //Clase Base
protected:
  char _direccion[50];
  Fecha _fechaIngreso;
  Fecha _fechaOperacion;
  int _superficieTotal;
  int _tipoOperacion;//1 venta - 2 alquiler

public:
  Inmueble(const char *dir = "S/D", Fecha fechIng = Fecha(1,1,1), Fecha fechOp = Fecha(1,1,1), int supTot = 1, int tipoOp = 1);

  void mostrar();

};

Inmueble::Inmueble(const char *dir, Fecha fechIng, Fecha fechOp, int supTot, int tipoOp) : _fechaIngreso(fechIng), _fechaOperacion(fechOp), _superficieTotal(supTot), _tipoOperacion(tipoOp){
  strcpy(_direccion, dir);
}

void Inmueble::mostrar(){
  cout << "DIRECCION: " << _direccion << endl;
  cout << "FECHA INGRESO: ";
  _fechaIngreso.mostrar();
  cout << "FECHA OPERACION: ";
  _fechaOperacion.mostrar();
  cout << "SUPERFICIE TOTAL: " << _superficieTotal << endl;
  cout << "TIPO OPERACION: " << _tipoOperacion << endl;
}
