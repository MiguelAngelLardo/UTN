#include "Punto.h"
#include <math.h>

float Punto::getX(){return _x;}
void Punto::setX(float x){_x = x;}
float Punto::getY(){return _y;}
void Punto::setY(float y){_y = y;}
Punto::Punto(float x,  float y){
  _x = x;
  _y = y;
}

int Punto::cuadrante(){
  if(_x == 0 && _y == 0) return 0;//0 para el origen
  if(_x == 0) return -1; //-1 para el eje de ordenadas
  if(_y == 0) return - 2;//-2 para el eje de abscisas

  if(_x > 0)
  {
   return (_y > 0) ? 1 : 4;
  }
  else
  {
    return (_y > 0) ? 2 : 3;
  }
}

double Punto::distanciaOrigen(){
  double cuadradoX = _x*_x;
  double cuadradoY = _y * _y;
  return sqrt(cuadradoX + cuadradoY);
}

std::string Punto::toString(){ //muestra coordenadas del punto como PAR ordenado
  std::string msj;
  int cuad = cuadrante();
  if(cuad == 0) msj = "En el origen";
  else if(cuad == -1) msj = "en el eje de las ordenadas";
  else if(cuad == -2) msj = "en el eje de las abscisas";
  else msj = "en el cuadrante" + std::to_string(cuad);

  return "EL punto (" + std::to_string(_x) + ", " + 
          std::to_string(_y) + ") esta " + msj + 
          " y esta a una distancia de " + std::to_string(distanciaOrigen());
}


