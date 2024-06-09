#pragma once

#include "Denominacion.h"
#include "Dimension.h"

class Animal{
protected:
  Denominacion _denominacion;
  int _tiempoVida;
  Dimension _dimension;
  int _peso;
  char _zonaHabitat[20];
  char _tipoAlimentacion; //'c'-carne, 'g'-grano
  int _poblacion;

public:
  Animal(Denominacion d = Denominacion("AA", "BB", "CC"), int t = -1, Dimension di = Dimension(-1,-1,-1), int p = -1, const char z[] = "S/Z", char ta = 'a', int po = -1);

  void cargar();
  void mostrar();
};

Animal::Animal(Denominacion d, int t, Dimension di, int p, const char z[], char ta, int po) :
  _denominacion(d), _tiempoVida(t), _dimension(di), _peso(p), _tipoAlimentacion(ta), _poblacion(po)
  {strcpy(_zonaHabitat, z);}


void Animal::cargar(){
  _denominacion.cargar();
  cout << "Tiempo vida: ";
  cin >> _tiempoVida;
  _dimension.cargar();
  cout << "Peso: ";
  cin >> _peso;
  cout << "Zona Habitat: ";
  cargarCadena(_zonaHabitat, 19);
  cout << "Tipo alimentacion: ";
  cin >> _tipoAlimentacion;
  cout << "Poblacion: ";
  cin >> _poblacion;
}

void Animal::mostrar(){
  _denominacion.mostrar();
  cout << "Tiempo de vida: " << _tiempoVida << endl;
  _dimension.mostrar();
  cout << "Peso: " << _peso << endl;
  cout << "Zona Habitat: " << _zonaHabitat << endl;
  cout << "Tipo Alimentacion: " << _tipoAlimentacion << endl;
  cout << "Peso: " << _poblacion << endl;
}
