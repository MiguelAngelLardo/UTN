#include <iostream>
using namespace std;
#include "Temporizador.h"

int main()
{
   Temporizador t1(4, 59, 59);
   Temporizador t2(-1, 40, 40);
   Temporizador t3(5, 0, 0);

   for (int i=1; i<=10; i++){
      t1.mostrar();
      t1.tic();
   }

   int valor = t1.comparar(t3);
   cout << "Comparar: " << valor;

    return 0;
}