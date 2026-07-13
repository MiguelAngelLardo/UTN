#include <cstring>
#include "HistoriaClinicaArchivo.h"


 HistoriaClinicaArchivo::HistoriaClinicaArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
 }


std::string HistoriaClinicaArchivo::getNombreArchivo() const{
  return _nombreArchivo;
}

bool HistoriaClinicaArchivo::primerCreacionHistorica(std::string nombreArchivo){
  FILE *nuevoArchivo = fopen(nombreArchivo.c_str(), "wb");
  if(nuevoArchivo != nullptr) {
    fclose(nuevoArchivo);
    return true;
  }  
  return false;
}


int  HistoriaClinicaArchivo::buscarPorCodigoHC(std::string nombreArchivo, std::string codigoHC){
  HistoriaClinica reg;
  FILE *pFile = fopen(nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return -1;
  }

  int pos = 0;
  while(fread(&reg, sizeof(HistoriaClinica), 1, pFile)){
    if(reg.getCodigoHC() == codigoHC){
      fclose(pFile);
      return pos;
    }
    pos++;
  }

  fclose(pFile);
  return -2;
}


