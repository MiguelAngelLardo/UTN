#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  char vChain[50] = {};

  cout << "Enter the character string: ";
  cin.getline(vChain, 50);  

  for (int x = 0; x < 50; x ++){
    if(vChain[x] != 0)
      cout << "Character #" << x+1 << " is: " << vChain[x] << endl;
  }



  return 0;

}