#pragma once
#include "Propietario.h"
#include "string.h"

class ArchivoPropietario{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoPropietario(const char *n="Propietarios.dat"){
            strcpy(nombre, n);
            tamanioRegistro=sizeof(Propietario);
        }
        int agregarRegistro(char* _nuevoDni = (char*) "NADA");
        int agregarRegistro(Propietario reg);
        bool listarRegistros();
        bool listarInactivos();
        int buscarPropietario(const char* codPropietario);
        Propietario leerRegistro(int pos);
        int modificarRegistro(Propietario reg, int pos);
        int contarRegistros();
        bool bajaLogica(const char* _dni);
        bool altaLogica(const char* _dni);
    };

