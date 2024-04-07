#include <iostream>
#include <cstring>

using namespace std;

/*
5) Hacer un programa para cargar y mostrar una matriz 
de char de 5x10 de la siguiente manera:
- Con palabras de hasta 9 caracteres.
- Con palabras de 10 o más caracteres.

Analizar y explicar las diferencias que se producen al 
mostrar palabra por palabra el contenido de la matriz.
*/

void cargarCadena (char *vec, int tamanio);

int main(){
  char matriz[5][10];
  char matriz2 [5][10];

  cout << "PALABRAS DE HASTA 9 CARACTERES" << endl;
  cout << "Ingrese la palabra:\n";
  for(int x = 0; x < 5; x++){
    cargarCadena(matriz[x], 9);
  }
  
  cout << "\nMatriz cargada:" << endl;
  for (int x = 0; x < 5; x++) {
    cout << matriz[x]; // Imprimir palabra &matriz[x][0]
    if (strlen(matriz[x]) <= 9 ) { // Si la palabra tiene 9 caracteres, agregar un salto de línea
      cout << endl;
    }
  }

  cout << "\nPALABRAS DE 10 CARACTERES O MAS" << endl;
  cout << "Ingrese el texto para la matriz 2 (termina con Enter):" << endl;
  cargarCadena(matriz2[0], 49); // Usamos 50 como tamaño para la matriz complet
  
  cout << "\nMatriz 2 cargada:" << endl;
  cout << matriz2[0]; // Imprimir la cadena completa


  return 0;
}

void cargarCadena (char *vec, int tamanio){
  int i;
  bool bandera = false;
  fflush(stdin);
  for(i = 0; i < tamanio; i ++){
    vec[i] = cin.get();
    if(vec[i] == '\n'){
      break;
    }
  }
  vec[i] = '\0';
  fflush(stdin);
}
