#include <iostream>
using namespace std;

/*Hacer un programa que solicite UN número y luego calcule y emita un cartel
aclaratorio si el mismo es primo o no es primo.
Nota: un numero es primo cuando es divisible únicamente por 1 y por sí
mismo.*/

int main (){
  
  int n, contador = 0;
  cout << "Ingrese un numero: ";
  cin >> n;

  for (int x = 1; x <= n; x ++)
  {
    /*if(n % x == 0){
      contador ++;
    }*/
    contador += (n % x == 0) ? 1:0;   
  }

  /*if(contador == 2){
    cout << "Es primo";
  }else{
    cout << "No es primo";
  }*/

  //(contador == 2) ? cout << "es primo" : cout << "no es primo";
  cout << (contador == 2 ? "Es primo" : "No es primo");



  return 0;
}