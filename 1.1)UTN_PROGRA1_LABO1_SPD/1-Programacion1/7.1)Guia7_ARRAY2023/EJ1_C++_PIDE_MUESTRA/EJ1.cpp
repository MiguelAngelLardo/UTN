#include <iostream>

using namespace std;
/*
1. Hacer	un	programa	que	solicite 50	números	enteros	y	los	guarde en	un	vector.	Luego	recorrer	
el	vector	y	determinar	e	informar	cuál	es	la	suma de	los	valores	del	mismo.
*/

const int TAM = 5;
int main (){
  int vNumero[TAM];
  int acum = 0;

  for(int x = 0; x < TAM; x ++){
    cout << x+1 << ")Ingrese un numero: ";
    cin >> vNumero[x];
  }

  for(int x = 0; x < TAM; x ++){
    acum += vNumero[x];
  }

  cout << acum;

  return 0;
}