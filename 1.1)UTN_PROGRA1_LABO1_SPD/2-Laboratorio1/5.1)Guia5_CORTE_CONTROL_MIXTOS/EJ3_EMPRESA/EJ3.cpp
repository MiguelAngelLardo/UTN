#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

//50 empleados trabajando durante 7 dias habiles. 

int main() 
{

  int nroLegajo, cantidadHorasATrabajarPorSemana, horaEntrada, horaSalida;
  int numeroLegajoEmpleadoFaltante; //A)
  bool banderafaltoAlTrabajo = false; //A)
  int acumHorasSemanalesReales; //B)

  for (int i = 0; i < 50; i ++)
  {
    horaEntrada = -1, horaSalida = -1, numeroLegajoEmpleadoFaltante = -1; //A)
    acumHorasSemanalesReales = 0; //B)

    cout << endl << "*****Empleado " << i+1 << "*****" << endl;
    cout << "Ingrese Nro de Legajo : ";
    cin >> nroLegajo;
    cout << "Ingrese la cantidad de horas a trabajar en la semana: ";
    cin >> cantidadHorasATrabajarPorSemana;

    for (int x = 0; x < 7; x++)
    {
      cout << endl << "***Dia " << x+1 << ")***" << endl;
      cout << "Ingrese la hora de ENTRADA (0 si falta): ";
      cin >> horaEntrada;
      cout << "Ingrese la hora de SALIDA (0 si falta): ";
      cin >> horaSalida;

      if(horaEntrada == 0 && horaSalida == 0){
         banderafaltoAlTrabajo = true;
      }

      acumHorasSemanalesReales += horaSalida - horaEntrada;
    }    

    if(banderafaltoAlTrabajo){
      numeroLegajoEmpleadoFaltante = nroLegajo;
      banderafaltoAlTrabajo = false;
    }

     if(numeroLegajoEmpleadoFaltante != -1)
      cout << endl << "El numero de legajo del empleado que falto es: " << numeroLegajoEmpleadoFaltante << endl; 
     else  
      cout << endl << "El empleado con numero: " << nroLegajo << " no falto en la semana. " << endl;     


    if(acumHorasSemanalesReales > cantidadHorasATrabajarPorSemana )
      cout << "El empleado trabajo mas horas de las estipuladas." << endl;
    else if (acumHorasSemanalesReales < cantidadHorasATrabajarPorSemana)
      cout << "El empleado trabajo MENOS horas de las estipuladas." << endl;
    else
      cout << "El empleado trabajo IGUAL horas de las estipuladas." << endl;
  }

  return 0;

}