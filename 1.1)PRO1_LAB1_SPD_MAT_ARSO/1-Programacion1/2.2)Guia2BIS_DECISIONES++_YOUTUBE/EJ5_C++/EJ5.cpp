#include <iostream>

using namespace std;

/*5. Hacer un programa que solicite el ingreso de las notas del primer parcial y del
segundo parcial de una alumna de programación. El programa deberá analizar
las notas y emitir la situación de la alumna según la siguiente escala:
a. Si tiene 8 o más en ambos parciales, emitir “aprobación directa”.
b. Si no tiene 8 o más en ambos pero tiene aprobados ambos parciales (se
aprueba con 6 o más), emitir “rinde examen final”.
c. Si tiene menos de 6 en alguno de los dos parciales, emitir “debe
recuperar”.
El programa debe emitir solo un cartel, el que corresponda.*/

int main (){

  int primerParcial, segundoParcial;

  cout << "Ingrese la nota del primer parcial: ";
  cin >> primerParcial;
  cout << "Ingrese la nota del segundo parcial: ";
  cin >> segundoParcial;

  //operador logico && ||  !(niego)

  //operador de comapracion < > <= >= == !=


  if(primerParcial >= 8 && segundoParcial >= 8){
    cout << "Aprobacion directa";
  }else if(primerParcial >= 6 && segundoParcial >=6){
    cout << "Rinde examen final";
  }else{
    cout << "Debe recuperar";
  }
  
  return 0;
}