#pragma once
#include "Inmueble.h"

class Departamento:public Inmueble{
public:
  int _cantAmbiente;
  bool _instalacionComplementaria;

public:
  Departamento(const char *dir = "S/Dir", Fecha fechIng = Fecha(2,2,2), Fecha fechOp = Fecha(2,2,2), int supTot = 2, int tipoOp = 2, int cantAmb = 2, bool instalCom = false);
  void mostrar();
};

Departamento::Departamento(const char *dir, Fecha fechIng, Fecha fechOp, int supTot, int tipoOp, int cantAmb, bool instalCom) :
  Inmueble(dir, fechIng, fechOp, supTot, tipoOp), _cantAmbiente(cantAmb), _instalacionComplementaria(instalCom) {}


void Departamento::mostrar(){
  Inmueble::mostrar();
  cout << "CANTIDAD AMBIENTE: " << _cantAmbiente << endl;
  cout << "INSTALACION COMPLEMENTARIA: " << _instalacionComplementaria << endl;
}
