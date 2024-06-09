#include <iostream>
using namespace std;
/* Hacer una función llamada Redondear que reciba como parámetro un número
 float y devuelva un número entero con el redondeo del mismo.
 Por ejemplo:
 Si recibe 7.78, debe devolver 8.
 Si recibe 7.48, debe devolver 7.
 Si recibe 7.5, debe devolver 8.
 Hacer un programa para ingresar un número y, utilizando Redondear, emita
 luego un cartel indicando el número redondeado.*/

  int truncar(float n){
    int truncado;
    return truncado =  n/1;
  }

  int redondear (float num){
    int parteEntera;
    float decimal;
    /*parteEntera = num;*/ //forma facil
    parteEntera = truncar(num);//forma dificil

    decimal = num - parteEntera;
    

    if(decimal >= 0.5){
      return parteEntera + 1;
    }else{
      return parteEntera;
    }
  }

 int main(){
  float n;
  int redondeo;
  cout << "Ingrese un numero:";
  cin >> n;

  redondeo = redondear(n);

  cout << "EL numero redondeado es: " << redondeo;

  return 0;
 }