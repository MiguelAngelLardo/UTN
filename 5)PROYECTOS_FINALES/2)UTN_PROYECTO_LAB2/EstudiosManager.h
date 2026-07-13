#pragma once
#include <string>
#include "EstudiosArchivo.h"

class EstudiosManager {
public:



  /******************************/
  void cargarEstudiosPorDefecto();//en el main me genera un estudios.dat

  Estudios listaEstudiosActuales();//dentro carga vec con leer del .dat => tiene menuInteractico(opcionesParaMenu)
  std::string opcionesParaMenu(Estudios estudios[], int cantidad);

  Estudios buscarEstudioPorCodigo(const std::string &codigoEstudio);


private:
  EstudiosArchivo _estudioArchivo;
};
