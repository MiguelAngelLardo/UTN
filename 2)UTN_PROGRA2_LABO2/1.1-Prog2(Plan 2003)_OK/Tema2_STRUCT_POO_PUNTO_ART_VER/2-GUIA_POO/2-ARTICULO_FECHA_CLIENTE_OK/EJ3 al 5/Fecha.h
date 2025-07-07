#pragma once

class Fecha {
private:
  int _dia;
  int _mes;
  int _anio;

public:
  Fecha(int dia= 0, int mes = 0, int anio = 0) : _dia(dia), _mes(mes), _anio(anio) {}
    
  void setDia (int d){_dia = d;}
  void setMes (int m){_mes = m;}
  void setAnio(int a){_anio = a;}

  int getDia(){return _dia;}
  int getMes(){return _mes;}
  int getAnio(){return _anio;}

  void cargar(){
    cout << "Dia: "; cin >> _dia;
    cout << "Mes: "; cin >> _mes;
    cout << "Anio: "; cin >> _anio;
  }

  void mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
  }

};