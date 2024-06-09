#include <iostream>
using namespace std;

int main() 
{
  int pesoEncomienda, contNumeroCamion = 0, maximaEncomienda = 0, camionMaximaEncomienda;

  cout << "Ingrese el peso de la encomienda: ";
  cin >> pesoEncomienda;

  while(pesoEncomienda > 0)
  {
    
   int pesoCamion = 0, contadorEncomiendas = 0;
   contNumeroCamion ++;

   while(pesoEncomienda + pesoCamion <= 200 && pesoEncomienda > 0)
   {
    pesoCamion += pesoEncomienda;
    contadorEncomiendas ++;

    cout << "Ingrese el peso de la encomienda: ";
    cin >> pesoEncomienda;
   }

   if(contadorEncomiendas > maximaEncomienda){
    maximaEncomienda = contadorEncomiendas;
    camionMaximaEncomienda = contNumeroCamion;
   }

    cout << "El camion " << contNumeroCamion << " traslada " << pesoCamion << "kg. " << endl;
 
  }

  cout << "Max encomiendas: camion " << camionMaximaEncomienda << " con " << maximaEncomienda << " encomiendas." << endl;  
  cout << "La cantidad de camiones totales es: " << contNumeroCamion << endl;

 
  return 0;
}