//TP         : 06 sugeridos
//EJERCICIO  : 04
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

long double calcularFactorial(short n){
  long double fact=1;
  short i;
  for(i=1; i<=n; i++){
    fact*=i;
  }
  return fact;
}

int main(void){
  long double resultado;
  short num;
  cout << "Ingresar el numero a calcular su factorial: ";
  cin >> num;
  if(num>0){
    resultado = calcularFactorial(num);
    cout << endl << "RESULTADO: " << resultado;
  }
  else{
    cout << endl << "SOLO FUNCIONA CON NUMEROS NATURALES.";
  }

  return 0;
}
