/*13 Hacer un programa para ingresar tres números distintos y listarlos ordenados
de menor a mayor.
Sugerimos probar CADA UNA de las siguientes 6 combinaciones.
Si N1=8, N2=6, N3=10 ó N1=8, N2=10, N3=6. Se muestra: 6, 8, 10.
Si N1=6, N2=8, N3=10 ó N1=10, N2=8, N3=6. Se muestra: 6, 8, 10.
Si N1=6, N2=10, N3=8 ó N1=10, N2=6, N3=8. Se muestra: 6, 8, 10.*/

#include <iostream>
using namespace std;


int main(){
      int num1,num2,num3,primero =0, segundo =0, tercero=0;

    cout << "Ingrese el primer numero" << endl;
    cin >> num1;
    cout << "Ingrese el segundo numero" << endl;
    cin >> num2;
    cout << "Ingrese el tercer numero" << endl;
    cin >> num3;
    // establezco el numero mas grande
    if(num1>num2 && num1>num3){
        tercero = num1;
    }else if (num2> num1 && num2 > num3){
        tercero = num2;
    }else{
        tercero = num3;
    };
    // establezco el numero mas chico
      if(num1<num2 && num1<num3){
        primero = num1;
    }else if (num2< num1 && num2 < num3){
        primero = num2;
    }else{
        primero = num3;
    };
    // determino el numero medio

      if(num1>primero && num1<tercero){
        segundo = num1;
    }else if (num2> primero && num2<tercero){
        segundo = num2;
    }else{
        segundo = num3;
    };

    cout << primero << ", " << segundo << ", " << tercero << endl;




return 0;
}
