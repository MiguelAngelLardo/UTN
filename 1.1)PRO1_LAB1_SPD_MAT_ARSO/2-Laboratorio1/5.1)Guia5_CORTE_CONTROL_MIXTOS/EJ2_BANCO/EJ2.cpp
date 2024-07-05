#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int nroCliente, nroSucursal;
  char codigoTransaccion;
  float montoTransaccion;
  int contadorCantidadDeposito1000 = 0; //A)
  int maximaExtraccion = -1, sucursalMaximaExtraccion;//B)
  int transaccionSucursal1 = 0, transaccionSucursal2 = 0, transaccionSucursal3 = 0;  //C
  int deposito, totalDeposito1 = 0, totalDeposito2 = 0, totalDeposito3 = 0; //D)
  int contDepositoTigre = 0, contDepositoVirrey = 0, contDepositoSanFernando = 0, nroSucursalMaxDepositoDeTodos; // E y F)

  cout << "Nro. cliente (100 al 1200): ";
  cin >> nroCliente;
  cout << "Nro. Sucursal (1, 2 o 3): ";
  cin >> nroSucursal;
  cout << "Codigo de transaccion ('D' o 'E'): ";
  cin >> codigoTransaccion;
  cout << "Monto de de transaccion: ";
  cin >> montoTransaccion;

  while(nroCliente != 0)
  {
    if(codigoTransaccion == 'D' && montoTransaccion > 1000){
      contadorCantidadDeposito1000 ++;
    }

    if(montoTransaccion > 0 && codigoTransaccion == 'E' && montoTransaccion > maximaExtraccion){
      maximaExtraccion = montoTransaccion;
      sucursalMaximaExtraccion = nroSucursal;
    }

    switch (nroSucursal)
    {
      case 1:
        transaccionSucursal1 ++;
        if(codigoTransaccion == 'D'){
          deposito = montoTransaccion;
          totalDeposito1 += deposito;
          contDepositoVirrey ++;
          
        }  
      break;
      case 2:
        transaccionSucursal2 ++;
        if(codigoTransaccion == 'D'){
          deposito = montoTransaccion;
          totalDeposito2 += deposito;
          contDepositoSanFernando ++;
        }  
      break;
      case 3:
        transaccionSucursal3 ++;
        if(codigoTransaccion == 'D'){
          deposito = montoTransaccion;
          totalDeposito3 += deposito;
          contDepositoTigre ++;
        }  
      break; 
    }

    if(contDepositoVirrey > contDepositoSanFernando && contDepositoVirrey > contDepositoTigre)
      nroSucursalMaxDepositoDeTodos = 1;
    else if (contDepositoSanFernando > contDepositoVirrey && contDepositoSanFernando > contDepositoTigre)
      nroSucursalMaxDepositoDeTodos = 2;
    else
      nroSucursalMaxDepositoDeTodos = 3;

    cout << endl <<  "Nro. cliente (100 al 1200): ";
    if(nroCliente != 0){
      cin >> nroCliente;
      cout << "Nro. Sucursal (1, 2 o 3): ";
      cin >> nroSucursal;
      cout << "Codigo de transaccion ('D' o 'E'): ";
      cin >> codigoTransaccion;
      cout << "Monto de de transaccion: ";
      cin >> montoTransaccion;
    }  
  }

    cout << endl << "Cantidad de depositos mayores a $1000: " << contadorCantidadDeposito1000 << endl;
    cout << "La maxima extraccion fue de: " << maximaExtraccion << ". La sucursal fue: " << sucursalMaximaExtraccion << endl;
    cout << "***EL porcentaje de transacciones***: " << endl;
    cout << "Sucursal 1: " << transaccionSucursal1 * 100 / (transaccionSucursal1 + transaccionSucursal2 + transaccionSucursal3) << endl;
    cout << "Sucursal 2: " << transaccionSucursal2 * 100 / (transaccionSucursal1 + transaccionSucursal2 + transaccionSucursal3) << endl;
    cout << "Sucursal 3: " << transaccionSucursal3 * 100 / (transaccionSucursal1 + transaccionSucursal2 + transaccionSucursal3) << endl << endl;
    cout << "***TOTAL DEPOSITO POR SUCURSAL***: " << endl;
    cout << "Sucursal 1: " << totalDeposito1 << endl;
    cout << "Sucursal 2: " << totalDeposito2 << endl;
    cout << "Sucursal 3: " << totalDeposito3 << endl << endl;
    cout << "Depositos en sucursal 3 (Tigre): " << contDepositoTigre << endl;
    cout << "La sucursal con mayor cantidad de depositos: " << nroSucursalMaxDepositoDeTodos << endl;

 return 0;

}