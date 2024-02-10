#include "horario.h"
#include <ctime>

int Horario::getHora(){
  return _hora;
}

int Horario::getMinuto(){
  return _minuto;
}

int Horario::getSegundo(){
  return _segundo;
}

void Horario::setHora(int hora){
  _hora = hora;
}

void Horario::setMinuto(int minuto){
  _minuto = minuto;
}

void Horario::setSegundo(int segundo){
  _segundo = segundo;
}

Horario::Horario(){
  time_t t = time(NULL);
  //time_t es un alias para un entero de 32 y 64 bits
  // time(NULL) nos da el el tiempo en formato 'timestamp' 
  //(segundos desde el  "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
  struct tm *f = localtime(&t); // el struct tm convierte el timestamp a un formato entendible
  _hora = f->tm_hour;
  _minuto = f ->tm_min;
  _segundo = f->tm_sec;//(*f).tm_sec => indirecciona f y accede a tm_sec
 }
  
Horario::Horario(int hora, int minuto, int segundo){
  setHora(hora);
  setMinuto(minuto);
  setSegundo(segundo);
}

std::string Horario::toString(){
  std::string valorADevolver;
  valorADevolver = std::to_string(_hora) + ":" + std::to_string(_minuto) + ":" + std::to_string(_segundo);
  return valorADevolver;
}

