#include <iostream>

using namespace std;

/*
Hacer una función que reciba un vector de enteros y su tamaño y luego muestre
el vector ordenado de forma ascendente, tener en cuenta que el vector enviado
como argumento no debe ser modificado.
*/

void ordenarVector(int v[], int tam){
  int aux;

  for(int i = 0; i < tam; i++){
    for(int j = i + 1; j < tam; j++){
      if(v[i] > v[j]){
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
      }  
    }  
  }  


}
int main(){
  int tam, *vDin = nullptr;
  cout << "Ingrese tam: ";
  cin >> tam;

  vDin = new int[tam];

  if(vDin == nullptr)exit(500);

  for(int i = 0; i < tam; i++){
    cout << "Ingrese un numero: ";
    cin >> vDin[i];
  }  

  ordenarVector(vDin, tam);

  for(int i = 0; i < tam; i++){
    cout << vDin[i] << endl;
  }  

  delete [] vDin;





  return 0;
}