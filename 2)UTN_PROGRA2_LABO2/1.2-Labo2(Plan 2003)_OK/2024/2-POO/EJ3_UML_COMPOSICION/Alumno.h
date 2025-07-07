#pragma once
#include <cstring>
#include "Funciones.h"
using namespace std;


class Alumno{
private:
  int _legajo;
  char _nombre[50];
  char _apellido[50];

public:
  Alumno(int l = -1, const char *nom = "S/N", const char *ape = "S/N"); 

  void setLegajo(int l){_legajo = l;}
  void setNombre(const char *n){strcpy(_nombre, n);}
  void setApellido(const char *a){strcpy(_apellido, a);}

  int getLegajo(){return _legajo;};
  const char *getNombre(){return _nombre;}
  const char *getApellido(){return _apellido;}

  void cargar();
  void mostrar();

};  

Alumno::Alumno(int l, const char *nom, const char *ape){
  _legajo = l;
  strcpy(_nombre, nom);
  strcpy(_apellido, ape);
}



void Alumno::cargar(){
  cout << "LEGAJO: ";
  cin >> _legajo;
  cout << "NOMBRE: ";
  cin.ignore();
  cargarCadena(_nombre, 49);
  cout << "APELLIDO: "; 
  cargarCadena(_apellido, 49);
}

void Alumno::mostrar(){
  cout << "LEGAJO: " << _legajo << endl;
  cout << "NOMBRE: " << _nombre << endl;
  cout << "APELLIDO: " << _apellido << endl;
}