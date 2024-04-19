#pragma once
#include "Inmueble.h"

class Casa:public Inmueble{
private:
  int _cantAmbiente;
  int _superficieConstruida;

public:
  Casa(const char *dir = "xxx", Fecha fechIng = Fecha(6,6,6), Fecha fechOp = Fecha(7,7,7), int supTot = -1, int tipoOp = -1, int cantAmb = -1, int sup = -1);

  void mostrar();

};

Casa::Casa(const char *dir, Fecha fechIng, Fecha fechOp, int supTot, int tipoOp, int cantAmb, int sup) :
  Inmueble(dir,fechIng, fechOp, supTot, tipoOp), _cantAmbiente(cantAmb), _superficieConstruida(sup){}


void Casa::mostrar(){
  Inmueble::mostrar();
  cout << "CANTIDAD AMBIENTE: " << _cantAmbiente << endl;
  cout << "SUPERFICIE CONSTRUIDA: " << _superficieConstruida << endl;
}
