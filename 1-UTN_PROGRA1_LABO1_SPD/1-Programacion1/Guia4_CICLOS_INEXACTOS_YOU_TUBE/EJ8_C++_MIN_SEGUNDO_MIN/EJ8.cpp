#include <iostream>
using namespace std;

/*Hacer un programa que solicite una lista de números que corta cuando se
ingresa un cero y luego mostrar por pantalla el menor y el segundo menor.*/

int main (){

  int numeros, primerMenor, segundoMenor;
  bool banderaMenor = false;

  cout << "Ingrese los numeros: ";
  cin >> numeros;
  //primerMenor = numeros;

  while (numeros != 0){

    if(!banderaMenor){ // bandera == false
      segundoMenor = 0; 
      primerMenor = numeros;
      banderaMenor = true;
    }else if(numeros < primerMenor){
      segundoMenor = primerMenor;
      primerMenor = numeros;
    }else if(numeros < segundoMenor){
      segundoMenor = numeros;
    }

    cout << "Ingrese los numeros: ";
    cin >> numeros;
  }

  cout << "El primer menor es: " << primerMenor << endl;
  printf("El segundo menor es %d", segundoMenor);

  return 0;
}