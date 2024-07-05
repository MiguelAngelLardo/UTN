#include <iostream>

using namespace std;
/*Hacer un programa para ingresar dos números y que luego emita por pantalla
el mayor de ellos o un cartel aclaratorio “Son iguales” en el caso de que así sea.
Nota: los números pueden ser iguales.*/

int main(){
  int n1, n2;

  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese otro numero: ";
  cin >> n2;
  
  if(n1 > n2){
    cout << "El numero mayor es: " << n1;
  }
  else if(n2> n1){
    cout << "El numero mayor es: " << n2;
  }else{
    cout << "SON IGUALES";
  }

  /*if(n1 > n2)
  {
    cout << "El numero mayor es: " << n1;
  }
  else
  {    //5   5
    if(n2 > n1)
    {
      cout << "El numero mayor es: " << n2;
    }
    else
    {
      cout << "SON IGUALES";
    }
  }*/

  return 0;
}