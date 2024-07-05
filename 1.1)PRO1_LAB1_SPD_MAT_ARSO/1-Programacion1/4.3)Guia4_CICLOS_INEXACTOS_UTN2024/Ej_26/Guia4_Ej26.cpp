/*
26 Un número Simonírico es un número positivo divisible por 15 y a la vez divisible
por 3 pero no divisible por 6. Hacer un programa que muestre los primeros 1000
números Simoníricos. El usuario no debe ingresar nada.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

    int numero = 0; //

    cout << "Los primeros 1000 números Simoníricos son:" << endl;

    while (numero < 1000) {
        // Verificar si el número cumple las condiciones para ser simonírico
        if (numero % 15 == 0 && numero % 3 == 0 && numero % 6 != 0) {
            cout << numero << endl; // Mostrar el número simonírico encontrado
        }

        numero++; // Pasar al siguiente número
    }

return 0;
}
