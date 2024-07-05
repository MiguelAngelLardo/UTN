/*1 Hacer un programa para ingresar por teclado la cantidad de horas trabajadas
por un operario y el valor que se le paga por hora trabajada y listar por pantalla
el sueldo que le corresponda.*/

#include <iostream>
using namespace std;

int main(){

int hsTrabajadas;
float precioXHora, sueldo;


cout << "Ingrese la cantidad de horas trabajadas :" ;
cin >> hsTrabajadas;

cout << "Ingrese el valor de la hora: ";
cin >> precioXHora;
sueldo = hsTrabajadas * precioXHora;

cout << "Por " << hsTrabajadas << " horas, le corresponden $ " << sueldo;

    return 0;
}
