#pragma once
#include <string>

class Punto{
private:
  float _x, _y;
public:
  float getX();
  void setX(float x);
  float getY();
  void setY(float y);

  Punto(float x,  float y);

  int cuadrante();

  //la distancia al origen es la rauz cuadrada
  // de la suma de los cuadradas de las coordenadas
  //TEOREMA DE PITAGORAS => necesita X e Y
  double distanciaOrigen();

  std::string toString();
};