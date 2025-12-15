#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}

//1) Listar la cantidad de servicios de mesa que fueron valorados con un puntaje mayor al puntaje promedio
void Examen::Punto1(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa archServMesa("restaurant.dat");

  int tamArchivo = archServMesa.CantidadRegistros();
  
  //promedio es el TOTAL / tam
  float acumPuntaje = 0.0;
 
  for(int i = 0; i < tamArchivo; i ++){
    objServMesa = archServMesa.Leer(i);
    acumPuntaje += objServMesa.getPuntajeObtenido();
  }

  float promedio = acumPuntaje / tamArchivo;
  
  int contPuntajesMayorPromedio = 0;
  for(int i = 0; i < tamArchivo; i ++){
    objServMesa = archServMesa.Leer(i);
    if(objServMesa.getPuntajeObtenido() > promedio){
      contPuntajesMayorPromedio ++;
    }  
  }

 cout << "La cantidad de servicios mayor al promedio " << contPuntajesMayorPromedio;

}

//2) Listar el número de plato que recaudó mayor cantidad de dinero
void Examen::Punto2(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa archServMesa("restaurant.dat");
  float vNumPlatoAcum[70] = {};

  int tamArchivo = archServMesa.CantidadRegistros();// posicionarme al final y con ftell / sizeof sacar el tam total

  for(int i = 0; i < tamArchivo; i ++){
    objServMesa = archServMesa.Leer(i);
    vNumPlatoAcum[objServMesa.getIDPlato()-1] += objServMesa.getImporte();
    //vNumPlatoAcum[0] - vNumPlatoAcum[1] - vNumPlatoAcum[2] - vNumPlatoAcum[3]
    //reg 1,25, 4, 10, 8, 5, 20000
  }
  /*//reg 2,45, 4,  8, 5, 4, 15000 
   int _IDServicioMesa, _IDMozo, _IDPlato, _tiempoPreparacion;//Mozo 1 a 20 - Plato 1 a 70 
        float _puntajeObtenido, _propina, _importe; //propina = 0 => no recibio
        Fecha _fecha;//Composicion 
  */

  int iMax = 0;
  for(int i = 1; i < 70; i++){ 
    ////vNumPlatoAcum[1] > vNumPlatoAcum[0]
    if(vNumPlatoAcum[i] > vNumPlatoAcum[iMax]){
      iMax = i;
    }
  }
  
system("cls"); 
cout << "EL numero de plato que recaudo mas dinero es: " << iMax +1 << " y el valor es $" << vNumPlatoAcum[iMax];
}

//3) Listar el número de mozo que recibió mayor cantidad total de propinas en el año 2024
//int _IDServicioMesa, _IDMozo, _IDPlato, _tiempoPreparacion;//Mozo 1 a 20 - Plato 1 a 70 
void Examen::Punto3(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa archServMesa("restaurant.dat");

  float vMozoContPropinas[20] = {};
  
  int tamArchivo = archServMesa.CantidadRegistros();//fseek y ftell
  
  for(int i = 0; i < tamArchivo; i ++){
    objServMesa = archServMesa.Leer(i); //fopen con rb + fread que traer de disco a memoria (el recuerdo de tu ex)
    
    //reg 1,25, 4, 10, 8, 5, 20000,  10/10/2025
                                                         //FECHA => get.Anio
    //objServMesa.getFecha => retornar la fecha entera => 10/10/2025
    if(objServMesa.getFecha().getAnio() == 2024 ){
      vMozoContPropinas[objServMesa.getIDMozo()-1] ++;

      // int numero = 0;
      //numero = numero + 1; == numero ++;

      // vMozoContPropinas[0] = 0 =>  vMozoContPropinas[0] =  vMozoContPropinas[0] + 1 ==  vMozoContPropinas[0]++
      // vMozoContPropinas[1] = 0
      // vMozoContPropinas[18] = 0
      // vMozoContPropinas[19] = 0

    }
  }

  int iMax = 0;
  for(int i = 1; i < 20; i++){
    if(vMozoContPropinas[i] > vMozoContPropinas[iMax]){
      iMax = i;
    }
  }

  cout << "El numero de mozo que recibio max propinas en 2024 es: " << iMax + 1;
 

}
