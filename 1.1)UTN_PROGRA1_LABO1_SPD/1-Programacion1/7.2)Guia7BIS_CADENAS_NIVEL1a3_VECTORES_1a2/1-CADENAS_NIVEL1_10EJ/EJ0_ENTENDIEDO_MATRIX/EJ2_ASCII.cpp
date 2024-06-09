#include <iostream>
using namespace std;
/*
Realiza la rotacion de las 26 letras del ABCD
Se realizara la rotacion de la letra con la correspondiente 3 espacios mas arriba
letra original A - letra rotada D
letra original B - letra rotada E
*/

int main(){
  char A = 'A'; // A tiene valor ASCII 65
  char Z = 'Z'; // Z tiene valor ASCII 90

  cout << "Valor ASCII de A: " << (int)A << endl;
  cout << "Valor ASCII de Z: " << (int)Z << endl;
  
  // 65 = 1
  // 70 = 6 => me queda 1 desfazado
  // 75 = 11
  // 80 = 16
  // 85 = 21
  // 90 = 26

  // 65 = 0
  // 70 = 5
  // 75 = 10
  // 90 = 25
  int rango = Z - A + 1 ; // le sumo uno para que no quede en 25
  
  for (char letra = A; letra <= Z; letra++) {
    int valor = letra - A; // A - A = 0 | B - A = 1
    int indice = (valor + 3) % rango; // 0+3 % 26 = 3 | 1+3 % 26 = 4; por que el cociente es cero siempre
    char letra_rotada = A + indice; // 65 + 3 = 68 (D)| 65 + 4 (E)

    cout << "Letra original: " << letra << ", Letra rotada: " << letra_rotada << endl;
  }

  return 0;
}