#include <iostream>
using namespace std;

int quitarRepetidos(int vSinProcesar[], int vSinRepetidos[]){
  bool hayRepetido, hayRepetido2;
  int contador = 0;

  for(int i = 0; i < 10; i++){
    hayRepetido = false;
    hayRepetido2 = false;
    for(int j = i+1; j < 10; j++){
      if(vSinProcesar[i] == vSinProcesar[j]){
        hayRepetido = true;
      }        
      
      if(hayRepetido){
        break;
      }
    } //j   

    if(hayRepetido){
      for(int k = 0; k < 10; k++){
        if(vSinProcesar[i] == vSinRepetidos[k]){
          hayRepetido2 = true;
        }
      }
    }//if

    if(hayRepetido && !hayRepetido2){
      vSinRepetidos[contador] = vSinProcesar[i];
      contador++;
    }
   
  }//i
  return contador;
}

int main(){

    int vectorSinProcesar[10] = { 1, 2, 1, 2, 5, 5, 4, 4, 1, 1};
    int vectorSinRepetidos[10]={};
    int elementos = quitarRepetidos(vectorSinProcesar, vectorSinRepetidos);
    
    cout << "los elementos sin repetir son: " << elementos << endl;
    cout << "mi vector sin repetir es: ";
    for(int i = 0; i < elementos; i++){
        cout << vectorSinRepetidos[i] << " ";
    }

    return 0;
}