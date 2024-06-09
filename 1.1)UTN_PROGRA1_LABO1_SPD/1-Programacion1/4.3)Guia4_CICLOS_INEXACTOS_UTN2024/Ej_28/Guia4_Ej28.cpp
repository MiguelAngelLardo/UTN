/*
Hacer un programa que contenga un menú con el siguiente formato:
Menú principal
-----------------------------
1 - Ingresar medida en metros
2 - Convertir a centímetros
3 - Convertir a kilómetros
4 - Convertir a pulgadas
5 - Convertir a pies
-----------------------------
0 - Salir del programa

Ingrese opción:


Al ingresar a la opción 1, nos pedirá una medida (float) en metros que con las
siguientes opciones del menú podremos mostrarla convertida a otras unidades.
El programa debe permitir al usuario ingresar a las opciones las veces que lo
desee y sólo finalizará al ingresar a la opción 0.

*/



#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    int opcion;
    float metros, cm, km, pulgada, pies;

    do {

        cout << "       Menú principal         " << endl;
        cout << "----------------------------- " << endl;
        cout << "1 - Ingresar medida en metros " << endl;
        cout << "2 - Convertir a centímetros   " << endl;
        cout << "3 - Convertir a kilómetros    " << endl;
        cout << "4 - Convertir a pulgadas      " << endl;
        cout << "5 - Convertir a pies          " << endl;
        cout << "----------------------------- " << endl;
        cout << "0 - Salir del programa        " << endl;

        cout << "Ingrese la opción: ";
        cin >> opcion;

        switch (opcion) {
            case 0:
                cout << "Saliendo del programa....." << endl;
                 system("pause");
                 system("cls");
                break;
            case 1:
                cout << "Ingrese la medida en metros: ";
                cin >> metros;
                break;
            case 2:
                cm = metros * 100;
                cout << metros << " metros, son " << cm << " cm" << endl;
                 system("pause");
                 system("cls");
                break;
            case 3:
                km = metros / 1000;
                cout << metros << " metros, son " << km << " km" << endl;
                 system("pause");
                 system("cls");
                break;
            case 4:
                pulgada = metros * 39.37;
                cout << metros << " metros, son " << pulgada << " pulgadas" << endl;
                 system("pause");
                 system("cls");
                break;
            case 5:
                pies = metros * 3.281;
                cout << metros << " metros, son " << pies << " pies" << endl;
                 system("pause");
                 system("cls");
                break;
            default:
                cout << "La opción ingresada es incorrecta" << endl;
                break;
        }






    } while (opcion != 0);

    return 0;
}

