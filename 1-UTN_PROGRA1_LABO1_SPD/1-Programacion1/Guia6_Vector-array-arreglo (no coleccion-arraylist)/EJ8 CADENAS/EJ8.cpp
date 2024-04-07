#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  char vChain[50] = {}, character;

  cout << "Enter the character string: ";
  cin.getline(vChain, 50);
  cout << "Enter de caracter to match: ";  
  cin >> character;  

  int position = 0;
  bool firstMatch = false;
  for (int x = 0; x < 50; x ++){
    position ++;
    if(vChain[x] == character && firstMatch == false){
      cout << "The Character '" << character << "' was in " << position << " position." << endl;
      firstMatch = true;   
    }  
  }

  if(!firstMatch)
    cout << "-1";

  return 0;

}