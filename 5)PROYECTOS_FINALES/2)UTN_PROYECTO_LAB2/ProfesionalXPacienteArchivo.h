#pragma once
#include <string>
#include "ProfesionalXPaciente.h"
#include "TemplateArchivo.h"


class ProfesionalXPacienteArchivo : public TArchivo <ProfesionalXPaciente> {
private:
    std::string _nombreArchivo;

public:
    ProfesionalXPacienteArchivo();

    std::string getNombreArchivo() const;

    int contarRegistrosPorDNI(const std::string &dniPaciente);
    int contarRegistrosPorMatricula(const std::string &matriculaProfesional);

    void buscarPorDNI(const std::string &dniPaciente, ProfesionalXPaciente *vecProfesionales, int cantidadRegistros);
    void buscarPorMatricula(const std::string &matriculaProfesional, ProfesionalXPaciente *vecProfesionales, int cantidadRegistros);


};