//TP         : 06 Sugeridos
//EJERCICIO  : 01
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: Teniendo en cuenta exponentes negativos.
#include <iostream>
using namespace std;

float calcularPotencia(int base, int exponente){
  float resultado=1;
  bool exponenteNegativo = false;
  if (exponente < 0){
    exponenteNegativo = true;
    exponente *= -1;
  }
  for(int i=1; i<=exponente; i++){
    resultado = resultado * base;
  }
  if (exponenteNegativo){
    return 1/resultado;
  }
  return resultado;
}

int main(void){
  int b, e;
  float resultado;

  cout << "INGRESAR BASE: ";
  cin >> b;
  cout << "INGRESAR EXPONENTE: ";
  cin >> e;
  resultado = calcularPotencia(b, e);
  cout << endl << "EL RESULTADO ES: " << resultado;
  return 0;
}
