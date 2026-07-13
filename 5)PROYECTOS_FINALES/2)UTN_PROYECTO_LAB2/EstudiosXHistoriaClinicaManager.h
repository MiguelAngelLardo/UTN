#pragma once
#include <string>
#include "EstudiosXHistoriaClinicaArchivo.h"
#include "PacienteArchivo.h"


class EstudiosXHistoriaClinicaManager {
private:
    EstudiosXHistoriaClinicaArchivo _estudiosXHistoriaClinica;

public:

    bool agregarRegistro(std::string dni, std::string idHc, std::string codigoEstudio, std::string matriculaMedico, std::string apellidoMedico, std::string nombreMedico, std::string resultadoEstudio);
	void buscarEstudiosPorDni(const std::string& dniPaciente, int opcion, Fecha fechaFiltro = Fecha(), const std::string& codigoFiltro = "");
    void mostrarEstudios(const string& encabezado, EstudiosXHistoriasClinicas* vecEstudiosXHC, int cantidadRegistros);
    void buscarEstudiosHC(const std::string& codigoHC, const std::string& dniPaciente);

};
