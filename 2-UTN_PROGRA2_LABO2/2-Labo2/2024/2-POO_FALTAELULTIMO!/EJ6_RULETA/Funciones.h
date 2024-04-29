#pragma once

#include "Ruleta.h"

///DECLARO
Ruleta crearRuleta();
void cargarPremios(Ruleta &rul);
bool validarCargaPremios(Ruleta &rul);
void jugarRuleta(Ruleta &rul);


///DEFINO-IMPLEMENTO
Ruleta crearRuleta(){ ///Creo el puntero a Ruleta para que no se active el DESTRUCTOR dentro de la fx
  int cantPremios;
  cout << "Ingrese la cantidad de premios (1 hasta 50): ";
  cin >> cantPremios;
  while(cantPremios < 1 || cantPremios > 50){
    cout << "crearRuleta() => CANTIDAD INVALIDA, RECUERDE INGRESAR DESDE 1 HASTA 50. DISFRUTE DEL JUEGO!" << endl;
    cout << "INGRESE NUMERO: ";
    cin >> cantPremios;
  }

  return Ruleta(cantPremios);
}

void cargarPremios(Ruleta &rul){
  string premio;
  cin.ignore();//por que viene del enter de crearRuleta+
  bool cargaCompleta = false;

  while(!cargaCompleta){
    for(int x = 0; x < rul.getCantidadPremios(); x ++){
      printf("INGRESE EL PREMIO #%d: ", x+1);
      getline(cin, premio);
      rul.agregarPremio(premio, x);
    }

    cargaCompleta = validarCargaPremios(rul);
    if(!cargaCompleta){
      cout << "\nERROR EN LA CARGA DE DATOS!!! => CARGUE TODOS LOS DATOS !!\n";
    }
  }
}

bool validarCargaPremios(Ruleta &rul){
  for(int x = 0; x < rul.getCantidadPremios(); ++x){
    if(rul.getvPremios(x).empty()){ //emtpy() es metodo de la clase string => su la cadena esta vacia retorna true
      return false;
    }
  }
  return true;
}

void jugarRuleta(Ruleta &rul){
  int casillaDeRuleta;
  cout << "\nPRESIONE ENTER PARA GIRAR LA RULETA!!\n";
  system ("PAUSE");
  rul.girarRuleta();
  casillaDeRuleta = rul.getNumeroRand();


  cout << "PREMIOS DISPONIBLES\n";
  for(int x = 0; x < rul.getCantidadPremios(); ++x){
    cout << "PREMIO #" << x + 1 << " => " << rul.getvPremios(x) << endl;
  }

  cout << endl <<  "FELICIDADES TU PREMIO GANADO ES: " << rul.getvPremios(casillaDeRuleta);
}
