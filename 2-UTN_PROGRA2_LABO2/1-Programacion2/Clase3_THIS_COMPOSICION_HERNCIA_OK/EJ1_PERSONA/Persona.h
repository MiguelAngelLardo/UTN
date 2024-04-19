#pragma once
#include <cstring>
#include "Fecha.h"
#include "Funciones.h"

class Persona{
protected:
  int _dni;
  char _nombre[20];
  char _apellido[20];
  Fecha _fechaNac; ///COMPOSICION
  char _direccion[50];
  int _codigoPostal;

public:
  Persona(int dni = 0, const char *nom = "S/N", const char *ape = "S/A", Fecha f = Fecha(), const char *dir = "S/D", int codPos = 0);

  ///SET
  void setDNI(int dni);
  void setNombre (const char *nom);
  void setApellido (const char *ape);
  void setFechaNacimiento (Fecha f);
  void setDireccion (const char *dir);
  void setCodigoPostal(int codPost);

  ///GET
  int getDNI();
  const char *getNombre();
  const char *getApellido();
  Fecha getFechaNacimiento();
  const char *getDireccion();
  int getCodigoPostal();

  ///CARGAR-LISTAR
  void cargar();
  void mostrar();

};

Persona::Persona(int dni, const char *nom, const char *ape, Fecha f, const char *dir, int codPos) : _dni(dni), _fechaNac(f), _codigoPostal(codPos){
  strcpy(_nombre, nom);
  strcpy(_apellido, ape);
  strcpy(_direccion, dir);
}

///SET
void Persona::setDNI(int dni){_dni = dni;}
void Persona::setNombre (const char *nom){strcpy(_nombre, nom);}
void Persona::setApellido (const char *ape){strcpy(_apellido, ape);}
void Persona::setFechaNacimiento (Fecha f){_fechaNac = f;}
void Persona::setDireccion (const char *dir){strcpy(_direccion, dir);}
void Persona::setCodigoPostal(int codPost){_codigoPostal = codPost;}

///GET
int Persona::getDNI(){return _dni;}
const char *Persona::getNombre(){return _nombre;}
const char *Persona::getApellido(){return _apellido;}
Fecha Persona::getFechaNacimiento(){return _fechaNac;}
const char *Persona::getDireccion(){return _direccion;}
int Persona::getCodigoPostal(){return _codigoPostal;}

///CARGAR-LISTAR
void Persona::cargar(){
  cout << "DNI: ";
  cin >> _dni;
  cout << "NOMBRE: ";
  cargarCadena(_nombre, 19);
  cout << "APELLIDO: ";
  cargarCadena(_apellido, 19);
  cout << "FECHA NACIMIENTO: " << endl;
  _fechaNac.cargar();
  cout << "DIRECCION: ";
  cargarCadena(_direccion, 49);
  cout << "CODIGO POSTAL: ";
  cin >> _codigoPostal;
}


void Persona::mostrar(){
  cout << "DNI: " << _dni << endl;
  cout << "NOMBRE: " << _nombre << endl;
  cout << "APELLIDO: " << _apellido << endl;
  cout << "FECHA NACIMIENTO: ";
  _fechaNac.mostrar();
  cout << "APELLIDO: " << _direccion << endl;
  cout << "CODIGO POSTAL: " << _codigoPostal << endl;
}
