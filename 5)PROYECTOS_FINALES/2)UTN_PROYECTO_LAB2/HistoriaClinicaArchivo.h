#pragma once
#include <string>
#include "HistoriaClinica.h"
#include "TemplateArchivo.h"

class HistoriaClinicaArchivo : public TArchivo<HistoriaClinica> {
public:
  HistoriaClinicaArchivo(std::string nombreArchivo = "historiasclinicas.dat");
  std::string getNombreArchivo() const;
  bool primerCreacionHistorica(std::string nombreArchivo);

  int buscarPorCodigoHC(std::string nombreArchivo, std::string codigoHC);

private:
  std::string _nombreArchivo;

}; 