#include <iostream>
#include <string>
using namespace std;
#include "funciones.h"

int main(){
	

	//Punto1
	bool p1_clientes[600] = {false};
	//Punto2
	int p2_contMismaTorta[600][7]{};
	//Punto3
	float p3_pesoMaximo[7]{};
	//Punto4
	bool p4_banPedidos[600] = { false };
	bool p4_pedidosXcliente[600][4] = {false};


	cargarDatos(p1_clientes, p2_contMismaTorta, p3_pesoMaximo, p4_pedidosXcliente, p4_banPedidos);
	//Punto1
	punto1(p1_clientes);
	//punto2
	punto2(p2_contMismaTorta);
	//punto3
	punto3(p3_pesoMaximo);
	//Punto4
	punto4(p4_pedidosXcliente, p4_banPedidos);

	return 0;
}



