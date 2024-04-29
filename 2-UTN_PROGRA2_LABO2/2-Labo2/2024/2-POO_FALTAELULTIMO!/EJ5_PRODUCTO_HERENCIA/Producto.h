#pragma once

#include <string>
#include <cstring>
#include "Funciones.h"

class Producto{
protected:
  std::string _nombre;
  char _id[10];
  float _precio;

public:
  Producto(std::string nom = "S/N", const char *id = "0000", float precio = 0.0);

  void setNombre (std::string nom);
  void setId(const char *id);
  void setPrecio(float prec);

  std::string getNombre();
  const char *getId();
  float getPrecio();

  void cargar();
  void mostrar();
};

Producto::Producto(std::string nom, const char *id, float precio){
  _nombre = nom;
  strcpy(_id, id);
  _precio = precio;
}


void Producto::setNombre (std::string nom){_nombre = nom;}
void Producto::setId(const char *id){strcpy(_id, id);}
void Producto::setPrecio(float prec){_precio = prec;}

std::string Producto::getNombre(){return _nombre;}
char const *Producto::getId(){return _id;}
float Producto::getPrecio(){return _precio;}

void Producto::cargar(){
  std::cout << "CARGA DEL PRODUCTO\n";
  std::cout << "NOMBRE: ";
  getline(std::cin, _nombre);
  std::cout << "ID: ";
  cin.getline(_id, 10);
  std::cout << "PRECIO: ";
  std::cin >> _precio;
}


void Producto::mostrar(){
  std::cout << "\nMOSTRAR\n";
  std::cout << "Nombre: " <<_nombre << std::endl;
  std::cout << "Id: " << _id << std::endl; 
  std::cout << "PRECIO: $" << _precio << std::endl;
}
