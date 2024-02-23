#include <iostream>

using namespace std;

int main(){
  char vCadena[30], letraAgregar;
  int posicion;

  cout << "Ingrese el texto: ";
  cin.getline(vCadena, 29);
  cout << endl << vCadena << endl;
  system("pause");

  cout << "ahora ingresela con el ciclo for: ";
  int x;
  bool bandera = false;
  for( x = 0; x < 30 && bandera == false; x ++)
  { 
    vCadena[x] = cin.get(); // lee un solo caracter

    if(vCadena[x] == '\n')
    {
      bandera = true;;
    }
  }
  vCadena[x] = '\0';

  cout << vCadena << endl;

  cout << "Ingrese la letra a agregar: ";
  cin >> letraAgregar;

  cout << "Ingrese la posicion de la letra a agregar ";
  cin >> posicion;

  //contador de indices
  int len = 0;
  while (vCadena[len] != '\0')
    len ++;
  
  char aux, aux2, temp;
  
  for(int x = len; x >= posicion -1; x--){
    vCadena[x+1] = vCadena [x];
  }

  vCadena[posicion-1] = letraAgregar; 
    
  cout << "La palabra es: " << vCadena;


  return 0;
}