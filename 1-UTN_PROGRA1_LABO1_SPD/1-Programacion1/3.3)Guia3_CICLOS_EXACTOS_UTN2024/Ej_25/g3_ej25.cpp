/*25 Hacer un programa que permita ingresar el legajo y sueldo de 10 empleados y
determine:
- El legajo del empleado con mayor sueldo*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int sueldo, legajo, maximo,legajoMaxSueldo;

	for(int i=1;i<=10;i++){
			cout << "Ingrese el sueldo del empleado " << i <<" $  " ;
		cin >> sueldo;
		cout << "Ingrese el legajo del empleado " << i <<" N° " ;
		cin >> legajo;
		cout <<"--------------------------------------------------" << endl;



		if( i==1){
			maximo = sueldo;
			legajoMaxSueldo = legajo;
		}else if (sueldo>maximo){
			maximo = sueldo;
			legajoMaxSueldo = legajo;
		}

	}

	cout <<"-------------------------------" << endl;
	cout <<"Sueldo máximo   : $" << maximo << endl;
	cout <<"Legajo empleado : N° " << legajoMaxSueldo<< endl;
	cout <<"-------------------------------" << endl;

return 0;
}
