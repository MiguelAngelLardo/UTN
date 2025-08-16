#pragma once
#include <string>
#include "Postulante.h"

class PostulanteArchivo{
private:
  std::string _nombreArchivo;
  

public:
  PostulanteArchivo(std::string nombreArchivo = "postulantes.dat");

  bool agregarRegistro(Postulante obj);
  int getCantidadRegistros();

  Postulante leerUnRegistro(int pos);//este no es tan bueno por que va a abrir 100 veces el archivo si tengo for de 100 en manager
  int buscarPorId(int id);//devuelve posicion
  int buscarPorPuestoYExperiencia(std::string puesto, int experiencia);//devuelve posicion
  
  bool modificarPorIndice(Postulante reg, int pos);//se usa para modificar o para cuando doy de baja logica

  int crearNuevoIdAUtomatico();
  void leerTodosLeyenedoConVecDin(Postulante vPos[], int cantidad);//mas eficiente que leerUnRegistro
};