/*19 Este ejercicio lo resolverán en la parte práctica de la materia.
El costo de un desarrollo de un proyecto de software se calcula en base al
lenguaje que se necesita:
Nombre    Tipo     Valor hora
C/C++     'C'       $ 7500
C#        '#'       $ 6100
Python    'P'       $ 5400
Go        'G'       $ 5000

Además, si el proyecto es marcado como Urgente, se le aumenta un 120 % más
al costo del proyecto.
Le solicitan un programa que permita calcular el costo total de un proyecto
basado en la cantidad de horas (int), el tipo de lenguaje (char) y si es urgente o
no (bool)*/

#include <iostream>
using namespace std;


int main(){

	char lenguaje;
	bool urgente;
	int horas, total;

	cout << "Ingrese la cantidad de horas que va a requerir el proyecto" << endl;
	cin >> horas;
	cout << endl;
	cout << "Ingrese una letra para indicar el lenguaje ( 'C'--> C/C++, '#'-->C#, 'P'-->Python, 'G'-->Go)" << endl;
	cin >> lenguaje;
	cout << endl;
	cout << "Es urgente (1-->SI, 0--> NO ?" << endl;
	cin >> urgente;
	cout << endl;
	switch(lenguaje){
		case 'c': total = horas*7500;
		break;
		case '#': total = horas*6100;
		break;
		case 'p': total = horas*5400;
		break;
		case 'g': total = horas*5000;
		break;
		default: "El lenguaje seleccionado no exite";
	}

	if(urgente){
		total = total*2,2;
	}

	cout << " El proyecto tiene un costo de $" << total << endl;


return 0;
}
