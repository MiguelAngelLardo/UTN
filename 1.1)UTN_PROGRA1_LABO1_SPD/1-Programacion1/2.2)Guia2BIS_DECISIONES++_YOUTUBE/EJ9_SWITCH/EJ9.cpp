#include <iostream>
using namespace std;


//Hermano del IF => es un hermano menor ( se usa menos) pero es optimo par algunas circunstancias - SWITCH-/


int main(){

  int opcionProcesador, opcionMemoria, opcionDisco;
  float montoFinal;
  


  cout << "Ingrese opcion del procesador (1, 2, 3): ";
  cin >> opcionProcesador;

  cout << "Ingrese opcion de la memoria (1, 2, 3): ";
  cin >> opcionMemoria;

  cout << "Ingrese aumento de disco (1-aumenta, 0-queda igual): ";
  cin >> opcionDisco;

  switch (opcionProcesador)
  {
    case 1:
      switch(opcionMemoria)
      {
        case 1: 
          montoFinal = 800;
          break;
        case 2:
          montoFinal = 900;
          break;
        case 3:
          montoFinal = 1000;
          break;
      }
      break;
    case 2:
      switch (opcionMemoria)
      {
        case 1: 
          montoFinal = 900;
          break;
        case 2: 
          montoFinal = 1000;
          break;
        case 3:
          montoFinal = 1400;
          break;
      }
      break;
    case 3:
      switch (opcionMemoria)
      {
        case 1:
          montoFinal = 1200;
          break;
        case 2:
          montoFinal = 1400;
          break;
        case 3:
          montoFinal = 2000;
          break;
      }
      break;  
  }

  /*if(opcionDisco){
    montoFinal = montoFinal + 300; // montoFinal += 300
  }*/
                             // verdadero              falso
  montoFinal = (opcionDisco) ? montoFinal + 300 : montoFinal;

  cout << "\nMonto total es: $" << montoFinal << ".-\n"; 

  //ESCAPAR AL CARACTER = "\" + algo => \n = salto de linea

  return 0;
}