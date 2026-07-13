#pragma once
#include <string>
#include "Paciente.h"
#include "TemplateArchivo.h"

class PacienteArchivo: public TArchivo<Paciente> { 

public:
  PacienteArchivo(std::string nombreArchivo = "pacientes.dat");
  std::string getNombreArchivo() const;
  int buscarPorDni(const std::string &dni);
  
  Paciente buscarPacientePorDni(const string &dni); 
  Paciente buscarPacientePorNombre(const std::string &nombre);
  Paciente buscarPacientePorApellido(const std::string &apellido); // no hay apellido aun, consultar como se buscaria  // implementar lueg


private: 
  std::string _nombreArchivo;  
};

