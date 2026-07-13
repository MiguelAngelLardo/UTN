#include <iostream>
#include <cstring>
#include "EstudiosXHistoriaClinicaArchivo.h"

using namespace std;

EstudiosXHistoriaClinicaArchivo::EstudiosXHistoriaClinicaArchivo(string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

std::string EstudiosXHistoriaClinicaArchivo::getNombreArchivo() const {
    return _nombreArchivo;
}

int EstudiosXHistoriaClinicaArchivo::contarRegistrosHistoriaClinica(const std::string& idHistoriaClinica, const std::string& dni) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return -1;
    }

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if ( registro.getDNI()==dni && registro.getIdHistoriaClinica() == idHistoriaClinica) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}

int EstudiosXHistoriaClinicaArchivo::contarRegistrosPorDNI(const std::string& DNI) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        return -1;
    }

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getDNI() == DNI) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}


void EstudiosXHistoriaClinicaArchivo::buscarRegistrosPorHistoriaClinica(const std::string& idHistoriaClinica, EstudiosXHistoriasClinicas *vecEstudios, int cantidadRegistros, const std::string& dni) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo) && contador < cantidadRegistros) {
        if (registro.getDNI()==dni && registro.getIdHistoriaClinica() == idHistoriaClinica) {
            vecEstudios[contador] = registro;
            contador++;
        }
    }

    fclose(pArchivo);
}
void EstudiosXHistoriaClinicaArchivo::buscarRegistrosPorDNI(const std::string& DNI, EstudiosXHistoriasClinicas *vecEstudios, int cantidadRegistros) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) {
        std::cout << "Error al abrir el archivo." << std::endl;
        return;
    }

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo) && contador < cantidadRegistros) {
        if (registro.getDNI() == DNI) {
            vecEstudios[contador] = registro;
            contador++;
        }
    }

    fclose(pArchivo);
}

int EstudiosXHistoriaClinicaArchivo::contarRegistrosPorDNIyFecha(const std::string& DNI, Fecha fecha) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) return -1;

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getDNI() == DNI && registro.getFechaEstudio() == fecha) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}
int EstudiosXHistoriaClinicaArchivo::contarRegistrosPorDNIyCodigo(const std::string& DNI, const std::string& codigo) {
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == nullptr) return -1;

    EstudiosXHistoriasClinicas registro;
    int contador = 0;

    while (fread(&registro, sizeof(registro), 1, pArchivo)) {
        if (registro.getDNI() == DNI && registro.getCodigoEstudio() == codigo) {
            contador++;
        }
    }

    fclose(pArchivo);
    return contador;
}


