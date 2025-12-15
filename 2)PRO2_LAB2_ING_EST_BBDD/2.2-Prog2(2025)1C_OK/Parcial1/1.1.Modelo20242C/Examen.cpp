#include <iostream>
#include <iomanip>

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

//1) Listar la cantidad de servicios de mesa 
//que fueron valorados con un puntaje mayor al puntaje promedio

void Examen::Punto1(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");

  int tam = archServicioMesa.CantidadRegistros();

  float acumPuntajes = 0;
  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    acumPuntajes += servicioMesa.getPuntajeObtenido();
  }

  float promedio;
  if(tam > 0){
    promedio = acumPuntajes / tam;
  }

  
  int contPuntajesMayorPromedio = 0;
  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getPuntajeObtenido() > promedio){
      contPuntajesMayorPromedio++;
    }
  }

  cout << "La cantidad de servicios de mesa que fueron valorados con un puntaje mayor al puntaje promedio es: " << contPuntajesMayorPromedio << endl;

}

void Examen::Punto1B(){
  ServicioMesa *vDinServicioMesa = nullptr;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  int tam = archServicioMesa.CantidadRegistros();
  vDinServicioMesa = new ServicioMesa[tam];
  if(vDinServicioMesa == nullptr){
    cout << "No se pudo reservar memoria" << endl;
    return;
  }

  archServicioMesa.Leer(tam, vDinServicioMesa);

  float acum = 0;
  for(int i = 0; i < tam; i++){
    acum += vDinServicioMesa[i].getPuntajeObtenido();
  }

  float promedio ;
  if(tam > 0){
   promedio = acum / tam;
  }
  
  int acumMayorPromedio = 0;
  for(int i = 0; i < tam; i++){
    if(vDinServicioMesa[i].getPuntajeObtenido() > promedio){
      acumMayorPromedio++;
    }
  }

  cout << "La cantidad de servicios de mesa que fueron valorados con un puntaje mayor al puntaje promedio es: " << acumMayorPromedio << endl;


}


//2) Listar el número de plato que recaudó mayor cantidad de dinero

void Examen::Punto2(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  float vNumPlatoAcum[70] = {};

  int tam = archServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    vNumPlatoAcum[servicioMesa.getIDPlato()-1] += servicioMesa.getImporte();
  }

  int iMax= 0;
  for(int i = 1; i < 70; i++){
    if(vNumPlatoAcum[i] > vNumPlatoAcum[iMax]){
      iMax = i;
    }
  } 
  
  cout << "El numero de plato que recaudo mayor cantidad de dinero es: " << iMax+1 << endl;
    
}

//3) Listar el número de mozo que recibió mayor cantidad total de propinas en el año 2024

void Examen::Punto3(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  float vMozoContPropina[20] = {};

  int tam = archServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getFecha().getAnio() == 2024){
      if(servicioMesa.getPropina() > 0){
        vMozoContPropina[servicioMesa.getIDMozo()-1] ++;
      }
    }
  }

  int iMax = 0;
  for(int i = 1; i < 20; i++){
    if(vMozoContPropina[i] > vMozoContPropina[iMax]){
      iMax = i;
    }
  } 

  if(vMozoContPropina[iMax] > 0){
      cout << "El numero de mozo que recibio mayor cantidad de propinas en el 2024 es: " << iMax+1 << endl;
  }else{
    cout << "No hubo propinas en el 2024" << endl;
  }
}

//4-¿Cuál es el ID del mozo que recibió la mayor cantidad de propinas en el año 2023?

void Examen::Punto4(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  float vMozoContPropina[20] = {};

  int tam = archServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getFecha().getAnio() == 2023){
      if(servicioMesa.getPropina() > 0){
        vMozoContPropina[servicioMesa.getIDMozo()-1] ++;
      }
    }
  }

  int iMax = 0;
  for(int i = 1; i < 20; i++){
    if(vMozoContPropina[i] > vMozoContPropina[iMax]){
      iMax = i;
    }
  }

  if(vMozoContPropina[iMax] > 0){
      cout << "El numero de mozo que recibio mayor cantidad de propinas en el 2023 es: " << iMax+1 << endl;
  }
}

//5-¿Qué plato tuvo el menor tiempo
// promedio de preparación en el primer trimestre de 2024 (enero, febrero, marzo)?

void Examen::Punto5(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  int vPlatosAcumTiempoPreparacion[70] = {};
  int vPlatosCont[70] = {};
  float vPlatosProm[70] = {0.0};
  
  int tam = archServicioMesa.CantidadRegistros();
  
  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getFecha().getAnio() == 2024 && servicioMesa.getFecha().getMes() >= 1 && servicioMesa.getFecha().getMes() <= 3){
      vPlatosAcumTiempoPreparacion[servicioMesa.getIDPlato()-1] += servicioMesa.getTiempoPreparacion();
      vPlatosCont[servicioMesa.getIDPlato()-1]++;
    }
  }

  for(int i = 0; i < 70; i++){
    if(vPlatosCont[i] > 0){
      vPlatosProm[i] = (float)vPlatosAcumTiempoPreparacion[i] / vPlatosCont[i];
    }
  }

  int iMin = 0;
  for(int i = 1; i < 70; i++){
    if(vPlatosProm[i] < vPlatosProm[iMin] && vPlatosCont[i] > 0){
      iMin = i;
      cout << iMin << endl;
    }
  }
  cout << "el menor promedio es " << iMin + 1 << endl; 
}

//6.¿Cuántos servicios de mesa obtuvieron un puntaje mayor a 8 pero no recibieron propina?
void Examen::Punto6(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");
  int contServiciosPuntajeMayor8SinPropina = 0;

  int tam = archServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getPuntajeObtenido() > 8 && servicioMesa.getPropina() == 0){
      contServiciosPuntajeMayor8SinPropina++;
    }
  }

  cout << "La cantidad de servicios de mesa que obtuvieron un puntaje mayor a 8 pero no recibieron propina es: " << contServiciosPuntajeMayor8SinPropina << endl;

}

//7.¿Qué plato tuvo al menos 1 servicios con puntaje 10, pero ningún servicio con puntaje menor a 7 en 2023?
void Examen::Punto7(){
  ServicioMesa servicioMesa;
  ArchivoServicioMesa archServicioMesa("restaurant.dat");

  int tam = archServicioMesa.CantidadRegistros();

  bool vPlatodif1A7[70];
  bool vPlatos10[70] = {};

  for(int i = 0; i < 70; i++){
    vPlatodif1A7[i] = true;
  }

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getFecha().getAnio() == 2023){
      if((servicioMesa.getPuntajeObtenido() > 0 && servicioMesa.getPuntajeObtenido() < 3)){
        vPlatodif1A7[servicioMesa.getIDPlato()-1] = false;
      }
    }
  }

  for(int i = 0; i < tam; i++){
    servicioMesa = archServicioMesa.Leer(i);
    if(servicioMesa.getFecha().getAnio() == 2023){
      if(vPlatodif1A7[servicioMesa.getIDPlato()-1]){
        if(servicioMesa.getPuntajeObtenido() == 9){
          vPlatos10[servicioMesa.getIDPlato()-1] = true;
        }
      }
    }
  }

  for(int i = 0; i < 70; i++){
    if(vPlatodif1A7[i] && vPlatos10[i]){
      cout << "El plato " << i+1 << " tuvo al menos 10 servicios con puntaje 10, pero ningun servicio con puntaje menor a 7 en 2023" << endl;
    }  
  }
}

