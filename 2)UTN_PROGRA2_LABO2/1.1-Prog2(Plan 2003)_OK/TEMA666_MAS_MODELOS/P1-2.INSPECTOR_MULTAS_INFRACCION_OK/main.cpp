
#include <iostream>
#include <cstring>

using namespace std;

#include "puntoHParcial.h"

class Multas2{
private:
  int _codigo;
  char _descripcion[40];
  int _cantidadInfracciones;
  bool _estado;

public:
  void setCodigo(int c){_codigo=c;}
  void setDescripcion(const char *d){strcpy(_descripcion, d);}
  void setInfracciones(int i){_cantidadInfracciones=i;}

  int getCodigo(){return _codigo;}
  const char *getDescripcion(){return _descripcion;}
  int getInfracciones(){return _cantidadInfracciones;}



  void mostrar(){
    cout << "CODIGO: " << _codigo << endl;
    cout << "DESCRIPCION: " << _descripcion << endl;
    cout << "CANT. INFRACCIONES: " << _cantidadInfracciones << endl;
  }
};


class ArchivoMultas2{
private:
	char _nombre[30];
public:
	ArchivoMultas2(const char *n){
		strcpy(_nombre, n);
	}

void cargarArchivo(Multas2 objM2){
  
  FILE *p;
  p = fopen(_nombre,"ab");
  if(p == NULL){
    cout << "No se pudo abrir el archivo";
    return;
  }
  fwrite(&objM2, sizeof(Multas2), 1, p);
  fclose(p);
}

void listarArchivo(){
  Multas2 objM2;
  FILE *p;
  p = fopen(_nombre, "rb");
  if (p == NULL){
    cout << "Error de apertura";
    return;
  }

  while (fread(&objM2, sizeof(Multas2), 1, p) == 1){
    objM2.mostrar();
    cout << endl;
  }
  fclose(p);
}

void limpiarArticulo(){
  FILE *p;
  p = fopen(_nombre, "wb");
  if(p == NULL){
    return;
  }
  fclose(p);
}
  
};


int main(){
  Multa objM;
  ArchivoMultas ARobjM("Multas.dat"); //anda con true
  Infraccion objI;
  ArchivoInfracciones ARobjI("Infracciones.dat"); //anda con false

  Multas2 objM2;
  ArchivoMultas2 ARobjM2("Multas2.dat");
  ARobjM2.limpiarArticulo();

   int tam1=ARobjM.contarRegistros();
   int tam2=ARobjI.contarRegistros();
   int locali;

  int contadorInfracciones[11]={};//PARA EL NUEVO ATRIBUTO DE LA CLASE

  for(int i=0;i<tam1;i++){
    objM = ARobjM.leerRegistro(i);
    if(objM.getEstado()==true){
      for(int j=0;j<tam2;j++){
        objI = ARobjI.leerRegistro(j);
        if(objI.getEstado()==false){ //-> VA EN FALSE POR QUE EL PROFE SE CONFUNDIO
          if((objM.getCodigo()==objI.getCodigoMulta()) && (objI.getLocalidad()==1)){
            contadorInfracciones[objI.getLocalidad()-1]++;
          }  
        }
      }
    }
  }

  
  for(int i=0;i<tam1;i++){
    objM = ARobjM.leerRegistro(i);
    if(objM.getEstado()==true){

      for(int j=0;j<tam2;j++){
        objI = ARobjI.leerRegistro(j);
        if(objI.getEstado()==false){ //-> VA EN FALSE POR QUE EL PROFE SE CONFUNDIO
          if((objM.getCodigo()==objI.getCodigoMulta()) && (objI.getLocalidad()==1)){
            objM2.setCodigo(objM.getCodigo());
            objM2.setInfracciones(contadorInfracciones[objI.getLocalidad()-1]);
            objM2.setDescripcion(objM.getDescripcion());
            ARobjM2.cargarArchivo(objM2);
          }  
        }
      }
    }
  }

  

  ARobjM2.listarArchivo();

 

  
  return 0;
}