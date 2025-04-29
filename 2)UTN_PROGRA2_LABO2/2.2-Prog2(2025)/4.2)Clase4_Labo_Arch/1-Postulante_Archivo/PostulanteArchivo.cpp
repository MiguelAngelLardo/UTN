#include "PostulanteArchivo.h"
#include <cstring>

// PostulanteArchivo::PostulanteArchivo(){
//   _nombreArchivo = "postulantes.dat";
// }
PostulanteArchivo::PostulanteArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

bool PostulanteArchivo::agregarRegistro(Postulante obj){
  bool resultado;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "ab");

  if(pFile == nullptr)return false;
  
  resultado = fwrite(&obj, sizeof (Postulante), 1, pFile);//0 = no se pudo escribir, 1 = se pudo escribir

  fclose(pFile);

  return resultado;
}

int PostulanteArchivo::getCantidadRegistros(){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return 0;

  fseek(pFile, 0, SEEK_END);
  int tam = ftell(pFile) / sizeof(Postulante);
  fclose(pFile);  

  return tam;
}

Postulante PostulanteArchivo::leerUnRegistro(int pos){
  Postulante objPos;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return objPos;
  
  fseek(pFile, sizeof(Postulante) * pos, SEEK_SET);

  fread(&objPos, sizeof(Postulante), 1, pFile);

  fclose(pFile);

  return objPos;
}


int PostulanteArchivo::buscarPorId(int id){
  int pos = 0;
  Postulante reg;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return -1;

  while(fread(&reg, sizeof(Postulante), 1, pFile)){
    if(reg.getId() == id){
      return pos;
    }
    pos ++;
  }


  fclose(pFile);
  return pos;

}

int PostulanteArchivo::buscarPorPuestoYExperiencia(std::string puesto, int experiencia){
  Postulante reg;
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return -1;

  int pos = 0;
  while(fread(&reg, sizeof(Postulante), 1, pFile)){
    if(reg.getPuesto() == puesto && reg.getAniosExperiencia() == experiencia){
      return pos;
    }
    pos ++;
  }
  fclose (pFile);
  
  return -1;
}

bool  PostulanteArchivo::modificarPorIndice(Postulante reg, int pos){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb+");
  if(pFile == nullptr)return false;

  fseek(pFile, sizeof(Postulante)*pos, SEEK_SET);
  
  fwrite(&reg, sizeof(Postulante), 1, pFile);
  fclose(pFile);
  return true;
}

int PostulanteArchivo::crearNuevoIdAUtomatico(){
  int cantidadActual = getCantidadRegistros();

  if(cantidadActual > 0){
    return leerUnRegistro(getCantidadRegistros() - 1).getId() + 1;
  }else{
    return 1;
  }
         
 //Postulante leerUnRegistro(int pos); 
 //int getCantidadRegistros(); => usa fseek y ftell y me da 5 como total, le resto 1 por q se maneja de 0 a 4
 //ahora tengo return ultimo objeto del archivo
 // le pongo objeto.getId() + 1 para q devuelva un numero
}

void PostulanteArchivo::leerTodosLeyenedoConVecDin(Postulante vPos[], int cantidad){
  FILE *pFile;
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  if(pFile == nullptr)return;

  fread(vPos, sizeof(Postulante), cantidad, pFile);
  fclose(pFile);
}
