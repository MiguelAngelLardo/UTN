#include <iostream>
using namespace std;

/*Hacer un programa que solicite 20 números y luego mostrar por pantalla el
menor de ellos y la posición en la que fue encontrado.*/
int main (){

  int n, menor, posicion;

  for ( int x = 0; x < 20; x++)
  {
    //cout << x+1 << "Ingrese un numero : ";
    printf("%d) Ingrese un numero: ", x+1);
    cin >> n;

    if (x == 0){
      menor = n;
      posicion = 1;
    }else if (n < menor){
      menor = n;
      posicion = x + 1;
    }
  }
   
  printf ("El numero menor es %d - POSICION: %i.\n", menor, posicion);
  cout << "El numero menor es: " << menor << "- Posicion: " << posicion << endl;
  //PLACE HOLDER => DAR FORMATO '%'

  return 0;
}