#include <iostream>

using namespace std;
/*Hacer un programa para ingresar por teclado una palabra y luego contar cuantas
 veces aparece el carácter ‘a’ en la misma
*/
int main ()
{
  char vLetras[10];

  cout << "Ingrese una palabra: ";
  cin.getline(vLetras, 10);
  
  int contadorA = 0, a = 0;
  while (vLetras[a] != '\0')
  {
    if(vLetras[a] == 'a')
      contadorA ++;

    a++;  
  }

  cout << "Palabra ingresada: " << vLetras << endl;
  cout << "Numero de letras 'a': " << contadorA ;


 return 0; 
}