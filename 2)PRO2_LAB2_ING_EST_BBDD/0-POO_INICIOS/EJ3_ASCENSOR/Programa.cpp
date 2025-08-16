#include "Programa.h"

#include <iostream>
using namespace std;

//ES AGNOSTICO De como se CREA
//A-Pedirlo por teclado B-Escaneo codigo Barra C-HardCodeo 
Ascensor Programa::crearAscensor(){
  int pisoMin, pisoMax, pisoInicio, capMax, cantOcupas;

  cout << "Ingrese el piso minimo de su edificio: ";
  cin >> pisoMin;
  cout << "Ingrese el piso max: ";
  cin >> pisoMax;
  cout << "Ingrese el punto de INICIO: ";
  cin >> pisoInicio;
  cout << "Ingrese la capacidad MAXIMA: ";
  cin >> capMax;
  cout << "Ingrese la cantidad de OCUPANTES: ";
  cin >> cantOcupas; 
  Ascensor aux(pisoMin, pisoMax, pisoInicio, capMax, cantOcupas);


  return aux;
}


void Programa::ejecutar(){
  int pisoDestino;//PTOA
  bool flagDestino;//PTOA
  int subirPersonas;//PTOB
  int bajarPersonas;//PTOC 
  
  cout << "ESTAS EN EL PROGRAMA DEL ASCENSOR" << endl;
  Ascensor a1 = crearAscensor();  
  
  cout << "------------------------------" << endl;
  cout << a1.toString() << endl;
  cout << "------------------------------" << endl;

  int opcion; 
  do{
    cout << "\nIngrese la opcion (1-Desplazarse, 2-Subir Personas, 3-Bajar Personas): ";
    cin >> opcion;
    
    switch(opcion)
    {
      case 1:
        do{
          cout << "Ahora ingrese a donde se quiere desplazar(entre " << a1.getPisoMin() << " y " << a1.getPisoMax() << "): ";
          cin >> pisoDestino;
          flagDestino =  a1.desplazamiento(pisoDestino); //me da true si esta entre los valores correctos
          (!flagDestino) ? cout << "INCORRECTO- BY THE WAY!\n" : cout << "CORRECTO\n"; 
          //cout << (!flagDestino ? "INCORRECTO - BY THE WAY!\n" : "CORRECTO\n");
          //printf("%s\n", (!flagDestino ? "INCORRECTO - BY THE WAY!" : "CORRECTO"));
        }while(!flagDestino);       
      break;

      case 2:
        cout << "Cuantas personas quieren subir? (MAXIMAS " << a1.getCapacidadMaxima() << " | ACTUALMENTE HAY " << a1.getOcupantes() << " personas): ";
        cin >> subirPersonas;
        a1.subirPersonas(subirPersonas);
        while(!(subirPersonas <= a1.getOcupantes()))
        {
          cout << "La cantidad de personas no entran." << endl;
          cout << "Hay " << a1.getOcupantes() << " - CAP MAX: " << a1.getCapacidadMaxima() << " - USTED QUIERE ENTRAR A " << subirPersonas << endl;
          cout << "Cuantas personas quieren subir? (MAXIMAS " << a1.getCapacidadMaxima() << " | ACTUALMENTE HAY " << a1.getOcupantes() << " personas): ";
          cin >> subirPersonas;
          a1.subirPersonas(subirPersonas);
        }

        cout << "Pueden subir las " << subirPersonas << " personas" << endl;
        cout << "Personas totales: " << a1.getOcupantes() << endl;
      break;  

      case 3:
      cout << "Cuantas personas quiere bajar? (AHORA HAY " << a1.getOcupantes() <<"): ";
      cin >> bajarPersonas;
      a1.setOcupantes(a1.bajarPersonas(bajarPersonas));
      cout << "------------------------------" << endl;
      cout << a1.toString() << endl;
      cout << "------------------------------" << endl;
      break;

      case 0:
        cout << "Saliendo del programa." << endl;
      break;

      default:
      cout << "Opcion no válida. Intente de nuevo." << endl;
    }    
  }while(opcion != 0);

}
