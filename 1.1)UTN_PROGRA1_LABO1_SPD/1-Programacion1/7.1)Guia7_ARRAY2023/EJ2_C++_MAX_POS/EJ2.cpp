#include <iostream>

using namespace std;
/*
2. Hacer	un	programa	que	solicite 50	números	enteros	y	los	guarde en	un	vector.	Luego	recorrer	
los	elementos y	determinar	e	informar	cuál	es	el	valor máximo	y	su	posición	dentro	del	vector.
*/
const int TAM = 5;

int main(){
  int vNumero[TAM];
  
  for(int x = 0; x < TAM; x ++){
    cout << x+1 << "Ingrese un numero: ";
  }

  return 0;
}