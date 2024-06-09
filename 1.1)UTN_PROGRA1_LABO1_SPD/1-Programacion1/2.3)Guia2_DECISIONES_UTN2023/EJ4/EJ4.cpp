#include <iostream>

using namespace std;
/*
Hacerun programa para ingresar por teclado dos números y luego informar por
pantalla la diferencia absoluta entre ambos.

 Ejemplo A: Si se ingresan 3 y 8 se emite 5. Si se ingresan 8 y 3 se emite 5.
 Ejemplo B: Si se ingresan-3 y 9 se emite 12. Si se ingresan-12 y-1 se emite 11.
 Ejemplo C: Si se ingresan-3 y-9 se emite 6. Si se ingresan-12 y-9 se emite 3.
 Importante: Verifique que el programa emite SIEMPRE UN VALOR POSITIVO
 porque la diferencia absoluta siempre es un valor positivo
*/

int main(){
  int n1, n2, diferencia;

  cout << "Ingrese numero 1:";
  cin >> n1;
  cout << "Ingrese numero 2:";
  cin >> n2;

  if(n1 < 0 && n2 < 0){ //redundancia
    n1 = n1 * -1;
    n2 = n2 * -1;
  }

               //-12  -1             -1  -(-12)
  diferencia = (n1 > n2) ? n1 - n2 : n2 - n1;// el signo negativo funciona con la regla de signos

  cout << diferencia;

  return 0;
}