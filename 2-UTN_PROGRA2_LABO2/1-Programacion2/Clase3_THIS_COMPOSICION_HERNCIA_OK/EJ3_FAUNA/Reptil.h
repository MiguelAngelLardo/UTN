#pragma once
#include "Animal.h"

class Reptil:public Animal{
private:
  int _tempCorporal;

public:
  Reptil(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int tc = -1);

  void cargar();
  void mostrar();
};

Reptil::Reptil(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int tc): Animal(d, t, di, p, z, ta, po), _tempCorporal(tc) {}

void Reptil::cargar(){
    Animal::cargar();
    cout << "Temperatura corporal: ";
    cin >> _tempCorporal;
}


void Reptil::mostrar(){
  Animal::mostrar();
  cout << "Temperatura corporal: " << _tempCorporal << endl;
}
