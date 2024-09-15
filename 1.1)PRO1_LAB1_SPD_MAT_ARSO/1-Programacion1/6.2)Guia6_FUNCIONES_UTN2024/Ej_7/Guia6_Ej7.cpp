/*

Escribir una función CalcularMaximoAbsoluto que reciba dos números y
retorne el máximo absoluto de ambos. Por ejemplo el máximo absoluto de los
números -40 y 20 es 40.
Hacer un programa para ingresar dos números y, utilizando
CalcularMaximoAbsoluto, emita luego el número mayor absoluto de ambos.
*/

#include <iostream>
using namespace std;

int CalcularMaximoAbsoluto (int n1, int n2);
int main(){
    setlocale(LC_ALL, "Spanish");
    int n1, n2, maximoAbsoluto;

    cout << "Ingrese un número ";
    cin >> n1;
    cout << "Ingrese otro número, distinto del anterior ";
    cin >> n2;
    maximoAbsoluto=CalcularMaximoAbsoluto(n1,n2);
    cout << endl << "El máximo absoluto entre " << n1 << " y " << n2 << " es: " << maximoAbsoluto<< endl;

return 0;
}

CalcularMaximoAbsoluto(int n1, int n2){
    if(n1<0){
        n1*=-1;
    }
    if(n2<0){
        n2*=-1;
    }
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    }
}
