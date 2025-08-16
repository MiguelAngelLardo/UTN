#pragma once //La denominación incluye: nombre científico, nombre común, nombre dado por pueblos originarios
#include <cstring>
#include "Funciones.h"

class Denominacion{
private:
  char _nombreCientifico[50];
  char _nombreComun[50];
  char _nombrePuebloOriginario[50];
public:
  Denominacion(const char *nomCien = "S/N", const char *nomComun = "S/N", const char nomPueb[] = "S/N");

  void cargar();
  void mostrar();
};

Denominacion::Denominacion(const char nomCien[], const char nomComun[], const char nomPueb[]){
    strcpy(_nombreCientifico, nomCien);
    strcpy(_nombreComun, nomComun);
    strcpy(_nombrePuebloOriginario, nomPueb);
  }

void Denominacion::cargar(){
  cout << "Nombre cientifico: ";
  cargarCadena(_nombreCientifico, 49);
  cout << "Nombre comun: ";
  cargarCadena(_nombreComun, 49);
  cout << "Nombre pueblo originario: ";
  cargarCadena(_nombrePuebloOriginario, 49);
}

void Denominacion::mostrar(){
  cout << "Denominacion => Nombre Cientifico: " << _nombreCientifico << " - Nombre Comun: " << _nombreComun << " - Nombre Pueblo Originario: " << _nombrePuebloOriginario << endl;
}
