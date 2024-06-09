/*24 Hacer un programa que permita ingresar el sueldo de 10 empleados y
determine:
- El sueldo máximo.
- El sueldo mínimo.
- El sueldo promedio.
- Cantidad de sueldos mayores a $50000.*/

#include <iostream>
#include <iomanip>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int sueldo, maximo, minimo, contador=0, totalSueldos;
	float promedio;

	for(int i=1;i<=10;i++){
		cout << "Ingrese el sueldo del empleado " << i <<" " ;
		cin >> sueldo;
		totalSueldos += sueldo;
		// para establecer maximos y minimos
		if( i==1){
			maximo = sueldo;
			minimo = sueldo;
		}else if (sueldo>maximo){
			maximo = sueldo;
		}else if(sueldo < minimo){
			minimo = sueldo;
		}

		//cantidad de sueldos mayores a $50000
		if( sueldo > 50000){
			contador ++;
		}
	}
	promedio = totalSueldos/10;
	cout <<"-------------------------------" << endl;
	cout <<"Sueldo máximo   : $" << maximo << endl;
	cout <<"Sueldo minimo   : $" << minimo<< endl;
	cout <<"Promedio sueldos: $" << promedio << endl;
	cout <<"Sueldos > 50000 : " << fixed << setprecision (2) << contador<< endl;
	cout <<"-------------------------------" << endl;

	return 0;
}
