#pragma once
#include "Mamifero.h"

class MamiferoAcuatico:public Mamifero{
private:
  int _profundidadMax;

public:
  MamiferoAcuatico (Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int ev = -1, int cc = -1, int ems = -1, int pm = -1);

  void cargar();
  void mostrar();

};

MamiferoAcuatico::MamiferoAcuatico(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int ev, int cc, int ems, int pm) :
  Mamifero(d, t, di, p, z, ta, po, ev, cc, ems), _profundidadMax(pm) {}

void MamiferoAcuatico::cargar(){
   Mamifero::cargar();
   cout << "Profundidad Maxima: ";
   cin >>_profundidadMax;
}


void MamiferoAcuatico::mostrar(){
  Mamifero::mostrar();
  cout << "Profundidad maxima: " << _profundidadMax << endl;
}
