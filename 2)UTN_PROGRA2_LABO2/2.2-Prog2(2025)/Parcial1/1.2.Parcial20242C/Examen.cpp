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

//hay 20 mozos
//¿Cuál es la cantidad de mozos distintos que no recibieron propina?
// void Examen::Punto1(){
//   ServicioMesa objServMesa;
//   ArchivoServicioMesa objArchMesa("restaurant.dat");
//   bool vMozosContSinPropina[20] = {};

//   int tam = objArchMesa.CantidadRegistros();
//   for(int i = 0; i < tam; i++){
//     objServMesa = objArchMesa.Leer(i);
//     if(objServMesa.getPropina() == 0){
//       vMozosContSinPropina[objServMesa.getIDMozo()-1] = true;
//     }
//   }  

//   int contMozoSinPropina = 0;
//   for(int i = 0; i < 20; i++){
//     if(vMozosContSinPropina[i] == true){
//       contMozoSinPropina++;
//     }
//   }
//   cout << "Mozos que no recibieron propina: " << contMozoSinPropina << endl;
// }


//hay 20 mozos
//¿Cuál es la cantidad de mozos distintos que no recibieron propina?

//reg 1 el mozo 1 tiene propina
//reg 2 el mozo 2 tiene propina
//reg 3 el mozo 1 no tiene propina
//reg 4 el mozo 3 tiene propina
//reg 5 el mozo 1 tiene propina  
void Examen::Punto1(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa objArchServicioMesa("restaurant.dat");

  bool vMozoSinPropina[20] = {};//significa que ASUMO que todos tienen propina

  int tam = objArchServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i ++){
    objServMesa = objArchServicioMesa.Leer(i);
    if(objServMesa.getPropina()==0){
      vMozoSinPropina[objServMesa.getIDMozo()-1] = true;
    }
  }

  int contador = 0;
  for(int i = 0; i < 20; i ++){
    if(vMozoSinPropina[i]){
      contador ++;
    }
  }

  cout << "cantidad de mozos distintos que no recibieron propina " << contador << endl;
}



void Examen::Punto1ConVec(){
  ServicioMesa objSer;
  ArchivoServicioMesa objArch("restaurant.dat");
  ServicioMesa *vDinServ;
  int vMozosSinProp[20] = {};//todos vienen con propona

  int tam = objArch.CantidadRegistros();
  vDinServ = new ServicioMesa[tam];
  if(vDinServ == NULL) return;
  objArch.Leer(tam, vDinServ);
  
  for(int i = 0; i < tam; i++){
    if(vDinServ[i].getPropina()== 0){
      vMozosSinProp[vDinServ[i].getIDMozo()-1] = true;
    }
  }  

  int contSinPropinas = 0;

  for(int i = 0; i < 20; i++){
    if(vMozosSinProp[i] == true){
      contSinPropinas++;
    }
  }  

  cout << "Mozos que no recibieron propina: " << contSinPropinas << endl;

  delete [] vDinServ;
}



//¿Qué números de mozo no obtuvieron nunca un puntaje de 10 pero tampoco un 1?
// void Examen::Punto2(){
//   ServicioMesa objServMesa;
//   ArchivoServicioMesa objArchMesa("restaurant.dat");
//   bool vMozoConExtremo[20] = {};//no tiene extremo por fabrica

//   int tam = objArchMesa.CantidadRegistros();

//   for(int i = 0; i < 20; i++){
//     for(int j = 0; j < tam; j++){
//       objServMesa = objArchMesa.Leer(j);
//       if(objServMesa.getIDMozo() == i+1){
//         if(objServMesa.getPuntajeObtenido() == 10 || objServMesa.getPuntajeObtenido() == 1){
//           vMozoConExtremo[i] = true;
//           break;
//         }
//       }
//     }  
//   }  

  

//   for(int i = 0; i < 20; i++) {
//     if(!vMozoConExtremo[i]) {
//         cout << "Mozo: " << i+1 << " nunca recibio puntaje 1 ni 10" << endl;
//     }
// }
// }

