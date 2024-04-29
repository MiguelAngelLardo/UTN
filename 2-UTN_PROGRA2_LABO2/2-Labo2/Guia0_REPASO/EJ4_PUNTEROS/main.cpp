#include <iostream>
using namespace std;

int main(){
  float peso = 55.5;
  float *punteroPeso;

  punteroPeso = &peso;

  cout << "El peso que angel quiere tener es: " << peso << endl;
  cout << "&Peso: " << &peso << endl;
  cout << endl << "punteroPeso: " << punteroPeso << endl;
  cout << endl << "*punteroPeso: " << *punteroPeso << endl;
  cout << "&punteroPeso: " << &punteroPeso << endl;

  *punteroPeso = 77;
   cout << "Peso: " << peso << endl;

  return 0;
}