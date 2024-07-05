#include <iostream>
using namespace std;

/*Hacer un programa para ingresar cuatro números distintos y luego mostrar por
pantalla el menor de ellos.*/

int main (){

int n1, n2, n3, n4;
int menor;

cout << "ingrese un numero: ";
cin >> n1;
cout << "ingrese otro numero: ";
cin >> n2;
cout << "ingrese otro numero: ";
cin >> n3;
cout << "ingrese otro numero: ";
cin >> n4;

if (n1 < n2)
{
  menor = n1;
}
else 
{
  menor = n2;
}

if (n3 < menor)
{
  menor = n3;
}

if (n4 < menor)
{
  menor = n4;
}

cout << "El numero menor es: " << menor;

  return 0;
}