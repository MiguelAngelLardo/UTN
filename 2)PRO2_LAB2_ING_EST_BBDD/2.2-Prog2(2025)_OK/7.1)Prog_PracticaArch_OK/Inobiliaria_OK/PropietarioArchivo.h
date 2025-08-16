#pragma once
#include <string>
#include "Propietario.h"

class PropietarioArchivo{
private:
  std::string _nombreArchivo;
  
public:
  PropietarioArchivo(std::string nombreArchivo = "Propietarios.dat");//por omision por que es uno solo

  int getCantidadRegistros();
  bool agregarRegistro(Propietario obj);
  Propietario leerUnRegistro(int pos);//este no es tan bueno por que va a abrir 100 veces el archivo si tengo for de 100 en manager

 
  bool modificarPorIndice(Propietario reg, int pos);//se usa para modificar o para cuando doy de baja logica
 

  int buscarPorId(int id);//devuelve posicion
  int buscarPorDNI(std::string dni);//devuelve posicion

 
  

  int crearNuevoIdAUtomatico();
  void leerTodosLeyenedoConVecDin(Propietario vPos[], int cantidad);//mas eficiente que leerUnRegistro
};