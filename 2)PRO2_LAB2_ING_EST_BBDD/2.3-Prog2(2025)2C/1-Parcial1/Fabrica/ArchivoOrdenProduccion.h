#pragma once
#include <string>
#include "OrdenProduccion.h"

class ArchivoOrdenProduccion {
    private:
        std::string _nombreArchivo;
        
    public:
        ArchivoOrdenProduccion(std::string nombreArchivo);
        bool Guardar(OrdenProduccion ordenProduccion);
        bool Guardar(OrdenProduccion ordenProduccion, int posicion);
        int Buscar(int IDProduccion);
        OrdenProduccion Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, OrdenProduccion *vector);
};