void Examen::Punto2ConVec(){
  ServicioMesa *vDinserv = nullptr;
  ArchivoServicioMesa objArch("restaurant.dat");

  bool vMozoSinPuntajeExtremo[20];
  for(int i = 0; i < 20; i++) {
      vMozoSinPuntajeExtremo[i] = true;
  }  
  
  int tam = objArch.CantidadRegistros();
  vDinserv = new ServicioMesa[tam];
  if(vDinserv == NULL) return;
  objArch.Leer(tam, vDinserv);

  for(int i = 0; i < 20; i++){
    for(int j = 0; j < tam; j++){
      if(vDinserv[j].getIDMozo() == i+1){
        if(vDinserv[j].getPuntajeObtenido() == 10 || vDinserv[j].getPuntajeObtenido() == 1){
          vMozoSinPuntajeExtremo[i] = false;
          break;
        } 
      } 
    }  
  }  

  for(int i = 0; i < 20; i++){
    if(vMozoSinPuntajeExtremo[i]){
        cout << "Mozo: " << i+1 << " nunca recibio puntaje 1 ni 10" << endl;
    }  
  }
}

//¿Qué números de mozo no obtuvieron nunca un puntaje de 10 pero tampoco un 1?
void Examen::Punto2(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa objArchServMesa("restaurant.dat");
  bool vMozoSin10Sin1[20] = {}; //hay 10 y hay 1

  for(int i = 0; i < 20; i ++){
    vMozoSin10Sin1[i] = true;
  }

  int tam = objArchServMesa.CantidadRegistros();

  for(int i = 0; i < tam; i ++){
     objServMesa = objArchServMesa.Leer(i);
     if(objServMesa.getPuntajeObtenido() == 10 || objServMesa.getPuntajeObtenido() == 1){
      vMozoSin10Sin1[objServMesa.getIDMozo()-1] = false;//also por que si tuvo 10 o 1
     }
  }

  for(int i = 0; i < 20; i ++){
    if(vMozoSin10Sin1[i]){
      cout << "El numero de mozo es: " << i +1 << endl;
    }
  }
}

//¿Qué plato se vendió más veces en el 2024 que en el 2023? => id plato es q se vendio
// void Examen::Punto3(){
//   ServicioMesa objServMesa;
//   ArchivoServicioMesa objArchMesa("restaurant.dat");
//   int vPlatoCont2023[70] = {};
//   int vPlatoCont2024[70] = {};

//   int tam = objArchMesa.CantidadRegistros();
//   for(int i = 0; i < tam; i++){
//     objServMesa = objArchMesa.Leer(i);
//     if(objServMesa.getFecha().getAnio() == 2023){
//       vPlatoCont2023[objServMesa.getIDPlato()-1]++;
//     }else if(objServMesa.getFecha().getAnio() == 2024){
//       vPlatoCont2024[objServMesa.getIDPlato()-1]++;
//     }  
//   }  

//   for(int i = 0; i < 70; i++){
//     if(vPlatoCont2024[i] > vPlatoCont2023[i]){
//       cout << "Plato: " << i+1 << " vendio " << vPlatoCont2024[i] << " vs " << vPlatoCont2023[i] << "" << endl;
//     }  
//   } 
  
//   //mostrar todos los resultado de los dos vectores
//   for(int i = 0; i < 70; i++){
//     cout << "Plato: " << i+1 << " vendio " << vPlatoCont2024[i] << " vs " << vPlatoCont2023[i] << "" << endl;
//   }  

// }

//¿Qué plato se vendió más veces en el 2024 que en el 2023? => id plato es q se vendio
void Examen::Punto3(){
  ServicioMesa objServMesa;
  ArchivoServicioMesa objArchServicioMesa("restaurant.dat");

  int vPlatoCont2024[70] = {};
  int vPlatoCont2023[70] = {};

  int tam = objArchServicioMesa.CantidadRegistros();

  for(int i = 0; i < tam; i ++){
    objServMesa = objArchServicioMesa.Leer(i);
    
    if(objServMesa.getFecha().getAnio() == 2024){
      vPlatoCont2024[objServMesa.getIDPlato()-1] ++;
    }

    if(objServMesa.getFecha().getAnio() == 2023){
      vPlatoCont2023[objServMesa.getIDPlato()-1] ++;
    }
  }

  //plato 1 se vendio 5 veces 2024 y 3 veces en 2023 => muestro el  1
  //plato 2 se vendio 1 vez en 2024 y 3 en 2023 => no muestro

  for(int i = 0; i < 70; i ++){
    if(vPlatoCont2024[i] > vPlatoCont2023[i]){
      cout << "plato " << i+1;
    }

  }
}