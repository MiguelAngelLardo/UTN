#include <iostream>
using namespace std;

int main() {
   int n;
   int minimo, maximo;
   int cantidadDiv = 0;
   
   cout << "Ingrese N: ";
   cin >> n;
   
   for(int i=2; i<n; i++){ /// obtener los numeros entre 2 y n-1
      if(n % i == 0){ /// averiguar si es divisible
         cantidadDiv++;
         
         if(cantidadDiv == 1){ /// para averiguar cuando es el primero
            minimo = i;
         } 
         
         maximo = i; /// algoritmo de ultimo
      }
   }
   
   cout << "Minimo Divisor: " << minimo<<endl;
   cout << "Maximo Divisor: " << maximo<<endl;
	
	return 0;
}