#include <iostream>

using namespace std;

int main()
{
  int n1, n2;

  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese otro numero(DISTINTO): ";
  cin >> n2;

  // < - > - <= - >= - == - !=
  //5    3
  if(n1 < n2) //3    5
  {
    cout << "El numero menor es: " << n1;
  }
  else
  {
   cout << "El numero menor es: " << n2;
  }

  return 0;
}


/*Hacer un programa para ingresar dos números distintos y luego se muestre por
pantalla el menor de ellos.*/