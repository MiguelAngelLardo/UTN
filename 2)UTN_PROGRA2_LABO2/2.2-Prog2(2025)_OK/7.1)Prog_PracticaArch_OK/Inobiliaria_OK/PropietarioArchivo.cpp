#include "PropietarioArchivo.h"
#include <cstring>

PropietarioArchivo::PropietarioArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}


int PropietarioArchivo::getCantidadRegistros(){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return 0;

  fseek(pFile, 0, SEEK_END);
  int tam = ftell(pFile) / sizeof(Propietario);
  fclose(pFile);  

  return tam;
}



bool PropietarioArchivo::agregarRegistro(Propietario obj){
  bool resultado;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)return false;
  
  resultado = fwrite(&obj, sizeof (Propietario), 1, pFile);//0 = no se pudo escribir, 1 = se pudo escribir

  fclose(pFile);

  return resultado;
}


Propietario PropietarioArchivo::leerUnRegistro(int pos){
  Propietario objPos;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return objPos;
  
  fseek(pFile, sizeof(Propietario) * pos, SEEK_SET);

  fread(&objPos, sizeof(Propietario), 1, pFile);

  fclose(pFile);

  return objPos;
}

 bool  PropietarioArchivo::modificarPorIndice(Propietario reg, int pos){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb+");
  if(pFile == nullptr)return false;

  fseek(pFile, sizeof(Propietario)*pos, SEEK_SET);
  
  fwrite(&reg, sizeof(Propietario), 1, pFile);
  fclose(pFile);
  return true;
}

int PropietarioArchivo::buscarPorDNI(std::string dni){
  Propietario reg;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return -1;
  
  int pos = 0;
  while(fread(&reg, sizeof(Propietario), 1, pFile)){
    if(reg.getDNI() == dni){
      return pos;
    }
    pos ++;
  }


  fclose(pFile);
  return -1;
}


// int PropietarioArchivo::buscarPorId(int id){
//   int pos = 0;
//   Propietario reg;
//   FILE *pFile;
//   pFile = fopen(_nombreArchivo.c_str(), "rb");
//   if(pFile == nullptr)return -1;

//   while(fread(&reg, sizeof(Propietario), 1, pFile)){
//     if(reg.getCodigo() == id){
//       return pos;
//     }
//     pos ++;
//   }


//   fclose(pFile);
//   return pos;
// }





// */
// /*
// int PropietarioArchivo::buscarPorPuestoYExperiencia(std::string puesto, int experiencia){
//   Propietario reg;
//   FILE *pFile;
//   pFile = fopen(_nombreArchivo.c_str(), "rb");
//   if(pFile == nullptr)return -1;

//   int pos = 0;
//   while(fread(&reg, sizeof(Propietario), 1, pFile)){
//     if(reg.getPuesto() == puesto && reg.getAniosExperiencia() == experiencia){
//       return pos;
//     }
//     pos ++;
//   }
//   fclose (pFile);
  
//   return -1;
// }*/



// int PropietarioArchivo::crearNuevoIdAUtomatico(){
//   int cantidadActual = getCantidadRegistros();

//   if(cantidadActual > 0){
//     return leerUnRegistro(getCantidadRegistros() - 1).getId() + 1;
//   }else{
//     return 1;
//   }
         
//  //Propietario leerUnRegistro(int pos); 
//  //int getCantidadRegistros(); => usa fseek y ftell y me da 5 como total, le resto 1 por q se maneja de 0 a 4
//  //ahora tengo return ultimo objeto del archivo
//  // le pongo objeto.getId() + 1 para q devuelva un numero
// }

// void PropietarioArchivo::leerTodosLeyenedoConVecDin(Propietario vPos[], int cantidad){
//   FILE *pFile;
//   pFile = fopen(_nombreArchivo.c_str(), "rb");
//   if(pFile == nullptr)return;

//   fread(vPos, sizeof(Propietario), cantidad, pFile);
//   fclose(pFile);
// }
