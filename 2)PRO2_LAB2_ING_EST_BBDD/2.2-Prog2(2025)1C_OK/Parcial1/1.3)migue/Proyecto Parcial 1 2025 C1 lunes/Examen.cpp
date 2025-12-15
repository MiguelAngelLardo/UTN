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


//1) Informar la calificación máxima obtenida, y los ID de reparación que la recibieron
void Examen::Punto1(){
  Servicio objServicioM;
  ArchivoServicio archivo("taller.dat");

  float vReparacionCalif[70] = {};

  int tam = archivo.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    Servicio objServicio = archivo.Leer(i);

    if(objServicio.getCalificacion() > vReparacionCalif[objServicio.getIDReparacion()-1]){
      vReparacionCalif[objServicio.getIDReparacion()-1] = objServicio.getCalificacion();
    }
  }

  int iMax = 0;
  for(int i = 1; i < 70; i++){
    if(vReparacionCalif[i] > vReparacionCalif[iMax]){
      iMax = i;
    }
  }

  cout << "La calificacion maxima es: " << vReparacionCalif[iMax] << endl;
  cout << "Los ID de reparacion que la recibieron son: " << endl;
  for(int i = 0; i < 70 ; i++){
    if(vReparacionCalif[i] == vReparacionCalif[iMax]){
      cout << i+1 << endl;
    }
  }
}

//2) Calcular e informar el número de empleado (ID de personal) con menor cantidad de servicios de reparación
void Examen::Punto2(){
  Servicio objServicioM;
  ArchivoServicio archivo("taller.dat");

  int vPersonalContServicios[20] = {};//1000 registros

  int tam = archivo.CantidadRegistros();

  for (int i = 0; i < tam; i++){
    Servicio objServicio = archivo.Leer(i);
    vPersonalContServicios[objServicio.getIDPersonal()-1]++;
  }

  int iMin = 0;
  for (int i = 1; i < 20; i++){
    if(vPersonalContServicios[i] < vPersonalContServicios[iMin]){
      iMin = i;
    }
  }

  cout << "El ID de personal con menor cantidad de servicios es: " << iMin+1 << endl;

}

//3) Listar la cantidad de Id de reparación distintos que no tuvieron servicios en el año 2024

void Examen::Punto3(){
  Servicio objServicioM;
  ArchivoServicio archivo("taller.dat");

  int vReparacionContServicios[70] = {};
  int tam = archivo.CantidadRegistros();

  for (int i = 0; i < tam; i++){
    Servicio objServicio = archivo.Leer(i);
    if(objServicio.getFecha().getAnio() == 2024){
      vReparacionContServicios[objServicio.getIDReparacion()-1]++;
    }
  }

  int cont = 0;
  for (int i = 0; i < 70; i++){
    if(vReparacionContServicios[i] == 0){
      cont++;
    }
  }

  if(cont == 0){
    cout << "No hay reparaciones sin servicios en el anio 2024" << endl;
  }else{
    cout << "La cantidad de reparaciones sin servicios en el año 2024 es: " << cont << endl;
  }
}
