#pragma once
#include "Animal.h"

class Ave:public Animal{
private:
  int _longitudAla;

public:
  Ave(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int la = -1);

  void cargar();
  void mostrar();
};

Ave::Ave(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int la): Animal(d, t, di, p, z, ta, po), _longitudAla(la) {}

void Ave::cargar(){
    Animal::cargar();
    cout << "Longitud del ala: ";
    cin >> _longitudAla;
}


void Ave::mostrar(){
  Animal::mostrar();
  cout << "Longitud del ala: " << _longitudAla << endl;
}
