#include <cstring>
#include "ProfesionalArchivo.h"

ProfesionalArchivo::ProfesionalArchivo() {
    _nombreArchivo = "profesionales.dat";
}

std::string ProfesionalArchivo::getNombreArchivo() const {
    return _nombreArchivo;
}

int ProfesionalArchivo::buscarPorLegajo(int legajo) {
    Profesional profesional;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    int pos = 0;
    while (fread(&profesional, sizeof(Profesional), 1, pFile)) {
        if (profesional.getLegajo() == legajo) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -2;
}

int ProfesionalArchivo::buscarPorMatricula(std::string matricula) {
    Profesional profesional;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    int pos = 0;
    while (fread(&profesional, sizeof(Profesional), 1, pFile)) {
        if (profesional.getMatricula() == matricula) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -2;
}

int ProfesionalArchivo::buscarPorNombre(std::string nombre) {
    Profesional profesional;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return -1;
    }

    int pos = 0;
    while (fread(&profesional, sizeof(Profesional), 1, pFile)) {
        if (profesional.getNombre() == nombre) {
            fclose(pFile);
            return pos;
        }
        pos++;
    }

    fclose(pFile);
    return -2;
}