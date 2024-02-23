#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
   char vChain[50], character1, character2, l;

  int x = 0;
  cout << x + 1 << ")Enter the character string(FINISH WHIT ';'): ";
  cin >> l;
  while(l != ';'){
    vChain[x] = l;
    x ++;

    cout << x + 1 << ")Enter the character string(FINISH WHIT ';'): ";
    cin >> l;
    cin.ignore(); // Ignora el carácter de nueva línea

  }
  vChain[x] = '\0';  // Asegúrate de que la cadena esté terminada con '\0'

  cout << endl << "Enter the character to remuve: ";
  cin >> character1;
  cout << "Enter the character to insert: ";
  cin >> character2;

  for (int x = 0; x < 50  && vChain[x] != '\0'; x ++){
    if(character1 == vChain[x]){
      vChain[x] = character2;
    }
  }

  cout << "The NEW character string is: USANDO vCHAIN sin INDICE " << vChain;

  cout << endl << endl << "USANDO FOR: " << endl;
  for(int x = 0; x < 50 && vChain[x] != '\0'; x ++){
    cout << vChain[x];
  }

  cout << endl << endl << "USANDO WHILE: " << endl;
  int a = 0;
  while (vChain[a] != '\0'){
    cout << vChain[a];
    a ++;
  }
  
  return 0;
}