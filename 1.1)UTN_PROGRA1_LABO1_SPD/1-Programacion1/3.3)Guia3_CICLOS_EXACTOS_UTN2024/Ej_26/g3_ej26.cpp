/*26 Hacer un programa que muestre los números primos entre el 1 y el 10000. El
usuario no debe ingresar nada en este programa.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int contador;

	cout << "Los números primos entre 1 y 1000 son : " << endl;
	for (int i=1; i<=1000; i++){
		contador =0;
		for (int j=1; j<=i;j++){
			if(i%j==0){
				contador ++;
				}
			}
		if(contador == 2){
			cout << i << ", ";
			}
		}

return 0;
}
