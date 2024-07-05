//TP         : 06 sugeridos
//EJERCICIO  : 06
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
  int nro, x, cant;
  cout << "Ingresar una cifra (1 - 99999): ";
  cin >> nro;
  cout << "Ingresar un digito (0 - 9): ";
  cin >> x;
  cant = cantidadXenCifra(nro, x);
  cout << endl << "EL DIGITO " << x << " SE ENCUENTRA " << cant << " VECES EN " << nro;
  return 0;
}
