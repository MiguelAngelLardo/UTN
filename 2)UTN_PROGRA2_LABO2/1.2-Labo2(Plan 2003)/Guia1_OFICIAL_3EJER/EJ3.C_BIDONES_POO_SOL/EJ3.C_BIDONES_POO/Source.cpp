#include <iostream>
using namespace std;
#include "Bidon.h"

int main(){
	Bidon b1, b2; //es unavariable que se llama INSTANCIA

	b1.setSabor("Banana");
	//b1.setCapaciad(40);

	cout << "El sabor: " << b1.getSabor() << endl;
	//cout << "Capacidad: " << b1.getCapacidad() << endl;

	//b1.extraer(20);


	return 0;
}