/*7 Hacer un programa para ingresar por teclado tres números e informar con una
leyenda aclaratoria si los tres son todos distintos entre sí, caso contrario no
emitir nada.
Tener en cuenta: Si A es distinto de B y B es distinto de C, eso no significa que A
y C sean distintos. Ejemplo: A=8, B=6 y C=8.*/

#include <iostream>
using namespace std;


int main(){
    int numero1,numero2,numero3;
    cout << "Ingrese el primer número" << endl;
    cin >> numero1;
    cout << "Ingrese el segundo número" << endl;
    cin >> numero2;
    cout << "Ingrese el tercer número" << endl;
    cin >> numero3;

    if(numero1!=numero2 && numero1!=numero3 && numero2!=numero3){
        cout << "Los numeros ingresados son distintos entre si" << endl;
    }

return 0;
}
