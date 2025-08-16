#pragma once
#include "Propietario.h"
#include "PropietarioArchivo.h"

class PropietarioManager{

public:

  void mostrarPropietario(Propietario reg);//APARTE
  
  void cargarPropietario();
  void listarTodosLeyendoDeAUno();/*=>*/ void buscarPorDNI();

  void modificarTodoElRegistro();  void bajaLogicaPorDNI();

  void listarInactivos();

  void listarPropiedadesDelCliente();
  
private:
  PropietarioArchivo _PropietarioArchivo;
}; 