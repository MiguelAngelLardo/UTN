#include "Ascensor.h"

int Ascensor::getPisoMin(){return _pisoMin;}
void Ascensor::setPisoMin(int pisoMin){
  _pisoMin = pisoMin;
}

int Ascensor::getPisoMax(){return _pisoMax;}
void Ascensor::setPisoMax(int pisoMax){
  _pisoMax = pisoMax;
}

int Ascensor::getPisoActual(){return _pisoActual;}
void Ascensor::setPisoActual(int pisoActual){
  _pisoActual = pisoActual;
}

int Ascensor::getCapacidadMaxima(){return _capacidadMaxima;}
void Ascensor::setCapacidadMaxima(int capacidadMaxima){
  _capacidadMaxima = capacidadMaxima;
}

int Ascensor::getOcupantes(){return _ocupantes;}
void Ascensor::setOcupantes(int ocupantes){
  _ocupantes = ocupantes;
}

Ascensor::Ascensor(){
  _pisoMin = -2;
  _pisoMax = 10;
  _pisoActual = 0;
  _ocupantes = 0;
  _capacidadMaxima = 5;

}

Ascensor::Ascensor(int pisoMin, int pisoMax, int pisoActual, int capacidadMaxima, int ocupantes){
  _pisoMin = pisoMin;
  _pisoMax = pisoMax;
  _pisoActual = pisoActual;
  _capacidadMaxima = capacidadMaxima;
  _ocupantes = ocupantes;
}

std::string Ascensor::toString(){
  std::string msj;
  msj = "PISO ACTUAL: " + std::to_string(_pisoActual) +
  "\nPersonas en el Ascensor: " + std::to_string(_ocupantes);

  return msj;
}

//PUNTO A - Desplazamiento del ascensor
bool Ascensor::desplazamiento(int pisoDestino){
  return (pisoDestino < _pisoMin || pisoDestino > _pisoMax || pisoDestino == _pisoActual) ? false : true;
}

//Punto B Subir Persona
int Ascensor::subirPersonas(int sumarPersonas){
  int ocupantes = _ocupantes + sumarPersonas;
  if(ocupantes <= _capacidadMaxima){
    _ocupantes = ocupantes;
  }   

return _ocupantes;
}

//Punto C Restar Personas
int Ascensor::bajarPersonas(int restarPersonas){
  int ocupantes = _ocupantes - restarPersonas;

  return (ocupantes < 0) ? 0 : ocupantes; //si queda numero negativo se bajan todos
}
