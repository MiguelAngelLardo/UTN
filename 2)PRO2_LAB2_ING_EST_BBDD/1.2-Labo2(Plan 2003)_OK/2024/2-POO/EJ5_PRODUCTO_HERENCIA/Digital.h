#pragma once
#include "Producto.h"

class Digital:public Producto {
private:

public:
  // Constructor
  Digital(std::string nom = "S/N", const char *id = "0000", float precio = 0.0);
  
  // No necesitamos métodos para establecer o obtener el stock
  // ya que los productos digitales no tienen stock.

  void cargarDigital(); 
  void mostrarDigital(); 
};

Digital::Digital(std::string nom, const char *id, float precio) : Producto (nom, id, precio){} 

void Digital::cargarDigital() {
  Producto::cargar();
  std::cout << "CARGA DIGITAL\n";
}

void Digital::mostrarDigital() {
  Producto::mostrar();
  std::cout << "\nMOSTRAR DIGITAL\n";
}