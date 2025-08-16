#include <iostream>
/*
Hacer un programa que solicite al usuario 10 números y luego muestre primero
los números positivos y luego los negativos.
El programa debe crear dos arrays dinámicos con la cantidad exacta en cada
caso: uno para almacenar los números positivos y otro para los números
negativos.
*/

using namespace std;

int main(){
  int *vDinPos = nullptr, *vDinNeg = nullptr, cantPos = 0, cantNeg = 0;
  int vTotal[10] = {};

  for(int i = 0; i < 10; i++){
    cout << "Ingrese un numero: ";
    cin >> vTotal[i];
    (vTotal[i] > 0) ? cantPos++ : cantNeg++;
  }  

  vDinPos = new int[cantPos];
  vDinNeg = new int[cantNeg];
  if(vDinPos == nullptr || vDinNeg == nullptr) exit (500);

  int idPos = 0, idNeg = 0;
  for(int i = 0; i < 10; i++){
    if(vTotal[i] > 0){
      vDinPos[idPos] = vTotal[i];
      idPos++;
    }else{
      vDinNeg[idNeg] = vTotal[i];
      idNeg++;
    }
  }  
  
   // Mostrar resultados
   cout << "Positivos: ";
   for (int i = 0; i < cantPos; i++) cout << vDinPos[i] << " ";

   cout << "\nNegativos: ";
   for (int i = 0; i < cantNeg; i++) cout << vDinNeg[i] << " ";

   // Liberar memoria
   delete[] vDinPos;
   delete[] vDinNeg;


  return 0;
}