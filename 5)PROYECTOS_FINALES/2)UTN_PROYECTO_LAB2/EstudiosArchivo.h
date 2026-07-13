#pragma once
#include <string>
#include "Estudios.h"
#include "TemplateArchivo.h"

class EstudiosArchivo: public TArchivo<Estudios>{

public:
  EstudiosArchivo(std::string nombreArchivo = "estudios.dat"); //omision por q es 1 parametro
  std::string getNombreArchivo() const;
  
  int buscarPorCodigoEstudio(std::string codigoEstudio);
 

private:
 std::string _nombreArchivo;
};