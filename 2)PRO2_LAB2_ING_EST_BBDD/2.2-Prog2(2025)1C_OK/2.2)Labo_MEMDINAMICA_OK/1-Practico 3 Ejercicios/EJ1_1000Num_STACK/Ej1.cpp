#include <iostream>
#include <ctime>//para time

using namespace std;

/*
1- 🧠 Actividad: 1.000 Números
Se desea cargar 1.000 números aleatorios enteros entre 1 y 100.000 y determinar:
● Cuál es el número más alto generado.
● Cuántas veces se repitió ese número en el conjunto.
💡 ¿Qué pasa si se quiere que se generen 1.000.000 de números?
*/

int main() {
  int vNumAleatorios[1000];
  srand(time(0));
  int aleatorio = rand()%5+1;

  for(int i = 0; i < 1000; i ++){
    vNumAleatorios[i] = rand()%100000+1;
  }

  int maxIndice = 0;
  for(int i = 1; i < 1000; i ++){
    if(vNumAleatorios[i] > vNumAleatorios[maxIndice]){
      maxIndice = i;
    }
  }

  for(int i = 0; i < 1000; i ++){
    cout << i+1 << ": " << vNumAleatorios[i] << endl;
  }
  

  cout << "el maximo numero es: " << vNumAleatorios[maxIndice] << " y esta en la posicion " << maxIndice+1 << endl;
  
  int contRepetidos = 0;
  for(int i = 0; i < 1000; i ++){
    if(vNumAleatorios[maxIndice] == vNumAleatorios[i]){
      contRepetidos ++;
    }
  }

  cout << "La cantidad de repetidos es: " << contRepetidos << endl;
  
  


  return 0;
}