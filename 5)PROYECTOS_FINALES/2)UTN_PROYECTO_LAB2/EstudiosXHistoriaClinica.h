#pragma once
#include <string>
#include "Fecha.h"

class EstudiosXHistoriasClinicas{
private:
  char _DNI [9];
  char _idHistoriaClinica[5];
  char _codigoEstudio [5];
  char _matriculaMedico[9];
  char _apellidoMedico[21];
  char _nombreMedico[21];
  char _resultadoEstudio [36];
  Fecha _fechaEstudio;

public:
  EstudiosXHistoriasClinicas();
  EstudiosXHistoriasClinicas(std::string DNI, std::string idHistoriaClinica, std::string codigoEstudio, std::string matriculaMedico, std::string apellidoMedico, std::string nombreMedico, std::string resultadoEstudio);

  void setDNI(const std::string &DNI);
  void setIdHistoriaClinica(const std::string &idHistoriaClinica);
  void setCodigoEstudio(const std::string &codigoEstudio);
  void setMatriculaMedico(const std::string &matriculaMedico);
  void setApellidoMedico(const std::string &apellidoMedico);
  void setNombreMedico(const std::string &nombreMedico);
  void setResultadoEstudio(const std::string &resultadoEstudio);
  void setFechaEstudio(const Fecha &fechaEstudio);

  std::string getDNI() const;
  std::string getIdHistoriaClinica() const;
  std::string getCodigoEstudio() const;
  std::string getMatriculaMedico() const;
  std::string getApellidoMedico() const;
  std::string getNombreMedico() const;
  std::string getResultadoEstudio() const;
  Fecha getFechaEstudio() const;
};
