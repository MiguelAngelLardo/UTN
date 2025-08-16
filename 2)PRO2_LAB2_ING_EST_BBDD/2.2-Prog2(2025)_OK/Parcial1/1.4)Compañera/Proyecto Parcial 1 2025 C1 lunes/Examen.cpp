#include <iostream>
using namespace std;

#include "Examen.h"
#include "Servicio.h"
#include "ArchivoServicio.h"

void Examen::EjemploDeListado(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}

/*
1) Informar la calificación mínima obtenida, y los ID de reparación que la recibieron.

2) Calcular e informar el número de empleado(ID de personal) con mayor cantidad de servicios de reparación

3) Listar la cantidad de Id de reparación distintos que tuvieron servicios en el año 2024

*/

void Examen::Punto1(){
  Servicio registro;
  ArchivoServicio Arch("taller.dat");

  int CalifMinima = 0;
  int contadorMinima = 0;

  int tamanio = Arch.CantidadRegistros();

  bool bandera = false;
  for(int x = 0; x < tamanio; x++){
    registro = Arch.Leer(x);
    if(!bandera){
      CalifMinima = registro.getCalificacion();
      bandera = true;
    }else if(registro.getCalificacion() < CalifMinima){
      CalifMinima = registro.getCalificacion();
    }

  }

  for(int x = 0; x < tamanio; x++){
    registro = Arch.Leer(x);
    if (registro.getCalificacion() == CalifMinima){
      contadorMinima++;
    }
  }
  
  cout << "CALIFICACION MINIMA: " << CalifMinima << endl;
  cout << "CANTIDAD DE SERVICIOS: " << contadorMinima << endl;

}

//2) Calcular e informar el número de empleado(ID de personal) con mayor cantidad de servicios de reparación

void Examen::Punto2(){
  Servicio registro;
  ArchivoServicio archivo("taller.dat");
  int vector[20]={};

  int tamanio = archivo.CantidadRegistros();

  for(int i=0; i<tamanio; i++){
    registro = archivo.Leer(i);
    vector[registro.getIDPersonal()-1]++;
  }

  
  int indiceMayor = 0;
  for(int i=1; i<20; i++){
    if(vector[i] > vector[indiceMayor]){
      indiceMayor = i;
    }
  }
  cout << "El ID de personal con mayor cantidad de servicios es: " << indiceMayor+1 << endl;

}

//3) Listar la cantidad de Id de reparación distintos que tuvieron servicios en el año 2024

void Examen::Punto3(){
  Servicio registro;
  ArchivoServicio archivo("taller.dat");

  int vectorIdReparacionContador2024[70] = {};  

  int tamanio = archivo.CantidadRegistros();

  for(int i=0; i<tamanio; i++){
    registro = archivo.Leer(i);
    if(registro.getFecha().getAnio() == 2024){
      vectorIdReparacionContador2024[registro.getIDReparacion()-1]++;
    }
  }

  for(int i=0; i<70; i++){
    if(vectorIdReparacionContador2024[i] > 0){
      cout << "ID de reparacion: " << i+1 << " Cantidad de servicios: " << vectorIdReparacionContador2024[i] << endl;
    }
  }
}
