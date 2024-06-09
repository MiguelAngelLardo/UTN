/**1 Hacer un programa para ingresar por teclado un número y luego emitir por
pantalla un cartel aclaratorio indicando si el mismo es positivo, negativo o cero.
Importante: Verifique que el programa emita UN SOLO CARTEL.*/


#include <iostream>
using namespace std;

int main(){
    float numero;
    cout << "Ingrese un numero"<< endl;
    cin >> numero;
    if(numero>0){
        cout << "El numero ingresado es positivo" <<endl;
    }else{
        if(numero<0){
            cout << "El numero ingresado es negativo" << endl;
        }else{
            cout << "El numero es cero" << endl;
        }
    };

return 0;
}
