#pragma once
#include "Gasto.h"
#include "Ingreso.h"


class Sistema{
public:
	void cargarTransacciones();
	void mostrarGastos(); ///Punto A
	void mostrarMayorIngreso(); /// Punto B
	void mostrarSaldo(); /// Punto C
	Gasto cargarGasto();

private: 
	Gasto _gastos[5];
	Ingreso _ingresos[5];


};

