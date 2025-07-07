#pragma once

class Fecha{
private:
  int _dia, _mes, _anio;

public:
  Fecha(int d = 0, int m = 0, int a = 0);

  ///SET
  void setDia(int d);
  void setMes(int m);
  void setAnio(int a);

  ///GET
  int getDia();
  int getMes();
  int getAnio();

  ///CARGAR-LISTAR
  void cargar();
  void mostrar();
};

Fecha::Fecha(int d, int m, int a): _dia(a), _mes(m), _anio(a){}

///SET
void Fecha::setDia(int d){_dia = (d >= 1 && d <= 31) ? d : -1;}
void Fecha::setMes(int m){_mes = (m >= 1 && m <= 12) ? m : -1;}
void Fecha::setAnio(int a){_anio = (a >=0 && a <= 2500) ? a : -1;}


///GET
int Fecha::getDia(){return _dia;}
int Fecha::getMes(){return _mes;}
int Fecha::getAnio(){return _anio;}

///CARGAR-LISTAR
void Fecha::cargar(){
  int d, m, a;
  cout << "DIA: ";
  cin >> d;
  setDia(d);
  cout << "MES: ";
  cin >> m;
  setMes(m);
  cout << "ANIO: ";
  cin >> a;
  setAnio(a);
}

void Fecha::mostrar(){
  cout << this->_dia << "/" << this->_mes << "/" << this->_anio << endl;
}
