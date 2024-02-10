#include <iostream>
#include <iomanip>  // "input/output manipulators"

using namespace std;

/*Hacer un programa que solicite 20 edades y luego calcule el promedio de edad
de aquellas personas mayores a 18 años.*/

int main (){
  int edades, contador = 0, acumulador = 0;
  float promedio;

  for(int x = 0; x < 3; x++ ){
    cout << x+1 << ") Ingrese las edades: ";
    cin >> edades;
    
    if(edades > 18){
      contador ++; // contador = contador + 1 || contador -=- 1 || contador += 1
      acumulador = acumulador + edades; // acumaldor += edades;
    }
  }

  promedio = (float)acumulador / contador;

  printf("\nEl promedio de sumar %i sobre la cantidad de %d es %.2f.\n", acumulador, contador, promedio);
  cout << "El promedio de edades es: " << fixed << setprecision(2) << (float)acumulador / contador <<".";

  return 0;
}