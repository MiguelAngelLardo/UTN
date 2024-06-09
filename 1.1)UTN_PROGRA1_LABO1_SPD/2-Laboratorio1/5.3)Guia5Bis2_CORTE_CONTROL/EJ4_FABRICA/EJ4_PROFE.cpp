//TP         : 05
//EJERCICIO  : 04
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -

#include <iostream>

using namespace std;

int main(void){
  int nroPlanta, nroPlantaAnt, legajo, dia, edad, cantProd;
  char sexo, zona;

  //PUNTO A
  int cph35=0;
  //PUNTO B
  int totalPlanta=0;
  int maxPlantaN=0, maxCPlantaN=0, maxPlantaS=0, maxCPlantaS=0, maxPlantaO=0, maxCPlantaO=0;
  //PUNTO C
  int maxCantProd=0, maxPlanta=0, maxLegajo=0;
  char maxZona;
  //PUNTO D
  int totalProd=0, cantProdN=0, cantProdS=0, cantProdO=0;

  cout << "Ingresar numero de planta: ";
  cin >> nroPlanta;
  while(nroPlanta < 0 || nroPlanta > 20){
    cout << "-- Reingresar numero de planta: ";
    cin >> nroPlanta;
  }

  while(nroPlanta != 0){
    nroPlantaAnt = nroPlanta;
    totalPlanta=0;
    cout << "Ingresar zona de ubicacion: ";
    cin >> zona;
    while(toupper(zona) != 'N' && toupper(zona) != 'S' && toupper(zona) != 'O'){
      cout << "-- Reingresar zona de ubicacion: ";
      cin >> zona;
    }
    while(nroPlanta == nroPlantaAnt){
      cout << "Ingresar legajo: ";
      cin >> legajo;
      while(legajo < 1 || legajo > 1000){
        cout << "-- Reingresar legajo: ";
        cin >> legajo;
      }
      cout << "Ingresar dia: ";
      cin >> dia;
      while(dia < 1 || dia > 31){
        cout << "-- Reingresar dia: ";
        cin >> dia;
      }
      cout << "Ingresar edad: ";
      cin >> edad;
      cout << "Ingresar sexo: ";
      cin >> sexo;
      while(toupper(sexo) != 'F' && toupper(sexo) != 'M'){
        cout << "-- Reingresar sexo: ";
        cin >> sexo;
      }
      cout << "Ingresar cantidad de productos: ";
      cin >> cantProd;

      //PUNTO A
      if((edad < 35) && (dia >= 1 && dia <=15) && toupper(sexo)=='M'){
        cph35+=cantProd;
      }
      //PUNTO B-D
      totalPlanta+=cantProd;
      //PUNTO C
      if(cantProd > maxCantProd){
        maxCantProd = cantProd;
        maxPlanta = nroPlanta;
        maxZona = zona;
        maxLegajo = legajo;
      }
      cout << "Ingresar numero de planta: ";
      cin >> nroPlanta;
      while(nroPlanta < 0 || nroPlanta > 20){
        cout << "-- Reingresar numero de planta: ";
        cin >> nroPlanta;
      }
    }
    //PUNTO B-D
    totalProd+=totalPlanta; //PUNTO D
    switch(zona){
      case 'n':
      case 'N':
        cantProdN+=totalPlanta; //PUNTO D
        if(totalPlanta > maxCPlantaN){ //PUNTO B
          maxCPlantaN = totalPlanta;
          maxPlantaN = nroPlantaAnt;
        }
      break;
      case 's':
      case 'S':
        cantProdS+=totalPlanta; //PUNTO D
        if(totalPlanta > maxCPlantaS){ //PUNTO B
          maxCPlantaS = totalPlanta;
          maxPlantaS = nroPlantaAnt;
        }
      break;
      case 'o':
      case 'O':
        cantProdO+=totalPlanta; //PUNTO D
        if(totalPlanta > maxCPlantaO){ //PUNTO B
          maxCPlantaO = totalPlanta;
          maxPlantaO = nroPlantaAnt;
        }
      break;
    }

  }
  cout << endl << "PUNTO A" << endl;
  cout << "------------------" << endl;
  cout << "CANTIDAD DE PRODUCTOS FABRICADOS: " << cph35 << endl;

  cout << endl << "PUNTO B" << endl;
  cout << "------------------" << endl;
  cout << "PLANTA ZONA NORTE" << endl;
  cout << "NRO PLANTA: " << maxPlantaN << endl;
  cout << "PLANTA ZONA SUR" << endl;
  cout << "NRO PLANTA: " << maxPlantaS << endl;
  cout << "PLANTA ZONA OESTE" << endl;
  cout << "NRO PLANTA: " << maxPlantaO << endl;

  cout << endl << "PUNTO C" << endl;
  cout << "----------------" << endl;
  cout << "LEGAJO: " << maxLegajo << endl;
  cout << "PLANTA: " << maxPlanta << endl;
  cout << "ZONA  : " << maxZona << endl;

  cout << endl << "PUNTO D" << endl;
  cout << "----------------" << endl;
  if(totalProd > 0){
    cout << "ZONA NORTE: " << ((float) cantProdN / totalProd)*100 << endl;
    cout << "ZONA SUR  : " << ((float) cantProdS / totalProd)*100 << endl;
    cout << "ZONA OESTE: " << ((float) cantProdO / totalProd)*100 << endl;
  }
  return 0;
}