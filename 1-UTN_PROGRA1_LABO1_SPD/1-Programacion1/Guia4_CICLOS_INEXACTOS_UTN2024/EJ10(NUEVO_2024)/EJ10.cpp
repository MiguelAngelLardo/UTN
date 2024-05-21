#include <iostream>

using namespace std;

/*
10 Hacer un programa para ingresar una lista de números que finaliza cuando se
ingresa un cero, luego informar el máximo y el mínimo.

Ejemplo A: 10, 20, -5, 30,-15, 5, 42, 2, 22, -13, 0. -> Se listará Máximo 42 Mínimo -15.
Ejemplo B: 10, 20, 5, 30, 15, 5, 42, 8, 22, 13, 0. -> Se listará Máximo 42 Mínimo 5.
Ejemplo C: -10, -20, -5, -30, -15, -12, -42, -8, -22, -13, 0. -> Se listará Máximo -5 Mínimo -42.

Observe que los ejemplos B y C dejan en claro que la suposición de que el máximo “seguramente” es un positivo y el mínimo “seguramente” es un  negativo, es incorrecta.

*/

int main(){
  int n, max, min;
  bool bandera =  false;//0

  cout << "Ingrese un numero: "; 
  cin >> n;

  while (n != 0){

    if(bandera == false){
      max = n;
      min = n;
      bandera = true;//1
    }else if (n > max){
      max = n;
    }else if (n < min){
      min = n;
    }
    
    cout << "Ingrese un numero: ";
    cin >> n;
  }
  
    cout << "El numero maximo es: " << max << endl;
    cout << "El numero minimo es: " << min;

  return 0;
}