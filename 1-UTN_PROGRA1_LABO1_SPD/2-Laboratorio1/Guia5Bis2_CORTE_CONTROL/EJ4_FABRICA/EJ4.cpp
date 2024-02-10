#include <iostream>

using namespace std;

int main(){

  int planta, plantaAnterior, legajo, dia, edad, cantProd;
  char sexo, zonaUbic;

  int acumPTA = 0; // PTA
  int acumZonaN = 0, acumZonaS = 0, acumZonaO = 0, zonaNMax = 0, zonaSMax = 0, zonaOMax = 0, plantaNMax, plantaSmax, plantaOmax; // PTOB
  int maxOperario, maxPlanta, maxCantidad = 0; //PTOC
  char maxZona;//PTOC
  int acumMaxProducto = 0;

  cout << "Ingrese el numero de planta (1 a 20)(CORTA CON CERO): ";
  cin >> planta;
  
  while (planta != 0)
  {
    plantaAnterior = planta;
    cout << "PLANTA ACTUAL: " << plantaAnterior << endl;

    while(plantaAnterior == planta)
    {
      cout << "Ingrese la zona de ubicacion de la planta (N-S-O): ";
      cin >> zonaUbic; 
      zonaUbic = toupper(zonaUbic);
      cout << "Ingrese el legajo del operario (1 a 1000): ";
      cin >> legajo;
      cout << "Ingrese el dia (1 a 31): ";
      cin >> dia;
      cout << "Ingrese la edad: ";
      cin >> edad;
      cout << "Ingrese el sexo (F-M): ";
      cin >> sexo;
      sexo = toupper(sexo);
      cout << "Ingrese la cantidad de productos fabricados en el dia: ";
      cin >> cantProd;
      
      //PTOA
      acumPTA += (dia >= 1 && dia <= 15 && edad < 35 && sexo == 'M') ? cantProd : 0;

      //PTOB
      switch (zonaUbic)
      {
      case 'N':
        acumZonaN += cantProd;
        break;
      case 'S':
        acumZonaS += cantProd;
        break; 
      case 'O':
        acumZonaO += cantProd;
        break;   
      }

      //PTO C
      if(cantProd > maxCantidad){
        maxCantidad = cantProd;
        maxPlanta = plantaAnterior;
        maxZona = zonaUbic;
        maxOperario = legajo;
      }

      cout << "Ingrese el numero de planta (1 a 20)(CORTA CON CERO): ";
      cin >> planta;
    } 

    //PTO B
    if(acumZonaN > zonaNMax){
      zonaNMax = acumZonaN;
      plantaNMax = plantaAnterior;
    }
    if(acumZonaS > zonaSMax){
      zonaSMax = acumZonaS;
      plantaSmax = plantaAnterior;
    }
    if(acumZonaO > zonaOMax){
      zonaOMax = acumZonaO;
      plantaOmax = plantaAnterior;
    }

    acumMaxProducto = acumZonaN + acumZonaS + acumZonaO;// PTOD
  }

  cout << endl << "PTO A: Cantidad de productos fabricados en total: " << acumPTA << endl;
  cout << "PTO B: NUMERO PLANTA ZONA N: " << plantaNMax << " - PLANTA ZONA S " << plantaSmax << " - PLANTA ZONA O " << plantaOmax << endl;
  cout << "PTOC: EL operario que mas producto hizo es: " << maxOperario << " - La planta es: " << maxPlanta << " - La zona es: " << maxZona << endl;
  cout << "PORCENTAJE PRODUCCION -> ZONA N " << acumZonaN * 100 / acumMaxProducto << "%" << endl; 
  cout << "PORCENTAJE PRODUCCION -> ZONA S " << acumZonaS * 100 / acumMaxProducto << "%"<< endl;
  cout << "PORCENTAJE PRODUCCION -> ZONA O " << acumZonaO * 100 / acumMaxProducto << "%" << endl; 
 
  return 0;
}