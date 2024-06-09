/*
19 Un negocio de venta de huevos tiene registrada la información de las ventas
efectuadas durante el mes pasado entre todas las sucursales. Los datos que se
disponen por cada una de las ventas efectuadas son:
● Número de sucursal (1 a 30)
● Día de la venta (1 a 31)
● Cantidad de cajas de huevos vendidas
● Importe de la venta
● Forma de Pago (1=Débito, 2=Crédito, 3=Contado)
Los datos están agrupados, no ordenados, por número de sucursal y puede
haber varias ventas para la misma sucursal, para el mismo día, etc.
Puede haber sucursales sin ventas durante todo el mes o durante algunos días
del mes. En tal caso no habrá registros de ventas para esa sucursal o para esos
días del mes. No habrá registros con cantidades o importes iguales a 0.
La finalización de todo el lote se indicará con un registro con número de
sucursal igual a 0.
Se pide determinar e informar:
a) Informar en cuál de las sucursales la cantidad TOTAL de cajas de huevos
vendidos haya sido menor descartando a las sucursales cuya cantidad
TOTAL de cajas vendidas fue menor a 100. Se informa 1 resultado al final.
b) Informar el número de quincena en la que se hayan vendido mayor cantidad
de cajas entre todas las sucursales. Se informa un resultado al final de todo.
c) Para cada una de las sucursales el porcentaje de recaudación total por sus
ventas discriminado en crédito, débito y contado. Se informan 3 resultados
por cada sucursal.
d) Para cada sucursal informar la primera y segunda venta individual de menor
importe, indicando además en qué día fueron esas ventas. Se informan 4
resultados por sucursal.

*/
#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL, "Spanish");
	//Variables generales
	int sucursal,dia,cantidad,importe,formaPago,sucAnterior;
	//variables punto a
	int ptoA_sucursalMenor = 0;
	int ptoA_totalCajas = 0;
	int ptoA_totalMenor = 0;
	//variables punto b
	int ptoB_totalQuincena1 = 0;
	int ptoB_totalQuincena2 = 0;
	//variables punto c
	int ptoC_totalCredito, ptoC_totalDebito, ptoC_totalCtdo, ptoC_total;
	float ptoC_ptjeCredito, ptoC_ptjeDebito, ptoC_ptjeCtdo;
	//variable punto d
	int ptoD_ventaMenor1, ptoD_ventaMenor2, ptoD_dia1, ptoD_dia2;

	cout << "Ingrese la sucursal ";
	cin >> sucursal;

	while(sucursal != 0){
		sucAnterior = sucursal; // corte de control
		// reinicio variables de grupo
		ptoC_totalDebito = ptoC_totalCredito = ptoC_totalCtdo = 0;
		ptoD_ventaMenor1 = ptoD_ventaMenor2 = 0;
		ptoD_dia1 = ptoD_dia2 = 0;
		ptoA_totalCajas = 0;

		while(sucAnterior == sucursal){
			cout << "Ingrese el Día de la venta (1 a 31) ";
			cin >> dia;
			cout << "Ingrese Cantidad de cajas de huevos vendidas ";
			cin >> cantidad;
			cout << "Ingrese el Importe de la venta $";
			cin >> importe;
			cout << "Ingrese la Forma de Pago (1=Débito, 2=Crédito, 3=Contado)";
			cin >> formaPago;
			cout << "---------------------------------------------------------------"<< endl;

			// punto a
			ptoA_totalCajas += cantidad;

			// punto b
			if (dia <= 15){
				ptoB_totalQuincena1 += cantidad;
			}
			else{
				ptoB_totalQuincena2 += cantidad;
			}

			// punto c
			switch(formaPago){
			case 1:
				ptoC_totalDebito += importe;
				break;
			case 2:
				ptoC_totalCredito += importe;
				break;
			case 3:
				ptoC_totalCtdo += importe;
				break;
			}

			// punto d
			if(ptoD_ventaMenor1 == 0 || importe < ptoD_ventaMenor1){
				ptoD_ventaMenor2 = ptoD_ventaMenor1;
				ptoD_dia2 = ptoD_dia1;
				ptoD_ventaMenor1 = importe;
				ptoD_dia1 = dia;
			}
			else if(importe < ptoD_ventaMenor2){
				ptoD_ventaMenor2 = importe;
				ptoD_dia2 = dia;
			}

			cout << "Ingrese la sucursal ";
			cin >> sucursal;
		}

		// punto A
		if ((ptoA_totalCajas >= 100) && (ptoA_totalMenor == 0 || ptoA_totalCajas < ptoA_totalMenor)){
			ptoA_totalMenor = ptoA_totalCajas;
			ptoA_sucursalMenor = sucAnterior;
		}

		// Calcular y Mostrar punto c
		ptoC_total = ptoC_totalCredito + ptoC_totalCtdo + ptoC_totalDebito;
		if (ptoC_total > 0) {
			ptoC_ptjeCredito = (float)ptoC_totalCredito * 100 / ptoC_total;
			ptoC_ptjeDebito = (float)ptoC_totalDebito * 100 / ptoC_total;
			ptoC_ptjeCtdo = (float)ptoC_totalCtdo * 100 / ptoC_total;

			cout << "----------------------------------------" << endl;
			cout << "            SUCURSAL " << sucAnterior << endl;
			cout << "Porcentaje de Recaudación por ventas al contado: " << ptoC_ptjeCtdo << "%" << endl;
			cout << "Porcentaje de Recaudación por ventas con débito: " << ptoC_ptjeDebito << "%" << endl;
			cout << "Porcentaje de Recaudación por ventas con crédito: " << ptoC_ptjeCredito << "%" << endl;
		}

		// Calcular y mostrar punto d
		cout << "La menor venta fue de $" << ptoD_ventaMenor1 << " y se realizó el día " << ptoD_dia1 << endl;
		if (ptoD_ventaMenor2 > 0) {
			cout << "La segunda menor venta fue de $" << ptoD_ventaMenor2 << " y se realizó el día " << ptoD_dia2 << endl;
		} else {
			cout << "No hubo segunda menor venta." << endl;
		}
	}

	// Mostrar punto A
	if (ptoA_totalMenor > 0) {
		cout << "La sucursal con menor venta total de huevos (sin contar las que vendieron menos de 100 cajas) fue la N° " << ptoA_sucursalMenor << endl;
	} else {
		cout << "No hubo sucursales con ventas superiores a 100 cajas." << endl;
	}

	// Mostrar punto B
	if (ptoB_totalQuincena1 > ptoB_totalQuincena2){
		cout << "En la Primer Quincena se vendieron mayor cantidad de cajas de huevos" << endl;
	}
	else if (ptoB_totalQuincena2 > ptoB_totalQuincena1){
		cout << "En la Segunda Quincena se vendieron mayor cantidad de cajas de huevos" << endl;
	}
	else{
		cout << "En ambas quincenas se vendieron la misma cantidad de cajas de huevos" << endl;
	}

	return 0;
}

