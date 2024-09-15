/*
2 Hacer una función llamada CalcularMaximo que determine el máximo entre
dos números. La función debe recibir dos números enteros por valor y devolver
el valor más grande. Si los números son iguales debe devolver cualquiera de
los dos. La función no debe mostrar nada por pantalla.
Hacer un programa para ingresar dos números y, utilizando CalcularMaximo,
emita luego el número mayor de ambos.
*/

#include <iostream>
using namespace std;

int CalcularMaximo (int n1,int n2){
	if (n1==n2){
		return n1;
	}else if (n1 >n2){
		return n1;
	}
	else{
		return n2;
	}

}


int main(){
	setlocale(LC_ALL, "Spanish");
	int n1, n2;

	cout << "Ingrese un número " ;
	cin >> n1;
	cout << "Ingrese otro número ";
	cin >> n2;

	if (n1!=n2){
		cout << "El número mayor es: " << CalcularMaximo(n1,n2);
	}
	else{
		cout << "Ambos números son inguales " << endl;
	}


return 0;
}
