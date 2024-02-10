#include <iostream>

using namespace std;
/*Hacer un programa para ingresar cuatro números distintos y luego mostrar por
pantalla el mayor de ellos.*/
int main(){
  int n1, n2, n3, n4;
  int mayor;

  cout << "ingrese un numero: ";
  cin >> n1;
  cout << "ingrese otro numero: ";
  cin >> n2;
  cout << "ingrese otro numero: ";
  cin >> n3;
  cout << "ingrese otro numero: ";
  cin >> n4;

  if (n1 > n2 )
  {
   mayor = n1;
  }
  else 
  {
    mayor =  n2;
  }

  if (n3 > mayor)
  {
    mayor = n3;
  }

  if (n4 > mayor)
  {
    mayor = n4;
  }

  cout << "El numero mayor es: " << mayor;

  return 0;
}