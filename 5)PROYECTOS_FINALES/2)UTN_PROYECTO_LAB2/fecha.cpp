#include "Fecha.h"
#include <ctime>

#include <iostream>
using namespace std;

Fecha::Fecha()
{
  setFechaActual();
  setHoraActual();

}

Fecha::Fecha(int dia, int mes, int anio)
{
  // ojo falta validacion de fecha que se va a hacer cuando se pidan los datos!!!
  setDia(dia);
  setMes(mes);
  setAnio(anio);
  setHoraActual();

}


void Fecha::setDia(int d)  { _dia = d; }
void Fecha::setMes(int m)  { _mes = m; }
void Fecha::setAnio(int a) { _anio = a; }

int Fecha::getDia() const { return _dia; }
int Fecha::getMes() const { return _mes; }
int Fecha::getAnio() const { return _anio; }

void Fecha::setFechaActual()
{
  time_t t = time(NULL);// time_t es un alias para un entero de 32 y 64 bits - time(NULL) nos da el el tiempo en formato 'timestamp' -> "Epoch time" es un punto inicial (como el 1 de enero de 1970, a las 00:00:00 UTC)
  struct tm *f = localtime(&t);// el struct tm convierte el timestamp a un formato entendible
  _dia = (*f).tm_mday;
  _mes = f->tm_mon + 1;
  _anio = f->tm_year + 1900;  ////(*f).tm_mday => indirecciona f y accede a tm_day

}


void Fecha::setHoraActual()
{
  time_t t = time(NULL);
  struct tm *f = localtime(&t);
  _hora=f->tm_hour;
  _minuto= f->tm_min;
  _segundo= f->tm_sec;
}


bool Fecha::esBisiesto(int anio) const{
  return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);//400 800 1200 es bisciesto
}

bool Fecha::esFechaValida(int dia, int mes, int anio) const {
  if (anio < 1 || mes < 1 || mes > 12 || dia < 1) return false;

  int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (mes == 2 && esBisiesto(anio)) {
    diasPorMes[1] = 29;
  }

  return dia <= diasPorMes[mes - 1];
}

  //no puedo modificar la referencia de otra
bool Fecha::operator==(const Fecha &otra) const{//no puedo modificar miembros de fecha
  return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio;
}

bool Fecha::operator>(const Fecha &otra)const{
  return  (_anio != otra._anio) ? (_anio > otra._anio) :
          (_mes != otra._mes) ? (_mes > otra._mes) :
          (_dia > otra._dia);

}

bool Fecha::operator<(const Fecha &otra) const{
    return (_anio != otra._anio) ? (_anio < otra._anio) :
           (_mes != otra._mes) ? (_mes < otra._mes) :
           (_dia < otra._dia);
}

string Fecha::toString() const{
  return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}
