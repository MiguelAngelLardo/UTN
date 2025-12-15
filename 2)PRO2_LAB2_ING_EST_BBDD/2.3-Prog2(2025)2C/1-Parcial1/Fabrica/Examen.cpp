#include <iostream>
using namespace std;

#include "Examen.h"
#include "OrdenProduccion.h"
#include "ArchivoOrdenProduccion.h"

void Examen::EjemploDeListado(){
   ArchivoOrdenProduccion archivo("ordenes_produccion.dat");
   OrdenProduccion registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}


/*
  int _IDProduccion, _IDMaquina, _IDTipoPieza, _cantidad;//id maquina de 1 a 15 - idTipoPieza 1 a 40
  float _costo, _tiempoEnHoras, _cantidadMateriaPrima;
  Fecha _fecha;

*/
//Indicar el número de máquina que más tiempo de trabajo haya registrado en el primer semestre de 2024
//idproduccion  idMaqu  idTipoPieza   cant    costo          tiempoHs   cantMateriaPrima       fecha
//1,             4      13            558     31882.015625   5.144978   15.672857             28/8/2024
void Examen::Punto1(){
  OrdenProduccion objOrdenProd;
  ArchivoOrdenProduccion archOrdProd("ordenes_produccion.dat");

  float vNumMaqTiempoHoras[15] = {};

  int tam = archOrdProd.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    objOrdenProd = archOrdProd.Leer(i);

    if(objOrdenProd.getFecha().getAnio() == 2024 && objOrdenProd.getFecha().getMes() <= 6){
      vNumMaqTiempoHoras[objOrdenProd.getIDMaquina() - 1] += objOrdenProd.getTiempoEnHoras();
    }
  }
 
  
  int iMax = 0;
  for(int i = 1; i < 15; i++){
    if(vNumMaqTiempoHoras[i] > vNumMaqTiempoHoras[iMax]){
      iMax = i;
    }
  }

  cout << "El numero de maquina que mas tiempo de trabajo haya registrado en el primer semestre de 2024 es: " << iMax + 1 << endl;
  
  
}


//La cantidad de máquinas distintas que gastaron más de 90000 en total entre todas las producciones del tipo de pieza 15 que realizaron.
void Examen::Punto2(){
 //tipopieza va de 1 a 40, necesito el 15
 //maquinas van de 1 a 15, tengo q acumular costos
 
  OrdenProduccion objOrdenProd;
  ArchivoOrdenProduccion archOrdProd("ordenes_produccion.dat");

  float vNumMaqAcumCosto[15] = {};

  int tam = archOrdProd.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    objOrdenProd = archOrdProd.Leer(i);
  
    if(objOrdenProd.getIDTipoPieza() == 15){
      vNumMaqAcumCosto[objOrdenProd.getIDMaquina() - 1] += objOrdenProd.getCosto();
    }
  }


  int contadorMaqDistintas = 0;
  for(int i = 0; i < 15; i++){
    if(vNumMaqAcumCosto[i] > 90000){
      contadorMaqDistintas++;
    }
  }

  cout << "La cantidad de maquinas distintas que gastaron mas de 90000 en total entre todas las producciones del tipo de pieza 15 que realizaron es: " << contadorMaqDistintas << endl;
  
}


//Las máquinas que hayan utilizado más materia prima en el 2025 que en el 2024.
void Examen::Punto3(){
  //idMaquina de 1 a 15 
  //materia prima es float y debe acumularse
  
  OrdenProduccion objOrdenProd;
  ArchivoOrdenProduccion archOrdProd("ordenes_produccion.dat");
  float vNumMaqAcumMatPrima2024[15] = {};
  float vNumMaqAcumMatPrima2025[15] = {};

  int tam = archOrdProd.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    objOrdenProd = archOrdProd.Leer(i);

    //cargo los vectores
    if(objOrdenProd.getFecha().getAnio() == 2024){
      vNumMaqAcumMatPrima2024[objOrdenProd.getIDMaquina() - 1] += objOrdenProd.getCantidadMateriaPrima();
    }

    if(objOrdenProd.getFecha().getAnio() == 2025){
      vNumMaqAcumMatPrima2025[objOrdenProd.getIDMaquina() - 1] += objOrdenProd.getCantidadMateriaPrima();
    }
  }
  


  for(int i = 0; i < 15; i++){
    if(vNumMaqAcumMatPrima2025[i] > vNumMaqAcumMatPrima2024[i]){
      cout << "La maquina " << i + 1 << " ha utilizado mas materia prima en el 2025 que en el 2024" << endl;
    }
  }
  
  
  
}  





