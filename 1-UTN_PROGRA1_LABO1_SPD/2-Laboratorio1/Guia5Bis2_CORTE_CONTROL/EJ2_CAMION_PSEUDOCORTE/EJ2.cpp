//TP         : 05
//EJERCICIO  : 02
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

int main(void){
  const float PESO_MAXIMO=200; //Originalmente 200
  float peso, sumaPeso;
  int nroCamion=0, maxNroCamion, cantEncomiendas=0, maxCantEncomiendas=0;

  cout << "Ingresar peso: ";
  cin >> peso;

  while(peso > 0){
    sumaPeso = peso;
    cantEncomiendas=peso=0;
    nroCamion++;
    while((sumaPeso + peso) <= 200 && (peso >= 0)){
      cantEncomiendas++;
      sumaPeso += peso;
      cout << "Ingresar peso: ";
      cin >> peso;
    }
    if(cantEncomiendas > maxCantEncomiendas){
      maxCantEncomiendas = cantEncomiendas;
      maxNroCamion = nroCamion;
    }
    cout << endl << "PUNTO A" << endl;
    cout << "---------------" << endl;
    cout << "NRO DE CAMION: " << nroCamion << endl;
    cout << "PESO TOTAL   : " << sumaPeso << " Kg." << endl;
  }
  cout << endl << "PUNTO B" << endl;
  cout << "---------------" << endl;
  cout << "CAMION QUE TRANSPORTA MAYOR CANT DE ENCOMIENDAS: " << maxNroCamion << endl;
  cout << "CANTIDAD DE ENCOMIENDAS: " << maxCantEncomiendas;
  return 0;
}