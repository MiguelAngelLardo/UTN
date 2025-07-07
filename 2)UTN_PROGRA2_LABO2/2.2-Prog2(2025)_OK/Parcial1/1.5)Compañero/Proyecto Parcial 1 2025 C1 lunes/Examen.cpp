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


//1) Informar la calificación mínima obtenida, y la cantidad de servicios que la recibieron.

void Examen::Punto1(){
  Servicio reg;
  ArchivoServicio objArch("taller.dat");

  int minimaCalif;
  int contMinimaCalif = 0;

  int tam = objArch.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    reg = objArch.Leer(i);
    if (i == 0){
        minimaCalif = reg.getCalificacion();
    }
    else if (reg.getCalificacion() < minimaCalif){
      minimaCalif = reg.getCalificacion();
    }
  }

  for(int i = 0; i < tam; i++){
    reg = objArch.Leer(i);
    if (reg.getCalificacion() == minimaCalif){
      contMinimaCalif++;
    }
  }
  
  cout << "La calificacion minima es: " << minimaCalif << endl;
  cout << "La cantidad de servicios que recibieron la calificacion minima es: " << contMinimaCalif << endl;


}

//2) Calcular e informar el ID de reparación con mayor cantidad de servicios de reparación

void Examen::Punto2(){
  Servicio reg;
  ArchivoServicio objArch("taller.dat");

  int reparadoresContador[70] = {}; 

  int tam = objArch.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    reg = objArch.Leer(i);
    reparadoresContador[reg.getIDReparacion()-1]++;
  }

  int indiceMaximo = 0;
  for(int i = 1; i < 70; i++){
    if (reparadoresContador[i] > reparadoresContador[indiceMaximo]){
      indiceMaximo = i;
    }
  }

  cout << "El ID de reparacion con mayor cantidad de servicios es: " << indiceMaximo + 1 << endl;
}

//3) Informar el número de empleado (Id de personal) con más cantidad de servicios en el año 2024 con costo de repuestos igual a 0.

void Examen::Punto3(){
  Servicio reg;
  ArchivoServicio objArch("taller.dat");
  int empleadosContador[20] = {};

  int tam = objArch.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    reg = objArch.Leer(i);
    if (reg.getCostoRepuestos() == 0 && reg.getFecha().getAnio() == 2024){
      empleadosContador[reg.getIDPersonal()-1]++;
    }
  }

  int indiceMaximo = 0;
  for(int i = 1; i < 20; i++){
    if (empleadosContador[i] > empleadosContador[indiceMaximo]){
      indiceMaximo = i;
    }
  }

  cout << "El ID de personal con mayor cantidad de servicios en el anio 2024 con costo de repuestos igual a 0 es: " << indiceMaximo + 1 << endl;


}
