/*
11 Hacer una función llamada contarDigitos que reciba por valor un número
entero y determine y devuelva la cantidad de dígitos del número. Por ejemplo,
si se recibe el número 840 debe devolver 3.
Hacer un programa que, a partir de un número que ingresa el usuario, informe
por pantalla la cantidad de dígitos del número ingresado.
*/

#include <iostream>
using namespace std;

int ContarDigitos(int numero);
int main(){
    setlocale(LC_ALL, "Spanish");
    int numero, digitos;
    cout << "Ingrese un número ";
    cin >> numero;
    digitos= ContarDigitos(numero);

    cout << endl << "El numero " << numero << " tiene " << digitos << " digitos" << endl;

return 0;
}
 ContarDigitos(int numero){
    int digitos=0;
     while(numero >0){
        numero = (numero/10);
        digitos++;
     }
    return digitos;
 }
