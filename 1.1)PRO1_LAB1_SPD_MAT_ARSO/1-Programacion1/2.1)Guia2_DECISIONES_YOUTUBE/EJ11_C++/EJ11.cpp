#include <iostream>
using namespace std;

/*Hacer un programa para ingresar cuatro números y luego mostrar por pantalla
cuántos son menores a 100.*/

int main (){

  int n1, n2, n3, n4, contador = 0; //basura: valor residual en memoria 


  cout << "ingrese un numero: ";
  cin >> n1;
  cout << "ingrese otro numero: ";
  cin >> n2;
  cout << "ingrese otro numero: ";
  cin >> n3;
  cout << "ingrese otro numero: ";
  cin >> n4;


  if (n1 < 100){
    contador ++; //contador = contador + 1
  }

  if (n2 < 100){
    contador ++; //contador = contador + 1
  }

  if (n3 < 100){
    contador ++; //contador = contador + 1
  }

  if (n4 < 100){
    contador ++; //contador = contador + 1
  }

  cout << "La cantidad de numeros menores a 100 es: " << contador;

  return 0;
}
