#pragma once
#include <iostream>
#include "Fisico.h"
#include "Digital.h"


/*
void cargarCadena(char *palabra, int tamano){ //⇒ aca si pongo 9 por que usa el 0 del for
	int i=0;
	fflush(stdin);
	for (i=0; i<tamano; i++){
		palabra[i] = std::cin.get();
		if (palabra[i]=='\n'){
		break;
		}
	}
	palabra[i]='\0';
	fflush(stdin);
}
*/

Fisico cargarProductoFisico(){
	string nombre;
	char id[10];
	float precio;
	int stockActual, stockMin;

	cout << "Ingrese el nombre del producto: ";
	cin >> nombre;

	cout << "Ingrese el ID del producto: ";
	cin.ignore();
  cin.getline(id, 10)
	;
	cout << "Ingrese el precio del producto: ";
	cin >> precio;

	cout << "Ingrese el stock actual del producto: ";
	cin >> stockActual;

	cout << "Ingrese el stock minimo del producto: ";
	cin >> stockMin;

  return Fisico(stockActual, stockMin, nombre, id, precio);
}

void mostrarProductoFisico(Fisico &fisico) {
  bool bandera = false;
	std::cout << "\nInformacion del producto fisico:\n";
  std::cout << "Nombre: " << fisico.getNombre() << std::endl;
  std::cout << "ID: " << fisico.getId() << std::endl;
  std::cout << "Precio: $" << fisico.getPrecio() << std::endl;
  std::cout << "Stock actual: " << fisico.getStockActual() << std::endl;
  std::cout << "Stock minimo: " << fisico.getStockMin() << std::endl;
    if ((fisico.getStockActual() <= fisico.getStockMin()) || fisico.getStockActual() < 0 || fisico.getStockMin() < 0) {
      std::cout << "ERROR => Debe reponer stock!" << std::endl;
	   	bandera = true;
    }
	if(!bandera) std::cout << "Valuacion del stock: $" << fisico.getStockActual() * fisico.getPrecio() << std::endl;
}

Digital cargarProductoDigital(){
	string nombre;
	char id[10];
	float precio;

	cout << "Ingrese el nombre del producto: ";
	cin >> nombre;

	cout << "Ingrese el ID del producto: ";
	cin.ignore();
  cin.getline(id, 10);

	cout << "Ingrese el precio del producto: ";
	cin >> precio;

	
	Digital aux(nombre, id, precio);
  return aux;

	//return Digital(nombre, id, precio)
}

void mostrarProductoDigital(Digital &digital) {
	std::cout << "\nInformacion del producto digital:\n";
  std::cout << "Nombre: " << digital.getNombre() << std::endl;
  std::cout << "ID: " << digital.getId() << std::endl;
  std::cout << "Precio: $" << digital.getPrecio() << std::endl;
	std::cout << "Valuacion del stock: $0";
}