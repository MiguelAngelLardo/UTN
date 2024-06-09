#include <ctime>
#include "Fecha.h"

int Fecha::getDia(){
  return _dia;
}

int Fecha::getMes (){
  return _mes; 
}

int Fecha::getAnio (){
  return _anio; 
}

void Fecha::setDia (int dia){
  _dia = dia;
}

void Fecha::setMes (int mes){
  _mes = mes;

}
void Fecha::setAnio (int anio){
  _anio = anio;
}

Fecha::Fecha(){
  time_t t = time(NULL);
  struct tm f;

  if (localtime_s(&f, &t) == 0) {
    _dia = f.tm_mday;
    _mes = f.tm_mon + 1;
    _anio = f.tm_year + 1900;
    _diaSemana = f.tm_wday;
  }

  /*time_t t = time(NULL);
  //time_t es un alias para un entero de 32 y 64 bits
  // time(NULL) nos da el el tiempo en formato 'timestamp' (segundos desde el  "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
 
 struct tm *f = localtime(&t); // el struct tm convierte el timestamp a un formato entendible
 _dia = f->tm_mday; //(*f).tm_mday => indirecciona f y accede a tm_day
 _mes = f->tm_mon+1; // => indirecciona f y accede a tm_mon
 _anio = f->tm_year + 1900; //2023-1900 da 123 => 123+1900
 _diaSemana = f->tm_wday;*/
}

//epoch time/UNIX


Fecha::Fecha(int dia, int mes, int anio){
  setDia(dia);
  setMes(mes);
  setAnio(anio);  
  _diaSemana = -1;
}

std::string Fecha::toString(){
  std::string valorADevoler;
  valorADevoler = std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
  return valorADevoler;
}

std::string Fecha::getNombreDia(){
  std::string nombres[7] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves","Viernes", "Sabado"};

  if(_diaSemana >= 0 && _diaSemana <= 6){
    return nombres[_diaSemana];
  }
  return "";
}

