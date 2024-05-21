#include <iostream>

/*1 Hacer un programa para ingresar una lista de 10 números y luego informar
cuántos de los números ingresados son perfectos. Se informa 1 resultado al
final.*/

//ciclos combinados de DOS FOR

using namespace std;


int main(){

  int n;
  int contadorNumPerfc = 0;// por que contas el total de todo el grupo
  int acumuladorDivisoresValidadores;

  
  for (int x = 0; x < 10; x++ ){
    cout << "Ingrese los numeros: "; 
    cin >> n;

    acumuladorDivisoresValidadores = 0;
    for(int i = 1; i < n; i ++){
       if(n % i == 0){
         acumuladorDivisoresValidadores += i;
       }
    }

    if(n == acumuladorDivisoresValidadores){
      contadorNumPerfc ++;
    }   
 
  }
  

  cout << "La cantidad de numeros perfectos es: " << contadorNumPerfc;
  return 0;
}
