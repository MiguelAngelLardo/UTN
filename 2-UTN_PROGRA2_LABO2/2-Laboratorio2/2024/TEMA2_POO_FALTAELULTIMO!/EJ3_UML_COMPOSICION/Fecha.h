#pragma once

class Fecha{
private:
  int _dia, _mes, _anio;
public:
  Fecha(int d=1, int m=1, int a=1);

  void setDia(int d);
  void setMes(int m);
  void setAnio(int a);
  int getDia(); 
  int getMes();
  int getAnio();

  void mostrar();
  void cargar();

  
};


Fecha::Fecha(int d, int m, int a){
  _dia = d;
  _mes = m;
  _anio = a;
}

void Fecha::setDia(int d){
  if(d > 0 && d < 32){
    _dia = d;
  }else{
    _dia = 1;
  }
}

int Fecha::getDia(){
  return _dia;
}

int Fecha::getMes(){
  return _mes;
}

int Fecha::getAnio(){
  return _anio;
}

void Fecha::cargar(){
  int d;
  cout << "DIA: ";
  cin >> d;
  setDia(d);
  cout << "MES: ";
  cin >> _mes;
  cout << "ANIO: ";
  cin >> _anio;
}

void Fecha::mostrar(){
  cout << _dia << "/" << _mes << "/" << _anio;
}