#include <iostream>
#include <string>
#include "Tarea.h"
#include <cstring>
using namespace std;

Tarea::Tarea(){
  _ID = 0;
  strcpy(_descripcion, "");
  _nivel = 0;
  _estado = 0;
}

Tarea::Tarea(int ID, string descripcion, Fecha fechaLimite, int nivel, int estado){
   _ID = ID;
   //_descripcion = descripcion;
   strcpy(_descripcion, descripcion.c_str());
   _nivel = nivel;
   _estado = estado;
   _fechaLimite = fechaLimite;
}

int Tarea::getID(){return _ID;}
void Tarea::setID(int ID){_ID = ID;}

std::string Tarea::getDescripcion(){
  std::string aux;
  aux = _descripcion;
  return aux;
}


void Tarea::setDescripcion(std::string descripcion){
  strcpy(_descripcion, descripcion.c_str());
}

Fecha Tarea::getFechaLimite(){return _fechaLimite;}
void Tarea::setFechaLimite(Fecha fechaLimite){ _fechaLimite = fechaLimite;}

std::string Tarea::getNivelDificultad(){
  std::string niveles[3] = {"Baja", "Media", "Alta"};

   if (_nivel >= 1 && _nivel <= 3){
      return niveles[_nivel-1];
   }

   return "Desconocido";
}
void Tarea::setNivelDificultad(int nivelDificultad){_nivel = nivelDificultad;}


std::string Tarea::getDescripcionEstado(){
   if (_estado){
      return "Hecho";
   }
   return "Pendiente";
}

void Tarea::setEstado(int estado){_estado = estado;}
