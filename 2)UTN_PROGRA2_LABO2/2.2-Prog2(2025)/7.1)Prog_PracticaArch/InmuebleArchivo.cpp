#include "InmuebleArchivo.h"
#include <cstring>

InmuebleArchivo::InmuebleArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}


int InmuebleArchivo::getCantidadRegistros(){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return 0;

  fseek(pFile, 0, SEEK_END);
  int tam = ftell(pFile) / sizeof(Inmueble);
  fclose(pFile);  

  return tam;
}



bool InmuebleArchivo::agregarRegistro(Inmueble obj){
  bool resultado;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)return false;
  
  resultado = fwrite(&obj, sizeof (Inmueble), 1, pFile);//0 = no se pudo escribir, 1 = se pudo escribir

  fclose(pFile);

  return resultado;
}


Inmueble InmuebleArchivo::leerUnRegistro(int pos){
  Inmueble objPos;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return objPos;
  
  fseek(pFile, sizeof(Inmueble) * pos, SEEK_SET);

  fread(&objPos, sizeof(Inmueble), 1, pFile);

  fclose(pFile);

  return objPos;
}

bool  InmuebleArchivo::modificarPorIndice(Inmueble reg, int pos){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb+");
  if(pFile == nullptr)return false;

  fseek(pFile, sizeof(Inmueble)*pos, SEEK_SET);
  
  fwrite(&reg, sizeof(Inmueble), 1, pFile);
  fclose(pFile);
  return true;
}


int InmuebleArchivo::buscarPorId(int id){
  int pos = 0;
  Inmueble reg;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return -1;

  while(fread(&reg, sizeof(Inmueble), 1, pFile)){
    if(reg.getCodigo() == id){
      return pos;
    }
    pos ++;
  }


  fclose(pFile);
  return pos;
}

int InmuebleArchivo::buscarPorCalle(std::string calle){
  Inmueble reg;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return -1;
  
  int pos = 0;
  while(fread(&reg, sizeof(Inmueble), 1, pFile)){
    if(reg.getCalle() == calle){
      return pos;
    }
    pos ++;
  }
  fclose(pFile);
  return pos;
}

// */
// /*
// int InmuebleArchivo::buscarPorPuestoYExperiencia(std::string puesto, int experiencia){
//   Inmueble reg;
//   FILE *pFile;
//   pFile = fopen(_nombreArchivo.c_str(), "rb");
//   if(pFile == nullptr)return -1;

//   int pos = 0;
//   while(fread(&reg, sizeof(Inmueble), 1, pFile)){
//     if(reg.getPuesto() == puesto && reg.getAniosExperiencia() == experiencia){
//       return pos;
//     }
//     pos ++;
//   }
//   fclose (pFile);
  
//   return -1;
// }*/



// int InmuebleArchivo::crearNuevoIdAUtomatico(){
//   int cantidadActual = getCantidadRegistros();

//   if(cantidadActual > 0){
//     return leerUnRegistro(getCantidadRegistros() - 1).getId() + 1;
//   }else{
//     return 1;
//   }
         
//  //Inmueble leerUnRegistro(int pos); 
//  //int getCantidadRegistros(); => usa fseek y ftell y me da 5 como total, le resto 1 por q se maneja de 0 a 4
//  //ahora tengo return ultimo objeto del archivo
//  // le pongo objeto.getId() + 1 para q devuelva un numero
// }

// void InmuebleArchivo::leerTodosLeyenedoConVecDin(Inmueble vPos[], int cantidad){
//   FILE *pFile;
//   pFile = fopen(_nombreArchivo.c_str(), "rb");
//   if(pFile == nullptr)return;

//   fread(vPos, sizeof(Inmueble), cantidad, pFile);
//   fclose(pFile);
// }
