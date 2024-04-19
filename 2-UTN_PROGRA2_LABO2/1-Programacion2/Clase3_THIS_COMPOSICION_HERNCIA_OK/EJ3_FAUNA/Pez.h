#pragma once
#include "Animal.h"

class Pez:public Animal{
private:
  int _cantAletas;

public:
  Pez(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int ca= -1);

  void cargar();
  void mostrar();
};

Pez::Pez(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int ca): Animal(d, t, di, p, z, ta, po), _cantAletas(ca) {}

void Pez::cargar(){
    Animal::cargar();
    cout << "Cantidad de Aletas: ";
    cin >> _cantAletas;
}


void Pez::mostrar(){
  Animal::mostrar();
  cout << "Cantidad Aletas: " << _cantAletas << endl;
}
