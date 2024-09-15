/*
14 Hacer una función llamada esNumeroArmstrong que reciba un número entero
y devuelva true si el número enviado es un Número Armstrong y false si no lo
es.
NOTA: Un número N es un número Armstrong si la suma de sus cifras elevadas
a la cantidad de cifras del número da como resultado N.
Por ejemplo:
371 tiene 3 cifras.
Luego:
33 + 73 + 13 → 371
27 + 343 + 1 → 371*/
#include <iostream>
#include <cmath>
using namespace std;

bool EsNumeroArmstrong(int numero);
int ContarDigitos(int numero);
float CalcularPotencia (int n1, int n2);

int main() {
    setlocale(LC_ALL, "Spanish");

    int numero;
    cout << "Ingrese un número: ";
    cin >> numero;

    if (EsNumeroArmstrong(numero)) {
        cout << endl <<numero << " es un número Armstrong." << endl;
    } else {
        cout << endl << numero << " no es un número Armstrong." << endl;
    }

    return 0;
}

int ContarDigitos(int numero) {
    int digitos = 0;
    while (numero > 0) {
        numero /= 10;
        digitos++;
    }
    return digitos;
}
float CalcularPotencia (int n1, int n2){
	float resultado= 1.0;

	 if(n2==0){
		resultado == 1.0;
	 }
	 else if(n2>0)
		{
		for(int i=0; i<n2;i++){
			resultado *= n1;
		}
	 }
	 else{
		n2 = n2 *(-1);
		for(int i=0; i<n2;i++){
			resultado *= (1.0/n1);
		}
	 }
	return resultado;
}

bool EsNumeroArmstrong(int numero) {
    int digitos = ContarDigitos(numero);
    int suma = 0;
    int auxiliar = numero;

    while (auxiliar > 0) {
        int cifra = auxiliar % 10;
        suma += CalcularPotencia(cifra, digitos);
        auxiliar /= 10;
    }

    return suma == numero;
}

