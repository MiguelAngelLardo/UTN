#pragma once
#include "Postulante.h"

class PostulanteManager{

private:
  void cargarPostulante();
  void mostrarPostulante(Postulante reg);
  void mostrarCantidadRegistros();
  
  void listarTodosLeyendoDeAUno();////este no es tan bueno por que va a abrir 100 veces el archivo si tengo for de 100 en manager
  void listarContratados();
  void mostrarPorPuestoYExperiencia();

  void modificarPostulante();
  void volverACargarSinId(Postulante &reg);

  void listarTodosLeyenedoConVecDin();

  void eliminarLogico();


public:
  void menu();
};