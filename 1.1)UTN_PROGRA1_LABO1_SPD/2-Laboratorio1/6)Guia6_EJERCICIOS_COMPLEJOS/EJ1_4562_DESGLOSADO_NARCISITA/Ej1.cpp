#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{

  int num, digito, contador=0, contadorPar=0, acumulador=0;

  cout << "Ingrese un numero: ";
  cin >> num;

  if(num < 0){
      num = -num;
  }

  int variable = num; //AL num lo divido por 10 y ese num se cambia, por eso lo guardo antes en variable. 
  cout << "Los digitos del numero son: " << endl;
  while (num>0)
  {
      digito = num%10; //si pongo 153 me queda un 3
      cout << digito<< endl;

      if(digito%2 == 0){
          contadorPar ++;
      }

      acumulador += digito*digito*digito;//vuelta 1 hace 1^3, vuelta 2 5^3, vuelta 3 3^3
      num = num / 10; // si pongo 153 me da 15
      contador++;
  }

  cout << endl << "PUNTO 1.A";
  if(contador == contadorPar){
    cout << endl << "Los digitos son todos pares" << endl;
  }else{
    cout << endl <<"No todos los digitos son pares" << endl;
  }

  cout << endl << "PUNTO 1.B" << endl;
  if(acumulador == variable){
      cout << "Es un numero narcisista" << endl;
  }else{
      cout << "No es un numero narcisita" << endl;
  }

  int aux = 0, invertido = 0, digit;
  cout << endl << "PUNTO 1.C" << endl;
  while (variable != 0)
  {
    aux = variable % 10;//aux = 3 - aux = 5 - aux = 1
    invertido = invertido * 10;//invertido = 0 - invertido = 30, invertido = 350 
    invertido = invertido + aux;//invertido = 3 - invertido = 35 - invertido = 351
    variable = variable / 10; //15 - 1 - 0
  }
  variable = invertido; // variable = 351

  while (variable != 0){
    digit = variable % 10; //351%10 = 1
    cout << digit << endl;
    variable = variable / 10; // 351 = 35
  }

 return 0;

}