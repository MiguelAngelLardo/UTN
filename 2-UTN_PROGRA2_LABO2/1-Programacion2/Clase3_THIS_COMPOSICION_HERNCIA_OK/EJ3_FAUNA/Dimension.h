#pragma once

class Dimension{
private:
  int _largo, _ancho, _alto;

public:
  Dimension(int lar = -1, int ancho = -1, int alto = -1);

  void cargar();
  void mostrar();
};

Dimension::Dimension(int lar, int ancho, int alto) : _largo(lar), _ancho(ancho), _alto(alto){}


void Dimension::cargar(){
  cout << "Largo: ";
  cin >> _largo;
  cout << "Ancho: ";
  cin >> _ancho;
  cout << "Alto: ";
  cin >> _alto;
}

void Dimension::mostrar(){
  cout << "Dimensiones => Largo: " << _largo << " - Ancho: " << _ancho << " - Alto: " << _alto << endl;
}
