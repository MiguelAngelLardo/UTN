#include <iostream>
using namespace std;

int main() {
  int sueldo, sueldoMaximo, sueldoMinimo = 0, contadorSueldo = 0, acumuladorSueldo = 0, cantidadMayor50Mil = 0;
  float sueldoPromedio;
  bool banderaMaximo = false;

  for (int i = 0; i < 10; i ++)
  {
    cout << "Imgrese el sueldo del empleado " << i+1 << "/10: ";
    cin >> sueldo;

    contadorSueldo ++;
    acumuladorSueldo += sueldo;

    if(!banderaMaximo)
    {
      sueldoMaximo = sueldo;
      banderaMaximo = true;
    }
    else
    {
      if (sueldo > sueldoMaximo)
      {
        sueldoMaximo = sueldo;
      }
    }

    if(sueldoMinimo == 0)  
      sueldoMinimo = sueldo;
    else if (sueldo < sueldoMinimo)
      sueldoMinimo = sueldo;
    
    if(sueldo > 50000)
      cantidadMayor50Mil ++;
  }

  sueldoPromedio = (float)acumuladorSueldo / contadorSueldo;

  cout << "Sueldo maximo: " << sueldoMaximo << endl;
  cout << "Sueldo minimo: " << sueldoMinimo << endl;
  cout << "Sueldo promedio: " << sueldoPromedio << endl;
  cout << "Cantidad de sueldo mayor a $50.000: " << cantidadMayor50Mil << endl;

	return 0;
}