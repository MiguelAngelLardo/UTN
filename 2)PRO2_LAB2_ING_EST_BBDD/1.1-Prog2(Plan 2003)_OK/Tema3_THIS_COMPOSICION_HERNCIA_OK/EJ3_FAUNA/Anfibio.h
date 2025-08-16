#pragma once
#include "Animal.h"

class Anfibio:public Animal{
private:
  char _tipoPiel; //s-suave, a-aspera

public:
  Anfibio(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, char tp = '+');

  void cargar();
  void mostrar();
};

Anfibio::Anfibio(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, char tp): Animal(d, t, di, p, z, ta, po), _tipoPiel(tp) {}

void Anfibio::cargar(){
    Animal::cargar();
    cout << "Tipo de Piel: ";
    cin >> _tipoPiel;
}


void Anfibio::mostrar(){
  Animal::mostrar();
  cout << "Tipo de Piel: " << _tipoPiel << endl;
}
