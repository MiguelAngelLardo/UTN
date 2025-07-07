#pragma once

#include "Inmueble.h"
#include "string.h"

class ArchivoPropiedades{
    private:
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoPropiedades(const char *n="Propiedades.dat"){
        strcpy(nombre,n);
        tamanioRegistro=sizeof(Inmueble);
    };
        int agregarRegistro();
        int agregarRegistro(Inmueble reg);
        bool listarRegistros();
        bool listarInactivos();
        int listarPropiedadesPorCliente(const char* _dni);
        bool listarRegistrosPorDireccion(const char* _calle);
        int listarRegistrosPorRangoDePrecios(float precioMin, float precioMax, int _tipoOperacion);
        int buscarInmueble(int codInmueble);
        int buscarInmueble(const char* _calle, const char* _numero= (char*)"0");
        Inmueble leerRegistro(int pos);
        int modificarRegistro(Inmueble reg, int pos);
        int contarRegistros();
        bool bajaLogica(int _cod);
        bool altaLogica (int cod);
        int proximoId();
        int obtenerTipoDePropiedad(int pos);
    };

