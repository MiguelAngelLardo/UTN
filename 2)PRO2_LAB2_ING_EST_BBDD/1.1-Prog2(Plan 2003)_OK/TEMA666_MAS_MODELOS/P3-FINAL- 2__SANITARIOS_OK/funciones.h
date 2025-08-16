#pragma once

#include "clases.h"

void crearArchvivoTecnicos(int tam=10){

    Tecnicos objT;
    ArchivoTecnicos arObjT;

    Tecnicos_Obras objT_O;
    ArchivoTecnicos_Obras arObjT_O;
    
    arObjT.crearArchivo(tam);
    arObjT_O.crearArchivo(tam);
    
}

void mostrarArchivoTecnicos(){
  Tecnicos objT;
  ArchivoTecnicos arObjT;

  Tecnicos_Obras objT_O;
  ArchivoTecnicos_Obras arObjT_O;

  arObjT.mostrarArchivo();
  arObjT_O.mostrarArchivo();
}
