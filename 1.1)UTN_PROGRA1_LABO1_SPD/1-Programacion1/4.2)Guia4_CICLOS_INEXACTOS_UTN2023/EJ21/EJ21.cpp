#include <iostream>
using namespace std;

int main() {
	
	int numeroCliente, numeroSucursal, saldoCliente, mayorSaldo, clienteMayorSaldo;
  int contadorClientes1 = 0, clientesSaldoSuperior1 = 0, contadorClientes2 = 0, clientesSaldoSuperior2 = 0;
  int contadorClientes3 = 0, clientesSaldoSuperior3 = 0, contadorClientes4 = 0, clientesSaldoSuperior4 = 0;
  int totalSaldo1 = 0, totalSaldo2 = 0, totalSaldo3 = 0, totalSaldo4 = 0;
  int sucursalMayorPorcentaje;
  float porcentajeSaldoSuperior1, porcentajeSaldoSuperior2, porcentajeSaldoSuperior3, porcentajeSaldoSuperior4;
  float mayorPorcentaje = 0.0;
  bool bandera = false;

	cout << endl << "Ingrese el numero de cliente: ";
	cin >> numeroCliente;
	cout << "Ingrese el numero de sucursal (1,2,3,4): ";
	cin >> numeroSucursal;
	cout << "Ingrese el saldo del cliente: ";
	cin >> saldoCliente;
	
  while (numeroSucursal != 10)
  {
    if(!bandera)
    { 
      mayorSaldo = saldoCliente;
      clienteMayorSaldo = numeroCliente;
      bandera = true;
    }
    else
    {
      if (saldoCliente > mayorSaldo)
      {
        mayorSaldo = saldoCliente;
        clienteMayorSaldo = numeroCliente;
      } 
    }

    switch (numeroSucursal)
    {
    case 1:
      contadorClientes1 ++;
      if(saldoCliente > 20000)
        clientesSaldoSuperior1 ++;  
      totalSaldo1 += saldoCliente;    
    break;
    case 2:
      contadorClientes2 ++;
      if(saldoCliente > 20000)
        clientesSaldoSuperior2 ++;  
      totalSaldo2 += saldoCliente;     
    break;
    case 3:
      contadorClientes3 ++;
      if(saldoCliente > 20000)
        clientesSaldoSuperior3 ++;  
      totalSaldo3 += saldoCliente;     
    break;
    case 4:
      contadorClientes4 ++;
      if(saldoCliente > 20000)
        clientesSaldoSuperior4 ++;
      totalSaldo4 += saldoCliente;       
    break;
    
    default:
      cout << "No ingreso una sucursal valida.";
    break;
    }

    cout << endl << "Ingrese el numero de cliente: ";
    cin >> numeroCliente;  
    cout << "Ingrese el numero de sucursal (1,2,3,4): ";
    cin >> numeroSucursal;
    if(numeroSucursal != 10)
    {
      cout << "Ingrese el saldo del cliente: ";
      cin >> saldoCliente;
    }
  }

  porcentajeSaldoSuperior1 = clientesSaldoSuperior1 * 100 / contadorClientes1;
  porcentajeSaldoSuperior2 = clientesSaldoSuperior2 * 100 / contadorClientes2;
  porcentajeSaldoSuperior3 = clientesSaldoSuperior3 * 100 / contadorClientes3;
  porcentajeSaldoSuperior4 = clientesSaldoSuperior4 * 100 / contadorClientes4;
  

  if(porcentajeSaldoSuperior1 > mayorPorcentaje){
    mayorPorcentaje = porcentajeSaldoSuperior1;
    sucursalMayorPorcentaje = 1;
  }else if (porcentajeSaldoSuperior2 > mayorPorcentaje){
    mayorPorcentaje = porcentajeSaldoSuperior2;
    sucursalMayorPorcentaje = 2;
  }else if (porcentajeSaldoSuperior3 > mayorPorcentaje){
    mayorPorcentaje = porcentajeSaldoSuperior3;
    sucursalMayorPorcentaje = 3;
  }else if (porcentajeSaldoSuperior4 > mayorPorcentaje){
    mayorPorcentaje = porcentajeSaldoSuperior4;
    sucursalMayorPorcentaje = 4;
  }

  cout << "Mayor saldo: " << mayorSaldo << ". Numero cliente: " << clienteMayorSaldo << endl;
  cout << "La sucursal con mayor porcentaje de clientes con saldo superior a $20.000 es la " << sucursalMayorPorcentaje << " y el valor es %" << mayorPorcentaje << endl;
  cout << "Suma total sucursal 1: $" << totalSaldo1 << endl;
  cout << "Suma total sucursal 2: $" << totalSaldo2 << endl;
  cout << "Suma total sucursal 3: $" << totalSaldo3 << endl;
  cout << "Suma total sucursal 4: $" << totalSaldo4 << endl;
	
	return 0;
}