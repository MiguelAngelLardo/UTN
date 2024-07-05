/*8 Basado en los 2 ejercicios anteriores, hacer un programa para ingresar por
teclado la longitud de los tres lados de un triángulo y luego listar qué tipo de
triángulo es:
- Equilátero: si los tres lados son iguales.
- Isósceles: si dos de los tres lados son iguales.
- Escaleno: si los tres lados son distintos entre sí.*/

#include <iostream>
using namespace std;

int main(){
    int lado1,lado2,lado3;
    cout << "Ingrese el lado 1" << endl;
    cin >> lado1;
    cout << "Ingrese el lado 2" << endl;
    cin >> lado2;
    cout << "Ingrese el lado 3" << endl;
    cin >> lado3;

    if(lado1 == lado2 && lado2==lado3){
        cout << "El triangulo es Equilatero"<< endl;
    } else if(lado1!=lado2 && lado2!=lado3 && lado1!=lado3){
        cout << "El triangulo es Escaleno" << endl;

    }else{
        cout << "El triangulo es Isoceles" << endl;
    }
return 0;
}
