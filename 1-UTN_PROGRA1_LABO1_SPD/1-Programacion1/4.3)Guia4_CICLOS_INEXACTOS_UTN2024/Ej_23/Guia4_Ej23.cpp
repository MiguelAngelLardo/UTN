/*
23
Dada una lista de números que finaliza cuando se ingresa un número divisible por 7,
informar cual es el anteúltimo y último número impar ingresado.
Ejemplo 8 4 -5 6 10 5 18 14 se informa -5 y 5.

Nota: Contemplar la posibilidad que podría no haber números impares en la lista.

*/

#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int numero,anteultimoImPar=0, ultimoImpar=0;

    cout<< "Ingrese un número ";
    cin >>numero;

    while(numero%7!=0){
        if(numero%2!=0){
            if(ultimoImpar ==0){
                ultimoImpar=numero;
            }
            else{
                anteultimoImPar = ultimoImpar;
                ultimoImpar = numero;
            }

        }
        cout<< "Ingrese un número ";
        cin >>numero;
    }

    if (ultimoImpar==0){
        cout << "No se ingresaron número impares" << endl;
    }
    else if (anteultimoImPar==0){
        cout << "Solo se ingreso un número par " << endl;
    }
    else{
        cout << "El último número impar ingresado es: " << ultimoImpar << endl;
        cout << "El anteúltimo número impar ingresado es: " << anteultimoImPar << endl;

    }

return 0;
}
