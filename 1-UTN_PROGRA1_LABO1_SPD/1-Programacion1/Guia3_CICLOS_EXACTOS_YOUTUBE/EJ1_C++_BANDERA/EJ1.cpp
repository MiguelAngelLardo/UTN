#include <iostream>

using namespace std;

/*
Hacer un programa que solicite el ingreso de 10 números y que muestre el
mayor de ellos por pantalla. Solo se debe emitir UN valor por pantalla.
*/

int main (){
  int n1, mayor = 0;

  //BANDERA INICIALIADA en CERO

  //CICLADO => REPETITIVIDAD del codigo


    //for EXACTO => por que el programador decide cuantas vueltas va a dar

  for(int x = 0; x < 10; x ++)
  {
    // x = x +1
    // 0 -> primer vuelta
    //1 -> segunda vuelta
    //8=> novena vuelta
    //9=> decime vuelta
    //10 es menor a diez? no, por que 10 == 10 
    // las vueltas son hasta n-1 => si tengo 10 las vueltas van a ser hasta llegar al 9 (PERO SON 10 VUELTAS EFECTIVAS)

    cout << x + 1 << ") Ingrese un numero: ";
    cin >> n1;

    if(n1 > mayor)
    {
      mayor = n1;
    }
  }


  cout << "El mayor numero es: " << mayor;
 
  return 0;
}