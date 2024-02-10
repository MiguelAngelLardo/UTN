#include <iostream>
#include "Bidon.h"

using namespace std;


int main(){
  Bidon b(20000, "BANANA"), a(35000, "ANANA"), c(44000, "SANDIA");
  Vaso vVasos [3] = {Vaso(150), Vaso(200), Vaso(300)};
  
  b.cargar();
  cout << "B: " << b.getSabor() << " - " << b.getCapacidad() << endl;
  b.servir(vVasos[0]);
  cout << "B: " << b.getSabor() << " - " << b.getCapacidad() << endl;
  b.servir(vVasos[1]);
  b.servir(vVasos[2]);
  cout << "B: " << b.getSabor() << " - " << b.getCapacidad() << endl;


  
  
  /*string vSabores[3] = {"Banana", "Anana", "Samdia"};
  int vBidones[3] = {20000, 35000, 44000};
  int vVasos[3] = {150, 200, 300};
  int vCantidad[3] = {};

  int codigoBatido, tipoVaso;

  cout << "Ingrese codigo de batido: ";
  cin >> codigoBatido;

  while(codigoBatido != 0)
  {
    cout << "Ingrese el tipo de vaso: ";
    cin >> tipoVaso;

    if(vBidones[codigoBatido-1] >= vVasos[tipoVaso-1]){
      vBidones[codigoBatido-1] -= vVasos[tipoVaso-1];
      vCantidad[codigoBatido -1] ++;
    }else{
      cout << "No te puedo servir del sabor " << vSabores[codigoBatido - 1] << " ya quedan " << vBidones[codigoBatido-1] << " mili litros" <<  endl;
    }  

  
    
    
    cout << "Ingrese codigo de batido: ";
    cin >> codigoBatido;
  }

  for (int i = 0; i < 3; i ++){
    cout << "Bidon #" << vSabores[i] << ": " << vBidones[i]/1000.0f << " litros" << endl;
    cout << "Se vendieron: " << vCantidad[i] << endl;
  }*/


  return 0;
}