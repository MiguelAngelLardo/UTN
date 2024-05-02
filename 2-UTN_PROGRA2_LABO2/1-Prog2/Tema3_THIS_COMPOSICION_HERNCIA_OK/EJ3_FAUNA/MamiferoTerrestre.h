#pragma once
#include "Mamifero.h"

class MamiferoTerrestre:public Mamifero{
private:
  int _numPatas;

public:
  MamiferoTerrestre(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int ev = -1, int cc = -1, int ems = -1, int np = -1);

  void cargar();
  void mostrar();
};

MamiferoTerrestre::MamiferoTerrestre(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int ev, int cc, int ems, int np) :
  Mamifero(d, t, di, p, z, ta, po, ev, cc, ems), _numPatas(np) {}

void MamiferoTerrestre::cargar(){
   Mamifero::cargar();
   cout << "Numero de Patas: ";
   cin >>_numPatas;
}


void MamiferoTerrestre::mostrar(){
  Mamifero::mostrar();
  cout << "Numero de Patas: " << _numPatas << endl;
}

