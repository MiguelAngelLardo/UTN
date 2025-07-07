#include "Postulante.h"
#include <iostream>
using namespace std;

void Postulante::setEdad(int edad){_edad = edad;}
void Postulante::setAniosExp(int anio){_aniosExp = anio;}
void Postulante::setNombre(string nombre){_nombre = nombre;}
void Postulante::setPuesto(string puesto){_puesto = puesto;}

int Postulante::getEdad(){return _edad;}
int Postulante::getAniosExp(){return _aniosExp;}
string Postulante::getNombre(){return _nombre;}
string Postulante::getPuesto(){return _puesto;}

void Postulante::cargar(){
  cout << "Ingrese Edad: ";
  cin >> _edad;
  cout << "Ingrese anios exp: ";
  cin >> _aniosExp;
  cout << "Ingrese nombre: "; 
  cin.ignore();
  getline(cin, _nombre);
  cout << "Ingrese puesto: ";
  cin >> _puesto;
} 

void Postulante::mostrar(){
  cout << "Edad: " << _edad << " Anio Exp: " << _aniosExp << " Nombre: " << _nombre << " puesto: " << _puesto << endl;
}


