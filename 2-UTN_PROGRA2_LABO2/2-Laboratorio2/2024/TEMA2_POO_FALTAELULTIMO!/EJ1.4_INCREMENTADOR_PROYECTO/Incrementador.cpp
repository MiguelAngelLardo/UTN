#include <iostream>
#include "Incrementador.h"

using namespace std;

void Incrementador::setValorIncremento(int valorIncremento){
  _valorIncremento = valorIncremento;
  if(_valorIncremento < 0){
    _valorIncremento = 0;
  }
}

Incrementador::Incrementador(){
  _valor = 0;
  _valorIncremento = 1;
  _cantidadIncrementos = 0;
}

Incrementador::Incrementador (int inicial, int incremento){
  _valor = inicial;
  _valorIncremento = incremento;
  setValorIncremento(incremento);
}

 
void Incrementador::incrementar(){
  _valor += _valorIncremento;
  _cantidadIncrementos = _cantidadIncrementos + 1;
}

int Incrementador::getValor(){
  return _valor;
}

int Incrementador::getCantidadIncrementos(){
  return _cantidadIncrementos;
}

Incrementador::~Incrementador(){
  cout << "Me destruyo.." << endl;
}

