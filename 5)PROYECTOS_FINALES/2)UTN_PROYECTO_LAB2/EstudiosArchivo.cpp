#include <cstring>
#include "EstudiosArchivo.h"

EstudiosArchivo::EstudiosArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

std::string EstudiosArchivo::getNombreArchivo() const{
  return _nombreArchivo;
}


int EstudiosArchivo::buscarPorCodigoEstudio(std::string codigoEstudio){
  Estudios reg;
  FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr){
    return -1;
  }

  int pos = 0;
  while(fread(&reg, sizeof(Estudios), 1, pFile)){
    if(reg.getCodigoEstudio() == codigoEstudio){
      fclose(pFile);
      return pos;//devuelve cero si es el primero
    }
    pos++;
  }

  fclose(pFile);
  return -2;
}



