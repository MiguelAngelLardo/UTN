#include <iostream>
using namespace std;
/*Hacerunafunción llamada EsPrimoSophieGermain que reciba un número
 entero y determine si el mismo es un número primo de Sophie Germain. Debe
 devolver verdadero si lo es y falso si no lo es.
 NOTA: En teoría de números, se dice que un número natural es un número
 primo de Sophie Germain, si el número n es primo y 2*n+1 también lo es.
Ejemplo:
 El número 2 es número primo de Sophie Germain porque:
 2 es primo
 2*2+1 → 5 es primo.
 Hacer un programa para ingresar un número y, utilizando
 EsPrimoSophieGermain, emita luego un cartel indicando si el número
 ingresado es primo Sophie Germain o no lo es.*/

bool esPrimoSophieGermain (int num){
  int prePrimo = 0;
  int sophieGermain;

  if (num <= 1){return false;}

  for (int x = 1; x <= num; x++ ){
    if(num % x == 0){prePrimo++;}
  }  

    if (prePrimo == 2){
        sophieGermain = 2*num+1;
    }

    prePrimo = 0;
    for(int x = 1; x <=sophieGermain; x ++){
        if(sophieGermain % x == 0){
        prePrimo++;
        }
    }

    return (prePrimo == 2) ? true : false;
    
  
}

 int main(){
  int num, resultado;

  cout << "Ingrese un numero: ";
  cin >> num;
  resultado = esPrimoSophieGermain (num);

  if (resultado == true){
    cout << "Es primo Sophie Germain" << endl;
  }else {
    cout << "No es primo Sophie Germain";
  }



  return 0;
 }