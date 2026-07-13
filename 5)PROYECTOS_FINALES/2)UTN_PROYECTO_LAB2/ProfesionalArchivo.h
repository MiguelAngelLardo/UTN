#pragma once
#include <string>
#include "Profesional.h"
#include "TemplateArchivo.h"


class ProfesionalArchivo : public TArchivo<Profesional> {
private:

 std::string _nombreArchivo;

public:
    ProfesionalArchivo();

    std::string getNombreArchivo() const;
    int buscarPorLegajo(int legajo);
    int buscarPorMatricula(std::string matricula);
    int buscarPorNombre(std::string nombre);


};