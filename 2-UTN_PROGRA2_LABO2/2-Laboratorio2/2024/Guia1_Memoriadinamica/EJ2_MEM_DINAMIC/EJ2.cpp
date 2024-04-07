#include <iostream>

using namespace std;
/*Problema 2
Igual al anterior, pero el programa debe informar qué número/s se repiten más veces dentro del vector.
*/

int main (){
  int n;
  int *vNumeros = nullptr; 

  cout << "Ingrese el numero de CASILLEROS para el vector: ";
  cin >> n;
  vNumeros = new int[n];

  if(vNumeros != nullptr){
    for(int x = 0;x < n; x ++){
        vNumeros[x] = 1 + (rand() % n); 
    }

    for(int x = 0; x < n; x ++){
      cout << x+1 << ") NUMERO #" << vNumeros[x] << endl;
    }

    int contador, maxContador = -1;
    for(int x = 0; x < n; x ++){
      contador = 1; 
      for(int y = x+1 ; y < n; y++){
        if(vNumeros [x] == vNumeros[y]){
          contador ++;
        }
        if(contador > maxContador){
          maxContador = contador;
        }
      }
    }

    cout << "Numero(s) que se repite(n) mas veces: ";
    for(int x = 0; x < n; x ++){
      int contador = 1;
      for(int y = x+1; y < n; y++){
        if(vNumeros[x] == vNumeros[y]){
          contador ++;
        }
      }
        if(contador == maxContador){
          cout << vNumeros[x] << " ";
          // Cambiamos todos los otros elementos iguales al número mostrado a un valor fuera del rango para que no se vuelvan a mostrar
          for(int y = x+1; y < n; y++){
            if(vNumeros[y] == vNumeros[x]){
              vNumeros[y] = n + 1;
            }
          }
        }
      }
      
      cout << "\nSe repite " << maxContador << " veces." << endl;

      delete []vNumeros;
  }else{
      cout << "Error: No se pudo asignar memoria." << endl;
  }
  return 0;
}