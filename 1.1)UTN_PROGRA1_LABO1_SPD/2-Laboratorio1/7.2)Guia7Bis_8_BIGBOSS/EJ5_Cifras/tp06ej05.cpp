//TP         : 06 sugeridos
//EJERCICIO  : 05
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
void cifras(int numero, int *unidad, int *decena, int *centena, int *uniDeMil, int *decDeMil){
    int digitos=5;
    //Decena de mil
    *decDeMil = numero / calcularPotencia(10, digitos-1);
    numero = numero - (*decDeMil * calcularPotencia(10, digitos-1));
    digitos--;
    //Unidad de mil
    *uniDeMil = numero / calcularPotencia(10, digitos-1);
    numero = numero - (*uniDeMil * calcularPotencia(10, digitos-1));
    digitos--;
    //Centenas
    *centena = numero / calcularPotencia(10, digitos-1);
    numero = numero - (*centena * calcularPotencia(10, digitos-1));
    digitos--;
    //Decenas
    *decena = numero / calcularPotencia(10, digitos-1);
    //Unidades
    *unidad = numero % (int) calcularPotencia(10, digitos-1);

}

int main(void){
  int numero, u, d, c, um, dm;
  cout << "Ingrese un numero para descomponerlo: ";
  cin >> numero;
  cifras(numero, &u, &d, &c, &um, &dm);
  cout << endl << "EL NUMERO " << numero << " ESTA COMPUESTO POR " << dm << " " << um << " " << c << " " << d << " " << u;
  return 0;
}
