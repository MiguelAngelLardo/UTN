#include <iostream>
using namespace std;
/*Leer TAM números y guardarlos en un vector. Calcular el promedio y luego
 mostrar por pantalla los valores que son mayores al promedio*/

//constante que tenga el numeero TAM y se llame TAM

const int TAM = 5;

void setearACero(int vec[]){
  
  for (int x = 0; x < 10; x++){
    vec[x]= 0;
  }
 }

 int main (){

  int vectorNum[TAM], acumVector=0;
  float promedio;

 setearACero(vectorNum);

  for (int x = 0; x < TAM; x++){
    cout << x+1 << ") Ingrese un numero: ";
    cin >> vectorNum[x];
  }

  for (int i = 0; i < TAM;  i++){
    acumVector += vectorNum[i];
    promedio = acumVector / TAM;
  }

  for (int y = 0; y < TAM; y++){
    if (vectorNum [y] > promedio){
      cout << vectorNum [y] << endl;
    }
  }



  return 0;
 }