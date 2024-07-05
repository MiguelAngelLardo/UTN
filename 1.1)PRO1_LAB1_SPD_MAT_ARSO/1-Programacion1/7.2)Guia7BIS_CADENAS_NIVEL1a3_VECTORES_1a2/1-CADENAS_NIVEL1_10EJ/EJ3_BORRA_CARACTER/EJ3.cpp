#include <iostream>

using namespace std;

int main(){
  char vPalabra[50], letra1;

  cout << "Ingrese la cadena de caracter: "; 
  cin.getline(vPalabra, 50);

  int len = 0;
  while (vPalabra [len] != '\0')
  {
    len ++;
  }

  cout << "La cadena tiene un total de " << len << " palabras." << endl;
  system("pause");

  cout << "Ingrese la letra que quiere borrar: ";
  cin >> letra1;

  int nuevoIndice = 0;
  for(int x = 0; x < len; x ++)
  {
    if(vPalabra[x] != letra1)
    {
      vPalabra[nuevoIndice] = vPalabra [x];
      nuevoIndice ++;
    }
  }

  
  cout << "La palabra es: ";
  cout << vPalabra;


  return 0;
}