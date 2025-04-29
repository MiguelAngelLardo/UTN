#include "clsIncrementador.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Incrementador::Incrementador(){
   _valor = 0;
   _valorInicial = 0;
   _valorIncremento = 1;
   _cantIncrementos = 0;
}

Incrementador::Incrementador(int valorInicial, int valorIncremento){

    _valorInicial = valorInicial;
    _valor = _valorInicial;
    _valorIncremento = valorIncremento;
    _cantIncrementos = 0;

    if (valorInicial < 0 ){
        _valor = 0;
        _valorInicial = 0;
    }

    if (valorIncremento <= 0){
        _valorIncremento = 1;
    }

}

Incrementador::~Incrementador(){
    cout << endl << "Adios mundo! Incremente hasta " << _cantIncrementos << " veces." << endl;
}

int Incrementador::getValor(){
    return _valor;
}

int Incrementador::getCantidadIncrementos(){
    return _cantIncrementos;
}

void Incrementador::Incrementar(){
    _valor += _valorIncremento;
    _cantIncrementos++;
}

void Incrementador::Restablecer(){
    _valor = _valorInicial;
    _cantIncrementos = 0;
}
