#pragma once
#include "Inmueble.h"
#include "InmuebleArchivo.h"

class InmuebleManager{

public:

  void mostrarCantidadRegistros(); //APARTE
  void mostrarInmueble(Inmueble reg);//APARTE
  
  void cargarInmueble();
  void listarTodosLeyendoDeAUno();////este no es tan bueno por que va a abrir 100 veces el archivo si tengo for de 100 en manager

  void modificarInmueble(); /*=>*/ void modificarPrecioInmueble();/*=>*/ void volverACargarSinId(Inmueble &reg);/*=>*/void eliminarLogico(); /*=>*/ void reactivarInmueble();
  
  void buscarPorCalle(); void buscarPorRangoPrecio();

  void listarContratados();
  void mostrarPorPuestoYExperiencia();
  
  
  void listarTodosLeyenedoConVecDin();
  
  
  
private:
  InmuebleArchivo _inmuebleArchivo;
};