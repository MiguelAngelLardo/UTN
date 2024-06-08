#include <iostream>

using namespace std;

/*
3. Hacer un programa que solicite la edad de un grupo de personas. El programa
deberá pedir edades hasta que se ingrese una edad menor a 18 años. Deberá
mostrar por pantalla cuántas personas mayores se registraron.
*/

int main(){
  int edad, contador = 0; 

  cout << "Ingrese la edad: ";
  cin >> edad;

  while(edad >= 18){ //SIEMPRE QUE SEA VERDADERO ENTRA
    contador ++; // contador = contador +1 || contador += 1

    cout << "Ingrese la edad: ";
    cin >> edad;
  }

  cout << "La cantidad de edades son: " << contador;
  
  return 0;
}