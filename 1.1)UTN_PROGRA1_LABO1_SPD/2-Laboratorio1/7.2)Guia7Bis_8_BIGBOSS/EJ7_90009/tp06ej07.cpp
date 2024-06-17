//TP         : 06 sugeridos
//EJERCICIO  : 07
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

float calcularPotencia(int base, int exponente){
  float resultado=1;
  bool exponenteNegativo = false;
  if (exponente < 0){
    exponenteNegativo = true;
    exponente *= -1;
  }
  for(int i=1; i<=exponente; i++){
    resultado = resultado * base;
  }
  if (exponenteNegativo){
    return 1/resultado;
  }
  return resultado;
}

//Descompone el número numero en cifras (funciona con números menores a 100.000 y mayores a -1)
void cifras(int numero, int *cfr){
    int digitos=5, i;
    for (i=digitos-1; i>=0; i--){
      cfr[i] = numero / calcularPotencia(10, i);
      numero = numero - (cfr[i] * calcularPotencia(10, i));
    }
}

//Obtiene la cantidad de veces que X se encuentra en cifra
int cantidadXenCifra(int cifra, int X){
  int v[5], cant=0, i;
  cifras(cifra, v);
  for(i=0; i<5; i++){
    if(v[i] == X){
      cant++;
    }
  }
  return cant;
}

int main(void){
    //DESCOMENTAR LINEAS 53, 55 y 58 PARA QUE MUESTRE UN CARTEL A LADO DE CADA NUMERO INDICANDO CUALES CUMPLEN LA REGLA(NO SE PIDE EN EJER).
    int i, inicio, fin, cant=0, cantTres, cantCuatro;
    //inicio=100; fin=500; //Para hacer pruebas se utiliza un rango mas acotado.
    inicio=10001; fin=90009; //Rango original del ejercicio.
    for(i=inicio; i<=fin; i++){
        cantTres=cantidadXenCifra(i, 3);
        cantCuatro=cantidadXenCifra(i, 4);
        //cout << "Numero: " << i;
        if((cantCuatro>0) && (cantTres > cantCuatro)){
           //cout << " <---- Este";
            cant++;
        }
        //cout << endl;
    }
    cout << "La cantidad de numeros con mas veces el 3 que el 4 en el rango ["<<inicio<<"-"<<fin<<"] es : " << cant;
    return 0;
}
