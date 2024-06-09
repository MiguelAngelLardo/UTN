#include <iostream>

using namespace std; // que se facil hacer el cout y el cin

/*
3) Una concesionaria de autos paga a los vendedores un sueldo fijo de $ 15.000 más $ 2.000
de premio por cada auto vendido. Hacer un programa que permita ingresar por teclado la
cantidad de autos vendidos por un vendedor y luego informar por pantalla el sueldo total a
pagar.
Ejemplo. Si la cantidad de autos vendidos fuera 4 entonces el sueldo total a pagar es de
$ 23.000. 
*/

int main(){
//sueldo fijo => 15.000
//por cada auto => 2000 mas

int cantidaDeAutos; //lowerCamelCase => DECLARAR la variable
int sueldoFijo = 15000; //INICIALIzAR la variable => que vos de fabrica venis con plata en el bolsillo
int sueldoTotal;

cout << "Ingrese la cantidad de autos que vendio: ";
cin >> cantidaDeAutos; //3

//N# 45000  <--- //15000        // 3  
sueldoTotal = sueldoFijo * cantidaDeAutos;
                     
cout << "El sueldo total es $ " << sueldoTotal << endl;

  return 0;
}