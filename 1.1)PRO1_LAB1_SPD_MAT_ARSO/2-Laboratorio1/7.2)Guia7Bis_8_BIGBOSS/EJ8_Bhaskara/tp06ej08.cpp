//TP         :
//EJERCICIO  :
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;
#include <cmath>

short funcionCuadratica(int a, int b, int c, float *x1, float *x2){
  float raiz;
  if(a==0){
    return -1; //Dividirá por cero.
  }
  else{
    raiz = (b*b) - 4 * a * c;
    if(raiz < 0){
      return -2; //Raíz negativa
    }
    else{ //Calcular x1 y x2
      *x1 = (-b - sqrt(raiz)) / (2*a);
      *x2 = (-b + sqrt(raiz)) / (2*a);
    }
  }
  return 1;
}

int main(void){
  int a, b, c, res;
  float x1, x2;
  cout << "Ingresar el valor de a: ";
  cin >> a;
  cout << "Ingresar el valor de b: ";
  cin >> b;
  cout << "Ingresar el valor de c: ";
  cin >> c;

  res = funcionCuadratica(a, b, c, &x1, &x2);
  cout << endl;
  if(res>0){
    cout << endl << "RAICES: ";
    cout << endl << "X1: " << x1;
    cout << endl << "X2: " << x2;
  }
  else if(res == -1){
    cout << endl << "EL VALOR a NO PUEDE SER CERO.";
  }
  else if(res == -2){
    cout << endl << "NO SE PUEDE CALCULAR UNA RAIZ NEGATIVA.";
  }
  return 0;
}
