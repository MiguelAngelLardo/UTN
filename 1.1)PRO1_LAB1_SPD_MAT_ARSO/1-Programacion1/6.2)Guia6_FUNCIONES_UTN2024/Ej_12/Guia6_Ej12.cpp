/*
12 Escribir una función de nombre validarFecha que reciba 3 valores
correspondientes al día, mes y año, y devuelva 1 si los valores recibidos
corresponden a una fecha correcta o 0 si no es correcta. Por ejemplo, si la
función recibe 30, 2, 2000 deberá devolver 0; y si recibe 12, 2, 1990, deberá
devolver 1.
*/

#include <iostream>
using namespace std;

bool EsBisiesto(int anio);
bool ValidarFecha(int dia, int mes, int anio);

int main() {
    setlocale(LC_ALL, "Spanish");

	int dia, mes, anio;


    cout << " Ingresa una dia (numero del 1 al 31) ";
    cin >> dia;
    cout << " Ingres un mes (numero del 1 al 12) ";
    cin >> mes;
    cout << " Ingresa un anio (ejemplo 1999) ";
    cin >> anio;
	bool fechaValida = ValidarFecha(dia, mes,anio);

	if(fechaValida){
		cout << endl <<"La fecha es correcta "<< endl;
	}
	else{
		cout << "La fecha es incorrecta" << endl;
	}

    return 0;
}

bool EsBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool ValidarFecha(int dia, int mes, int anio) {
    if (mes < 1 || mes > 12) {
        return false;
    }

    if (dia < 1 || dia > 31) {
        return false;
    }

    bool esBisiesto = EsBisiesto(anio);

    switch (mes) {
        case 2:
            if (esBisiesto && dia <= 29) {
                return true;
            } else if (!esBisiesto && dia <= 28) {
                return true;
            } else {
                return false;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia <= 30) {
                return true;
            } else {
                return false;
            }
        default:
            if (dia <= 31) {
                return true;
            } else {
                return false;
            }
    }
}
