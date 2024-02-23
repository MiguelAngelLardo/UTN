#include <iostream>

using namespace std;
/*
 sabiendo que A vale 65 y que Z vale 90
 el sueldo es de $70
 trabajo 100 hs que es un 'd'
 encontrar a que letra le corresponde 70 y el sueldo total en int
*/

int main (){
  char setenta;
  for(char letra = 'A'; letra <= 70; letra ++){
    setenta = letra;
  }

  cout << "El 70 vale: " << setenta << endl;

  int sueldo = setenta * 'd';

  cout << "EL sueldo es: " << sueldo;

  return 0;
}