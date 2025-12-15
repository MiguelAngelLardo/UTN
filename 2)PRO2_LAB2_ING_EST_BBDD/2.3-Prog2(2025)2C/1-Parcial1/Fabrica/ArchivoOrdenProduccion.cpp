#include "ArchivoOrdenProduccion.h"

ArchivoOrdenProduccion::ArchivoOrdenProduccion(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoOrdenProduccion::Guardar(OrdenProduccion ordenProduccion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&ordenProduccion, sizeof(OrdenProduccion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoOrdenProduccion::Guardar(OrdenProduccion ordenProduccion, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(OrdenProduccion) * posicion, SEEK_SET);
    bool ok = fwrite(&ordenProduccion, sizeof(OrdenProduccion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoOrdenProduccion::Buscar(int IDProduccion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    OrdenProduccion ordenProduccion;
    int i = 0;
    while(fread(&ordenProduccion, sizeof(OrdenProduccion), 1, pArchivo)){
        if(ordenProduccion.getIDProduccion() == IDProduccion){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

OrdenProduccion ArchivoOrdenProduccion::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return OrdenProduccion();
    }
    OrdenProduccion ordenProduccion;
    fseek(pArchivo, sizeof(OrdenProduccion) * posicion, SEEK_SET);
    fread(&ordenProduccion, sizeof(OrdenProduccion), 1, pArchivo);
    fclose(pArchivo);
    return ordenProduccion;
}

int ArchivoOrdenProduccion::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(OrdenProduccion);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoOrdenProduccion::Leer(int cantidadRegistros, OrdenProduccion *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(OrdenProduccion), 1, pArchivo);
    }
    fclose(pArchivo);
}