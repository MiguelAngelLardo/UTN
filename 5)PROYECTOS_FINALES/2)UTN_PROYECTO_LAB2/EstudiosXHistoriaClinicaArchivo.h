#pragma once
#include <string>
#include "EstudiosXHistoriaClinica.h"
#include "TemplateArchivo.h"


class EstudiosXHistoriaClinicaArchivo : public TArchivo <EstudiosXHistoriasClinicas>{

public:
  EstudiosXHistoriaClinicaArchivo(std::string nombreArchivo = "estudiosXhistoriaclinica.dat");
  std::string getNombreArchivo() const;

  int contarRegistrosHistoriaClinica(const std::string& idHistoriaClinica, const std::string& dni);
  int contarRegistrosPorDNI(const std::string& DNI);
  int contarRegistrosPorDNIyCodigo(const std::string& DNI, const std::string& codigo);
 int contarRegistrosPorDNIyFecha(const std::string& DNI, Fecha fecha);


  void buscarRegistrosPorHistoriaClinica(const std::string& idHistoriaClinica, EstudiosXHistoriasClinicas *vecEstudios, int cantidadRegistros, const std::string& dni);
  void buscarRegistrosPorDNI(const std::string& DNI, EstudiosXHistoriasClinicas *vecEstudios, int cantidadRegistros);

private:
  std:: string _nombreArchivo;

};
