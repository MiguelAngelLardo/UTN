#pragma once
#include <string>
#include "Inmueble.h"

class InmuebleArchivo{
private:
  std::string _nombreArchivo;
  

public:
  InmuebleArchivo(std::string nombreArchivo = "Inmuebles.dat");//por omision por que es uno solo

  int getCantidadRegistros();
  bool agregarRegistro(Inmueble obj);
  Inmueble leerUnRegistro(int pos);//este no es tan bueno por que va a abrir 100 veces el archivo si tengo for de 100 en manager

  int buscarPorId(int id);//devuelve posicion
  bool modificarPorIndice(Inmueble reg, int pos);//se usa para modificar o para cuando doy de baja logica
 
  
  int buscarPorPuestoYExperiencia(std::string puesto, int experiencia);/*=>*/int buscarPorCalle(std::string calle);/*=>*/int buscarPorRangoPrecio(float precioMin, float precioMax);

  int crearNuevoIdAUtomatico();
  void leerTodosLeyenedoConVecDin(Inmueble vPos[], int cantidad);//mas eficiente que leerUnRegistro
};