#pragma once
#include <string>

class Ascensor{
private:
 int _pisoMin, _pisoMax, _pisoActual; //el actual es el de inicio
 int _capacidadMaxima, _ocupantes;

public:
  int getPisoMin();
  void setPisoMin(int pisoMin);
  int getPisoMax();
  void setPisoMax(int pisoMax);
  int getPisoActual();
  void setPisoActual(int pisoActual);
  int getCapacidadMaxima();
  void setCapacidadMaxima(int capacidadMaxima);
  int getOcupantes();
  void setOcupantes(int ocupantes);

  Ascensor();
  Ascensor(int pisoMin, int pisoMax, int pisoActual, int capacidadMaxima, int ocupantes);

  std::string toString();

  //PUNTO A
  bool desplazamiento(int  pisoDestino);

  //PUNTO B Subir Personas
  int subirPersonas(int sumarPersonas);

  //PUNTO C Bajar Personas
  int bajarPersonas(int restarPersonas);

  //Punto D.1 Piso donde se encuentra
  void pisoActual();


};