/*6 Hacer un programa para ingresar por teclado tres números y luego determinar e
informar con una leyenda aclaratoria si los tres son iguales entre sí, caso
contrario no emitir nada.
Tener en cuenta: Si A es igual a B y B es igual a C, entonces A y C son iguales.*/

#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3;
    cout <<"Ingrese el primer numero" << endl;
    cin >> num1;
    cout <<"Ingrese el segundo numero" << endl;
    cin >> num2;
    cout <<"Ingrese el tercer numero" << endl;
    cin >> num3;

    if(num1==num2){
        if(num2==num3){
            cout << " Los tres numeros ingresados son iguales" << endl;
        }
    };


return 0;
}
