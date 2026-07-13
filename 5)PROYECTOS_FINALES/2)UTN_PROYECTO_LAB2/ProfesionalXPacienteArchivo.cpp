#include <cstring>
#include "ProfesionalXPacienteArchivo.h"

ProfesionalXPacienteArchivo::ProfesionalXPacienteArchivo() {
    _nombreArchivo = "profesionalesXPacientes.dat";
}

std::string ProfesionalXPacienteArchivo::getNombreArchivo() const {
    return _nombreArchivo;
}

int ProfesionalXPacienteArchivo::contarRegistrosPorDNI(const std::string &dniPaciente) {
       FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

     if (pArchivo == nullptr) {
        return -1;
    }

   int contador = 0;
    ProfesionalXPaciente registro;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getDniPaciente() == dniPaciente) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}

int ProfesionalXPacienteArchivo::contarRegistrosPorMatricula(const std::string &matriculaProfesional) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if (pArchivo == nullptr) {
        return -1;
    }

    int contador = 0;
    ProfesionalXPaciente registro;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getMatriculaProfesional() == matriculaProfesional) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}

void ProfesionalXPacienteArchivo::buscarPorDNI(const std::string &dniPaciente, ProfesionalXPaciente *vecPxP, int cantidadRegistros) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    ProfesionalXPaciente registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getDniPaciente() == dniPaciente) {
                vecPxP[contador] = registro;
                contador++;
        }
    }

    fclose(pArchivo);
}

void ProfesionalXPacienteArchivo::buscarPorMatricula(const std::string &matriculaProfesional, ProfesionalXPaciente *vecPxP, int cantidadRegistros) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    ProfesionalXPaciente registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getMatriculaProfesional() == matriculaProfesional) {
                vecPxP[contador] = registro;
                contador++;
        }
    }

    fclose(pArchivo);
}