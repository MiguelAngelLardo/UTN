#pragma once
#include "ProfesionalXPacienteArchivo.h"
#include "PacienteArchivo.h"

class ProfesionalXPacienteManager {

private:
    ProfesionalXPacienteArchivo _profesionalXPacienteArchivo;

public:

  bool agregarRegistro(const std::string &dniPaciente, const std::string &matriculaProfesional, bool &fallaPorMemoria);//CAMBIO

   void bucarProfesionalesPorDniPaciente(const std::string& dniPaciente);
   void mostrarRegistrosProfesionales(Paciente &paciente, ProfesionalXPaciente *vecPxP, int cantidadRegistros);


};
