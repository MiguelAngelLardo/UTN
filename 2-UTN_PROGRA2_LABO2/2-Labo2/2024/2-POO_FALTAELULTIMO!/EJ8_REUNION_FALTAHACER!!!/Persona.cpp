#include "Persona.h"
using namespace std;

void Persona::setNombrePersona(string nombre){_nombre = nombre;}
void Persona::setapellidoPersona(string apellido){_apellido = apellido;}

string Persona::getNombrePersona(){return _nombre;}
string Persona::getApellidoPersona(){return _apellido;}

Persona::Persona(string nombre, string apellido) : _nombre(nombre), _apellido(apellido) {}

void Persona::cargar(){
  cout << "NOMBRE: ";
  getline(cin, _nombre);
  cout << "APELLIDO: ";
  getline(cin, _apellido);
}
