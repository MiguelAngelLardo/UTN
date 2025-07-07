#pragma once
#include "Animal.h"

class Mamifero:public Animal{
protected:
  int _esperanzaVida;
  int _cantCrias;
  int _edadMadurezSex;

public:
  Mamifero(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1, int ev = -1, int cc = -1, int ems = -1);

  void cargar();
  void mostrar();
};

Mamifero::Mamifero(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po, int ev, int cc, int ems) :
  Animal(d, t, di, p, z, ta, po), _esperanzaVida(ev), _cantCrias(cc), _edadMadurezSex(ems) {}

void Mamifero::cargar(){
    Animal::cargar();
    cout << "Esperanza vida: ";
    cin >>_esperanzaVida;
    cout << "Cantidad de crias: ";
    cin >> _cantCrias;
    cout << "Edad de madurez sexual: ";
    cin >> _edadMadurezSex;
}


void Mamifero::mostrar(){
  Animal::mostrar();
  cout << "Esperanza vida: " << _esperanzaVida << endl;
  cout << "Cantidad crias: " << _cantCrias << endl;
  cout << "Edad madurez sexual: " << _edadMadurezSex << endl;
}
