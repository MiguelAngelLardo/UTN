#include <iostream>

using namespace std;

/*Una casa de computación paga a sus empleados un sueldo fijo de ARS 15000
más una comisión del 5% sobre el total facturado por cada empleado. Hacer un
programa para ingresar el total facturado por un empleado y que luego calcule
y emita por pantalla el sueldo total a cobrar por el mismo.*/

int main (){
  int totalFacturado, constanteSueldo;
  float comision, sueldoTotal;

  constanteSueldo = 15000;

  cout << "Ingrese el total facturado: ";
  cin >> totalFacturado;
  comision = totalFacturado * 0.05;

  sueldoTotal = comision + constanteSueldo;

  cout << "EL sueldo total a cobrar es: " << sueldoTotal;

  return 0;
}