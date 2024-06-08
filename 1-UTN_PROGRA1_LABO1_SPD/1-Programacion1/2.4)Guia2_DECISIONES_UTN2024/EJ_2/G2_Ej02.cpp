/*2 Hacer un programa para ingresar por teclado dos números y luego informar por
pantalla con un cartel aclaratorio si el primer número es múltiplo del segundo.*/

#include <iostream>
using namespace std;

int main(){
int num1, num2;

cout << "Ingrese un numero" << endl;
cin >> num1;

cout << "Ingrese otro numero" << endl;
cin >> num2;
if( (num1%num2) == 0){
    cout << "El numero " << num1 << " es multiplo de " << num2 << endl;
}else{
     cout << "El numero " << num1 << " no es multiplo de " << num2 << endl;

}

return 0;
}
