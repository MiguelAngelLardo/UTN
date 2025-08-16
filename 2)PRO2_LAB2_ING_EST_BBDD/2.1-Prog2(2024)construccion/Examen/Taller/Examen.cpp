#include <iostream>
using namespace std;

#include "Examen.h"
#include "Servicio.h"
#include "ArchivoServicio.h"

void Examen::EjemploDeListado(){
   ArchivoServicio archivo("taller.dat");
   Servicio registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   cout<<cantidadRegistros<<endl;
   system("pause");
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      registro.Mostrar();
   }
}


void Examen::Punto1(){

}

void Examen::Punto2(){

}

void Examen::Punto3(){

}
