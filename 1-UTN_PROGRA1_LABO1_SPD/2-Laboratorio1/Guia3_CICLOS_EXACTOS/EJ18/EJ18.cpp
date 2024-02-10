#include <iostream>
using namespace std;

int main() {
  const int DIAS_MOVIMIENTO = 15;
  int numeroMovimiento, diaMovimiento, contMovimientosTotales = 0, contExtraccion = 0, contDeposito = 0, mayorNumMov, diaMayorMov, cantidadMovDia10 = 0;
  float importe, saldoCuenta = 0, porcentajeExtraccion = 0, porcentajeDeposito = 0, mayorImporte;
  char extraccionDeposito;
  bool bandera = false;

  for ( int x = 0; x < DIAS_MOVIMIENTO; x ++)
  {
    cout << endl << "Ingrese el numero de movimiento: ";   
    cin >> numeroMovimiento;
    cout << "Dia del movimiento: ";    
    cin >> diaMovimiento;
    cout << "Extraccion ('E') - Deposito ('D'): ";    
    cin >> extraccionDeposito;
    cout << "Ingrese el importe: ";    cin >> importe;

    if(!bandera && extraccionDeposito == 'D'){
      mayorImporte = importe;
      mayorNumMov = numeroMovimiento;
      diaMayorMov = diaMovimiento;
      bandera = true;
    }else if (importe > mayorImporte && extraccionDeposito == 'D'){
      mayorImporte = importe;
      mayorNumMov = numeroMovimiento;
      diaMayorMov = diaMovimiento;
    }

    if(extraccionDeposito == 'E' && saldoCuenta > importe)
    {
      saldoCuenta -= importe;
      contMovimientosTotales ++;
      contExtraccion ++;
    }
    else 
    {
      if (extraccionDeposito == 'E' && saldoCuenta < importe)
      {
        cout << "Ingrese un importe para poder extraer el total que le queda disponible de $" << saldoCuenta << endl;
      }
      else
      {
        if (extraccionDeposito == 'D')
        {
          saldoCuenta += importe;
          contMovimientosTotales ++;
          contDeposito ++;
        } 
      }
    }

    if (diaMovimiento == 10 && (extraccionDeposito == 'E' || extraccionDeposito == 'D'))
    {
      cantidadMovDia10 ++;
    }
  }
    
  porcentajeExtraccion = contExtraccion * 100 / contMovimientosTotales;
  porcentajeDeposito = contDeposito * 100 / contMovimientosTotales;

  cout << "El saldo final en la cuenta es: " << saldoCuenta << endl;
  cout << "El porcentaje de movimientos de extraccion es: " << porcentajeExtraccion << "%" << endl;
  cout << "El porcentaje de movimientos de deposito es: " << porcentajeDeposito << "%" << endl;
  cout << "Mayor importe de deposito: " << mayorImporte << ". Dia: " << diaMayorMov << ". Numero de movimiento: " << mayorNumMov << endl;
  cout << "Cantidad de movimientos realizados el dia 10: " << cantidadMovDia10; 

	return 0;
}